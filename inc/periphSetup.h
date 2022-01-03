#ifndef PERIPH_SETUP
#define PERIPH_SETUP

void enableGpioA(void);
void setPinToOutputMode(uint8_t pinNumber);
void setPinsToOutputMode(uint8_t * pins, uint8_t numberOfPins);
void setPinToAnalogInput(uint8_t pinNumber);
void setupAdc1(void);
#endif
