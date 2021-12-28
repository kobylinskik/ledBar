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

void shouldEnableApb2Bus(void) {
  uint32_t * apb2BusEnReg = RCC_APB2ENR;
  enableApb2Bus();
  TEST_ASSERT_BIT_HIGH(2, *apb2BusEnReg);
}

void shouldSetPa5ToOutput(void) {
  uint32_t * gpioACrl = GPIOA_CRL;
  setPinToOutputMode(5);
  uint32_t bitMask = (1<<20) | (1<<21) | (1<<22) | (1<<23);
  uint32_t expectedResult = (1<<20);
  TEST_ASSERT_BITS(bitMask, expectedResult, *gpioACrl);
}

void shouldSwitchLed5On(void) {
  uint32_t * gpioaOdr = GPIOA_ODR;
  switchOnLed();
  TEST_ASSERT_BIT_HIGH(5, *gpioaOdr);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(shouldEnableApb2Bus);
  RUN_TEST(shouldSetPa5ToOutput);
  RUN_TEST(shouldSwitchLed5On);
  return UNITY_END();
}
