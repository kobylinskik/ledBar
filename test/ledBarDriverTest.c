#include <stdlib.h>
#include <stdint.h>
#include "peripherals.h"
#include "unity.h"
#include "ledBarDriver.h"

uint8_t leds[6];

void setUp(void) {
  testGpioaOdr = calloc(1, sizeof(uint32_t));
  for (int i = 0; i < 6; i++) {
    leds[i] = i;
  }
}

void tearDown(void) {
  free(testGpioaOdr);
}

void shouldSwitchOnTwoLeds(void) {
  uint32_t * gpioAOdr = GPIOA_ODR;
  setLeds(leds, 6U, 2U);

  uint32_t expectedBits = (1<<leds[0]) | (1<<leds[1]);
  uint32_t testedBits = 0;

  for (int i = 0; i < 6; i++) {
    testedBits |= 1<<leds[i];
  }

  TEST_ASSERT_BITS(testedBits, expectedBits, *gpioAOdr);
}

void shouldSwitchOnFiveLedsAndThenOne(void) {
  uint32_t * gpioAOdr = GPIOA_ODR;
  setLeds(leds, 6U, 5U);

  uint32_t expectedBits = (1<<leds[0]) | (1<<leds[1]) | (1<<leds[2]) | (1<<leds[3]) | (1<<leds[4]);
  uint32_t testedBits = 0;

  for (int i = 0; i < 6; i++) {
    testedBits |= 1<<leds[i];
  }

  TEST_ASSERT_BITS(testedBits, expectedBits, *gpioAOdr);
  setLeds(leds, 6U, 1U);

  expectedBits = (1<<leds[0]);

  TEST_ASSERT_BITS(testedBits, expectedBits, *gpioAOdr);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(shouldSwitchOnTwoLeds);
  RUN_TEST(shouldSwitchOnFiveLedsAndThenOne);
  return UNITY_END();
}
