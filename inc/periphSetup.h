#ifndef PERIPH_SETUP
#define PERIPH_SETUP

void enableApb2Bus(void);
void setPinToOutputMode(uint8_t pinNumber);
void setPinsToOutputMode(uint8_t * pins, uint8_t numberOfPins);
#endif
