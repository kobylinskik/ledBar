periphSetup:
TARGET = periphSetupTest

CC = gcc

CCFLAGS += -I../inc/
CCFLAGS += -I../src/
CCFLAGS += -I../Unity/src/
CCFLAGS += -g

INPUT = src/periphSetupTest.c
OUTPUT = -o periphSetupTest.elf

$(TARGET).elf:
	$(CC) $(CCFLAGS) $(INPUT) $(OUTPUT)

clean:
	rm periphSetupTest.elf
