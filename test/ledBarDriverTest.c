#include <stdlib.h>
#include <stdint.h>
#include "peripherals.h"
#include "unity.h"
#include "ledBarDriver.h"
#include<stdio.h>

pin_t leds[6];
uint8_t ledsSize = 6;

void setUp(void) {
  testGpioaCrl = calloc(1, sizeof(uint32_t));
  testGpioaCrh = calloc(1, sizeof(uint32_t));
  testGpioaOdr = calloc(1, sizeof(uint32_t));

  testGpioa = (POINTER_SIZED_INT_TYPE)testGpioaCrl;
  testGpioCrlOffset = 0;
  testGpioCrhOffset = (POINTER_SIZED_INT_TYPE)testGpioaCrh - testGpioa;
  testGpioOdrOffset = (POINTER_SIZED_INT_TYPE)testGpioaOdr - testGpioa;

  for (uint8_t i = 0; i < ledsSize; i++) {
    leds[i].gpioBaseAddress = GPIOA;
    leds[i].pinNumber = i;
  }
}

void tearDown(void) {
  free(testGpioaCrl);
  free(testGpioaCrh);
  free(testGpioaOdr);
}

void shouldSwitchOnTwoLeds(void) {
  uint32_t * gpioAOdr = GPIOA_ODR;
  setPins(leds, 6U, 2U);

  uint32_t expectedBits = (1<<leds[0].pinNumber) | (1<<leds[1].pinNumber);
  uint32_t testedBits = 0;

  for (int i = 0; i < 6; i++) {
    testedBits |= 1<<leds[i].pinNumber;
  }

  TEST_ASSERT_BITS(testedBits, expectedBits, *gpioAOdr);
}

void shouldSwitchOnFiveLedsAndThenOne(void) {
  uint32_t * gpioAOdr = GPIOA_ODR;
  setPins(leds, 6U, 5U);

  uint32_t expectedBits = (1<<leds[0].pinNumber) | (1<<leds[1].pinNumber) | (1<<leds[2].pinNumber) | (1<<leds[3].pinNumber) | (1<<leds[4].pinNumber);
  uint32_t testedBits = 0;

  for (int i = 0; i < 6; i++) {
    testedBits |= 1<<leds[i].pinNumber;
  }

  TEST_ASSERT_BITS(testedBits, expectedBits, *gpioAOdr);
  setPins(leds, 6U, 1U);

  expectedBits = (1<<leds[0].pinNumber);

  TEST_ASSERT_BITS(testedBits, expectedBits, *gpioAOdr);
}

void shouldReturnZeroWhenAdcReadingIsZero(void) {
  uint8_t numberOfLedsToSwitchOn = getNumberOfLedsToSwitchOnFromAdcReading(ledsSize, 0);
  TEST_ASSERT_EQUAL_UINT8(0, numberOfLedsToSwitchOn);
}

void shouldReturnSixWhenAdcReadingIsMax(void) {
  uint8_t numberOfLedsToSwitchOn = getNumberOfLedsToSwitchOnFromAdcReading(ledsSize, ADC_MAX_VAL);
  TEST_ASSERT_EQUAL_UINT8(6, numberOfLedsToSwitchOn);
}

void shouldReturnTwoWhenAdcReadingIsOneThirdOfMax(void) {
  uint8_t numberOfLedsToSwitchOn = getNumberOfLedsToSwitchOnFromAdcReading(ledsSize, ADC_MAX_VAL / 3);
  TEST_ASSERT_EQUAL_UINT8(2, numberOfLedsToSwitchOn);
}

void shouldReturnOneWhenAdcReadingIsOneFourthOfMax(void) {
  uint8_t numberOfLedsToSwitchOn = getNumberOfLedsToSwitchOnFromAdcReading(ledsSize, ADC_MAX_VAL / 4);
  TEST_ASSERT_EQUAL_UINT8(1, numberOfLedsToSwitchOn);
}

void shouldReturnSixWhenAdcReadingIsAlmostMax(void) {
  uint8_t numberOfLedsToSwitchOn = getNumberOfLedsToSwitchOnFromAdcReading(ledsSize, ADC_MAX_VAL / 1.05);
  TEST_ASSERT_EQUAL_UINT8(6, numberOfLedsToSwitchOn);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(shouldSwitchOnTwoLeds);
  RUN_TEST(shouldSwitchOnFiveLedsAndThenOne);
  RUN_TEST(shouldReturnZeroWhenAdcReadingIsZero);
  RUN_TEST(shouldReturnSixWhenAdcReadingIsMax);
  RUN_TEST(shouldReturnTwoWhenAdcReadingIsOneThirdOfMax);
  RUN_TEST(shouldReturnOneWhenAdcReadingIsOneFourthOfMax);
  RUN_TEST(shouldReturnSixWhenAdcReadingIsAlmostMax);
  return UNITY_END();
}
