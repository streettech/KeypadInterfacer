#pragma once
#ifndef KEY_H
#define KEY_H

typedef enum {IDLE, KEYDOWN, KEYUP} KEYSTATE;
typedef unsigned int uint;
const char EMPTY = '\0';
static int identifier = 0;  // running identifier value

class Key {
public:  // key definers 
	KEYSTATE kstate;
	char kchar;
	int kIndentifier;
	bool stateChanged;

	Key();
	Key(char mkey);
	~Key();

	void setKey(char mkey);
	void updateState(bool mstateChanged);

private:

};

#endif // !KEY_H