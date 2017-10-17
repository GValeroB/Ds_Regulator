/*
  Ds_Regulator_Lib.h - Library for "DangerSolutions Ds_Regulator Shield" .
  Created by Germán Valero. 17 de November del 2017.
  Dangersolutions@gmail.com - http://www.dangersolutions.es/
*/

#ifndef Ds_Regulator_Lib_h
#define Ds_Regulator_Lib_h
#include "Arduino.h"

class Regulator
{
  public:
    Regulator(int Out0, int Out1, int Out2, int Out3);
    void Up();
    void Down();
    void On();
    void Off();
    void Activacion();
    void Setpoint(int ValueChangued);
    int Value;
    bool SetOn = true;
  private:
    int _bit0;
    int _bit1;
    int _bit2;
    int _bit3;
};

#endif

