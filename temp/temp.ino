#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(2);
DallasTemperature sensors(&oneWire);
 
void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  sensors.begin();
}
 
 
void loop(void)
{
  Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); 
  Serial.println("DONE");
  Serial.print("Temperature for Device 1 is: ");
  Serial.print(sensors.getTempCByIndex(0)); 
  delay(500);

}

