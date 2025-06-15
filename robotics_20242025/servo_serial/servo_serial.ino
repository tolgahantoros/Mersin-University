#include <Servo.h>
Servo myServo;
int sayac = 0;
String girdi;
int girdival = 180;

void setup() {
  Serial.begin(115200);
  myServo.attach(10);
}

void loop() {
  if (Serial.available()>0)
  {
    girdi = Serial.readStringUntil('\n');
    girdival = girdi.toInt();
    delay(2000);
  }

  Serial.println(girdival);
  myServo.write(sayac);
  delay(40);
  sayac = sayac + 1;

  if(sayac > girdival)
  {
  while(sayac > 0)
    {
      sayac = sayac -1;
      myServo.write(sayac);
        delay(40);
    }
  }
}
