#include <stdint.h>
#include "peripherals.h"
#include "periphSetup.h"

void enableApb2Bus(void) {
  volatile uint32_t * apb2Enr = RCC_APB2ENR;
  *apb2Enr |= (1<<2);
}

void setPa5ToOutput(void) {
  volatile uint32_t * gpioACrl = GPIOA_CRL;
  *gpioACrl &= ~((1<<21) | (1<<22) | (1<<23));
  *gpioACrl |= (1<<20);
}

void setPinToOutputMode(uint8_t pinNumber) {
  volatile uint32_t * gpioACr;
  if (pinNumber < 8) {
    gpioACr = GPIOA_CRL;
  } else {
    gpioACr = GPIOA_CRH;
  }
  uint8_t pinCnfOffset = (pinNumber % 8)*4;
  *gpioACr &= ~((1<<(pinCnfOffset + 1)) | (1<<(pinCnfOffset + 2)) | (1<<(pinCnfOffset + 3)));
  *gpioACr |= (1<<(pinCnfOffset));
}

void switchOnLed(void) {
  volatile uint32_t * gpioAOdr = GPIOA_ODR;
  *gpioAOdr |= (1<<5);
}
