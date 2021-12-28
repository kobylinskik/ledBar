TARGET = ledBar.elf

CC = arm-none-eabi-gcc

CCFLAGS += -mcpu=cortex-m3
CCFLAGS += -mthumb
CCFLAGS += -nostdlib
CCFLAGS += -I./inc
CCFLAGS += -I./src
CCFLAGS += -g

INPUT = src/startup.S
INPUT += src/main.c
INPUT += src/periphSetup.c
LD = -T./linkerScript.ld
OUTPUT = -o $(TARGET)

PERIPH_SETUP_TEST_TARGET = periphSetupTest

TEST_CC = gcc

TEST_CCFLAGS += -I./inc/
TEST_CCFLAGS += -I./test/
TEST_CCFLAGS += -I./Unity/src/
TEST_CCFLAGS += -g

PERIPH_SETUP_TEST_INPUT = ./test/periphSetupTest.c
PERIPH_SETUP_TEST_INPUT += ./src/periphSetup.c
PERIPH_SETUP_TEST_INPUT += ./Unity/src/unity.c
PERIPH_SETUP_TEST_OUTPUT = -o $(PERIPH_SETUP_TEST_TARGET)

main:
	$(CC) $(CCFLAGS) $(INPUT) $(LD) $(OUTPUT)

clean:
	rm $(TARGET)

testPeriphSetup:
	$(TEST_CC) $(TEST_CCFLAGS) $(PERIPH_SETUP_TEST_INPUT) $(PERIPH_SETUP_TEST_OUTPUT)
	./$(PERIPH_SETUP_TEST_TARGET)

testClean:
	rm $(PERIPH_SETUP_TEST_TARGET)
