#include <pebble.h>
// pour afficher les segments
#define IS_DEBUG_VERSION false
#define IS_HOUR_FICTIVE false
#define FICTIVE_HOUR 10
#define FICTIVE_MINUTE 00    

  
#if defined(PBL_ROUND)  
#define RULER_XOFFSET 55
#define TEXT_HOUR_OFFSET 83  
#define IS_ROUND true
#define MARK_0  42  
#else 
#define RULER_XOFFSET 36
#define TEXT_HOUR_OFFSET 56     
#define IS_ROUND false  
#define MARK_0  42      
#endif     

#define RULER_SIZE -2  
#define MAXRAIN 40  

#define LINE_THICK 3    

// For the gradiant effect, 1/2 pixels, 1/3 and 1/4
#define GRADIANT 4
#define GRADIANT_X_OFFSET -1
#define GRADIANT_Y_OFFSET -10

#ifdef PBL_COLOR   

#define BLUE_LINE GColorElectricBlue
#define RED_LINE GColorRed 
#define RAIN_COLOR GColorCobaltBlue
#define IS_COLOR true

#else 

#define BLUE_LINE GColorWhite  
#define RAIN_COLOR GColorWhite
#define RED_LINE GColorWhite 
#define IS_COLOR false

#endif

#define STATUS_FONT FONT_KEY_GOTHIC_14

#define KEY_TEMPERATURE 0

#define KEY_DESCRIPTION 2
#define KEY_WIND_SPEED 3 
#define KEY_CLOUDS 4
#define KEY_HUMIDITY 5
#define KEY_SUNRISE 6
#define KEY_SUNSET 7  
#define KEY_TMIN 8 
#define KEY_TMAX 9  
#define KEY_ICON 10   

#define KEY_FORECAST_TEMP1 11 
#define KEY_FORECAST_TEMP2 12
#define KEY_FORECAST_TEMP3 13
#define KEY_FORECAST_TEMP4 14
#define KEY_FORECAST_TEMP5 15
#define KEY_FORECAST_H1 16
#define KEY_FORECAST_H2 17
#define KEY_FORECAST_H3 18
#define KEY_FORECAST_RAIN1 21
#define KEY_FORECAST_RAIN2 22
#define KEY_FORECAST_RAIN3 23
#define KEY_FORECAST_RAIN4 24
#define KEY_FORECAST_RAIN5 25
#define KEY_FORECAST_ICON1 26
#define KEY_FORECAST_ICON2 27
#define KEY_FORECAST_ICON3 28
#define KEY_FORECAST_WIND1 29
#define KEY_FORECAST_WIND2 30
#define KEY_FORECAST_WIND3 31
#define KEY_LOCATION 32

#define KEY_GPS 33
#define KEY_INPUT_CITY 34
#define KEY_SELECT_UTC 35
#define KEY_RADIO_UNITS 36
#define KEY_RADIO_REFRESH 54
#define KEY_TOGGLE_VIBRATION 37
#define KEY_TOGGLE_BW_ICONS 38 
#define KEY_COLOR_RIGHT_R 39
#define KEY_COLOR_RIGHT_G 40
#define KEY_COLOR_RIGHT_B 41
#define KEY_COLOR_LEFT_R 42
#define KEY_COLOR_LEFT_G 43
#define KEY_COLOR_LEFT_B 44
#define KEY_COLOR_HOURS_R 45
#define KEY_COLOR_HOURS_G 46   
#define KEY_COLOR_HOURS_B 47

#define KEY_COLOR_RULER_R 48
#define KEY_COLOR_RULER_G 49
#define KEY_COLOR_RULER_B 50
#define KEY_COLOR_TEMPERATURES_R 51
#define KEY_COLOR_TEMPERATURES_G 52
#define KEY_COLOR_TEMPERATURES_B 53
#define KEY_RADIO_REFRESH 54
#define KEY_LAST_REFRESH 55
#define KEY_COLOR_LINE_R 56
#define KEY_COLOR_LINE_G 57
#define KEY_COLOR_LINE_B 58
#define KEY_TOGGLE_GRADIANT 59
#define KEY_SELECT_SCREEN 60
#define KEY_COLOR_2ND_BACK_R 61
#define KEY_COLOR_2ND_BACK_G 62
#define KEY_COLOR_2ND_BACK_B 63
#define KEY_COLOR_2ND_TEMP_R 64
#define KEY_COLOR_2ND_TEMP_G 65
#define KEY_COLOR_2ND_TEMP_B 66
#define KEY_TOGGLE_RULER_LARGE 67
#define KEY_TOGGLE_CENTERED 68

#define KEY_SELECT_GOAL 69
#define KEY_SELECT_FONTS 102
#define KEY_TOGGLE_BT 103
#define KEY_TOGGLE_MONTH 104
#define KEY_PHONE_BAT 105
#define KEY_PHONE_CHARGE 106
#define KEY_TOGGLE_100 107
#define KEY_TOGGLE_80 108
#define KEY_TOGGLE_INV 109
#define KEY_TOGGLE_TG 110
#define KEY_TOGGLE_PC 111
#define KEY_SELECT_PROVIDER 112


#if defined(PBL_ROUND)

#define XOFFSET 18
#define YOFFSET 6

#define WIDTH 180
#define HEIGHT 180

#define TEXT_MONTH_STATUS_OFFSET_X 5 
#define TEXT_MONTH_STATUS_OFFSET_Y 0

#define TEXT_DAYW_STATUS_OFFSET_X 6 
#define TEXT_DAYW_STATUS_OFFSET_Y 32 
#define TEXT_DAY_STATUS_OFFSET_X 8 
#define TEXT_DAY_STATUS_OFFSET_Y 40 

#define TEXT_TMAX_OFFSET_X -21
#define TEXT_TMAX_OFFSET_Y 67 
#define TEXT_TMIN_OFFSET_X -82
#define TEXT_TMIN_OFFSET_Y 91 

#define ICON_X 19
#define ICON_Y 66
#define ICON6_X 18
#define ICON6_Y 100

#define ICONW_X 10
#define ICONW_Y 50

#define TEXT_TEMP_OFFSET_X 8  
#define TEXT_TEMP_OFFSET_Y 105 

#define BAT_STATUS_OFFSET_X 25
#define BAT_STATUS_OFFSET_Y 140

// For bluetooth lost notification
#define BT_STATUS_OFFSET_Y 7

#define WEATHER_OFFSET_X 0
#define WEATHER_OFFSET_Y 0

#define TEXT_WIND_OFFSET_X 10
#define TEXT_WIND_OFFSET_Y 70

#define BAT_PHONE_STATUS_OFFSET_X 0
#define BAT_PHONE_STATUS_OFFSET_Y 5

#define ICON_BT_X 0
#define ICON_BT_Y 5



#else
//******************************************************************
//******************************************************************
//******************************************************************


#define WIDTH 144
#define HEIGHT 168   

#define XOFFSET 18
#define YOFFSET 0


#define TEXT_DAYW_STATUS_OFFSET_X -3
#define TEXT_DAYW_STATUS_OFFSET_Y 1
#define TEXT_DAY_STATUS_OFFSET_X -1
#define TEXT_DAY_STATUS_OFFSET_Y 6
#define TEXT_MONTH_STATUS_OFFSET_X -3
#define TEXT_MONTH_STATUS_OFFSET_Y 30

#define ICON_BT_X -1
#define ICON_BT_Y 44

#define BAT_STATUS_OFFSET_X 0
#define BAT_STATUS_OFFSET_Y 52

#define BAT_PHONE_STATUS_OFFSET_X 0
#define BAT_PHONE_STATUS_OFFSET_Y 57

#define TEXT_TEMP_OFFSET_X 2
#define TEXT_TEMP_OFFSET_Y 97
#define ICON_X 0
#define ICON_Y 58

#define TEXT_TMAX_OFFSET_X 2
#define TEXT_TMAX_OFFSET_Y 88
#define ICON6_X 0
#define ICON6_Y 108
#define TEXT_TMIN_OFFSET_X -34
#define TEXT_TMIN_OFFSET_Y 147


#define ICONW_X 3   
#define ICONW_Y 77  
#define TEXT_WIND_OFFSET_X 10
#define TEXT_WIND_OFFSET_Y 80


// For bluetooth lost notification
#define BT_STATUS_OFFSET_Y -27

#define WEATHER_OFFSET_X -14
#define WEATHER_OFFSET_Y -9
#endif 

#define MARK_5  12
#define MARK_15 22 
#define MARK_30 32  


#define QUIET_TIME_START 22
#define QUIET_TIME_END 10


static bool is_vibration = false;
static bool is_inv = true;
// Is time graph
static bool is_tg = false;
// is notif when Phone Charge
static bool is_pc = false;
static Window *s_main_window;
static Layer *s_canvas_layer;
static Layer *layer;   

static int hour_part_size=0;
static int phone_bat=0;
static bool is_phone_charging=false;

static char week_day[4]=" ";   
static char month[4]=" ";
static char mday[4]=" ";
static char tmin[10]=" " ;
static char tmax[10]=" ";
static char weather_temp_char[10]=" ";


// WEATHER  

static int weather_temp=0;

static time_t t;
static struct tm now;


  static int tmin_val=0;
static int tmax_val=0;
static int wind_speed_val=0;
static int wind1_val=0;
static int wind2_val=0;
static int wind3_val=0;
static int temp1_val=0;
static int temp2_val=0;
static int temp3_val=0;
static int temp4_val=0;
static int temp5_val=0;
static int rain1_val=0;
static int rain2_val=0;
static int rain3_val=0;
static int rain4_val=0;
time_t last_refresh=0;
int duration=3600;
AppTimer *timer_short;



static char icon[20]=" "; 
static char icon1[20]=" ";
static char icon2[20]=" ";
static char icon3[20]=" "; 

static char h1[20]=" ";
static char h2[20]=" "; 
static char h3[20]=" ";
static char location[100]=" ";  
static char wind1[10]=" ";
static char wind2[10]=" ";
static char wind3[10]=" ";
static char temp1[10]=" ";
static char temp2[10]=" ";
static char temp3[10]=" ";
static char temp4[10]=" ";
static char temp5[10]=" ";
static char rain1[10]=" ";
static char rain2[10]=" ";
static char rain3[10]=" ";
static char rain4[10]=" ";
static char rain_ico_val;
static char city[50]=" ";

