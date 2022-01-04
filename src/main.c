#include <stdint.h>
#include "peripherals.h"
#include "periphSetup.h"
#include "ledBarDriver.h"

int main(void) {
  uint8_t leds [4] = {6, 7, 9, 8};
  uint8_t ledsSize = 4;
  enableGpioA();
  setPinsToOutputMode(leds, ledsSize);
  setupAdc1();
  volatile uint32_t * adc1Sr = ADC1_SR;
  volatile uint16_t * adc1Dr = (uint16_t *)ADC1_DR;
  while (1) {
    if (*adc1Sr & 2) {
      uint8_t ledsToSwitchOn = getNumberOfLedsToSwitchOnFromAdcReading(ledsSize, *adc1Dr & ADC_MAX_VAL);
      setLeds(leds, ledsSize, ledsToSwitchOn);
    }
    /*for (uint32_t i = 0; i < 60000; i++) {
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
    }*/
  }
}
