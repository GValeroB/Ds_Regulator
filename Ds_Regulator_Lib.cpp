/*
  Ds_Regulator_Lib.h - Library for "DangerSolutions Ds_Regulator Shield" .
  Created by Germán Valero. 14, November 2017.
  ---------------------------------------------------------------------
*/

#include "Arduino.h"
#include "Ds_Regulator_Lib.h"
Regulator::Regulator(int Out0, int Out1, int Out2, int Out3)  /*  *** Outputs are defined *** */
{
  pinMode(Out0, OUTPUT);
  _bit0 = Out0;
  pinMode(Out1, OUTPUT);
  _bit1 = Out1;
  pinMode(Out2, OUTPUT);
  _bit2 = Out2;
  pinMode(Out3, OUTPUT);
  _bit3 = Out3;
}
void Regulator::Setpoint(int ValueChangued) /*  *** Changue the Setpoint  *** */
{
  Value = ValueChangued;
  if (Value > 15) {
    Value = 15;
  }
  if (Value < 0) {
    Value = 0;
  }
  if (SetOn == true) {
    On();
  }
}
void Regulator::On()  /*  *** Set On Regulation *** */
{
  SetOn = true;
  Activacion();
}
void Regulator::Off()  /*  *** Set Off Regulation *** */
{
  SetOn = false;
  digitalWrite (_bit0, 1);
  digitalWrite (_bit1, 1);
  digitalWrite (_bit2, 1);
  digitalWrite (_bit3, 1);
}
void Regulator::Activacion()  /*  *** Set Om/Off the Outputs  *** */
{
  byte ValorModEnBits;
  bool Bit0 = false; // 0= Resistencia puenteada, 1= Valor resistencia x.
  bool Bit1 = false;
  bool Bit2 = false;
  bool Bit3 = false;
  ValorModEnBits = byte(Value);
  /*  *** BCD Conversion  *** */
  if ((ValorModEnBits & 0b00000001) == 1) {
    Bit0 = true;
  }
  if ((ValorModEnBits & 0b00000010) == 2) {
    Bit1 = true;
  }
  if ((ValorModEnBits & 0b00000100) == 4)  {
    Bit2 = true;
  }
  if ((ValorModEnBits & 0b00001000) == 8)  {
    Bit3 = true;
  }
  /*  *** Activation of Phototriacs  ***  */
  digitalWrite (_bit0, Bit0);
  digitalWrite (_bit1, Bit1);
  digitalWrite (_bit2, Bit2);
  digitalWrite (_bit3, Bit3);
}
void Regulator::Up()  /*  *** Setpoint +1 *** */
{
  Value++;
  if (Value > 15) {
    Value = 15;
  }
  if (SetOn == true)
  {
    Activacion();
  }
}
void Regulator::Down()  /*  *** Setpoint -1 *** */
{
  Value--;
  if (Value < 0) {
    Value = 0;
  }
  if (SetOn == true)
  {
    Activacion();
  }
}


