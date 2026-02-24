// force la météo sur l'émulateur
var m_b_Debug = false;

var phone_bat = 100;

// Current position storage
var current_Latitude;
var current_Longitude;

// Weather fetch retry configuration
var weatherRetryCount = 0;
var weatherMaxRetries = 3;
var weatherRetryDelayMs = 10000;
var weatherRetryTimer = null;
var weatherXhrPending = false;

function celsiusToFahrenheit(celsius) {
  return Math.round((celsius * 9 / 5) + 32);
}

// WMO Weather Code to icon mapping compatible with Ruler Weather
// Maps to icon strings that build_icon() in C already supports
function wmoCodeToIcon(wmoCode, isNight) {
  switch (wmoCode) {
    case 0:  // Clear sky
      return isNight ? 'clear-night' : 'clear-day';
    case 1:  // Mainly clear
      return isNight ? '02n' : '02d';
    case 2:  // Partly cloudy
      return isNight ? 'partly-cloudy-night' : 'partly-cloudy-day';
    case 3:  // Overcast
      return 'cloudy';
    case 45: // Fog
    case 48: // Depositing rime fog
      return 'fog';
    case 51: // Drizzle: Light
    case 53: // Drizzle: Moderate
    case 55: // Drizzle: Dense
      return 'rain';
    case 56: // Freezing Drizzle: Light
    case 57: // Freezing Drizzle: Dense
      return 'sleet';
    case 61: // Rain: Slight
      return isNight ? '10n' : '10d';
    case 63: // Rain: Moderate
    case 65: // Rain: Heavy
      return 'rain';
    case 66: // Freezing Rain: Light
    case 67: // Freezing Rain: Heavy
      return 'sleet';
    case 71: // Snow fall: Slight
    case 73: // Snow fall: Moderate
    case 75: // Snow fall: Heavy
    case 77: // Snow grains
      return 'snow';
    case 80: // Rain showers: Slight
    case 81: // Rain showers: Moderate
    case 82: // Rain showers: Violent
      return isNight ? '10n' : '10d';
    case 85: // Snow showers: Slight
    case 86: // Snow showers: Heavy
      return 'snow';
    case 95: // Thunderstorm: Slight or moderate
    case 96: // Thunderstorm with slight hail
    case 99: // Thunderstorm with heavy hail
      return 'thunderstorm';
    default:
      return isNight ? 'partly-cloudy-night' : 'partly-cloudy-day';
  }
}

// Check if current hour is night time (between 21:00 and 6:00)
function isNightTime(hour) {
  return hour >= 21 || hour < 6;
}

var xhrRequest = function (url, type, callback, errorCallback) {
  var xhr = new XMLHttpRequest();

  xhr.timeout = 15000;

  xhr.onload = function () {
    callback(this.responseText);
  };

  xhr.onerror = function (err) {
    console.error('XHR failed', err);
    if (errorCallback) errorCallback('network_error');
  };

  xhr.ontimeout = function () {
    console.error('XHR timeout after 15s');
    if (errorCallback) errorCallback('timeout');
  };

  xhr.open(type, url);
  xhr.send();
};

// Called when weather fetch succeeds - reset retry state
function onWeatherFetchSuccess() {
  weatherRetryCount = 0;
  weatherXhrPending = false;
  if (weatherRetryTimer) {
    clearTimeout(weatherRetryTimer);
    weatherRetryTimer = null;
  }
  console.log("Weather fetch successful");
}

// Called when weather fetch fails - schedule retry if under limit
function onWeatherFetchError(reason) {
  weatherXhrPending = false;
  weatherRetryCount++;
  console.log("Weather fetch failed (" + reason + "), retry " + weatherRetryCount + "/" + weatherMaxRetries);

  if (weatherRetryCount < weatherMaxRetries) {
    console.log("Scheduling retry in " + weatherRetryDelayMs + "ms");
    weatherRetryTimer = setTimeout(function () {
      weatherRetryTimer = null;
      getForecast();
    }, weatherRetryDelayMs);
  } else {
    console.log("Max retries reached, giving up until next scheduled refresh");
    weatherRetryCount = 0;
  }
}

