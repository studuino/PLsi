#include <globals.h>
#include <TFT_eSPI.h>
#include <hmi.h>

//--------------------------------------------------------------------------------
// PLC Configuration Page
//--------------------------------------------------------------------------------

void pageConfigPLC (uint16_t firstLoad, uint16_t touchType, uint16_t ts_x, uint16_t ts_y){
  //-------------------------------
  // draw full Page on first load
  //-------------------------------
    
    if(firstLoad){
      drawConfigPLC();
    }
    
  //-------------------------------
  // update required fields
  //-------------------------------

    //Nothing to update

  //-------------------------------
  // Parse touch screen
  //-------------------------------

  if (touchType){
    touchConfigPLC(ts_x, ts_y); 
  } 
}

//--------------------------------------------------------------------------------
// PLC Configuration draw 
//--------------------------------------------------------------------------------

void drawConfigPLC (void){
  tft.fillScreen(MAGENTA);
  tft.setTextColor(WHITE);
  tft.setCursor(10, 10);
  tft.setTextSize(2);
  tft.print("PLC !");
}

//--------------------------------------------------------------------------------
// PLC configuration page
// Touch Screen parsing
//--------------------------------------------------------------------------------

void touchConfigPLC(uint16_t ts_x, uint16_t ts_y){
  HMI_Page = PAGE_MainConfig;
}
