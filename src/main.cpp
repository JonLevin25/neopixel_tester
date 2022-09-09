#include <Arduino.h>
#include "FastLED.h"

#define Pln Serial.println
#define P Serial.print

// arduino nano cant seem to handle 300+ leds. 240 worked. Lacking Memory?
#define NUM_LEDS      240 //   (120= 2m @60/m) Max 6A (Usually less)
#define BRIGHTNESS 127

#define LED_TYPE   WS2812B
#define COLOR_ORDER   GRB
#define DATA_PIN  13

#define LEDS_T CRGBArray<NUM_LEDS>
LEDS_T leds;

#define COLOR_DELAY 1200

struct color_config_t
{
  const uint16_t delay;
  const CRGB col;
  const char* name;
};

void test_leds_solid(LEDS_T leds, const color_config_t cols[], size_t length)
{
  for (size_t i=0; i < length; i++)
  {
    color_config_t x = cols[i];
    Pln(x.name);
    leds.fill_solid(x.col);
    FastLED.show();
    delay(x.delay);
  }

  leds = CRGB::Black;
  FastLED.show();
}


void setup() {
  Serial.begin(9600);
  delay( 2000 ); //safety startup delay
    FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip);
  
  FastLED.setBrightness(BRIGHTNESS);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  const static color_config_t cols[] =
  {
      {COLOR_DELAY, CRGB(255, 0, 0), "red"},
      {COLOR_DELAY, CRGB(0, 255, 0), "green"},
      {COLOR_DELAY, CRGB(0, 0, 255), "blue"},

      // often got stuck on white (large current?)
      // {300, CRGB(255, 255, 255), "white"}, // dont show white for too long
  };
  size_t num_colors = sizeof(cols)/sizeof(cols[0]);
  

  test_leds_solid(leds, cols, num_colors);
  
  Pln("rainbow");
  leds.fill_rainbow(0, max(1u, 255u / NUM_LEDS));
  FastLED.show();
  delay(COLOR_DELAY);

  Pln("Off");
  leds.fill_solid(CRGB::Black);
  FastLED.show();
  delay(COLOR_DELAY);
}