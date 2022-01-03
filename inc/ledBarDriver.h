#ifndef LED_BAR_DRIVER
#define LED_BAR_DRIVER

void setLeds(uint8_t * leds, uint8_t ledsSize, uint8_t numberOfLeds);
uint8_t getNumberOfLedsToSwitchOnFromAdcReading(uint8_t ledsSize, uint16_t valueFromAdc);

#endif
