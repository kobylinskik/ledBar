#include <stdint.h>
#include "ledBarDriver.h"
#include "peripherals.h"
#include<stdio.h>

void setPins(volatile pin_t * pins, uint8_t pinsSize, uint8_t numberOfPins){
  for (uint8_t i = 0; i < pinsSize; i++) {
    pin_t pin = pins[i];
    uint32_t * gpioOdr = (uint32_t *)(pin.gpioBaseAddress + GPIO_ODR_OFFSET);
    if (i < numberOfPins) {
      *gpioOdr |= 1<<pins[i].pinNumber;
    } else {
      *gpioOdr &= ~(1<<pins[i].pinNumber);
    }
  }
}

uint8_t getNumberOfLedsToSwitchOnFromAdcReading(uint8_t ledsSize, uint16_t valueFromAdc) {
  return (ledsSize + 1) * (valueFromAdc - 1) / ADC_MAX_VAL;
}
