#include <globals.h>
#include <ladder.h>

//--------------------------------------------------------------------------------
// Local Inputs
//--------------------------------------------------------------------------------

void readInputsLocal(void){
  I[0] = !digitalRead(INPUT_00); 
  I[1] = !digitalRead(INPUT_01); 
  I[2] = !digitalRead(INPUT_02); 
  I[3] = !digitalRead(INPUT_03); 
  I[4] = !digitalRead(INPUT_04); 
  I[5] = !digitalRead(INPUT_05); 
  I[6] = !digitalRead(INPUT_06); 
  I[7] = !digitalRead(INPUT_07); 
//  IW[0]= analogRead(AN_INPUT_00);
//  IW[AN_INPUT_BAT]= uint16_t(float(analogRead(AN_INPUT_BAT_PIN))*330.0/4095.0*2.29); //2.25 because R divisor in circuit / 330 is 3.3V *100 (nominal max voltage of the ADC) / 4095 max of 12bits ADC
//  IW[AN_INPUT_BAT-1]= uint16_t(analogRead(AN_INPUT_BAT_PIN));
}

//--------------------------------------------------------------------------------
// Local Outputs
//--------------------------------------------------------------------------------

void writeOutputsLocal(void){
  digitalWrite(OUTPUT_00, Q[0]);
  digitalWrite(OUTPUT_01, Q[1]);
  digitalWrite(OUTPUT_02, Q[2]);
  digitalWrite(OUTPUT_03, Q[3]);
  digitalWrite(OUTPUT_04, Q[4]);
  digitalWrite(OUTPUT_05, Q[5]);
  //dacWrite(AN_OUTPUT_01, QW[0]);
}

//--------------------------------------------------------------------------------
// IO physical assignment 
//--------------------------------------------------------------------------------

void configureLocal_IO(void){
  pinMode( INPUT_00,  INPUT);
  pinMode( INPUT_01,  INPUT);
  pinMode( INPUT_02,  INPUT);
  pinMode( INPUT_03,  INPUT);
  pinMode( INPUT_04,  INPUT);
  pinMode( INPUT_05,  INPUT);
  pinMode( INPUT_06,  INPUT);
  pinMode( INPUT_07,  INPUT);
  
  pinMode(OUTPUT_00, OUTPUT);
  pinMode(OUTPUT_01, OUTPUT);
  pinMode(OUTPUT_02, OUTPUT);
  pinMode(OUTPUT_03, OUTPUT);
  pinMode(OUTPUT_04, OUTPUT);
  pinMode(OUTPUT_05, OUTPUT);
}