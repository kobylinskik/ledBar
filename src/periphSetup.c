#include <stdint.h>
#include "peripherals.h"
#include "periphSetup.h"

void enableGpioA(void) {
  volatile uint32_t * apb2Enr = RCC_APB2ENR;
  *apb2Enr |= (1<<2);
}

void enableAdc1(void) {
  volatile uint32_t * rccCfgr = RCC_CFGR;
  *rccCfgr |= ((1<<14) | (1<<15));

  volatile uint32_t * apb2Enr = RCC_APB2ENR;
  *apb2Enr |= (1<<9);
}

void setPinToOutputMode(pin_t * pin) {
  volatile uint32_t * gpioCr;
  if (pin->pinNumber < 8u) {
    gpioCr = (uint32_t *)((POINTER_SIZED_INT_TYPE)(pin->gpioBaseAddress)+GPIO_CRL_OFFSET);
  } else {
    gpioCr = (uint32_t *)((POINTER_SIZED_INT_TYPE)(pin->gpioBaseAddress)+GPIO_CRH_OFFSET);
  }
  uint8_t pinCnfOffset = (pin->pinNumber % 8)*4;
  *gpioCr &= ~((1<<(pinCnfOffset + 1)) | (1<<(pinCnfOffset + 2)) | (1<<(pinCnfOffset + 3)));
  *gpioCr |= (1<<(pinCnfOffset));
}

void setPinToAnalogInput(pin_t * pin) {
  volatile uint32_t * gpioCr;
  if (pin->pinNumber < 8u) {
    gpioCr = (uint32_t *)(pin->gpioBaseAddress+GPIO_CRL_OFFSET);
  } else {
    gpioCr = (uint32_t *)(pin->gpioBaseAddress+GPIO_CRH_OFFSET);
  }
  uint8_t pinCnfOffset = (pin->pinNumber % 8)*4;
  *gpioCr &= ~((1<<pinCnfOffset) | (1<<(pinCnfOffset + 1)) | (1<<(pinCnfOffset + 2)) | (1<<(pinCnfOffset + 3)));
}

void setPinsToOutputMode(pin_t * pins, uint8_t numberOfPins) {
  for (uint8_t i = 0; i < numberOfPins; i++) {
    setPinToOutputMode(&pins[i]);
  }
}

void setupAdc1(void) {
  enableAdc1();
  setPinToAnalogInput(0);
  volatile uint32_t * adc1Cr = ADC1_CR2;

  //First enable
  *adc1Cr |= 1;

  //Continuous mode enable
  *adc1Cr |= 2;

  //Set sample time
  volatile uint32_t * adc1Smpr2 = ADC1_SMPR2;
  *adc1Smpr2 |= (1 | (1<<1) | (1<<2));

  //Start calibration
  *adc1Cr |= (1<<2);

  while ((*adc1Cr & (1<<2)) != 0) {
    //Calibration in progress
  }

  //Second enable
  *adc1Cr |= 1;
}
