#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_ADDR 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
    // write your initialization code here
    Serial.begin(9600);
    if (!display.begin(SSD1306_SWITCHCAPVCC, SSD1306_SWITCHCAPVCC)) {
        Serial.println(F("OLED not found"));
        while (true);
    }
    // Clear display
    display.clearDisplay();
    // Set text size and color
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    //displytext
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 0);
    display.println("Arduino Uno R4");
    display.println("Oled with I2C");
    display.println("Hello Students");
    display.display();

}

void loop() {
    // write your code here
}