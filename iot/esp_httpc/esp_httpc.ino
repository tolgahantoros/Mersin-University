#include <Arduino.h>

#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>

WiFiMulti wifiMulti;

String webadress;
String payload;
int LedPin = 2;
int rnd = 0;

void setup() {
    pinMode(LedPin, OUTPUT);
    Serial.begin(115200);

    Serial.println();
    Serial.println();
    Serial.println();

    for(uint8_t t = 4; t > 0; t--) {
        Serial.printf("[SETUP] WAIT %d...\n", t);
        Serial.flush();
        delay(1000);
    }

    wifiMulti.addAP("AtomicMobile", "vlk953f.");

}

void loop() {
    // wait for WiFi connection
    Serial.println("--------------------------------------------");
    if((wifiMulti.run() == WL_CONNECTED)) {
        rnd = random(1,4);
        switch (rnd){
          case 1:
          webadress = "https://vyamacli.com/classroom/IoT2023/status_1.php";
          Serial.println("Random Sayı: " + String(rnd));
          Serial.println("Adres: " + webadress);
          break;

          case 2:
          webadress = "https://vyamacli.com/classroom/IoT2023/status_2.php";
          Serial.println("Random Sayı: " + String(rnd));
          Serial.println("Adres: " + webadress);
          break;

          case 3:
          webadress = "https://vyamacli.com/classroom/IoT2023/status_3.php";
          Serial.println("Random Sayı: " + String(rnd));
          Serial.println("Adres: " + webadress);
          break;
        }
        delay(5000);
        HTTPClient http;
        Serial.print("[HTTP] begin...\n");
        
        http.begin(webadress); //HTTP
        http.setConnectTimeout(30000);
        http.setTimeout(30000);

        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            Serial.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                payload = http.getString();
                Serial.println(payload);
            }
        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();

        if(payload == "1"){
          digitalWrite(LedPin,HIGH);
          Serial.println("LED Aktif");
        }
        if(payload == "0"){
          digitalWrite(LedPin,LOW);
          Serial.println("LED Pasif");
        }
        if(payload !="1" && payload !="0"){
          Serial.println("İşlem Yapılmadı");
        }
    }

    delay(5000);
}
