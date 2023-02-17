#include <Arduino.h>
#include "Porte.h"


Porte Porte1(12, 11, 10, 9, 8, 7, 6, 5);
Porte Porte3(13, 14, 15, 16, 17, 18, 19, 4);





void setup()
{

  Porte1.mode(1);
  Porte2.mode(2);

}

void loop (){

  Porte1.allume();
  Porte2.teste();
  if(Porte2.teste() == true)
  {
  Porte1.arreter();
  nature(Porte1, Porte2);
  }
 else{
        Serial.println("ni droit ni croisee");
    }

  delay(2000);
}