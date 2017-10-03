float tempC;
int reading;
int tempPin = 0;

void setup()
{
Serial.begin(9600);
}

void loop()
{
reading = analogRead(tempPin);
tempC = reading * 0.48828125;
Serial.println(tempC);
delay(1000);
}

