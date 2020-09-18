#include <globals.h>
#include <TFT_eSPI.h>
#include <hmi.h>

//--------------------------------------------------------------------------------
// Main Menu Page
//--------------------------------------------------------------------------------

void pageMainMenu (uint16_t firstLoad, uint16_t touchType, uint16_t ts_x, uint16_t ts_y){
  //-------------------------------
  // draw full Page on first load
  //-------------------------------
    
    if(firstLoad){
      drawMainMenu ();
    }

  //-------------------------------
  // update required fields
  //-------------------------------

  if(PLCstateChanged() || ScanTimeChanged() || userProgramChanged()) {
    printPLCstate();
  }

  //-------------------------------
  // Parse touch screen
  //-------------------------------

  if (touchType){
    touchMainMenu(ts_x, ts_y); 
  } 
}

//--------------------------------------------------------------------------------
// Main Menu Page full draw 
//--------------------------------------------------------------------------------

void drawMainMenu (void){
  tft.fillScreen(BLACK);
   
  tft.fillRect     (  0,   0, 320, 34,    DARKGREY); // Header
  tft.fillRoundRect( 20,  48, 280, 55, 6, WHITE);    // Button 1
  tft.fillRoundRect( 20, 111, 280, 55, 6, CYAN);     // Button 2
  tft.fillRoundRect( 20, 174, 280, 55, 6, AQUA);     // Button 3

  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  // tft.setCursor(10, 10);
  // tft.print("PLsi v" + String(FIRMWARE));
  tft.setCursor(5, 10);

  String str = FILENAME_USER_PROGRAMS[settings.ladder.UserProgram];
  str = str.substring(1, str.length());
  tft.print(str);

  printPLCstate();

  tft.setTextColor(BLACK);
  tft.setTextSize(4);
  tft.setCursor(90, 61);
  tft.print("LADDER");
  
  tft.setCursor(130, 124);
  tft.print("HMI");

  tft.setTextSize(3);
  tft.setCursor(43, 191);
  tft.print("CONFIGURATION");
}

//--------------------------------------------------------------------------------
// Update Values on top bar while in Main Menu  
//--------------------------------------------------------------------------------

void printPLCstate(void){
  tft.fillRect     (  0,   0, 320, 34,    DARKGREY); 

  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.setCursor(5, 10);

  String str = FILENAME_USER_PROGRAMS[settings.ladder.UserProgram];
  str = str.substring(1, str.length());
  tft.print(str);

  if (PLCstate == RUNNING){
    tft.setTextColor(GREEN);
    String auxString = "RUN " + String(float(actualScanTime)/1000.0, 1) + " ms";
    tft.setCursor(315 - auxString.length() * 12, 10);
    tft.print(auxString);
  }
  else if (PLCstate == STOPPED){
    tft.setCursor(240, 10);
    tft.setTextColor(YELLOW);
    tft.print("STOP");
  }
  else if (PLCstate >= PLCERROR){
    tft.setCursor(240, 10);
    tft.setTextColor(RED);
    tft.print("ERROR");
  }
}

//--------------------------------------------------------------------------------
// Return True if the PLC Staus has changed
//--------------------------------------------------------------------------------

uint16_t PLCstateChanged(void) {
  if (PLCstateOld != PLCstate){
    PLCstateOld = PLCstate;
    return 1;
  }
  else {return 0;}
}

//--------------------------------------------------------------------------------
// Return True if the User Program Slot has changed
//--------------------------------------------------------------------------------

uint16_t userProgramChanged(void) {
  if (userProgramOld != settings.ladder.UserProgram){
    userProgramOld = settings.ladder.UserProgram;
    return 1;
  }
  else {return 0;}
}

//--------------------------------------------------------------------------------
// Return True if the PLC Scan Time has changed
//--------------------------------------------------------------------------------

uint16_t ScanTimeChanged(void) {
  unsigned int auxScanTime = actualScanTime/100;
  if (auxOldScanTime != auxScanTime){
    auxOldScanTime = auxScanTime;
    return 1;
  }
  else {return 0;}
}

//--------------------------------------------------------------------------------
// Main Menu Page
// Touch Screen parsing
//--------------------------------------------------------------------------------

void touchMainMenu(uint16_t X, uint16_t Y){
  if      (Y <= 40 && X > 200) {changePLCstate();}
  else if (Y >  40 && Y < 111) {HMI_Page = PAGE_MainLadder;}
  else if (Y > 111 && Y < 174) {HMI_Page = PAGE_MainHMI   ;}  
  else if (Y > 174           ) {HMI_Page = PAGE_MainConfig;}
}

//--------------------------------------------------------------------------------
// Change PLC State 
// Ask for user decision usong a Dialog OK / CANCEL screen
//--------------------------------------------------------------------------------

void changePLCstate(void){  
  if (PLCstate >= PLCERROR) {
    PLCstate = STOPPED;
  }
  else if (PLCstate == RUNNING){
    HMI_PageMemory = HMI_Page;
    dialogCode = DIALOG_RUN_STOP;
    HMI_Page = PAGE_DialogOkCancel;
  }
  else if (PLCstate == STOPPED){
    HMI_PageMemory = HMI_Page;
    dialogCode = DIALOG_STOP_RUN;
    HMI_Page = PAGE_DialogOkCancel;
  }
}



