#include <stdint.h>
#include "peripherals.h"
#include "periphSetup.h"
#include "ledBarDriver.h"

int main(void) {
  uint8_t leds [4] = {6, 7, 9, 8};
  enableApb2Bus();
  setPinsToOutputMode(leds, 4);
  while (1) {
    for (uint32_t i = 0; i < 60000; i++) {
      setLeds(leds, 4, 1);
    }
    for (uint32_t i = 0; i < 60000; i++) {
      setLeds(leds, 4, 2);
    }
    for (uint32_t i = 0; i < 60000; i++) {
      setLeds(leds, 4, 0);
    }
    for (uint32_t i = 0; i < 60000; i++) {
      setLeds(leds, 4, 4);
    }
    for (uint32_t i = 0; i < 60000; i++) {
      setLeds(leds, 4, 0);
    }
  }
}
