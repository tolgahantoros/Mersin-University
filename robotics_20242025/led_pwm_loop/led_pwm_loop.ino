int LedPin = 3;
int i = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LedPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(i;i<=255;i++)
  {
  analogWrite(LedPin, i);
  delay(100);
  Serial.println(i);
  }

  for(i;i>0;i--)
  {
  analogWrite(LedPin, i);
  delay(100);
  Serial.println(i);
  }
}
