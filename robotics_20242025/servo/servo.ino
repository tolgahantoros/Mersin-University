#include <Servo.h>
Servo myServo;
int sayac = 0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  myServo.write(sayac);
  delay(100);
  sayac = sayac + 1;

  if(sayac > 180)
  {
  while(sayac > 0)
    {
      sayac = sayac -1;
      myServo.write(sayac);
        delay(50);
    }
  }
}
