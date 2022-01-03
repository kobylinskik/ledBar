#include <stdint.h>
#include "ledBarDriver.h"
#include "peripherals.h"

void setLeds(uint8_t * leds, uint8_t ledsSize, uint8_t numberOfLeds){
  uint32_t * gpioAOdr = GPIOA_ODR;
  for (uint8_t i = 0; i < ledsSize; i++) {
    if (i < numberOfLeds) {
      *gpioAOdr |= 1<<leds[i];
    } else {
      *gpioAOdr &= ~(1<<leds[i]);
    }
  }
}

uint8_t getNumberOfLedsToSwitchOnFromAdcReading(uint8_t ledsSize, uint16_t valueFromAdc) {
  return (ledsSize + 0.99) * valueFromAdc / ADC_MAX_VAL;
}