// Config data
static bool is_gps;
static bool is_centered=false;
static bool is_month=false;

static int utc=1;
static int select_screen=2;
static bool is_metric=1;
static bool is_30mn=1;
static bool is_bt=0;
static bool is_phone_100=0;
static bool is_phone_80=0;
static int select_fonts =0;
static int select_provider=0;
static int select_goal=0;

static bool is_bw_icon=0;
static bool is_gradiant=0;
static bool is_ruler_large=1;
static GColor color_right;
static GColor color_left;
static GColor color_hours;
static GColor color_ruler;
static GColor color_temp;
static GColor color_line;
static GColor color_2nd_back;
static GColor color_2nd_temp;

static GPoint line1_p1 = { 0, 84 };
static GPoint line1_p2 = { 143, 84 };
static GPoint line2_p1 = { 0, 0 };
static GPoint line2_p2 = { 0, 0 };

static int hour_offset_x=0;
static int hour_offset_y=0;
static int status_offset_x=0;
static int status_offset_y=0;


static int hour_line_ypos = 84+YOFFSET;

static char pebble_Lang[20]=" ";

bool is_charging=false;

bool is_connected=false;

// For week day
static GFont fontsmall;
// For 2dn screen
static GFont fontsmallbold;
// Dates and temp
static GFont fontmedium;
// Hour display
static GFont fontbig;

int line_interval=4;
int segment_thickness=2;

static int markWidth[12] = { MARK_0, MARK_5, MARK_5, MARK_15, MARK_5, MARK_5, MARK_30, MARK_5, MARK_5, MARK_15, MARK_5, MARK_5 };
static int labels_12h[28] = { 10, 11, 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 , 1};
static int labels[28] = { 22, 23, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 0, 1};

static uint8_t battery_level=0;

static char hour_text[5]=" ";

