#include <globals.h>
#include <tskLadder.h>
#include <ladder.h>

#include "FS.h"
#include "SPIFFS.h"

//--------------------------------------------------------------------------------
// Ladder logic execution Task 
// Running on Core 1 
//--------------------------------------------------------------------------------

void TaskLadder(void *pvParameters)
{
  (void) pvParameters;

  //----------------------------------------------------
  // Task lock / unlock
  //----------------------------------------------------

  ladderWaitSettings();
  
  //----------------------------------------------------
  // Ladder Logic initializations
  //----------------------------------------------------

  Network Networks[TOTAL_NETWORKS];

  configureLocal_IO();
  


  // clearMemory();   // lucas delete
  // clearProgram(Networks);  //lucas delete
  // loadDemoUserPogram(Networks); // lucas delete
  


  
  //--------------------------------------------------
  // Task Main Loop
  //--------------------------------------------------

  while(1){
    
    //----------------------------------------------------------------
    // Load saved program indicated in settings.ladder.UserProgram
    //    If file doesnt exist creates the empty file
    //    If User Proggram number is 0, load Demo to this slot
    //    this assumes that is the first boot
    //----------------------------------------------------------------
    
    if(loadSelectedProgram){

      PLCstate = STOPPED;
      //String programFileName = FILENAME_PROGRAMS + String(settings.ladder.UserProgram) + FILENAME_PLSI; // "/programX.plsi"
      SPIFFS.begin();

      if (SPIFFS.exists(FILENAME_USER_PROGRAMS[settings.ladder.UserProgram])){
        Serial.print("TaskLadder - File ");
        Serial.print(FILENAME_USER_PROGRAMS[settings.ladder.UserProgram]);
        Serial.println(" exists. Will be loaded to RAM");

        File userProgramFile = SPIFFS.open(FILENAME_USER_PROGRAMS[settings.ladder.UserProgram],"r");
        userProgramFile.read((uint8_t *)&Networks, sizeof(Networks));
        userProgramFile.close();
      }
      else{
        Serial.print("TaskLadder - File ");
        Serial.print(FILENAME_USER_PROGRAMS[settings.ladder.UserProgram]);
        Serial.println(" does not exists. Program file is going to be created");

        clearProgram(Networks);      
        if(settings.ladder.UserProgram == DEMO_PROGRAM_SLOT){
          loadDemoUserPogram(Networks);
        }
        File userProgramFile = SPIFFS.open(FILENAME_USER_PROGRAMS[settings.ladder.UserProgram],"w");
        userProgramFile.write((uint8_t *)&Networks, sizeof(Networks));
        userProgramFile.close();
      }
   
      SPIFFS.end();
      clearMemory();
      PLCstate = RUNNING;
      loadSelectedProgram = 0;
    }


















    //----------------------------------------------------------------
    // Load saved program indicated in settings.ladder.UserProgram
    //    If file doesnt exist creates the empty file
    //    If User Proggram number is 0, load Demo to this slot
    //    this assumes that is the first boot
    //----------------------------------------------------------------
    
    if(loadSelectedProgram && 0){

      PLCstate = STOPPED;
      String programFileName = FILENAME_PROGRAMS + String(settings.ladder.UserProgram) + FILENAME_PLSI; // "/programX.plsi"
      
      if (SPIFFS.exists(programFileName)){
        Serial.print("TaskLadder - File ");
        Serial.print(programFileName);
        Serial.println(" exists. Will be loaded to RAM");

        File userProgramFile = SPIFFS.open(programFileName,"r");
        userProgramFile.read((uint8_t *)&Networks, sizeof(Networks));
        userProgramFile.close();
      }
      else{
        Serial.print("TaskLadder - File ");
        Serial.print(programFileName);
        Serial.println(" does not exists. Program file is going to be created");

        clearProgram(Networks);      
        if(settings.ladder.UserProgram == DEMO_PROGRAM_SLOT){
          loadDemoUserPogram(Networks);
        }
        File userProgramFile = SPIFFS.open(programFileName,"w");
        userProgramFile.write((uint8_t *)&Networks, sizeof(Networks));
        userProgramFile.close();
      }
   
      clearMemory();
      PLCstate = RUNNING;
      loadSelectedProgram = 0;
    }





















    //------------------------------------------------------
    // PLC ladder Program SCAN
    //     Read Inputs
    //     Evaluate Logic
    //     Write Outputs
    //------------------------------------------------------

    scanTime();
    
    readInputsLocal();
    readInputsRemote();

    execScanPLC(Networks); 
    savePreviousValues();

    writeOutputsLocal();
    writeOutputsRemote();
  }
}
