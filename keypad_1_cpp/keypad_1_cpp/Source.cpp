// Main class
// Developed by Frank Mukete
// Keypad Software for the G Pad
// May be compatible with other pads that use the adafruit/arduino boards
// Started on: 09/16/2021
#include "srcHeaders/GLibs.h"

int main() {
	Runnable prg;

	while (true/*not quit event*/) {
		prg.priorityRun();
		prg.run();
	}
}