static char *weekdayLangFr[7]={"DIM","LUN","MAR","MER","JEU","VEN","SAM"};
static char *weekdayLangEn[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
static char *weekdayLangGe[7]={"SON","MON","DIE","MIT","DON","FRE","SAM"};
static char *weekdayLangSp[7]={"DOM","LUN","MAR","MIE","JUE","VIE","SAB"};

static char *MonthLangFr[12]={"JAN","FEV","MAR","AVR","MAI","JUI","JUI","AOU","SEP","OCT","NOV","DEC"};
static char *MonthLangEn[12]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
static char *MonthLangGe[12]={"JAN","FEB","MÄR","APR","MAI","JUN","JUL","AUG","SEP","AKT","NOV","DEZ"};
static char *MonthLangSp[12]={"ENE","FEB","MAR","ABR","MAY","JUN","JUL","AGO","SEP","OCT","NOV","DIC"};



static void app_focus_changed(bool focused) {
  if (focused) {
    layer_set_hidden(layer, false);  
    layer_mark_dirty(layer);
  }
}

static void app_focus_changing(bool focusing) {
  if (focusing) {
    layer_set_hidden(layer, true);  
  }
}


static int build_icon (char *text_icon){
  if ((strcmp (text_icon,"01d")==0)||(strcmp (text_icon,"clear-day")==0)){
    if((is_bw_icon)||(!IS_COLOR))
      return RESOURCE_ID_ENSOLEILLE_W;
    else    
      return RESOURCE_ID_ENSOLEILLE;  

  }  
  if ((strcmp (text_icon,"01n")==0)|| (strcmp (text_icon,"clear-night")==0)){

    if((is_bw_icon)||(!IS_COLOR))
      return RESOURCE_ID_NUIT_CLAIRE_W;
    else   
      return RESOURCE_ID_NUIT_CLAIRE;

  }    
  if (strcmp (text_icon,"02d")==0){
    if((is_bw_icon)||(!IS_COLOR))
      return RESOURCE_ID_FAIBLES_PASSAGES_NUAGEUX_W;
    else  
      return RESOURCE_ID_FAIBLES_PASSAGES_NUAGEUX;
  }    
  if (strcmp (text_icon,"02n")==0){
    if((is_bw_icon)||(!IS_COLOR))
      return RESOURCE_ID_NUIT_BIEN_DEGAGEE_W;  
    else  
      return RESOURCE_ID_NUIT_BIEN_DEGAGEE;   
  }  
  if (strcmp (text_icon,"03d")==0||strcmp (text_icon,"partly-cloudy-day")==0){
    if((is_bw_icon)||(!IS_COLOR))
      return RESOURCE_ID_DEVELOPPEMENT_NUAGEUX_W;
    else  
      return RESOURCE_ID_DEVELOPPEMENT_NUAGEUX;
  }  
  if ((strcmp (text_icon,"03n")==0)|| (strcmp (text_icon,"partly-cloudy-night")==0)){
    if((is_bw_icon)||(!IS_COLOR))
      return RESOURCE_ID_NUIT_AVEC_DEVELOPPEMENT_NUAGEUX_W;
    else  
      return RESOURCE_ID_NUIT_AVEC_DEVELOPPEMENT_NUAGEUX;
  }    
  if (strcmp (text_icon,"wind")==0){
    return RESOURCE_ID_WIND;
  }  


  if ((strcmp (text_icon,"04d")==0)||(strcmp (text_icon,"cloudy")==0)){
    if((is_bw_icon)||(!IS_COLOR))
      return RESOURCE_ID_FORTEMENT_NUAGEUX_W;
    else 
      return RESOURCE_ID_FORTEMENT_NUAGEUX;
  }    
  if (strcmp (text_icon,"04n")==0){
    if((is_bw_icon)||(!IS_COLOR))
      return RESOURCE_ID_NUIT_NUAGEUSE_W;
    else  
      return RESOURCE_ID_NUIT_NUAGEUSE;
  } 
  if (strcmp (text_icon,"09d")==0||strcmp (text_icon,"09n")==0){
    if((is_bw_icon)||(!IS_COLOR))
      return RESOURCE_ID_COUVERT_AVEC_AVERSES_W;
    else  
      return RESOURCE_ID_COUVERT_AVEC_AVERSES;
  }  

  if ((strcmp (text_icon,"10d")==0)||(strcmp (text_icon,"rain")==0)){
    int max_rain = MAXRAIN; 
    int rain_pixel=  (int)(30*rain_ico_val/max_rain);
    if((is_bw_icon)||(!IS_COLOR)){
      if (rain_pixel<10)
        return RESOURCE_ID_AVERSES_DE_PLUIE_FORTE_W1;
      if (rain_pixel<20)
        return RESOURCE_ID_AVERSES_DE_PLUIE_FORTE_W2;

      return RESOURCE_ID_AVERSES_DE_PLUIE_FORTE_W;
    }
    else  
      if (rain_pixel<10)
      return RESOURCE_ID_AVERSES_DE_PLUIE_FORTE1;
      if (rain_pixel<20)
      return RESOURCE_ID_AVERSES_DE_PLUIE_FORTE2;

      return RESOURCE_ID_AVERSES_DE_PLUIE_FORTE;
  }   
  if (strcmp (text_icon,"10n")==0){
    if((is_bw_icon)||(!IS_COLOR))
      return RESOURCE_ID_NUIT_AVEC_AVERSES_W;
    else  
      return RESOURCE_ID_NUIT_AVEC_AVERSES;
  }    

  if (strcmp (text_icon,"11d")==0||strcmp (text_icon,"11n")==0||strcmp (text_icon,"thunderstorm")==0||strcmp (text_icon,"tornado")==0){
    if((is_bw_icon)||(!IS_COLOR))
      return RESOURCE_ID_FORTEMENT_ORAGEUX_W;
    else  
      return RESOURCE_ID_FORTEMENT_ORAGEUX;
  }    

  if (strcmp (text_icon,"13d")==0||strcmp (text_icon,"13n")==0||strcmp (text_icon,"snow")==0||strcmp (text_icon,"sleet")==0){
    if((is_bw_icon)||(!IS_COLOR))
      return RESOURCE_ID_NEIGE_FORTE_W;
    else  
      return RESOURCE_ID_NEIGE_FORTE;
  }    

  if (strcmp (text_icon,"50d")==0||strcmp (text_icon,"50n")==0||strcmp (text_icon,"fog")==0||strcmp (text_icon,"hail")==0){
    if((is_bw_icon)||(!IS_COLOR))
      return RESOURCE_ID_BROUILLARD_W;
    else  
      return RESOURCE_ID_BROUILLARD;
  }   

  return RESOURCE_ID_BT;

}


int abs(int x){
  if (x>=0)
    return x;
  else 
    return-x;
}

float my_sqrt( float num )
{  
  float a, p, e = 0.001, b;

  a = num;
  p = a * a; 
  while( p - num >= e )
  {
    b = ( a + ( num / a ) ) / 2;
    a = b;
    p = a * a;
  }
  return a;
}



static void update_proc(Layer *layer, GContext *ctx) {


  if(is_ruler_large){
    line_interval = 5;
    segment_thickness = 3 ;
  }
  else
  {
    line_interval = 4;
    segment_thickness = 2 ; 
  }
  int hour_size = 12 * line_interval; // 12 marks, one every 5 minutes
  GBitmap *s_icon;


  // DRAW DIAL
  GRect rect_text_day = { { TEXT_DAY_STATUS_OFFSET_X+status_offset_x, TEXT_DAY_STATUS_OFFSET_Y+status_offset_y }, {RULER_XOFFSET , 150 } };
  GRect rect_text_dayw = { { TEXT_DAYW_STATUS_OFFSET_X+status_offset_x, TEXT_DAYW_STATUS_OFFSET_Y+status_offset_y }, {RULER_XOFFSET , 150 } };
  GRect rect_text_month= { { TEXT_MONTH_STATUS_OFFSET_X+status_offset_x, TEXT_MONTH_STATUS_OFFSET_Y+status_offset_y }, {RULER_XOFFSET , 150 } };
  GRect rect_temp = { { TEXT_TEMP_OFFSET_X+status_offset_x, TEXT_TEMP_OFFSET_Y +status_offset_y}, { RULER_XOFFSET , 150 } };
  GRect rect_tmin = { { TEXT_TMIN_OFFSET_X+status_offset_x, TEXT_TMIN_OFFSET_Y+status_offset_y }, { 100 , 150 } };
  GRect rect_tmax = { { TEXT_TMAX_OFFSET_X+status_offset_x, TEXT_TMAX_OFFSET_Y+status_offset_y }, { 40 , 150 } };
  GRect rect_icon = { { ICON_X, ICON_Y+9}, { 35, 35 } };
  GRect rect_icon6 = { { ICON6_X, ICON6_Y+9}, { 35, 35 } };
  GRect rect_text_hour = { { RULER_XOFFSET + XOFFSET+5+hour_offset_x, 0 }, { 100, 100 } };
  GRect rect_bt_disconect = { { ICON_BT_X+status_offset_x, ICON_BT_Y+status_offset_y }, {35 , 17 } };;


  int icon_id;
  int icon_id6;
  //  APP_LOG(APP_LOG_LEVEL_INFO, "2");
  rain_ico_val=rain1_val;
  icon_id = build_icon(icon);
  rain_ico_val=rain3_val;
  icon_id6 = build_icon(icon2);
  // icon_id = build_icon("01d");
  // icon_id6 = build_icon("01d");


  //  APP_LOG(APP_LOG_LEVEL_INFO, "icone %s", icon);  

  // Draw background
  graphics_context_set_fill_color(ctx, color_right);
  graphics_fill_rect(ctx, GRect(RULER_XOFFSET, 0, 160, 180), 0, GCornerNone);
  graphics_context_set_fill_color(ctx, color_left);
  graphics_fill_rect(ctx, GRect(0, 0, RULER_XOFFSET, 180), 0, GCornerNone);


  t = time(NULL);
  now = *(localtime(&t)); 

  snprintf(week_day, sizeof(week_day), "%s", weekdayLangEn[now.tm_wday]);
  if (strcmp(pebble_Lang, "fr_FR") == 0)
    snprintf(week_day, sizeof(week_day), "%s", weekdayLangFr[now.tm_wday]);

  if (strcmp(pebble_Lang, "de_DE") == 0)
    snprintf(week_day, sizeof(week_day), "%s", weekdayLangGe[now.tm_wday]);

  if (strcmp(pebble_Lang, "es_ES") == 0)
    snprintf(week_day, sizeof(week_day), "%s", weekdayLangSp[now.tm_wday]);


  snprintf(month, sizeof(month), "%s", MonthLangEn[now.tm_mon]);
  if (strcmp(pebble_Lang, "fr_FR") == 0)
    snprintf(month, sizeof(month), "%s", MonthLangFr[now.tm_mon]);

  if (strcmp(pebble_Lang, "de_DE") == 0)
    snprintf(month, sizeof(month), "%s", MonthLangGe[now.tm_mon]);

  if (strcmp(pebble_Lang, "es_ES") == 0)
    snprintf(month, sizeof(month), "%s", MonthLangSp[now.tm_mon]);


  snprintf(mday, sizeof(mday), "%i", now.tm_mday);
  // APP_LOG(APP_LOG_LEVEL_INFO, "3");
  graphics_context_set_text_color(ctx, color_temp);
  int bat_gradiant_offset=0;
  rect_text_dayw.origin.x+=2;
  rect_text_month.origin.x+=2;



  // Météo

  // APP_LOG(APP_LOG_LEVEL_INFO, "4");

  graphics_context_set_compositing_mode(ctx, GCompOpSet);
  int bat_offset=0;
  if(((mktime(&now)-last_refresh)<duration+600)) {
    s_icon=gbitmap_create_with_resource(icon_id);
    graphics_draw_bitmap_in_rect(ctx, s_icon, rect_icon); 
    gbitmap_destroy (s_icon);

    if(is_bw_icon){
      s_icon=gbitmap_create_with_resource(RESOURCE_ID_POURTOUR);
      graphics_draw_bitmap_in_rect(ctx, s_icon, rect_icon); 
      gbitmap_destroy (s_icon);
    }
    int met_unit;
    if(is_metric)
      met_unit=10;
    else
      met_unit=5;


    if (wind1_val>met_unit){
      s_icon=gbitmap_create_with_resource(RESOURCE_ID_POURTOURW1);
      graphics_draw_bitmap_in_rect(ctx, s_icon, rect_icon); 
      gbitmap_destroy (s_icon);
    }

    if (wind1_val>met_unit*2){
      s_icon=gbitmap_create_with_resource(RESOURCE_ID_POURTOURW2);
      graphics_draw_bitmap_in_rect(ctx, s_icon, rect_icon); 
      gbitmap_destroy (s_icon);
    }

    if (wind1_val>met_unit*3){
      s_icon=gbitmap_create_with_resource(RESOURCE_ID_POURTOURW3);
      graphics_draw_bitmap_in_rect(ctx, s_icon, rect_icon); 
      gbitmap_destroy (s_icon);
    }
    if (wind1_val>met_unit*4) {         
      s_icon=gbitmap_create_with_resource(RESOURCE_ID_POURTOURW4);
      graphics_draw_bitmap_in_rect(ctx, s_icon, rect_icon); 
      gbitmap_destroy (s_icon);
    }


    if(!IS_ROUND){
      s_icon=gbitmap_create_with_resource(icon_id6);
      graphics_draw_bitmap_in_rect(ctx, s_icon, rect_icon6); 
      gbitmap_destroy (s_icon);

      if(is_bw_icon){
        s_icon=gbitmap_create_with_resource(RESOURCE_ID_POURTOUR2);
        graphics_draw_bitmap_in_rect(ctx, s_icon, rect_icon6); 
        gbitmap_destroy (s_icon);  
      }

      if (wind2_val>met_unit){
        s_icon=gbitmap_create_with_resource(RESOURCE_ID_POURTOURW1);
        graphics_draw_bitmap_in_rect(ctx, s_icon, rect_icon6); 
        gbitmap_destroy (s_icon);
      }

      if (wind2_val>met_unit*2){
        s_icon=gbitmap_create_with_resource(RESOURCE_ID_POURTOURW2);
        graphics_draw_bitmap_in_rect(ctx, s_icon, rect_icon6); 
        gbitmap_destroy (s_icon);
      }

      if (wind2_val>met_unit*3){
        s_icon=gbitmap_create_with_resource(RESOURCE_ID_POURTOURW3);
        graphics_draw_bitmap_in_rect(ctx, s_icon, rect_icon6); 
        gbitmap_destroy (s_icon);
      }
      if (wind2_val>met_unit*4) {         
        s_icon=gbitmap_create_with_resource(RESOURCE_ID_POURTOURW4);
        graphics_draw_bitmap_in_rect(ctx, s_icon, rect_icon6); 
        gbitmap_destroy (s_icon);
      }


    }
  }     
  
  else{

    //rect_text_dayw.origin.y+=56;
   // rect_text_month.origin.y+=56;
   //rect_text_day.origin.y+=56;
    //rect_bt_disconect.origin.y+=50;
  //  bat_offset=105;      
  }
  
  if(!IS_ROUND){  
    snprintf(tmin, sizeof(tmin), "%i|%i", tmax_val,tmin_val);

    snprintf(weather_temp_char, sizeof(weather_temp_char), "%i°", weather_temp);
  }
  else{
    snprintf(tmin, sizeof(tmin), "%i", tmin_val);
    snprintf(tmax, sizeof(tmax), "%i", tmax_val);
    snprintf(weather_temp_char, sizeof(weather_temp_char), "%i", weather_temp);

  }

  // Batterie
  // APP_LOG(APP_LOG_LEVEL_INFO, "5");

  if(!IS_ROUND){   

    if(phone_bat==0)
      bat_offset+=2;

    // phone battery diplay
    int bat;
    int offset;
    graphics_context_set_fill_color(ctx, color_temp);
    if ((is_connected)||(IS_HOUR_FICTIVE)){ 
      if (IS_HOUR_FICTIVE){
        phone_bat=30;   
      }
      bat = (int)phone_bat*36/100; 
      offset=(int)((36-bat)/2); 

      graphics_fill_rect(ctx, GRect(BAT_PHONE_STATUS_OFFSET_X+offset, BAT_PHONE_STATUS_OFFSET_Y+bat_gradiant_offset+bat_offset, (18-offset)*2, 2), 0, GCornerNone);
      if (is_phone_charging){
        graphics_fill_rect(ctx, GRect(BAT_PHONE_STATUS_OFFSET_X+17,BAT_PHONE_STATUS_OFFSET_Y+2+bat_gradiant_offset+bat_offset, 2, 3), 0, GCornerNone);
      }  
    }

    // Batterie chargement
    if (is_charging){
      graphics_context_set_fill_color(ctx, color_temp);
      graphics_fill_rect(ctx, GRect(BAT_STATUS_OFFSET_X+17,BAT_STATUS_OFFSET_Y-3+bat_gradiant_offset+bat_offset, 2, 3), 0, GCornerNone);
    }

    bat = (int)battery_level*36/100;
    offset=(int)((36-bat)/2); 
    graphics_context_set_fill_color(ctx, color_temp);
    // APP_LOG(APP_LOG_LEVEL_INFO,"phone bat %d",phone_bat);

    if ((is_connected)||(IS_HOUR_FICTIVE))
      graphics_fill_rect(ctx, GRect(BAT_STATUS_OFFSET_X+offset, BAT_STATUS_OFFSET_Y+bat_gradiant_offset+bat_offset, (18-offset)*2, 2), 0, GCornerNone);


    if (is_connected){ 
      graphics_fill_rect(ctx, GRect(BAT_STATUS_OFFSET_X+9,BAT_STATUS_OFFSET_Y+2+bat_gradiant_offset+bat_offset, 2, 3), 0, GCornerNone);
      graphics_fill_rect(ctx, GRect(BAT_STATUS_OFFSET_X+17,BAT_STATUS_OFFSET_Y+2+bat_gradiant_offset+bat_offset, 2, 3), 0, GCornerNone);
      graphics_fill_rect(ctx, GRect(BAT_STATUS_OFFSET_X+25,BAT_STATUS_OFFSET_Y+2+bat_gradiant_offset+bat_offset, 2, 3), 0, GCornerNone);
    }

  }
  else{  
    int bat = (int)battery_level*2/10;
    int invbat = 20-bat;
    graphics_context_set_fill_color(ctx, color_temp);
    graphics_fill_rect(ctx, GRect(BAT_STATUS_OFFSET_X, BAT_STATUS_OFFSET_Y+bat_gradiant_offset, bat, 2), 0, GCornerNone);

    graphics_fill_rect(ctx, GRect(BAT_STATUS_OFFSET_X, BAT_STATUS_OFFSET_Y-3+bat_gradiant_offset, 1, 5), 0, GCornerNone);
    graphics_fill_rect(ctx, GRect(BAT_STATUS_OFFSET_X+10, BAT_STATUS_OFFSET_Y-3+bat_gradiant_offset, 1, 5), 0, GCornerNone);
    graphics_fill_rect(ctx, GRect(BAT_STATUS_OFFSET_X+20, BAT_STATUS_OFFSET_Y-3+bat_gradiant_offset, 1, 5), 0, GCornerNone);
    /*
      graphics_fill_rect(ctx, GRect(BAT_STATUS_OFFSET_X+2,BAT_STATUS_OFFSET_Y-1+bat_gradiant_offset, 1, 3), 0, GCornerNone);
      graphics_fill_rect(ctx, GRect(BAT_STATUS_OFFSET_X+4, BAT_STATUS_OFFSET_Y-1+bat_gradiant_offset, 1, 3), 0, GCornerNone);
      graphics_fill_rect(ctx, GRect(BAT_STATUS_OFFSET_X+6,BAT_STATUS_OFFSET_Y-1+bat_gradiant_offset, 1, 3), 0, GCornerNone);
      graphics_fill_rect(ctx, GRect(BAT_STATUS_OFFSET_X+8, BAT_STATUS_OFFSET_Y-1+bat_gradiant_offset, 1, 3), 0, GCornerNone);
      graphics_fill_rect(ctx, GRect(BAT_STATUS_OFFSET_X+12,BAT_STATUS_OFFSET_Y-1+bat_gradiant_offset, 1, 3), 0, GCornerNone);
      graphics_fill_rect(ctx, GRect(BAT_STATUS_OFFSET_X+14, BAT_STATUS_OFFSET_Y-1+bat_gradiant_offset, 1, 3), 0, GCornerNone);
      graphics_fill_rect(ctx, GRect(BAT_STATUS_OFFSET_X+16,BAT_STATUS_OFFSET_Y-1+bat_gradiant_offset, 1, 3), 0, GCornerNone);
      graphics_fill_rect(ctx, GRect(BAT_STATUS_OFFSET_X+18, BAT_STATUS_OFFSET_Y-1+bat_gradiant_offset, 1, 3), 0, GCornerNone);
*/
  }


  #if defined(PBL_ROUND)
  if((mktime(&now)-last_refresh)<duration+600){
    graphics_draw_text(ctx, weather_temp_char, fontmedium, rect_temp, GTextOverflowModeWordWrap,
                       GTextAlignmentCenter, NULL);
    graphics_draw_text(ctx, tmin, fontsmallbold, rect_tmin, GTextOverflowModeWordWrap,
                       GTextAlignmentRight, NULL);
    graphics_draw_text(ctx, tmax, fontsmallbold, rect_tmax, GTextOverflowModeWordWrap,
                       GTextAlignmentRight, NULL);

  }

  graphics_draw_text(ctx, week_day, fontsmallbold, rect_text_dayw, GTextOverflowModeWordWrap,
                     GTextAlignmentCenter, NULL);


  graphics_draw_text(ctx, mday, fontmedium, rect_text_day, GTextOverflowModeWordWrap,
                     GTextAlignmentCenter, NULL);

  #else
  if(!IS_ROUND){
    if(is_connected){
      if (!is_month){
        graphics_draw_text(ctx, week_day, fontsmall, rect_text_dayw, GTextOverflowModeWordWrap,
                           GTextAlignmentCenter, NULL);

        graphics_draw_text(ctx, month, fontsmall, rect_text_month, GTextOverflowModeWordWrap,
                           GTextAlignmentCenter, NULL);
      }
      else{
        graphics_draw_text(ctx, week_day, fontsmall, rect_text_month, GTextOverflowModeWordWrap,
                           GTextAlignmentCenter, NULL);
        graphics_draw_text(ctx, month, fontsmall, rect_text_dayw, GTextOverflowModeWordWrap,
                           GTextAlignmentCenter, NULL);
      }

    }
    else{
      graphics_draw_text(ctx, week_day, fontsmall, rect_text_dayw, GTextOverflowModeWordWrap,
                         GTextAlignmentCenter, NULL);

      s_icon = gbitmap_create_with_resource(RESOURCE_ID_BT_DISCONECT);
      graphics_draw_bitmap_in_rect(ctx, s_icon, rect_bt_disconect);   
      gbitmap_destroy(s_icon);
    }
  }


  graphics_draw_text(ctx, mday, fontmedium, rect_text_day, GTextOverflowModeWordWrap,
                     GTextAlignmentCenter, NULL);

  // APP_LOG(APP_LOG_LEVEL_INFO, "7");
  if((mktime(&now)-last_refresh)<duration+600){
    graphics_draw_text(ctx, weather_temp_char, fontsmallbold, rect_temp, GTextOverflowModeWordWrap,
                       GTextAlignmentCenter, NULL);
    graphics_draw_text(ctx, tmin, fontsmallbold, rect_tmin, GTextOverflowModeWordWrap,
                       GTextAlignmentCenter, NULL);
    graphics_draw_text(ctx, tmax, fontsmallbold, rect_tmax, GTextOverflowModeWordWrap,
                       GTextAlignmentRight, NULL);

  }   
  #endif

  // APP_LOG(APP_LOG_LEVEL_INFO, "8");

  // Draw Health
  #if defined(PBL_HEALTH)
  if(select_goal!=0){
    HealthMetric metric = HealthMetricStepCount;
    time_t start = time_start_of_today();
    time_t end = time(NULL);

    // Check the metric has data available for today
    HealthServiceAccessibilityMask mask = health_service_metric_accessible(metric, start, end);

    if(mask & HealthServiceAccessibilityMaskAvailable) {
      // Data is available!
      int steps= (int)health_service_sum_today(metric);


      graphics_context_set_stroke_width(ctx, 10);
      graphics_context_set_stroke_color(ctx, color_ruler);  
      graphics_context_set_fill_color(ctx, color_ruler);

      steps=steps%select_goal;
      int y_health=(int)(HEIGHT-HEIGHT*steps/select_goal);
      graphics_draw_line(ctx, GPoint(RULER_XOFFSET+1,y_health), GPoint(RULER_XOFFSET+4,y_health));


    } else {
      // No data recorded yet today
      //     APP_LOG(APP_LOG_LEVEL_ERROR, "Data unavailable!");
    }
  }

  #endif

  //
  // Ruler format :
  // 
  //    <------------------HOURS---------------->
  //    |  |  |  |  |  |  |  |  |  |  |  |  |  |  
  //    22 0  2  4  6  8  10 12 14 16 18 20 22 0  
  //
  // hour_size is 60 pixels (if line interval is not changed)
  // Hours part is (hour_size * 26) pixels
  // 
  // In "normal" hour mode, position is depending only on the number of minutes since midnight
  // 



  // DRAW RULER

  unsigned int i, j;
  int hour_offset, y;

  // Pixel offset of the middle of the screen
  // Offset for hour mode, starting at 22
  t = time(NULL);
  now = *(localtime(&t)); 
  hour_offset = ((now.tm_hour+2) * hour_size) + (now.tm_min * hour_size / 60); 
  //  APP_LOG(APP_LOG_LEVEL_DEBUG, "hour_offset %d", hour_offset);

  // APP_LOG(APP_LOG_LEVEL_INFO, "9");

  if (IS_HOUR_FICTIVE){
    int hour = FICTIVE_HOUR;
    int minute = FICTIVE_MINUTE;
    hour_offset = ((hour+2) * hour_size) + (minute * hour_size / 60); 
  }
  // APP_LOG(APP_LOG_LEVEL_INFO, "10");

  y = hour_line_ypos - hour_offset;
  // APP_LOG(APP_LOG_LEVEL_INFO, "20");
  graphics_context_set_stroke_color(ctx, color_ruler);   
  // APP_LOG(APP_LOG_LEVEL_INFO, "21");
  graphics_context_set_fill_color(ctx, color_ruler);
  // APP_LOG(APP_LOG_LEVEL_INFO, "22");
  //Hours
  graphics_context_set_text_color(ctx, color_hours);

  rect_text_hour.origin.x = TEXT_HOUR_OFFSET+hour_offset_x+5;  
  // APP_LOG(APP_LOG_LEVEL_INFO, "23");
  for (i=0; i<28; i++) {
    for (j=0; j<12; j++) {
      if ((y >= -30)&&(y<=HEIGHT+30)) {
        if (j == 0){
          snprintf(hour_text, sizeof(hour_text), "%d", labels[i]);        
          int y_offset;
          if (is_centered){
            if(is_ruler_large)
              y_offset = -8;
            else
              y_offset = -15; 
          }
          else
          {
            if(is_ruler_large)
              y_offset = -38;
            else
              y_offset = -38;
          } 

          rect_text_hour.origin.y = y + y_offset+hour_offset_y;  
          if (is_inv){
            int inv_offset=0;
            if(select_fonts==0)
              inv_offset=8;
            if(select_fonts==1)
              inv_offset=32;
            if(select_fonts==2)
              inv_offset=30; 


            rect_text_hour.origin.y= (int)(HEIGHT/2 + inv_offset - rect_text_hour.origin.y);

          }
          graphics_draw_text(ctx, hour_text, fontbig, rect_text_hour, GTextOverflowModeWordWrap,
                             GTextAlignmentCenter, NULL);               
        }
      }      

      y += line_interval;
    }
  }

  // APP_LOG(APP_LOG_LEVEL_INFO, "11");

  // Central line  
  graphics_context_set_fill_color(ctx, color_line);
  graphics_fill_rect(ctx, GRect(RULER_XOFFSET, HEIGHT/2-1, 180, segment_thickness), 0, GCornerNone);

  y = hour_line_ypos - hour_offset;
  graphics_context_set_stroke_color(ctx, color_ruler);   
  graphics_context_set_fill_color(ctx, color_ruler);
  //   APP_LOG(APP_LOG_LEVEL_INFO, "12");
  for (i=0; i<28; i++) {
    for (j=0; j<12; j++) {
      if ((y >= -20)&&(y<=HEIGHT+20)) {

        if ((y >= 0) && (y < HEIGHT)) {    
          if (!is_inv)
            graphics_fill_rect(ctx, GRect(RULER_XOFFSET, y-1, markWidth[j]+RULER_SIZE, segment_thickness), 3, GCornerNone);                
          else
            graphics_fill_rect(ctx, GRect(RULER_XOFFSET, HEIGHT - y-1, markWidth[j]+RULER_SIZE, segment_thickness), 3, GCornerNone);                

        } 
      }      
      y += line_interval;
    }
  }

}


static void handle_tick(struct tm *cur, TimeUnits units_changed) {
  // APP_LOG(APP_LOG_LEVEL_INFO, "tick start");
  // APP_LOG(APP_LOG_LEVEL_INFO, "t1");
  t = time(NULL);
  now = *(localtime(&t)); 
  // APP_LOG(APP_LOG_LEVEL_INFO, "t2");
  if (is_vibration){
    if (now.tm_min == 0 && now.tm_hour >= QUIET_TIME_END && now.tm_hour <= QUIET_TIME_START) {
      vibes_double_pulse();
    }
  }


  // Get weather update every 30 minutes
  if(is_connected) {
    if((select_provider!=0)&&(((is_30mn)&&(now.tm_min % 30 == 0))||(now.tm_min % 60 == 0)||((mktime(&now)-last_refresh)>duration))){
      //     APP_LOG(APP_LOG_LEVEL_INFO, "appel météo");
      // Begin dictionary
      DictionaryIterator *iter;
      app_message_outbox_begin(&iter);
      // Add a key-value pair
      dict_write_uint8(iter, 0, 0);
      // Send the message!
      app_message_outbox_send();
      //     APP_LOG(APP_LOG_LEVEL_INFO, "t4");

    }   
  }

  // APP_LOG(APP_LOG_LEVEL_DEBUG, "Time now: %d", (int)mktime(&now));
  // APP_LOG(APP_LOG_LEVEL_DEBUG, "Last refresh: %d", (int)last_refresh);


  // APP_LOG(APP_LOG_LEVEL_DEBUG,"dirty tick");

  if(((now.tm_min%5)==0)||((now.tm_min%5)==3)) 
    layer_mark_dirty(layer);
  // APP_LOG(APP_LOG_LEVEL_INFO, "tick end");
}

static void handle_battery(BatteryChargeState charge) {
  battery_level = charge.charge_percent;
  // APP_LOG(APP_LOG_LEVEL_DEBUG, "handle_battery -> %d", (int)battery_level);
  bool save_state = is_charging;
  is_charging=charge.is_charging;
  /*
    if (is_charging){
      if ((battery_level)<40)
      battery_level;
      if(battery_level>100)
        battery_level=100; 
    }*/

  if(is_charging!=save_state){
    layer_mark_dirty(layer);
    //   APP_LOG(APP_LOG_LEVEL_DEBUG,"dirty handle battery");
  }
}



static void setHourLinePoints() {

  line1_p1.y = line1_p2.y = hour_line_ypos;
  line2_p1 = line1_p1;
  line2_p2 = line1_p2;
  line2_p1.y++;
  line2_p2.y++;
}


void bt_handler(bool connected) {
  if(connected){
    is_connected=true;
  }
  else
  {
    is_connected=false;
  }
  // APP_LOG(APP_LOG_LEVEL_DEBUG,"dirty handler bt");
  if (is_bt){
    vibes_double_pulse();
  }
  layer_mark_dirty(layer);
}


static void initBatteryLevel() {
  BatteryChargeState battery_state = battery_state_service_peek();
  battery_level = battery_state.charge_percent;
}


static void assign_fonts(){
  if(!IS_ROUND){
    if (select_fonts==0){
      fontsmall = fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD);
      fontsmallbold = fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD);
      fontmedium = fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD);
      fontbig = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_SQUARE_50));
      hour_offset_x=5;
      hour_offset_y=0;
      status_offset_x=1;
      status_offset_y=0;


    }
    else if (select_fonts==1){

      fontsmall = fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD);
      fontsmallbold = fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD);
      fontmedium = fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD);
      fontbig = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_CLEARVIEW_45)); 
      hour_offset_x=1;
      hour_offset_y=9;
      status_offset_x=1;
      status_offset_y=0;   
    }
    else if (select_fonts==2){
      fontsmall = fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD);
      fontsmallbold = fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD);
      fontmedium = fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD);
      fontbig =fonts_get_system_font(FONT_KEY_LECO_42_NUMBERS);
      hour_offset_x=1;
      hour_offset_y=11;
      status_offset_x=1;
      status_offset_y=0;
    }

  }
  else{

    fontsmall = fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD);
    fontsmallbold = fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD);
    fontmedium = fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD);


    status_offset_x=0;
    status_offset_y=0;

    if (select_fonts==0){
      fontbig = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_SQUARE_50));
      hour_offset_x=-6;
      hour_offset_y=0;
    }
    else if (select_fonts==1){
      fontbig = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_CLEARVIEW_45)); 
      hour_offset_x=-7;
      hour_offset_y=10;
    }
    else if (select_fonts==2){
      fontbig =fonts_get_system_font(FONT_KEY_LECO_42_NUMBERS);
      hour_offset_x=-8;
      hour_offset_y=11;
    }

  }
}


