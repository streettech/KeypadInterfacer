#include "Key.h"

Key::Key() {
	kchar = EMPTY;
	kstate = IDLE;
	kstateChanged = false;
	kidentifier = ++identifier;
}

Key::Key(char mkey) {
	this->kchar = mkey;
	kstate = IDLE;
	this->kstateChanged = false;
	kidentifier = ++identifier;
}

void Key::setKey(char mkey) {
	this->kchar = mkey;
}

void Key::updateState(KEYSTATE mstate, bool mstateChanged) {
	this->kstate = mstate;
	this->kstateChanged = mstateChanged;
}

int Key::getKidentifier() {
	return kidentifier;
}