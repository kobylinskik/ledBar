#include "buildConfig.h"

#ifndef PERIPHERALS
#define PERIPHERALS

#define ADC_MAX_VAL      (uint16_t)0xfff

#ifdef MAIN_BUILD

#define RCC              (POINTER_SIZED_INT_TYPE)0x40021000
#define RCC_CR           (uint32_t *)RCC
#define RCC_CFGR         (uint32_t *)(RCC+0x8)
#define RCC_APB2ENR      (uint32_t *)(RCC+0x18)

#define GPIO_CRL_OFFSET  (POINTER_SIZED_INT_TYPE)0
#define GPIO_CRH_OFFSET  (POINTER_SIZED_INT_TYPE)0x4
#define GPIO_ODR_OFFSET  (POINTER_SIZED_INT_TYPE)0xC

#define GPIOA            (POINTER_SIZED_INT_TYPE)0x40010800

#define GPIOA_CRL        (uint32_t *)(GPIOA_GPIO_CRL_OFFSET)
#define GPIOA_CRH        (uint32_t *)(GPIOA+GPIO_CRH_OFFSET)
#define GPIOA_ODR        (uint32_t *)(GPIOA+GPIO_ODR_OFFSET)

#define ADC1_PIN      0

#define ADC1          (POINTER_SIZED_INT_TYPE)0x40012400
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

#define RCC           testRcc
#define RCC_CR        testRccCr
#define RCC_CFGR      testRccCfgr
#define RCC_APB2ENR   testRccApb2Enr


#define GPIO_CRL_OFFSET  testGpioCrlOffset
#define GPIO_CRH_OFFSET  testGpioCrhOffset
#define GPIO_ODR_OFFSET  testGpioOdrOffset

#define GPIOA         testGpioa
#define GPIOA_CRL     testGpioaCrl
#define GPIOA_CRH     testGpioaCrh
#define GPIOA_ODR     testGpioaOdr

#define ADC1_CR1      testAdc1Cr1
#define ADC1_CR2      testAdc1Cr2
#define ADC1_SMPR2    testAdc1Smpr2

uint32_t * testRcc;
uint32_t * testRccCr;
uint32_t * testRccCfgr;
uint32_t * testRccApb2Enr;

POINTER_SIZED_INT_TYPE testGpioCrlOffset;
POINTER_SIZED_INT_TYPE testGpioCrhOffset;
POINTER_SIZED_INT_TYPE testGpioOdrOffset;

POINTER_SIZED_INT_TYPE testGpioa;
uint32_t * testGpioaCrl;
uint32_t * testGpioaCrh;
uint32_t * testGpioaOdr;

uint32_t * testAdc1Cr1;
uint32_t * testAdc1Cr2;
uint32_t * testAdc1Smpr2;

#endif

#endif
