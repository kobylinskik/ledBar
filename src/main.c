#include <stdint.h>
#include "peripherals.h"
#include "periphSetup.h"
#include "ledBarDriver.h"

int main(void) {
  uint32_t leds [1];
  leds[0] = 5;
  enableApb2Bus();
  setPinToOutputMode(5);
  setLeds(leds, 1, 1);
  while (1) {

  }
}