static void inbox_received_callback(DictionaryIterator *iterator, void *context) {

  // Read tuples for data
  Tuple *phone_bat_tuple = dict_find(iterator, KEY_PHONE_BAT);
  Tuple *phone_bat_charge_tuple = dict_find(iterator, KEY_PHONE_CHARGE);

  Tuple *tg_tuple = dict_find(iterator, KEY_TOGGLE_TG);
  Tuple *pc_tuple = dict_find(iterator, KEY_TOGGLE_PC);
  Tuple *temp_tuple = dict_find(iterator, KEY_TEMPERATURE);
  Tuple *wind_speed_tuple = dict_find(iterator, KEY_WIND_SPEED);
  Tuple *tmin_tuple = dict_find(iterator, KEY_TMIN);
  Tuple *tmax_tuple = dict_find(iterator, KEY_TMAX); 
  Tuple *icon_tuple = dict_find(iterator, KEY_ICON);

  Tuple *h1_tuple = dict_find(iterator, KEY_FORECAST_H1);
  Tuple *h2_tuple = dict_find(iterator, KEY_FORECAST_H2);
  Tuple *h3_tuple = dict_find(iterator, KEY_FORECAST_H3);
  Tuple *wind1_tuple = dict_find(iterator, KEY_FORECAST_WIND1);
  Tuple *wind2_tuple = dict_find(iterator, KEY_FORECAST_WIND2);
  Tuple *wind3_tuple = dict_find(iterator, KEY_FORECAST_WIND3);
  Tuple *temp1_tuple = dict_find(iterator, KEY_FORECAST_TEMP1);
  Tuple *temp2_tuple = dict_find(iterator, KEY_FORECAST_TEMP2);
  Tuple *temp3_tuple = dict_find(iterator, KEY_FORECAST_TEMP3);
  Tuple *temp4_tuple = dict_find(iterator, KEY_FORECAST_TEMP4);
  Tuple *temp5_tuple = dict_find(iterator, KEY_FORECAST_TEMP5);
  Tuple *icon1_tuple = dict_find(iterator, KEY_FORECAST_ICON1);
  Tuple *icon2_tuple = dict_find(iterator, KEY_FORECAST_ICON2);
  Tuple *icon3_tuple = dict_find(iterator, KEY_FORECAST_ICON3);
  Tuple *rain1_tuple = dict_find(iterator, KEY_FORECAST_RAIN1);
  Tuple *rain2_tuple = dict_find(iterator, KEY_FORECAST_RAIN2);
  Tuple *rain3_tuple = dict_find(iterator, KEY_FORECAST_RAIN3);
  Tuple *rain4_tuple = dict_find(iterator, KEY_FORECAST_RAIN4);

  Tuple *gps_tuple = dict_find(iterator, KEY_GPS);
  Tuple *centered_tuple = dict_find(iterator, KEY_TOGGLE_CENTERED);
  Tuple *month_tuple = dict_find(iterator, KEY_TOGGLE_MONTH);
  Tuple *city_tuple = dict_find(iterator, KEY_INPUT_CITY);
  Tuple *utc_tuple = dict_find(iterator, KEY_SELECT_UTC);
  Tuple *screen_tuple = dict_find(iterator, KEY_SELECT_SCREEN);

  Tuple *radio_tuple = dict_find(iterator, KEY_RADIO_UNITS);
  Tuple *refresh_tuple = dict_find(iterator, KEY_RADIO_REFRESH);
  Tuple *vibration_tuple = dict_find(iterator, KEY_TOGGLE_VIBRATION);
  Tuple *bw_icon_tuple = dict_find(iterator, KEY_TOGGLE_BW_ICONS);
  Tuple *gradiant_tuple = dict_find(iterator, KEY_TOGGLE_GRADIANT);
  Tuple *gradiant_ruler_large_tuple = dict_find(iterator, KEY_TOGGLE_RULER_LARGE);


  Tuple *goal_tuple = dict_find(iterator, KEY_SELECT_GOAL);
  Tuple *fonts_tuple = dict_find(iterator, KEY_SELECT_FONTS);
  Tuple *provider_tuple = dict_find(iterator, KEY_SELECT_PROVIDER);

  Tuple *bt_tuple = dict_find(iterator, KEY_TOGGLE_BT);
  Tuple *inv_tuple = dict_find(iterator, KEY_TOGGLE_INV);
  Tuple *phone_100_tuple = dict_find(iterator, KEY_TOGGLE_100);
  Tuple *phone_80_tuple = dict_find(iterator, KEY_TOGGLE_80);

  Tuple *color_right_r_tuple = dict_find(iterator, KEY_COLOR_RIGHT_R);
  Tuple *color_right_g_tuple = dict_find(iterator, KEY_COLOR_RIGHT_G);
  Tuple *color_right_b_tuple = dict_find(iterator, KEY_COLOR_RIGHT_B);

  Tuple *color_left_r_tuple = dict_find(iterator, KEY_COLOR_LEFT_R);
  Tuple *color_left_g_tuple = dict_find(iterator, KEY_COLOR_LEFT_G);
  Tuple *color_left_b_tuple = dict_find(iterator, KEY_COLOR_LEFT_B); 

  Tuple *color_hours_r_tuple = dict_find(iterator, KEY_COLOR_HOURS_R);
  Tuple *color_hours_g_tuple = dict_find(iterator, KEY_COLOR_HOURS_G);
  Tuple *color_hours_b_tuple = dict_find(iterator, KEY_COLOR_HOURS_B);

  Tuple *color_ruler_r_tuple = dict_find(iterator, KEY_COLOR_RULER_R);
  Tuple *color_ruler_g_tuple = dict_find(iterator, KEY_COLOR_RULER_G);
  Tuple *color_ruler_b_tuple = dict_find(iterator, KEY_COLOR_RULER_B);

  Tuple *color_temp_r_tuple = dict_find(iterator, KEY_COLOR_TEMPERATURES_R);
  Tuple *color_temp_g_tuple = dict_find(iterator, KEY_COLOR_TEMPERATURES_G);
  Tuple *color_temp_b_tuple = dict_find(iterator, KEY_COLOR_TEMPERATURES_B);

  Tuple *color_line_r_tuple = dict_find(iterator, KEY_COLOR_LINE_R);
  Tuple *color_line_g_tuple = dict_find(iterator, KEY_COLOR_LINE_G);
  Tuple *color_line_b_tuple = dict_find(iterator, KEY_COLOR_LINE_B); 

  Tuple *color_2nd_back_r_tuple = dict_find(iterator, KEY_COLOR_2ND_BACK_R);
  Tuple *color_2nd_back_g_tuple = dict_find(iterator, KEY_COLOR_2ND_BACK_G);
  Tuple *color_2nd_back_b_tuple = dict_find(iterator, KEY_COLOR_2ND_BACK_B); 

  Tuple *color_2nd_temp_r_tuple = dict_find(iterator, KEY_COLOR_2ND_TEMP_R);
  Tuple *color_2nd_temp_g_tuple = dict_find(iterator, KEY_COLOR_2ND_TEMP_G);
  Tuple *color_2nd_temp_b_tuple = dict_find(iterator, KEY_COLOR_2ND_TEMP_B); 

  int red;  
  int green;
  int blue;


  // If all data is available, use it
  if(temp_tuple && wind_speed_tuple && icon_tuple && wind_speed_tuple && tmin_tuple &&tmax_tuple
     &&h1_tuple&&h2_tuple&&h3_tuple
     &&wind1_tuple&&wind2_tuple&&wind3_tuple

     &&temp1_tuple&&temp1_tuple&&temp2_tuple&&temp3_tuple&&temp4_tuple&&temp5_tuple
     &&icon1_tuple&&icon2_tuple&&icon3_tuple
     &&rain1_tuple&&rain2_tuple&&rain3_tuple&&rain4_tuple) {

    //vibes_double_pulse(); 



    snprintf(h1, sizeof(h1), "%s", h1_tuple->value->cstring);
    snprintf(h2, sizeof(h2), "%s", h2_tuple->value->cstring);
    snprintf(h3, sizeof(h3), "%s", h3_tuple->value->cstring);
    snprintf(icon, sizeof(icon), "%s", icon_tuple->value->cstring);
    snprintf(icon1, sizeof(icon1), "%s", icon1_tuple->value->cstring);
    snprintf(icon2, sizeof(icon2), "%s", icon2_tuple->value->cstring);
    snprintf(icon3, sizeof(icon3), "%s", icon3_tuple->value->cstring);
    weather_temp=(int)temp_tuple->value->int32;
    rain1_val=(int)rain1_tuple->value->int32;
    rain2_val=(int)rain2_tuple->value->int32;
    rain3_val=(int)rain3_tuple->value->int32;
    rain4_val=(int)rain4_tuple->value->int32;
    tmin_val=(int)tmin_tuple->value->int32;
    tmax_val=(int)tmax_tuple->value->int32;
    wind1_val=(int)wind1_tuple->value->int32;
    wind2_val=(int)wind2_tuple->value->int32;
    wind3_val=(int)wind3_tuple->value->int32;
    temp1_val=(int)temp1_tuple->value->int32;
    temp2_val=(int)temp2_tuple->value->int32;
    temp3_val=(int)temp3_tuple->value->int32;
    temp4_val=(int)temp4_tuple->value->int32;
    temp5_val=(int)temp5_tuple->value->int32;
    wind_speed_val=(int)wind_speed_tuple->value->int32;

    last_refresh = mktime(&now);


    persist_write_string(KEY_FORECAST_H1, h1);
    persist_write_string(KEY_FORECAST_H2, h2);
    persist_write_string(KEY_FORECAST_H3, h3);
    persist_write_string(KEY_ICON, icon);
    persist_write_string(KEY_LOCATION, location);

    persist_write_string(KEY_FORECAST_ICON1, icon1);
    persist_write_string(KEY_FORECAST_ICON2, icon2);
    persist_write_string(KEY_FORECAST_ICON3, icon3);

    persist_write_int(KEY_LAST_REFRESH, last_refresh);
    persist_write_int(KEY_TEMPERATURE, weather_temp);
    persist_write_int(KEY_WIND_SPEED, wind_speed_val);
    persist_write_int(KEY_TMIN, tmin_val);
    persist_write_int(KEY_TMAX, tmax_val);

    persist_write_int(KEY_FORECAST_WIND1, wind1_val);
    persist_write_int(KEY_FORECAST_WIND2, wind2_val);
    persist_write_int(KEY_FORECAST_WIND3, wind3_val);

    persist_write_int(KEY_FORECAST_TEMP1, temp1_val);
    persist_write_int(KEY_FORECAST_TEMP2, temp2_val);
    persist_write_int(KEY_FORECAST_TEMP3, temp3_val);
    persist_write_int(KEY_FORECAST_TEMP4, temp4_val);
    persist_write_int(KEY_FORECAST_TEMP5, temp5_val);

    persist_write_int(KEY_FORECAST_RAIN1, rain1_val);
    persist_write_int(KEY_FORECAST_RAIN2, rain2_val);
    persist_write_int(KEY_FORECAST_RAIN3, rain3_val);
    persist_write_int(KEY_FORECAST_RAIN4, rain4_val);

    //   APP_LOG(APP_LOG_LEVEL_DEBUG,"dirty inbox_received_callback + weather");
    layer_mark_dirty(layer);  

  }


  if((phone_bat_tuple)&&(phone_bat_charge_tuple)){  

    // 80 20
    if(is_phone_charging&&(phone_bat<=80)&&((int)phone_bat_tuple->value->int32>=80)&&is_phone_80)
      vibes_double_pulse();  
    if(!is_phone_charging&&(phone_bat>=20)&&((int)phone_bat_tuple->value->int32<=20)&&is_phone_80)
      vibes_double_pulse();  
    // 100
    if(is_phone_charging&&((int)phone_bat_tuple->value->int32==100)&&is_phone_100)
      vibes_double_pulse();  

    if(!is_phone_charging&&phone_bat_charge_tuple->value->int32&&is_pc)
      vibes_double_pulse();  

    phone_bat=(int)phone_bat_tuple->value->int32;
    is_phone_charging=phone_bat_charge_tuple->value->int32;


    // APP_LOG(APP_LOG_LEVEL_DEBUG, "phone bat %d", phone_bat);
    persist_write_int(KEY_PHONE_BAT, phone_bat);

    layer_mark_dirty(layer);  

  }


  if(gps_tuple&&city_tuple&&utc_tuple&&radio_tuple&&vibration_tuple&&bw_icon_tuple&&color_right_r_tuple&&color_right_g_tuple
     &&color_right_b_tuple&&color_left_r_tuple&&color_left_g_tuple&&color_left_b_tuple&&color_hours_r_tuple
     &&color_hours_g_tuple&&color_hours_b_tuple&&color_ruler_r_tuple&&color_ruler_g_tuple&&color_ruler_b_tuple
     &&color_temp_r_tuple&&color_temp_g_tuple&&color_temp_b_tuple&&refresh_tuple&&color_line_r_tuple&&
     color_line_g_tuple&&color_line_b_tuple&&gradiant_tuple&&screen_tuple&&color_2nd_back_r_tuple
     &&color_2nd_back_g_tuple&&color_2nd_back_b_tuple&&color_2nd_temp_r_tuple&&color_2nd_temp_g_tuple
     &&color_2nd_temp_b_tuple&&gradiant_ruler_large_tuple&&centered_tuple&&month_tuple&&goal_tuple&&fonts_tuple
     &&provider_tuple&&bt_tuple&&inv_tuple&&phone_100_tuple&&phone_80_tuple&&tg_tuple&&pc_tuple){

    is_gps=gps_tuple->value->int32;
    is_centered=centered_tuple->value->int32;
    is_month=month_tuple->value->int32;

    is_tg=tg_tuple->value->int32;
    is_pc=pc_tuple->value->int32;
    snprintf(city, sizeof(city), "%s", city_tuple->value->cstring);  

    char utc_char[10];
    char screen_mode_char[10];
    snprintf(utc_char, sizeof(utc_char), "%s", utc_tuple->value->cstring);  
    snprintf(screen_mode_char, sizeof(screen_mode_char), "%s", screen_tuple->value->cstring);  
    utc=atoi(utc_char);
    select_screen=atoi(screen_mode_char);

    char goal_char[10];
    char fonts_char[10];
    char provider_char[10];

    snprintf(goal_char, sizeof(goal_char), "%s", goal_tuple->value->cstring);  
    snprintf(fonts_char, sizeof(fonts_char), "%s", fonts_tuple->value->cstring);  
    snprintf(provider_char, sizeof(provider_char), "%s", provider_tuple->value->cstring);  


    select_goal=atoi(goal_char);
    select_fonts=atoi(fonts_char);
    select_provider=atoi(provider_char);

    assign_fonts();
    is_bt=bt_tuple->value->int32;
    is_inv=inv_tuple->value->int32;
    is_phone_100 = phone_100_tuple->value->int32;
    is_phone_80 = phone_80_tuple->value->int32; 

    is_metric=!(radio_tuple->value->int32);
    is_30mn=refresh_tuple->value->int32;

    is_vibration=vibration_tuple->value->int32;
    is_bw_icon=bw_icon_tuple->value->int32;
    if(!IS_COLOR)
      is_bw_icon=true;

    is_ruler_large=gradiant_ruler_large_tuple->value->int32;
    is_gradiant=gradiant_tuple->value->int32;

    red = color_right_r_tuple->value->int32;
    green = color_right_g_tuple->value->int32;
    blue = color_right_b_tuple->value->int32;
    // Persist values
    persist_write_int(KEY_COLOR_RIGHT_R, red);
    persist_write_int(KEY_COLOR_RIGHT_G, green);
    persist_write_int(KEY_COLOR_RIGHT_B, blue);
    color_right = GColorFromRGB(red, green, blue);

    red = color_left_r_tuple->value->int32;
    green = color_left_g_tuple->value->int32;
    blue = color_left_b_tuple->value->int32;
    // Persist values
    persist_write_int(KEY_COLOR_LEFT_R, red);
    persist_write_int(KEY_COLOR_LEFT_G, green);
    persist_write_int(KEY_COLOR_LEFT_B, blue);
    color_left = GColorFromRGB(red, green, blue);

    red = color_line_r_tuple->value->int32;
    green = color_line_g_tuple->value->int32;
    blue = color_line_b_tuple->value->int32;
    // Persist values
    persist_write_int(KEY_COLOR_LINE_R, red);
    persist_write_int(KEY_COLOR_LINE_G, green);
    persist_write_int(KEY_COLOR_LINE_B, blue);
    color_line = GColorFromRGB(red, green, blue); 

    red = color_2nd_back_r_tuple->value->int32;
    green = color_2nd_back_g_tuple->value->int32;
    blue = color_2nd_back_b_tuple->value->int32;
    // Persist values
    persist_write_int(KEY_COLOR_2ND_BACK_R, red);
    persist_write_int(KEY_COLOR_2ND_BACK_G, green);
    persist_write_int(KEY_COLOR_2ND_BACK_B, blue);
    color_2nd_back = GColorFromRGB(red, green, blue);  

    red = color_2nd_temp_r_tuple->value->int32;
    green = color_2nd_temp_g_tuple->value->int32;
    blue = color_2nd_temp_b_tuple->value->int32;
    // Persist values
    persist_write_int(KEY_COLOR_2ND_TEMP_R, red);
    persist_write_int(KEY_COLOR_2ND_TEMP_G, green);
    persist_write_int(KEY_COLOR_2ND_TEMP_B, blue);
    color_2nd_temp = GColorFromRGB(red, green, blue); 


    red = color_hours_r_tuple->value->int32;
    green = color_hours_g_tuple->value->int32;
    blue = color_hours_b_tuple->value->int32;
    //   APP_LOG(APP_LOG_LEVEL_DEBUG, "RGB color temp %i %i %i", red, green, blue);
    // Persist values
    persist_write_int(KEY_COLOR_HOURS_R, red);
    persist_write_int(KEY_COLOR_HOURS_G, green);
    persist_write_int(KEY_COLOR_HOURS_B, blue);
    color_hours=GColorFromRGB(red, green, blue);

    red = color_ruler_r_tuple->value->int32;
    green = color_ruler_g_tuple->value->int32;
    blue = color_ruler_b_tuple->value->int32;
    // Persist values
    persist_write_int(KEY_COLOR_RULER_R, red);
    persist_write_int(KEY_COLOR_RULER_G, green);
    persist_write_int(KEY_COLOR_RULER_B, blue);
    color_ruler=GColorFromRGB(red, green, blue);

    red = color_temp_r_tuple->value->int32;
    green = color_temp_g_tuple->value->int32;
    blue = color_temp_b_tuple->value->int32;
    color_temp=GColorFromRGB(red, green, blue);  

    // Colors for OG pebbles
    if(!IS_COLOR){
      color_temp=GColorWhite;
      color_ruler=GColorWhite;
      color_hours=GColorWhite;
      color_left=GColorBlack;
      color_line=GColorWhite;
      color_right=GColorBlack;
      color_2nd_back=GColorBlack;
      color_2nd_temp=GColorWhite;
    }


    // Persist values
    persist_write_int(KEY_COLOR_TEMPERATURES_R, red);
    persist_write_int(KEY_COLOR_TEMPERATURES_G, green);
    persist_write_int(KEY_COLOR_TEMPERATURES_B, blue);


    persist_write_bool(KEY_GPS, is_gps);
    persist_write_bool(KEY_TOGGLE_CENTERED, is_centered);
    persist_write_bool(KEY_TOGGLE_MONTH, is_month);
    persist_write_bool(KEY_TOGGLE_RULER_LARGE, is_ruler_large);
    persist_write_string(KEY_INPUT_CITY, city);
    persist_write_int(KEY_SELECT_UTC, utc);
    persist_write_int(KEY_SELECT_SCREEN, select_screen);
    persist_write_int(KEY_SELECT_GOAL, select_goal);
    persist_write_int(KEY_SELECT_FONTS, select_fonts);
    persist_write_int(KEY_SELECT_PROVIDER, select_provider);
    persist_write_bool( KEY_RADIO_UNITS, is_metric);
    persist_write_bool( KEY_RADIO_REFRESH, is_30mn);
    persist_write_bool( KEY_TOGGLE_BT, is_bt);
    persist_write_bool( KEY_TOGGLE_TG, is_tg);
    persist_write_bool( KEY_TOGGLE_PC, is_pc);
    persist_write_bool( KEY_TOGGLE_INV, is_inv);
    persist_write_bool( KEY_TOGGLE_100, is_phone_100);
    persist_write_bool( KEY_TOGGLE_80, is_phone_80);

    persist_write_bool( KEY_TOGGLE_VIBRATION, is_vibration);
    persist_write_bool( KEY_TOGGLE_BW_ICONS, is_bw_icon);
    persist_write_bool( KEY_TOGGLE_GRADIANT, is_gradiant);
    //   APP_LOG(APP_LOG_LEVEL_DEBUG,"dirty inbox_received_callback+ settings");
    // Begin dictionary
    vibes_double_pulse();
    if(select_provider!=0){
      DictionaryIterator *iter;
      app_message_outbox_begin(&iter);
      // Add a key-value pair
      dict_write_uint8(iter, 0, 0);
      // Send the message!
      app_message_outbox_send();
    }
  }




}

