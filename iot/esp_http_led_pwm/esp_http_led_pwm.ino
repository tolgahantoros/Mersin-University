#include <Arduino.h>

#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>

WiFiMulti wifiMulti;

String webadress;
String payload;
int ledPin = 4;
int dutyCycle = 0;

const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);

  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin, ledChannel);

  wifiMulti.addAP("AtomicMobile", "vlk953f.");
}

void loop() {
  // wait for WiFi connection
  Serial.println("--------------------------------------------");
  if ((wifiMulti.run() == WL_CONNECTED)) {
    webadress = "https://vyamacli.com/classroom/IoT2023/phplib/gdata_get.php?param=led";
    Serial.println("Adres: " + webadress);
    delay(5000);
    HTTPClient http;
    Serial.print("[HTTP] begin...\n");

    http.begin(webadress);  //HTTP
    http.setConnectTimeout(30000);
    http.setTimeout(30000);

    Serial.print("[HTTP] GET...\n");
    // start connection and send HTTP header
    int httpCode = http.GET();

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        payload = http.getString();
        Serial.print("Payload: ");
        Serial.println(payload);
      }
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
    dutyCycle = payload.toInt();
    Serial.print("DutyCycle: ");
    Serial.println(dutyCycle);
    ledcWrite(ledChannel, dutyCycle);
  }

  delay(15000);
}
