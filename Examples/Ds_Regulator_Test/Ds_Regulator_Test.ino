/*
  Ds_Regulator_Lib.h - Library for "DangerSolutions Ds_Regulator Shield" .
  Created by Germán Valero. 17 de November del 2017.
  Dangersolutions@gmail.com - http://www.dangersolutions.es/
*/
/*
   This example shows how to control the Ds_Regulator shield of DangerSolutions
    Set up Outputs:
      Regulator Regulator(8, 9, 10, 11);
 *    * Conect Pin 8 Arduino to Pin 1 Ds_Regulator Shield.
 *    * Conect Pin 9 Arduino to Pin 2 Ds_Regulator Shield.
 *    * Conect Pin 10 Arduino to Pin 3 Ds_Regulator Shield.
 *    * Conect Pin 11 Arduino to Pin 4 Ds_Regulator Shield.
 *  * Functions:
 *    * Regulator.Up();
        - Up one point the regulation
 *    * Regulator.Down();
        - Down one point the regulation
 *    * Regulator.On();
        - Set the regulation On.
 *    * Regulator.Off();
        - Set the regulation Off.
 *    * Regulator.SetPoint(NewValue);
        - Changue the value of Setpoint.
 *  * Variables:
 *    * int ReadValue=Regulator.Value;
*/
#include <Ds_Regulator_Lib.h>

Regulator Regulator(8, 9, 10, 11);
int DatoRecibido;
void setup()
{
  Serial.begin(9600);
  Serial.println("___________________________________");
  Serial.println("--- Ds-Regulator  ---");
  Serial.println("Example shows how to control the Ds_Regulator shield");
  Serial.println("Created Germán Valero Dangersolutions@gmail.com");
  Serial.println("___________________________________");
  Menu();
}
void loop()
{
  EventosSerial();
}
void Menu()
{
  Serial.println("_______________________________________________________________");
  Serial.println("---     Menú:       ---");
  Serial.println("0 - Mostrar Menú");
  Serial.println("1 - Subir Set Point");
  Serial.println("2 - Bajar Set Point");
  Serial.println("3 - Ver Set Point");
  Serial.println("4 - Activar Regulación");
  Serial.println("5 - Desactivar Regulación");
  Serial.println("Sx - Ajustar Set Point a x");
  Serial.println("_______________________________________________________________");
  if (Regulator.SetOn == true) {
    Serial.println("Regulación activada");
  }
  else {
    Serial.println("Regulación desactivada");
  }
  Serial.print("Set Point actual: ");
  Serial.println(Regulator.Value);
  Serial.println("_______________________________________________________________");
}
void EventosSerial()
{
  bool CambioManual = false;
  char cadena[3];
  byte posicion = 0;
  if (Serial.available())
  {
    memset(cadena, 0, sizeof(cadena));
    while (Serial.available() > 0)
    {
      delay(5);
      cadena[posicion] = Serial.read();
      String Clave = cadena;
      if (Clave == "S")
      {
        CambioManual = true;
      }
      else {
        posicion++;
      }
    }
    delay(2);
    DatoRecibido = atoi(cadena);
    posicion = 0; //Ponemos la posicion a 0
    Serial.println("_____________");
    if (CambioManual == true)
    {
      Regulator.Setpoint(DatoRecibido);
      Serial.print("Setpoint cambiado a: ");
      Serial.println(Regulator.Value);
      return;
    }
    if (DatoRecibido == 0)
    {
      Menu();
    }
    if (DatoRecibido == 1)
    {
      Regulator.Up();
      Serial.println("Setpoint Subido");
      Serial.print("Nuevo valor: ");
      Serial.println(Regulator.Value);
    }
    if (DatoRecibido == 2)
    {
      Regulator.Down();
      Serial.println("Setpoint Bajado");
      Serial.print("Nuevo valor: ");
      Serial.println(Regulator.Value);
    }
    if (DatoRecibido == 3)
    {
      Serial.print("Set Point actual: ");
      Serial.println(Regulator.Value);
    }
    if (DatoRecibido == 4)
    {
      Serial.println("Activando Regulación.");
      Serial.print("Set Point actual: ");
      Serial.println(Regulator.Value);
      Regulator.On();
    }
    if (DatoRecibido == 5)
    {
      Serial.println("Desactivando Regulación. Velocidad máxima");
      Regulator.Off();
    }
  }
}
