int LedPin = 3;

void setup() {
  Serial.begin(115200);
  pinMode(LedPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(LedPin, 50);
  Serial.println("Led Az Yanıyor");
  delay(2000);
  analogWrite(LedPin, 255);
  Serial.println("Led Çok Yanıyor");
  delay(2000);

}