static void outbox_failed_callback(DictionaryIterator *iterator, AppMessageResult reason, void *context) {
  // APP_LOG(APP_LOG_LEVEL_ERROR, "Outbox send failed!");
}

static void outbox_sent_callback(DictionaryIterator *iterator, void *context) {
  // APP_LOG(APP_LOG_LEVEL_INFO, "Outbox send success!");
}

static void init_var(){
  int i;

  t = time(NULL);
  now = *(localtime(&t)); 


  fontsmall = fonts_get_system_font(FONT_KEY_GOTHIC_14);
  fontsmallbold = fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD);
  fontmedium = fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD);
  fontbig = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_CLEARVIEW_45)); 

  if(persist_exists(KEY_GPS)){
    phone_bat=persist_read_int(KEY_PHONE_BAT);
  }
  else {
    phone_bat=0;

  }

  if(persist_exists(KEY_GPS)&&persist_exists(KEY_SELECT_UTC)&&persist_exists(KEY_RADIO_UNITS)
     &&persist_exists(KEY_RADIO_REFRESH)&&persist_exists(KEY_TOGGLE_VIBRATION)
     &&persist_exists(KEY_TOGGLE_BW_ICONS)&&persist_exists(KEY_TOGGLE_GRADIANT)&&persist_exists(KEY_SELECT_SCREEN)
     &&persist_exists(KEY_SELECT_FONTS)&&persist_exists(KEY_SELECT_PROVIDER)&&persist_exists(KEY_SELECT_GOAL)&&persist_exists(KEY_TOGGLE_RULER_LARGE)
     &&persist_exists(KEY_TOGGLE_CENTERED)&&persist_exists(KEY_TOGGLE_MONTH)&&persist_exists(KEY_TOGGLE_BT)
     &&persist_exists(KEY_TOGGLE_TG)){

    is_gps=persist_read_bool(KEY_GPS); 
    is_centered=persist_read_bool(KEY_TOGGLE_CENTERED);
    is_month=persist_read_bool(KEY_TOGGLE_MONTH);
    is_ruler_large=persist_read_bool(KEY_TOGGLE_RULER_LARGE); 
    utc=persist_read_int(KEY_SELECT_UTC);
    select_screen=persist_read_int(KEY_SELECT_SCREEN);
    select_fonts=persist_read_int(KEY_SELECT_FONTS);
    select_provider=persist_read_int(KEY_SELECT_PROVIDER);
    select_goal=persist_read_int(KEY_SELECT_GOAL);

    is_metric=persist_read_bool(KEY_RADIO_UNITS);
    is_30mn=persist_read_bool(KEY_RADIO_REFRESH);
    is_bt=persist_read_bool(KEY_TOGGLE_BT);
    is_tg=persist_read_bool(KEY_TOGGLE_TG);
    is_pc=persist_read_bool(KEY_TOGGLE_PC);
    is_inv=persist_read_bool(KEY_TOGGLE_INV);
    is_phone_100=persist_read_bool(KEY_TOGGLE_100);
    is_phone_80=persist_read_bool(KEY_TOGGLE_80);

    is_vibration=persist_read_bool(KEY_TOGGLE_VIBRATION);
    is_bw_icon=persist_read_bool(KEY_TOGGLE_BW_ICONS);
    if(!IS_COLOR)
      is_bw_icon=true;
    is_gradiant=persist_read_bool(KEY_TOGGLE_GRADIANT);
    int red;
    int green;
    int blue;
    red = persist_read_int(KEY_COLOR_RIGHT_R);
    green = persist_read_int(KEY_COLOR_RIGHT_G);
    blue = persist_read_int(KEY_COLOR_RIGHT_B);
    color_right=GColorFromRGB(red, green, blue);

    red = persist_read_int(KEY_COLOR_LEFT_R);
    green = persist_read_int(KEY_COLOR_LEFT_G);
    blue = persist_read_int(KEY_COLOR_LEFT_B);
    color_left=GColorFromRGB(red, green, blue);

    red = persist_read_int(KEY_COLOR_LINE_R);
    green = persist_read_int(KEY_COLOR_LINE_G);
    blue = persist_read_int(KEY_COLOR_LINE_B);
    color_line=GColorFromRGB(red, green, blue);

    red = persist_read_int(KEY_COLOR_2ND_BACK_R);
    green = persist_read_int(KEY_COLOR_2ND_BACK_G);
    blue = persist_read_int(KEY_COLOR_2ND_BACK_B);
    color_2nd_back=GColorFromRGB(red, green, blue);

    red = persist_read_int(KEY_COLOR_2ND_TEMP_R);
    green = persist_read_int(KEY_COLOR_2ND_TEMP_G);
    blue = persist_read_int(KEY_COLOR_2ND_TEMP_B);
    color_2nd_temp=GColorFromRGB(red, green, blue);

    red = persist_read_int(KEY_COLOR_HOURS_R);
    green = persist_read_int(KEY_COLOR_HOURS_G);
    blue = persist_read_int(KEY_COLOR_HOURS_B);
    color_hours=GColorFromRGB(red, green, blue);

    red = persist_read_int(KEY_COLOR_RULER_R);
    green = persist_read_int(KEY_COLOR_RULER_G);
    blue = persist_read_int(KEY_COLOR_RULER_B);
    color_ruler=GColorFromRGB(red, green, blue);

    red = persist_read_int(KEY_COLOR_TEMPERATURES_R);
    green = persist_read_int(KEY_COLOR_TEMPERATURES_G);
    blue = persist_read_int(KEY_COLOR_TEMPERATURES_B);
    color_temp=GColorFromRGB(red, green, blue);

  }
  else{
    is_gps=true; 
    is_centered=false;
    is_month=false;
    utc=0;
    select_screen=2;
    select_fonts=0;
    select_provider=2;
    is_ruler_large=true;

    is_metric=true;
    is_vibration=false;
    is_bw_icon=false; 
    if(!IS_COLOR)
      is_bw_icon=true;
    is_gradiant=false; 
    color_right=GColorBlack;
    color_left=GColorWhite;
    color_line=GColorWhite;
    color_hours=GColorWhite;
    color_ruler=GColorWhite;
    color_2nd_back=GColorBlack;
    color_2nd_temp=GColorWhite;
    color_temp=GColorBlack;
  }
  if(persist_exists(KEY_LAST_REFRESH)&&persist_exists(KEY_WIND_SPEED)&&persist_exists(KEY_TMIN)
     &&persist_exists(KEY_TMAX)&&persist_exists(KEY_FORECAST_WIND1)&&persist_exists(KEY_FORECAST_WIND2)
     &&persist_exists(KEY_FORECAST_WIND3)&&persist_exists(KEY_FORECAST_TEMP1)&&persist_exists(KEY_FORECAST_TEMP2)
     &&persist_exists(KEY_FORECAST_TEMP3)&&persist_exists(KEY_FORECAST_TEMP4)&&persist_exists(KEY_FORECAST_TEMP5)
     &&persist_exists(KEY_FORECAST_RAIN1)&&persist_exists(KEY_FORECAST_RAIN2)&&persist_exists(KEY_FORECAST_RAIN3)
     &&persist_exists(KEY_FORECAST_RAIN4)&&persist_exists(KEY_TEMPERATURE)
     &&persist_exists(KEY_FORECAST_H1)&&persist_exists(KEY_FORECAST_H2)&&persist_exists(KEY_FORECAST_H3)
     &&persist_exists(KEY_ICON)&&persist_exists(KEY_LOCATION)&&persist_exists(KEY_FORECAST_ICON1)
     &&persist_exists(KEY_FORECAST_ICON2)&&persist_exists(KEY_FORECAST_ICON3)){

    last_refresh = persist_read_int(KEY_LAST_REFRESH);
    wind_speed_val = persist_read_int(KEY_WIND_SPEED);
    tmin_val = persist_read_int(KEY_TMIN);
    tmax_val = persist_read_int(KEY_TMAX);
    wind1_val = persist_read_int(KEY_FORECAST_WIND1);
    wind2_val = persist_read_int(KEY_FORECAST_WIND2);
    wind3_val = persist_read_int(KEY_FORECAST_WIND3);
    temp1_val = persist_read_int(KEY_FORECAST_TEMP1);
    temp2_val = persist_read_int(KEY_FORECAST_TEMP2);
    temp3_val = persist_read_int(KEY_FORECAST_TEMP3);
    temp4_val = persist_read_int(KEY_FORECAST_TEMP4);
    temp5_val = persist_read_int(KEY_FORECAST_TEMP5);
    rain1_val = persist_read_int(KEY_FORECAST_RAIN1);
    rain2_val = persist_read_int(KEY_FORECAST_RAIN2);
    rain3_val = persist_read_int(KEY_FORECAST_RAIN3);
    rain4_val = persist_read_int(KEY_FORECAST_RAIN4);
    weather_temp = persist_read_int(KEY_TEMPERATURE);




    persist_read_string(KEY_FORECAST_H1, h1, sizeof(h1));
    persist_read_string(KEY_FORECAST_H2, h2, sizeof(h2));
    persist_read_string(KEY_FORECAST_H3, h3, sizeof(h3));
    persist_read_string(KEY_ICON, icon, sizeof(icon));
    persist_read_string(KEY_LOCATION, location, sizeof(location));
    persist_read_string(KEY_FORECAST_ICON1, icon1, sizeof(icon1));
    persist_read_string(KEY_FORECAST_ICON2, icon2, sizeof(icon2));
    persist_read_string(KEY_FORECAST_ICON3, icon3, sizeof(icon3));
  }
  else{
    last_refresh = 0;
    wind_speed_val = 0;
    tmin_val = 0;
    tmax_val = 0;
    wind1_val = 0;
    wind2_val = 0;
    wind3_val = 0;
    temp1_val = 0;
    temp2_val = 0;
    temp3_val = 0;
    temp4_val = 0;
    temp5_val = 0;
    rain1_val = 0;
    rain2_val = 0;
    rain3_val = 0;
    rain4_val = 0;
    weather_temp = 0;  



    snprintf(h1, sizeof(h1), " ");
    snprintf(h2, sizeof(h2), " ");
    snprintf(h3, sizeof(h3), " ");
    snprintf(icon, sizeof(icon), " ");
    snprintf(icon1, sizeof(icon1), " ");
    snprintf(icon2, sizeof(icon2), " ");
    snprintf(icon3, sizeof(icon3), " ");
    snprintf(location, sizeof(location), " ");
  }


  if(!IS_COLOR){
    color_temp=GColorWhite;
    color_ruler=GColorWhite;
    color_hours=GColorWhite;
    color_left=GColorBlack;
    color_line=GColorWhite;
    color_right=GColorBlack;
    color_2nd_temp=GColorWhite;
    color_2nd_back=GColorBlack;
  }
  // APP_LOG(APP_LOG_LEVEL_DEBUG, "select_fonts %d", select_fonts);

  assign_fonts();

  //APP_LOG(APP_LOG_LEVEL_DEBUG, "\n\nselect screen %d\nis_30mn %d \n is_gps %d\n utc %d\nis_metric %d\nis_vibration %d\nis_bw_icon %d\n", select_screen, is_30mn, is_gps, utc, is_metric, is_vibration, is_bw_icon);

  snprintf(pebble_Lang, sizeof(pebble_Lang), "%s", i18n_get_system_locale());

  BatteryChargeState charge_state = battery_state_service_peek();
  is_charging = charge_state.is_charging;
  is_connected = connection_service_peek_pebble_app_connection();

  if(is_ruler_large){
    line_interval = 5;
    segment_thickness = 2 ;  
  }
  else
  { 
    line_interval = 4;
    segment_thickness = 2 ;
  }

  if (!clock_is_24h_style()) {
    for (i=0; i<28; i++) {
      labels[i] = labels_12h[i];
    }
  }
  setHourLinePoints();
  initBatteryLevel();

  int hour_size = 12 * line_interval; // 12 marks, one every 5 minutes
  hour_part_size = 26 * hour_size;

  if(is_30mn)
    duration=1800;
  else
    duration=3600;


}


