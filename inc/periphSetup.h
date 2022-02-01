#ifndef PERIPH_SETUP
#define PERIPH_SETUP

#include "buildConfig.h"

typedef struct {
  POINTER_SIZED_INT_TYPE gpioBaseAddress;
  uint8_t pinNumber;
} pin_t;

void enableGpioA(void);
void setPinToOutputMode(pin_t * pin);
void setPinsToOutputMode(pin_t * pins, uint8_t numberOfPins);
void setPinToAnalogInput(pin_t * pinNumber);
void setupAdc1(void);
#endif
