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

  if (settings.io.localInputs[6] == IO_TYPE_DIGITAL){
    I[6] = !digitalRead(INPUT_06); 
  }
  else{
    IW[6]= analogRead(AN_INPUT_00);


    // if (analogRead(AN_INPUT_00) > IW[6]){
    //   IW[6]= uint16_t(IW[6] + double(analogRead(AN_INPUT_00) - IW[6]) * 0.1);
    // }
    // else{
    //   IW[6]= uint16_t(IW[6] - double(IW[6] - analogRead(AN_INPUT_00)) * 0.1);
    // }


    // IW_p[6]= uint16_t(double(analogRead(AN_INPUT_00)));
    // IW[6]= IW_p[6];
  }
  if (settings.io.localInputs[7] == IO_TYPE_DIGITAL){
    I[7] = !digitalRead(INPUT_07); 
  }
  else{
    IW[7]= analogRead(AN_INPUT_01);
  }
}

//--------------------------------------------------------------------------------
// Local Outputs
//--------------------------------------------------------------------------------

void writeOutputsLocal(void){
  digitalWrite(OUTPUT_00, Q[0]);
  digitalWrite(OUTPUT_01, Q[1]);
  digitalWrite(OUTPUT_02, Q[2]);
  digitalWrite(OUTPUT_03, Q[3]);
  
  if (settings.io.localOutputs[4] == IO_TYPE_DIGITAL){
    digitalWrite(OUTPUT_04, Q[4]);
  }
  else{
    dacWrite(AN_OUTPUT_00, QW[4]/4); // ESP32 dac resolution is 0-255 PLsi standard analog I/O resolution is 0-4095
  }

  if (settings.io.localOutputs[5] == IO_TYPE_DIGITAL){
    digitalWrite(OUTPUT_05, Q[5]);
  }
  else{
    dacWrite(AN_OUTPUT_01, QW[5]/4); // ESP32 dac resolution is 0-255 PLsi standard analog I/O resolution is 0-4095
  }
}

//--------------------------------------------------------------------------------
// IO physical assignment 
//--------------------------------------------------------------------------------

void configureLocal_IO(void){
  analogSetAttenuation(ADC_6db);
  analogSetWidth(10);
  analogSetClockDiv(1);

  pinMode(INPUT_00, INPUT);
  pinMode(INPUT_01, INPUT);
  pinMode(INPUT_02, INPUT);
  pinMode(INPUT_03, INPUT);
  pinMode(INPUT_04, INPUT);
  pinMode(INPUT_05, INPUT);
  pinMode(INPUT_06, INPUT);
  pinMode(INPUT_07, INPUT);
  
  pinMode(OUTPUT_00, OUTPUT);
  pinMode(OUTPUT_01, OUTPUT);
  pinMode(OUTPUT_02, OUTPUT);
  pinMode(OUTPUT_03, OUTPUT);
  
  if (settings.io.localOutputs[4] == IO_TYPE_DIGITAL){
    pinMode(OUTPUT_04, OUTPUT);
  }
  else{
    pinMode(AN_OUTPUT_00, ANALOG);
  }

  if (settings.io.localOutputs[5] == IO_TYPE_DIGITAL){
    pinMode(OUTPUT_05, OUTPUT);
  }
  else{
    pinMode(AN_OUTPUT_01, ANALOG);
  }
}