static void init() {

  init_var();

  s_main_window = window_create();
  window_stack_push(s_main_window, true);

  s_canvas_layer = window_get_root_layer(s_main_window);
  layer = layer_create(layer_get_bounds(s_canvas_layer));
  layer_set_update_proc(layer, update_proc);
  layer_add_child(s_canvas_layer, layer);


  tick_timer_service_subscribe(MINUTE_UNIT, handle_tick);
  battery_state_service_subscribe(handle_battery);
  bluetooth_connection_service_subscribe(bt_handler); 

  //JS Messages

  app_message_register_inbox_received(inbox_received_callback);
  app_message_register_outbox_failed(outbox_failed_callback);
  app_message_register_outbox_sent(outbox_sent_callback);

  // Open AppMessage

  app_message_open(650, 50);
  app_focus_service_subscribe_handlers((AppFocusHandlers){
    .did_focus = app_focus_changed,
    .will_focus = app_focus_changing
  });

  // Begin dictionary
  DictionaryIterator *iter;
  app_message_outbox_begin(&iter);

}


static void deinit() {

  tick_timer_service_unsubscribe();
  battery_state_service_unsubscribe();
  bluetooth_connection_service_unsubscribe();  
  app_message_deregister_callbacks();

  layer_destroy(layer);
  window_destroy(s_main_window);

}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
