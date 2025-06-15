#include <Servo.h>
Servo myServo;
int sayac = 0;
const int sensorPin = A0;
float sensorADC = 0;
float sensorVout = 0;
float sensormVout = 0;

float tempC = 0;
float tempF = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(sensorPin,INPUT);
  myServo.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorADC = analogRead(sensorPin);
  sensorVout = sensorADC*5/1024;
  sensormVout = sensorVout*1000;
  tempC = sensormVout/10;
  tempF = (tempC*1.8)+32;
  Serial.println(sensorADC);
  Serial.println(sensorVout);
  Serial.println(sensormVout);
  Serial.println(tempC);
  Serial.println(tempF);
  Serial.println("----------------------");
  Serial.println("----------------------");

  if(tempC<25)
  {
    myServo.write(0);
  }
  if(tempC>25 && tempC<30)
  {
    myServo.write(90);
  }
  if(tempC>30)
  {
    myServo.write(180);
  }
  
  delay(5000);

}
