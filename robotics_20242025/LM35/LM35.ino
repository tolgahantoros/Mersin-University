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
  delay(5000);

}
