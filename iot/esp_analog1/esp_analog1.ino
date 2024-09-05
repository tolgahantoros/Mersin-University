#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

WiFiMulti wifiMulti;
String stemp;
String webadress;
String payload;
float tmp;
float volt;

void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  wifiMulti.addAP("AtomicMobile", "vlk953f.");
  //set the resolution to 12 bits (0-4096)
  analogReadResolution(10);
}

void loop() {
  // read the analog / millivolts value for pin 2:
  Serial.println("--------------------------------------------");
  if ((wifiMulti.run() == WL_CONNECTED)) {
    int analogValue = analogRead(33);
    int analogVolts = analogReadMilliVolts(33);
    volt = analogVolts;
    tmp = volt/10;
    stemp = String(tmp);
    // print out the values you read:
    Serial.printf("ADC analog value = %d\n", analogValue);
    Serial.printf("ADC millivolts value = %d\n", analogVolts);

    webadress = "https://vyamacli.com/classroom/IoT2023/phplib/insert_temp.php?temp="+stemp;
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
  }
  delay(5000);  // delay in between reads for clear read from serial
}