// Process Open-Meteo API response
function processOpenMeteoResponse(responseText) {
  var json = JSON.parse(responseText);
  var hourly = json.hourly;
  var units = localStorage.getItem(152);

  // Current conditions (first hour in forecast)
  var now = new Date();
  var currentHour = now.getHours();
  var isNight = isNightTime(currentHour);

  // Calculate current hour offset in API data
  var hourOffset = currentHour;

  var currentTemp = hourly.temperature_2m[hourOffset];
  var currentWindSpeed = hourly.wind_gusts_10m[hourOffset];
  var currentWmoCode = hourly.weather_code[hourOffset];
  var icon = wmoCodeToIcon(currentWmoCode, isNight);

  // Calculate min/max for next 24 hours
  var tmin = 1000;
  var tmax = -1000;
  for (var i = hourOffset; i <= hourOffset + 24 && i < hourly.temperature_2m.length; i++) {
    var temp = hourly.temperature_2m[i];
    if (temp < tmin) tmin = temp;
    if (temp > tmax) tmax = temp;
  }

  var temperature = currentTemp;

  if (units == 1) {
    temperature = celsiusToFahrenheit(temperature);
    tmin = celsiusToFahrenheit(tmin);
    tmax = celsiusToFahrenheit(tmax);
  } else {
    temperature = Math.round(temperature);
    tmin = Math.round(tmin);
    tmax = Math.round(tmax);
  }

  temperature = Math.round(temperature);
  tmax = Math.round(tmax);
  tmin = Math.round(tmin);

  // Wind speed conversion
  var wind;
  if (units == 1) {
    // Convert km/h to mph
    wind = Math.round(currentWindSpeed * 0.621371);
  } else {
    // Keep in km/h
    wind = Math.round(currentWindSpeed);
  }

  // Extract hourly forecast data (every 3 hours: +0, +3, +6, +9)
  var temp1, temp2, temp3, temp4, temp5;
  var hour1, hour2, hour3;
  var icon1, icon2, icon3;
  var wind1, wind2, wind3;
  var rain1, rain2, rain3, rain4, rain5;

  // Calculate indices for +0, +3, +6, +9, +12 hours
  var idx0 = hourOffset;
  var idx1 = hourOffset + 3;
  var idx2 = hourOffset + 6;
  var idx3 = hourOffset + 9;
  var idx4 = hourOffset + 12;

  // Temperatures
  temp1 = hourly.temperature_2m[idx0];
  temp2 = hourly.temperature_2m[idx1];
  temp3 = hourly.temperature_2m[idx2];
  temp4 = hourly.temperature_2m[idx3];
  temp5 = hourly.temperature_2m[idx4];

  if (units == 1) {
    temp1 = celsiusToFahrenheit(temp1);
    temp2 = celsiusToFahrenheit(temp2);
    temp3 = celsiusToFahrenheit(temp3);
    temp4 = celsiusToFahrenheit(temp4);
    temp5 = celsiusToFahrenheit(temp5);
  } else {
    temp1 = Math.round(temp1);
    temp2 = Math.round(temp2);
    temp3 = Math.round(temp3);
    temp4 = Math.round(temp4);
    temp5 = Math.round(temp5);
  }

  // Hours (local time)
  hour1 = ((currentHour + 3) % 24) + "";
  hour2 = ((currentHour + 6) % 24) + "";
  hour3 = ((currentHour + 9) % 24) + "";

  // Icons for forecast hours
  icon1 = wmoCodeToIcon(hourly.weather_code[idx1], isNightTime((currentHour + 3) % 24));
  icon2 = wmoCodeToIcon(hourly.weather_code[idx2], isNightTime((currentHour + 6) % 24));
  icon3 = wmoCodeToIcon(hourly.weather_code[idx3], isNightTime((currentHour + 9) % 24));

  console.log("Icons: main=" + icon + " wmo=" + currentWmoCode + " icon1=" + icon1 + " icon2=" + icon2 + " icon3=" + icon3);
  console.log("Temp=" + temperature + " wind=" + wind + " tmin=" + tmin + " tmax=" + tmax);

  // Wind speed for forecast hours
  if (units == 1) {
    wind1 = Math.round(hourly.wind_gusts_10m[idx1] * 0.621371);
    wind2 = Math.round(hourly.wind_gusts_10m[idx2] * 0.621371);
    wind3 = Math.round(hourly.wind_gusts_10m[idx3] * 0.621371);
  } else {
    wind1 = Math.round(hourly.wind_gusts_10m[idx1]);
    wind2 = Math.round(hourly.wind_gusts_10m[idx2]);
    wind3 = Math.round(hourly.wind_gusts_10m[idx3]);
  }

  // Precipitation (scaled by 10 for compatibility)
  rain1 = Math.round((hourly.precipitation[idx0] || 0) * 10);
  rain2 = Math.round((hourly.precipitation[idx1] || 0) * 10);
  rain3 = Math.round((hourly.precipitation[idx2] || 0) * 10);
  rain4 = Math.round((hourly.precipitation[idx3] || 0) * 10);
  rain5 = Math.round((hourly.precipitation[idx4] || 0) * 10);

  // Get location from localStorage if available
  var location = localStorage.getItem(154);
  if (location) {
    location = location.replace(/"/g, "");
  } else {
    location = "GPS";
  }

  // Assemble dictionary using Ruler Weather keys
  var dictionary = {
    "KEY_TEMPERATURE": temperature,
    "KEY_WIND_SPEED": wind,
    "KEY_ICON": icon,
    "KEY_TMIN": tmin,
    "KEY_TMAX": tmax,
    "KEY_FORECAST_H1": hour1,
    "KEY_FORECAST_H2": hour2,
    "KEY_FORECAST_H3": hour3,
    "KEY_FORECAST_WIND1": wind1,
    "KEY_FORECAST_WIND2": wind2,
    "KEY_FORECAST_WIND3": wind3,
    "KEY_FORECAST_TEMP1": temp1,
    "KEY_FORECAST_TEMP2": temp2,
    "KEY_FORECAST_TEMP3": temp3,
    "KEY_FORECAST_TEMP4": temp4,
    "KEY_FORECAST_TEMP5": temp5,
    "KEY_FORECAST_RAIN1": rain1,
    "KEY_FORECAST_RAIN2": rain2,
    "KEY_FORECAST_RAIN3": rain3,
    "KEY_FORECAST_RAIN4": rain4,
    "KEY_FORECAST_ICON1": icon1,
    "KEY_FORECAST_ICON2": icon2,
    "KEY_FORECAST_ICON3": icon3,
    "KEY_LOCATION": location,
  };

  // Send to Pebble
  Pebble.sendAppMessage(dictionary,
    function (e) {
      console.log("Weather info sent to Pebble successfully!");
    },
    function (e) {
      console.log("Error sending weather info to Pebble!");
    }
  );
}

function getForecast() {
  console.log("getForecast using Open-Meteo API");

  // Prevent concurrent requests
  if (weatherXhrPending) {
    console.log("Weather XHR already pending, skipping");
    return;
  }

  weatherXhrPending = true;

  // Open-Meteo API with Météo-France AROME model (excellent for France)
  var urlOpenMeteo = 'https://api.open-meteo.com/v1/meteofrance?' +
    'latitude=' + current_Latitude + '&longitude=' + current_Longitude +
    '&hourly=temperature_2m,precipitation,weather_code,wind_gusts_10m' +
    '&forecast_days=2&timezone=auto';

  console.log("Weather URL: " + urlOpenMeteo);

  xhrRequest(urlOpenMeteo, 'GET',
    function (responseText) {
      try {
        processOpenMeteoResponse(responseText);
        onWeatherFetchSuccess();
      } catch (e) {
        console.error("Error processing Open-Meteo response: " + e);
        onWeatherFetchError('parse_error');
      }
    },
    onWeatherFetchError
  );
}

function locationSuccess(pos) {
  current_Latitude = pos.coords.latitude;
  current_Longitude = pos.coords.longitude;

  // Store coordinates for fallback
  localStorage.setItem(160, current_Latitude);
  localStorage.setItem(161, current_Longitude);

  console.log("Location success: " + current_Latitude + ", " + current_Longitude);
  getForecast();
}

function locationError(err) {
  console.log("Error requesting location, trying saved coordinates");

  current_Latitude = localStorage.getItem(160);
  current_Longitude = localStorage.getItem(161);

  if (current_Latitude !== null && current_Longitude !== null) {
    console.log("Using saved coordinates: " + current_Latitude + ", " + current_Longitude);
    getForecast();
  } else {
    console.log("No saved coordinates available");
  }
}

function getPosition() {
  console.log("Getting position...");
  navigator.geolocation.getCurrentPosition(
    locationSuccess,
    locationError,
    { timeout: 15000, maximumAge: 120000 }
  );
}

function getWeather() {
  console.log("getWeather called");
  getPosition();
}

// Listen for when the watchface is opened
Pebble.addEventListener('ready',
  function (e) {
    Battery_Init();
    console.log("PebbleKit JS ready - auto weather fetch");
    // Auto-trigger one weather fetch on startup
    setTimeout(function () {
      getWeather();
    }, 500);
  }
);



Pebble.addEventListener('appmessage',
  function (e) {
    if ((navigator.onLine) || (m_b_Debug)) {
      //  console.log("Appel météo !!");
      getWeather();
    }
  }
);



Pebble.addEventListener('showConfiguration', function () {
  var url = 'https://sichroteph.github.io/Ruler-Weather/?v=124';

  //  console.log('Showing configuration page: ' + url);
  Pebble.openURL(url);
});





Pebble.addEventListener('webviewclosed', function (e) {
  var configData = JSON.parse(decodeURIComponent(e.response));
  // console.log('Configuration page returned: ' + JSON.stringify(configData));

  var gps = configData['gps'];
  var input_city = configData['input_city'];
  var input_api = configData['input_api'];
  var select_utc = configData['select_utc'];
  var select_goal = configData['select_goal'];
  var select_provider = configData['select_provider'];
  var select_screen = configData['select_screen'];
  var radio_units = configData['radio_units'];
  var radio_refresh = configData['radio_refresh'];
  var toggle_vibration = configData['toggle_vibration'];

  var select_fonts = configData['select_fonts'];
  // console.log(select_fonts);

  var toggle_bt = configData['toggle_bt'];
  var toggle_pc = configData['toggle_pc'];
  var toggle_tg = configData['toggle_tg'];
  var toggle_inv = configData['toggle_inv'];
  var toggle_100 = configData['toggle_100'];
  var toggle_80 = configData['toggle_80'];
  var toggle_centered = configData['toggle_centered'];
  var toggle_month = configData['toggle_month'];
  var toggle_classic = configData['toggle_classic'];


  var toggle_bw_icons = configData['toggle_bw_icons'];
  var toggle_gradiant = configData['toggle_gradiant'];
  var toggle_ruler_large = configData['toggle_ruler_large'];
  var color_right_back = configData['color_right_back'];
  var color_left_back = configData['color_left_back'];
  var color_hours = configData['color_hours'];
  var color_ruler = configData['color_ruler'];
  var color_temperatures = configData['color_temperatures'];
  var color_line = configData['color_line'];
  var color_2nd_back = configData['color_2nd_back'];
  var color_2nd_temp = configData['color_2nd_temp'];


  var dict = {};


  localStorage.setItem(150, configData['gps'] ? 1 : 0);
  localStorage.setItem(151, configData['input_city']);
  localStorage.setItem(152, configData['radio_units'] ? 1 : 0);
  localStorage.setItem(153, configData['select_provider']);
  localStorage.setItem(154, configData['input_city']);




  dict['KEY_GPS'] = configData['gps'] ? 1 : 0;  // Send a boolean as an integer
  dict['KEY_INPUT_CITY'] = configData['input_city'];
  dict['KEY_SELECT_UTC'] = configData['select_utc'];
  dict['KEY_SELECT_GOAL'] = configData['select_goal'];
  dict['KEY_SELECT_SCREEN'] = configData['select_screen'];
  dict['KEY_SELECT_FONTS'] = configData['select_fonts'];

  dict['KEY_SELECT_PROVIDER'] = configData['select_provider'];

  dict['KEY_RADIO_UNITS'] = configData['radio_units'] ? 1 : 0;
  dict['KEY_RADIO_REFRESH'] = configData['radio_refresh'] ? 1 : 0;

  dict['KEY_TOGGLE_VIBRATION'] = configData['toggle_vibration'] ? 1 : 0;


  dict['KEY_TOGGLE_BT'] = configData['toggle_bt'] ? 1 : 0;
  dict['KEY_TOGGLE_PC'] = configData['toggle_pc'] ? 1 : 0;
  dict['KEY_TOGGLE_TG'] = configData['toggle_tg'] ? 1 : 0;
  dict['KEY_TOGGLE_INV'] = configData['toggle_inv'] ? 1 : 0;
  dict['KEY_TOGGLE_100'] = configData['toggle_100'] ? 1 : 0;
  dict['KEY_TOGGLE_80'] = configData['toggle_80'] ? 1 : 0;
  dict['KEY_TOGGLE_BW_ICONS'] = configData['toggle_bw_icons'] ? 1 : 0;
  dict['KEY_TOGGLE_GRADIANT'] = configData['toggle_gradiant'] ? 1 : 0;
  dict['KEY_TOGGLE_RULER_LARGE'] = configData['toggle_ruler_large'] ? 1 : 0;
  dict['KEY_TOGGLE_CENTERED'] = configData['toggle_centered'] ? 1 : 0;
  dict['KEY_TOGGLE_MONTH'] = configData['toggle_month'] ? 1 : 0;
  dict['KEY_TOGGLE_CLASSIC'] = configData['toggle_classic'] ? 1 : 0;
  dict['KEY_TOGGLE_STEEL_OFFSET'] = configData['toggle_steel_offset'] ? 1 : 0;

  dict['KEY_COLOR_RIGHT_R'] = parseInt(color_right_back.substring(2, 4), 16);
  dict['KEY_COLOR_RIGHT_G'] = parseInt(color_right_back.substring(4, 6), 16);
  dict['KEY_COLOR_RIGHT_B'] = parseInt(color_right_back.substring(6, 8), 16);
  dict['KEY_COLOR_LEFT_R'] = parseInt(color_left_back.substring(2, 4), 16);
  dict['KEY_COLOR_LEFT_G'] = parseInt(color_left_back.substring(4, 6), 16);
  dict['KEY_COLOR_LEFT_B'] = parseInt(color_left_back.substring(6, 8), 16);


  dict['KEY_COLOR_HOURS_R'] = parseInt(color_hours.substring(2, 4), 16);
  dict['KEY_COLOR_HOURS_G'] = parseInt(color_hours.substring(4, 6), 16);
  dict['KEY_COLOR_HOURS_B'] = parseInt(color_hours.substring(6, 8), 16);

  dict['KEY_COLOR_LINE_R'] = parseInt(color_line.substring(2, 4), 16);
  dict['KEY_COLOR_LINE_G'] = parseInt(color_line.substring(4, 6), 16);
  dict['KEY_COLOR_LINE_B'] = parseInt(color_line.substring(6, 8), 16);


  dict['KEY_COLOR_LINE_R'] = parseInt(color_line.substring(2, 4), 16);
  dict['KEY_COLOR_LINE_G'] = parseInt(color_line.substring(4, 6), 16);
  dict['KEY_COLOR_LINE_B'] = parseInt(color_line.substring(6, 8), 16);

  dict['KEY_COLOR_RULER_R'] = parseInt(color_ruler.substring(2, 4), 16);
  dict['KEY_COLOR_RULER_G'] = parseInt(color_ruler.substring(4, 6), 16);
  dict['KEY_COLOR_RULER_B'] = parseInt(color_ruler.substring(6, 8), 16);


  dict['KEY_COLOR_2ND_BACK_R'] = parseInt(color_2nd_back.substring(2, 4), 16);
  dict['KEY_COLOR_2ND_BACK_G'] = parseInt(color_2nd_back.substring(4, 6), 16);
  dict['KEY_COLOR_2ND_BACK_B'] = parseInt(color_2nd_back.substring(6, 8), 16);


  dict['KEY_COLOR_2ND_TEMP_R'] = parseInt(color_2nd_temp.substring(2, 4), 16);
  dict['KEY_COLOR_2ND_TEMP_G'] = parseInt(color_2nd_temp.substring(4, 6), 16);
  dict['KEY_COLOR_2ND_TEMP_B'] = parseInt(color_2nd_temp.substring(6, 8), 16);

  dict['KEY_COLOR_TEMPERATURES_R'] = parseInt(color_temperatures.substring(2, 4), 16);
  dict['KEY_COLOR_TEMPERATURES_G'] = parseInt(color_temperatures.substring(4, 6), 16);
  dict['KEY_COLOR_TEMPERATURES_B'] = parseInt(color_temperatures.substring(6, 8), 16);



  // Send to watchapp
  Pebble.sendAppMessage(dict, function () {
    // console.log('Send successful: ' + JSON.stringify(dict));
  }, function () {
    // console.log('Send failed!');
  }
  );


});
