#include "Key.h"

Key::Key() {
	kchar = EMPTY;
	kIndentifier = identifier+1;
	kstate = IDLE;
	stateChanged = false;
	identifier++;
}

Key::Key(char mkey) {
	this->kchar = mkey;
	kIndentifier = identifier+1;
	kstate = IDLE;
	stateChanged = false;
	identifier++;
}

Key::~Key() {
	identifier--;
}

void Key::setKey(char mkey) {
	this->kchar = mkey;
}

void Key::updateState(bool mstateChanged) {
	this->stateChanged = mstateChanged;
}