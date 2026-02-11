# OLED I2C Display Project

## Overview
This small PlatformIO/Arduino project shows how to drive a 128x64 SSD1306 I2C OLED and print a few lines of text. The main source is `src/main.cpp`.

## IDE
- IDE: CLion
- Notes: Project is a PlatformIO-style embedded project; CLion is used as the editor/IDE and can build/upload when PlatformIO or Arduino tooling is configured.

## Code explanation
- Entry point: `src/main.cpp`.
- Behavior:
  - Initializes Serial at 9600 baud.
  - Initializes the I2C OLED display via Adafruit_SSD1306.
  - If the display cannot be initialized, prints "OLED not found" and halts.
  - Clears the display, sets text size and color, and prints three lines:
    - "Arduino Uno R4"
    - "Oled with I2C"
    - "Hello Students"
  - Calls `display.display()` once to push the buffer to the screen.
  - `loop()` is empty — no repeating updates are implemented.
- File: `src/main.cpp` (small, easy to extend to show dynamic data or a looped animation)

## Libraries used in the code
- Wire (I2C)
- Adafruit_GFX
- Adafruit_SSD1306
- Arduino core (Arduino.h)

## Dependencies
- PlatformIO (recommended) or Arduino CLI + appropriate board support
- Adafruit GFX library (install via PlatformIO or Arduino Library Manager)
- Adafruit SSD1306 library (install via PlatformIO or Arduino Library Manager)
- The code assumes an SSD1306-compatible OLED module (commonly 0x3C). If your module uses a different driver/address, update the code accordingly.

PlatformIO example (platformio.ini should be present in the repo and configured for your board).

## Components used with the OLED
- 0.96" (or similar) 128x64 SSD1306 I2C OLED module (common I2C address 0x3C)
- Arduino Uno R4 (or other compatible Arduino / microcontroller)
- Breadboard and jumper wires
- USB cable (for programming / serial)
- Optional: pull-up resistors on SDA/SCL if not provided on the module
- Optional: logic-level shifter if using a module with different voltage requirements

## Wiring summary
- OLED VCC -> 3.3V or 5V (check module spec)
- OLED GND -> GND
- OLED SDA -> board SDA pin
- OLED SCL -> board SCL pin

Note: On Arduino Uno R4 (and many Arduinos) the I2C pins are on the dedicated SDA/SCL pins (not always A4/A5 on every board variant). Verify the board pinout.

## Author
- Author: Paras-79

## Software requirements
- CLion (any recent release; assumed 2025.3.2 for this README)
- PlatformIO (recommended) or Arduino CLI + board package
- Adafruit_GFX and Adafruit_SSD1306 libraries installed via PlatformIO or Arduino Library Manager

PlatformIO quick commands (examples):
- Build: `pio run`
- Upload: `pio run -t upload` (ensure `platformio.ini` selects the correct environment/board)
- Monitor serial: `pio device monitor`

(If using Arduino CLI, use `arduino-cli compile` / `arduino-cli upload` with the correct FQBN.)

## Hardware requirements
- Arduino Uno R4 (or other compatible microcontroller)
- SSD1306 128x64 I2C OLED
- USB cable, breadboard, jumper wires

## Troubleshooting
- If display.begin(...) fails:
  - Confirm the OLED is powered and wired correctly.
  - Run an I2C scanner sketch to see the device address.
  - Try common addresses (0x3C or 0x3D).
  - Check for missing pull-ups on SDA/SCL if you have multiple devices on the bus.
- If text is too small/large: use `display.setTextSize(n)` to adjust.

## Extending this project
- Add dynamic content (sensor readings, time, menus) by writing to the display inside `loop()` and calling `display.display()` after updating the buffer.
- Add an I2C scan utility or configuration UI to detect OLED address at runtime.

