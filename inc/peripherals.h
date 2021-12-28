#include "buildConfig.h"

#ifndef PERIPHERALS
#define PERIPHERALS

#ifdef MAIN_BUILD

#define RCC           (uint32_t)0x40021000
#define RCC_CR        (uint32_t *)RCC
#define RCC_APB2ENR   (uint32_t *)(RCC+0x18)

#define GPIOA         (uint32_t)0x40010800
#define GPIOA_CRL     (uint32_t *)GPIOA
#define GPIOA_CRH     (uint32_t *)(GPIOA+0x4)
#define GPIOA_ODR    (uint32_t *)(GPIOA+0xC)

#endif


#ifdef TEST_BUILD

#define RCC_APB2ENR   testRccApb2Enr
#define GPIOA_CRL     testGpioaCrl
#define GPIOA_CRH     testGpioaCrh
#define GPIOA_ODR    testGpioaOdr

uint32_t * testRccApb2Enr;
uint32_t * testGpioaCrl;
uint32_t * testGpioaCrh;
uint32_t * testGpioaOdr;

#endif

#endif
