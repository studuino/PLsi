#include <globals.h>
#include <TFT_eSPI.h>
#include <hmi.h>

//--------------------------------------------------------------------------------
// Wait for tskDisk to load the User Settings  
//--------------------------------------------------------------------------------

void hmiWaitSettings (void){
  Serial.println("TaskHMI - Waiting for Unlock");
  while (bootSequence != BOOT_TASK_UNLOCKED){
    delay(10); // forces to update bootSequence global variable
  }
  Serial.println("TaskHMI - Task Unlocked");
}

//--------------------------------------------------------------------------------
// Draw CANCEL BACK ACCEPT Buttons in the bottom of the page
// Used in edition of memory areas of Ladder Instructions Editor
//--------------------------------------------------------------------------------

void drawLadderEditorInstructionsNavigation(){
  #define BORDER10        2
  #define SPACING10       2
  #define BUTTON_H10     45
  #define BUTTON_W10    104
  #define BUTTON_Y10    TFT_PIXELS_Y - SPACING10 - BUTTON_H10 // Y where the button starts

  tft.fillRoundRect(BORDER10, BUTTON_Y10, BUTTON_W10, BUTTON_H10, 8, COLOR_BUTTON_BORDER_INSTRUC_EDITOR);
  tft.fillRoundRect(BORDER10+1, BUTTON_Y10+1, BUTTON_W10-2, BUTTON_H10-2, 7, COLOR_BUTTON_CANCEL_INSTRUC_EDITOR);

  tft.fillRoundRect(BORDER10+BUTTON_W10+SPACING10, BUTTON_Y10, BUTTON_W10, BUTTON_H10, 8, COLOR_BUTTON_BORDER_INSTRUC_EDITOR);
  tft.fillRoundRect(BORDER10+BUTTON_W10+SPACING10+1, BUTTON_Y10+1, BUTTON_W10-2, BUTTON_H10-2, 7, COLOR_BUTTON_BACK_INSTRUC_EDITOR);

  tft.fillRoundRect(BORDER10+BUTTON_W10*2+SPACING10*2, BUTTON_Y10, BUTTON_W10, BUTTON_H10, 8, COLOR_BUTTON_BORDER_LADDER_EDITOR);
  tft.fillRoundRect(BORDER10+BUTTON_W10*2+SPACING10*2+1, BUTTON_Y10+1, BUTTON_W10-2, BUTTON_H10-2, 8, COLOR_BUTTON_ACCEPT_INSTRUC_EDITOR);

  tft.setTextSize(2);
  tft.setTextColor(COLOR_BUTTON_FONT_INSTRUC_EDITOR);
  tft.setCursor(20, BUTTON_Y10 + 16);
  tft.print("CANCEL");
  tft.setCursor(140, BUTTON_Y10 + 16);
  tft.print("BACK");
  tft.setCursor(232, BUTTON_Y10 + 16);
  tft.print("ACCEPT");
}

//--------------------------------------------------------------------------------
// Parse 3 navigation buttons for Instructions Memory edition pages
//--------------------------------------------------------------------------------

void touchEditLadderInstructionsNavigation(uint16_t ts_x, uint16_t ts_y){
  if (ts_y > TFT_PIXELS_Y - BUTTON_H10 - SPACING10){
    if (ts_x < BUTTON_W10 - SPACING10){                    // CANCEL
      editingNetwork = onlineNetwork;
      HMI_Page = PAGE_MainLadder;
      Serial.println("InstructionEditor - CANCEL"); //lucas
    }
    else if (ts_x < BUTTON_W10*2 - SPACING10*2){            // BACK
      HMI_Page = PAGE_LadderEditor;
      Serial.println("InstructionEditor - BACK"); //lucas
    }
    else {                                                  // ACCEPT
      onlineNetwork = editingNetwork;
      HMI_Page = PAGE_MainLadder;
      Serial.println("InstructionEditor - ACCEPT"); //lucas
    }
  }
}

//--------------------------------------------------------------------------------
// Return the max Memory valid index for the given Type of Memory area
//--------------------------------------------------------------------------------

uint16_t getMaxMemoryAddress(uint16_t type){
  if(type == TypeM)  {return QTY_M - 1;}
  if(type == TypeQ)  {return QTY_Q - 1;}
  if(type == TypeI)  {return QTY_I - 1;}
  if(type == TypeCd) {return QTY_C - 1;}
  if(type == TypeCr) {return QTY_C - 1;}
  if(type == TypeTd) {return QTY_T - 1;}
  if(type == TypeTr) {return QTY_T - 1;}
  if(type == TypeIW) {return QTY_IW - 1;}
  if(type == TypeQW) {return QTY_QW - 1;}
  if(type == TypeC)  {return QTY_C - 1;}
  if(type == TypeT)  {return QTY_T - 1;}
  if(type == TypeD)  {return QTY_D - 1;}
  if(type == TypeR)  {return 65535;}
  return 0;
}
