#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>

WiFiMulti wifiMulti;

String webaddress;
String payload;
int rnd = 0;

void setup() {
  Serial.begin(115200);

  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  wifiMulti.addAP("AtomicMobile", "vlk953f.");
}

void loop() {
  // wait for WiFi connection
  Serial.println("--------------------------------------------");
  Serial.println("--------------------------------------------");
  if ((wifiMulti.run() == WL_CONNECTED)) {
    rnd = random(1, 4);
    switch (rnd) {
      case 1:
        webaddress = "https://vyamacli.com/classroom/IoT2023/status_1.php";
        Serial.println("Random Sayı: " + String(rnd));
        Serial.println("Adres: " + webaddress);
        break;

      case 2:
        webaddress = "https://vyamacli.com/classroom/IoT2023/status_2.php";
        Serial.println("Random Sayı: " + String(rnd));
        Serial.println("Adres: " + webaddress);
        break;

      case 3:
        webaddress = "https://vyamacli.com/classroom/IoT2023/status_3.php";
        Serial.println("Random Sayı: " + String(rnd));
        Serial.println("Adres: " + webaddress);
        break;
    }
    delay(5000);
    HTTPClient http;
    Serial.print("[HTTP] begin...\n");

    http.begin(webaddress);  //HTTP
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
        Serial.println("Okunan Veri: " + payload);
      }
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }

  delay(15000);
}
