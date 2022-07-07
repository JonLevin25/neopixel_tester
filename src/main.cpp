#include <Arduino.h>

#include "FastLED.h"

#define Pln Serial.println
#define P Serial.print

#define NUM_LEDS      300 // 5m * 60leds/m
#define LED_TYPE   WS2812B
#define COLOR_ORDER   GRB
#define DATA_PIN  A5
//#define CLK_PIN       4
#define VOLTS          12

#define LEDS_T CRGBArray<NUM_LEDS>
LEDS_T leds;

#define COLOR_DELAY 750


void test_leds(LEDS_T leds, uint32_t color_delay)
{
  static const struct { CRGB col; const char* name; } cols[] =
  {
      {CRGB(255, 0, 0), "red"},
      {CRGB(0, 255, 0), "green"},
      {CRGB(0, 0, 255), "blue"},
      {CRGB(255, 255, 255), "white"},
  };

  for (auto&& x : cols)
  {
    Pln(x.name);
    leds.fill_solid(x.col);
    FastLED.show();
    delay(color_delay);
  }

  leds = CRGB::Black;
  FastLED.show();
}


void setup() {
  delay( 2000 ); //safety startup delay
    FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  test_leds(leds, COLOR_DELAY);
}