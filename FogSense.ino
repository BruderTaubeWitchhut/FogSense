#include <ESP8266WiFi.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    return;
  }
  display.clearDisplay();
}

void loop() {
  if (Serial.available()) {
    display.clearDisplay();
    display.drawBitmap(0, 0, (const uint8_t*)Serial.read(), SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
    display.display();
  }
}
