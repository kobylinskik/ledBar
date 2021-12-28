#include <stdlib.h>
#include <stdint.h>
#include "peripherals.h"
#include "periphSetup.h"
#include "unity.h"

void setUp(void) {
  testRccApb2Enr = calloc(1, sizeof(uint32_t));
  testGpioaCrl = calloc(1, sizeof(uint32_t));
  testGpioaOdr = calloc(1, sizeof(uint32_t));
}

void tearDown(void) {
    free(testRccApb2Enr);
    free(testGpioaCrl);
    free(testGpioaOdr);
}

void test_enableApb2Bus(void) {
  uint32_t * apb2BusEnReg = RCC_APB2ENR;
  enableApb2Bus();
  TEST_ASSERT_BIT_HIGH(2, *apb2BusEnReg);
}

void test_Pa5Output(void) {
  uint32_t * gpioACrl = GPIOA_CRL;
  setPinToOutputMode(5);
  uint32_t bitMask = (1<<20) | (1<<21) | (1<<22) | (1<<23);
  uint32_t expectedResult = (1<<20);
  TEST_ASSERT_BITS(bitMask, expectedResult, *gpioACrl);
}

void test_LedOn(void) {
  uint32_t * gpioaOdr = GPIOA_ODR;
  switchOnLed();
  TEST_ASSERT_BIT_HIGH(5, *gpioaOdr);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_enableApb2Bus);
  RUN_TEST(test_Pa5Output);
  RUN_TEST(test_LedOn);
  return UNITY_END();
}
