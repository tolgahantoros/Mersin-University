int LedPin = 3;

void setup() {
  Serial.begin(115200);
  pinMode(LedPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LedPin, HIGH);
  Serial.println("Led Yanıyor");
  delay(2000);
  digitalWrite(LedPin, LOW);
  Serial.println("Led Yanmıyor");
  delay(2000);

}
