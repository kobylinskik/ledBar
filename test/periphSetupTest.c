#include <stdlib.h>
#include <stdint.h>
#include "peripherals.h"
#include "periphSetup.h"
#include "unity.h"

void setUp(void) {
  testRccApb2Enr = calloc(1, sizeof(uint32_t));
  testGpioaCrl = calloc(1, sizeof(uint32_t));
  testGpioaCrh = calloc(1, sizeof(uint32_t));
  testGpioaOdr = calloc(1, sizeof(uint32_t));

  testGpioa = (POINTER_SIZED_INT_TYPE)testGpioaCrl;
  testGpioCrlOffset = 0;
  testGpioCrhOffset = (POINTER_SIZED_INT_TYPE)testGpioaCrh - testGpioa;
  testGpioOdrOffset = (POINTER_SIZED_INT_TYPE)testGpioaOdr - testGpioa;
}

void tearDown(void) {
  free(testRccApb2Enr);
  free(testGpioaCrl);
  free(testGpioaCrh);
  free(testGpioaOdr);
}

void shouldEnableGpioA(void) {
  uint32_t * apb2BusEnReg = RCC_APB2ENR;
  enableGpioA();
  TEST_ASSERT_BIT_HIGH(2, *apb2BusEnReg);
}

void shouldSetPa5ToOutput(void) {
  pin_t pins[6];
  uint8_t numberOfPins = 6;
  for (uint8_t i = 0; i < numberOfPins; i++) {
    pins[i].gpioBaseAddress = GPIOA;
    pins[i].pinNumber = i + 8;
  }

  uint32_t * gpioACrl = GPIOA_CRH;
  setPinToOutputMode(&pins[5]);
  uint32_t bitMask = (1<<20) | (1<<21) | (1<<22) | (1<<23);
  uint32_t expectedResult = (1<<20);
  TEST_ASSERT_BITS(bitMask, expectedResult, *gpioACrl);
}

void shouldSetPa0To4ToOutput(void) {
  uint32_t * gpioACrl = GPIOA_CRL;
  pin_t pins[6];
  uint8_t numberOfPins = 6;

  for (uint8_t i = 0; i < numberOfPins; i++) {
    pins[i].gpioBaseAddress = GPIOA;
    pins[i].pinNumber = i;
  }
  setPinsToOutputMode(pins, numberOfPins);
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
