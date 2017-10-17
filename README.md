 # Ds_Regulator_Lib.h - Library for "DangerSolutions Ds_Regulator Shield" .
  
  Created by Germán Valero. 17 de November del 2017.
  Dangersolutions@gmail.com - http://www.dangersolutions.es/

  - This example shows how to control the Ds_Regulator shield of DangerSolutions
   
#  Set up Outputs:
Set te Arduino Outputs to connect Ds_Regulator
- Regulator Regulator(8, 9, 10, 11);

     * Conect Pin 8 Arduino to Pin 1 Ds_Regulator Shield.
     * Conect Pin 9 Arduino to Pin 2 Ds_Regulator Shield.
     * Conect Pin 10 Arduino to Pin 3 Ds_Regulator Shield.
     * Conect Pin 11 Arduino to Pin 4 Ds_Regulator Shield.
# Functions:
- Regulator.Up();
     * Up one point the regulation 
- Regulator.Down();
     * own one point the regulation
 - Regulator.On();
     * Set the regulation On.
  - Regulator.Off();
     * Set the regulation Off.
 - Regulator.SetPoint(NewValue);
     * Changue the value of Setpoint.
 Variables:
  int ReadValue=Regulator.Value;
*/
