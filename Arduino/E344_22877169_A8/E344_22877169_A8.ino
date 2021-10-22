#include <Wire.h>


int BatteryCurrent = A0;
int SupplyVoltage = A1;
int BatteryVoltage = A2;
int LightSensor = A9;



bool CS = 1;
float SV = 0;
float BV = 0;
float BC = 0;
float LS = 0;
float averageSV;
float averageBC;
float averageBV;
float averageLS;

int MeasurementsToAverage = 200;

void setup() {
  // put your setup code here, to run once:
pinMode(11,OUTPUT);
digitalWrite(11,HIGH);
Serial.begin(9600);

}

void loop() {
//   put your main code here, to run repeatedly:

SV = analogRead(SupplyVoltage);
BV = analogRead(BatteryVoltage);
BC = analogRead(BatteryCurrent);
LS = analogRead(LightSensor);

SV = map(SV, 0, 1023, 0, 22);
BV = map(BV, 0, 1023, 57, 75);
BC = map(BC, 0, 1023, -362, 662);
LS = map(LS, 0, 1023, -18, 140);

for(int i = 0; i < MeasurementsToAverage; ++i)
  {
    averageSV += SV;
    averageBC += BC;
    averageBV += BV;
    averageLS += LS;
    delay(1);
  }
  averageSV /= MeasurementsToAverage;
   averageBC /= MeasurementsToAverage;
   averageBV /= MeasurementsToAverage;
   averageLS /= MeasurementsToAverage;

if(averageBV/10<7.2)
{
  digitalWrite(11,HIGH);
  CS = 1;
  }
  else
  {
    digitalWrite(11,LOW);
    CS = 0;
  }
Serial.print(CS);
Serial.print(",");
Serial.print(averageBV);
Serial.print(",");
Serial.print(averageSV);
Serial.print(",");
Serial.print(averageBC);
Serial.print(",");
Serial.print(averageLS/100);
Serial.print("\n");


  
delay(1000);


}
