#include "buildConfig.h"

#ifndef PERIPHERALS
#define PERIPHERALS

#define ADC_MAX_VAL   (uint16_t)0xfff

#ifdef MAIN_BUILD

#define RCC           (uint32_t)0x40021000
#define RCC_CR        (uint32_t *)RCC
#define RCC_CFGR      (uint32_t *)(RCC+0x8)
#define RCC_APB2ENR   (uint32_t *)(RCC+0x18)

#define GPIOA         (uint32_t)0x40010800
#define GPIOA_CRL     (uint32_t *)GPIOA
#define GPIOA_CRH     (uint32_t *)(GPIOA+0x4)
#define GPIOA_ODR     (uint32_t *)(GPIOA+0xC)

#define ADC1_PIN      0

#define ADC1          (uint32_t)0x40012400
#define ADC1_SR       (uint32_t *)ADC1
#define ADC1_CR1      (uint32_t *)(ADC1+0x4)
#define ADC1_CR2      (uint32_t *)(ADC1+0x8)
#define ADC1_SMPR1    (uint32_t *)(ADC1+0xC)
#define ADC1_SMPR2    (uint32_t *)(ADC1+0x10)
#define ADC1_SQR1     (uint32_t *)(ADC1+0x2C)
#define ADC1_SQR2     (uint32_t *)(ADC1+0x30)
#define ADC1_SQR3     (uint32_t *)(ADC1+0x34)
#define ADC1_DR       (uint32_t *)(ADC1+0x4C)

#endif


#ifdef TEST_BUILD

#define RCC_APB2ENR   testRccApb2Enr
#define GPIOA_CRL     testGpioaCrl
#define GPIOA_CRH     testGpioaCrh
#define GPIOA_ODR     testGpioaOdr

uint32_t * testRccApb2Enr;
uint32_t * testGpioaCrl;
uint32_t * testGpioaCrh;
uint32_t * testGpioaOdr;

#endif

#endif
