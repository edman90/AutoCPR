#include "DualG2HighPowerMotorShield.h"

// Uncomment the version corresponding with the version of your shield.
//DualG2HighPowerMotorShield24v14 md;
// DualG2HighPowerMotorShield18v18 md;
 DualG2HighPowerMotorShield24v18 md;
// DualG2HighPowerMotorShield18v22 md;



void setup()
{
  Serial.begin(115200);  //This allows us to use the serial monitor
  Serial.println("Dual G2 High Power Motor Shield");
  md.init(); //Method that initializes the pinmodes for all the pins listed in document 4b.
  md.calibrateCurrentOffsets(); //Sets the voltage offset of M1 current reading at 0 speed

  delay(10);

  // Uncomment to flip a motor's direction:
  //md.flipM1(true);
  //md.flipM2(true);
}

void loop()
{
  md.enableDrivers(); //enables the MOSFET drivers for  both M1 and M2
  delay(1);  // The drivers require a maximum of 1ms to elapse when brought out of sleep mode.

 /* for (int i = 0; i <= 400; i++)
  {
    md.setM1Speed(i); // Set speed for motor 1, speed is a number betwenn -400 and 400
   
    if (i%200 == 100)
    {
      Serial.print("Current Speed: ");
      Serial.println(i);
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
	}
    delay(2);
  }

  for (int i = 400; i >= -400; i--)
  {
    md.setM1Speed(i); 
    
    if (i%200 == 100)
    {
      Serial.print("Current Speed: ");
      Serial.println(i);
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
	}
    delay(2);
  }

  for (int i = -400; i <= 0; i++)
  {
    md.setM1Speed(i);
    
    if (i%200 == 100)
    {
      Serial.print("Current Speed: ");
      Serial.println(i);
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
	}
    delay(2);
  } /*/

analogWrite(_M1PWM, 255);
delay(5);
  


 

  md.disableDrivers(); // Put the MOSFET drivers into sleep mode.
  delay(500);

}