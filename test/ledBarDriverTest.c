#include <stdlib.h>
#include <stdint.h>
#include "peripherals.h"
#include "unity.h"
#include "ledBarDriver.h"

uint32_t leds[6];

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

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(shouldSwitchOnTwoLeds);
  return UNITY_END();
}
