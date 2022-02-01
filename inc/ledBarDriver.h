#ifndef LED_BAR_DRIVER
#define LED_BAR_DRIVER

#include "periphSetup.h"

void setPins(volatile pin_t * pins, uint8_t pinsSize, uint8_t numberOfPins);
uint8_t getNumberOfLedsToSwitchOnFromAdcReading(uint8_t ledsSize, uint16_t valueFromAdc);

#endif
