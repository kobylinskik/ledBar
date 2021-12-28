#include <stdint.h>
#include "peripherals.h"
#include "periphSetup.h"

int main(void) {
  enableApb2Bus();
  setPa5ToOutput();
  switchOnLed();
  while (1) {
    
  }
}
