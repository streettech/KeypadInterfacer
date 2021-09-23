#pragma once
#ifndef KEYPAD_H
#define KEYPAD_H

#include <vector>
#include "Helper.h"
#include "Event.h"
#include "Key.h"

class Keypad : public Key {
public:
	Keypad();
	Keypad(char* keylist, xy_size keypadsize);
	bool keydown();  // key just went down
	bool keyhelddown();  // key has been down for holdtime
	bool keyup();  // key has been up for holdtime
	bool keyjustup();  // key just went up
	void updatekeylist(char* keylist);
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
	std::vector<Key> key;
	xy_size keypadsize;
};

#endif // !KEYPAD_H
