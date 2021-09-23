// Keypad programmer by Frank Mukete.
// Developed with the G pads in mind, but may be compatible
// with other pads that use the adafruit/arduino boards.
// Started on: 09/14/2021

#pragma once
#ifndef KEY_PAD_H
#define KEY_PAD_H

#include "Key.h"

#define MAXKEYS 25

typedef struct {
	int rows;
	int cols;
} keypad_size;

class KeyPad : public Key {
public:
	Key key[MAXKEYS];
	keypad_size keypadsize;

	KeyPad();
	KeyPad(char *keylist);
	bool keydown();  // key just went down
	bool keyhelddown();  // key has been down for holdtime
	bool keyup();  // key has been up for holdtime
	bool keyjustup();  // key just went up
	void updatekeylist(char *keylist);
	void updatekey(char key);

	// utilities
	void setkeyholdtime(float t);
	int findinlist(char key);  // use key char to get key list number
	int findinlist(int identifier);  // use key identifier to get key list number  
	char findkeyat(int listnum);  // return key char at list number
	bool keystateChanged(char key);  // check if that particular key has changed state
	bool keystateChanged(int listnum); // check if key at list num has changed
	bool keystateChanged();  // check if any key has changed state

private:

};

#endif // !KEY_PAD_H