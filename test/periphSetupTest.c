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

void shouldEnableGpioA(void) {
  uint32_t * apb2BusEnReg = RCC_APB2ENR;
  enableGpioA();
  TEST_ASSERT_BIT_HIGH(2, *apb2BusEnReg);
}

void shouldSetPa5ToOutput(void) {
  uint32_t * gpioACrl = GPIOA_CRL;
  setPinToOutputMode(5);
  uint32_t bitMask = (1<<20) | (1<<21) | (1<<22) | (1<<23);
  uint32_t expectedResult = (1<<20);
  TEST_ASSERT_BITS(bitMask, expectedResult, *gpioACrl);
}

void shouldSetPa0To4ToOutput(void) {
  uint32_t * gpioACrl = GPIOA_CRL;
  uint8_t pins[5];
  for (int i = 0; i < 5; i++) {
    pins[i] = i;
  }
  setPinsToOutputMode(pins, 5);
  uint32_t bitMask = 0xffff;
  uint32_t expectedResult = 0x1111;
  TEST_ASSERT_BITS(bitMask, expectedResult, *gpioACrl);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(shouldEnableGpioA);
  RUN_TEST(shouldSetPa5ToOutput);
  RUN_TEST(shouldSetPa0To4ToOutput);
  return UNITY_END();
}
