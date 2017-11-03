//This code will check the distance every 10 milliseconds
//If the distance is less than 10 cm, it will light up bulb on pin 7
//Works just witha  wave, even a fast one
int trigPin = 12;  
int echoPin = 11;   
int ledpin = 7;
long duration, cm;
 
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledpin, OUTPUT);
}
 
void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;
  if (cm < 10) {
      digitalWrite(ledpin, HIGH);
      delay(1000);
      digitalWrite(ledpin, LOW);
  }
  delay(10);
}
