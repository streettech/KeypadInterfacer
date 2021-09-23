#pragma once
#ifndef KEY_H
#define KEY_H

typedef enum {IDLE, KEYDOWN, KEYUP} KEYSTATE;
typedef unsigned int uint;
const char EMPTY = '\0';
static int identifier = 0;

class Key {
public:
	KEYSTATE kstate;
	char kchar;
	bool kstateChanged;

	Key();
	Key(char mkey);
	void setKey(char mkey);
	void updateState(KEYSTATE mstate, bool mstateChanged);
	int getKidentifier();
private:
	int kidentifier;
};

#endif // !KEY_H
