#include <Servo.h>
Servo myServo;
int sayac = 0;

int trigpin = 6;
int echopin = 7;
float zaman = 0;
float dist = 0;

float minDist = 2000;
int minAngle = 500;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(10);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Başlıyor");
  delay(5000);
  for(int i=0; i<180; i++)
  {
    myServo.write(i);
    delay(50);

    digitalWrite(trigpin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin, LOW);

    zaman = pulseIn(echopin, HIGH);
    dist = (zaman/2)*0.0344;
    Serial.println(String(dist));

    if(dist < minDist) {
      minDist = dist;
      minAngle = i;
    }
  }
Serial.print("Minimum Mesafe");
Serial.println(String(minDist));
Serial.print("Minimum Açı");
Serial.println(String(minAngle));

delay(60000);

  for(int i=180; i>0; i--)
  {
    myServo.write(i);
    delay(50);

    digitalWrite(trigpin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin, LOW);

    zaman = pulseIn(echopin, HIGH);
    dist = (zaman/2)*0.0344;
    Serial.println(String(dist));
  }
}
