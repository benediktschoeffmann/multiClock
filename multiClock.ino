#include <TM1637Display.h>

#include "pins.h"

const int dotBitMask = 0b00100000;
const int baud = 9600;
const int dly = 2000;
const int longDly = 5000;

uint8_t data[] = {0xff, 0xff, 0xff, 0xff};

TM1637Display display(CLK, DIO);

void setup() {
  Serial.begin(baud);
  Serial.println("Start.");

  display.setBrightness(0x0f);
  display.setSegments(data);
  delay(longDly);

  Serial.println("Init done. ");
}


void loop() {
  for (int i = 880; i < 2200; i += 30) {
    display.showNumberDecEx(i, dotBitMask, true, 4, 0);
    Serial.println(i);
    delay(dly);
  }

  Serial.println("DONE.");
  delay(longDly);
  delay(longDly);
}
