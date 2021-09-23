#pragma once
#ifndef KEY_EVENTS_H
#define KEY_EVENTS_H

#include "Event.h"

class KeyPressedEvent : public Event {
public:
	KeyPressedEvent() = default;

	EVENT_CLASS_TYPE(KEYPRESSED)
	EVENT_CLASS_CAT(KEYEVENTCAT)
private:

};

class KeyReleasedEvent : public Event {
public:
	KeyReleasedEvent() = default;

	EVENT_CLASS_TYPE(KEYRELEASED)
	EVENT_CLASS_CAT(KEYEVENTCAT)
private:
};

class KeyLongPressedEvent : public Event {
public:
	KeyLongPressedEvent() = default;

	EVENT_CLASS_TYPE(KEYLONGPRESSED)
	EVENT_CLASS_CAT(KEYEVENTCAT)
private:
};

class KeyOverPressed : public Event {
public:
	KeyOverPressed() = default;

	EVENT_CLASS_TYPE(KEYOVERPRESSED)
	EVENT_CLASS_CAT(KEYEVENTCAT)
private:
};

#endif // !KEY_EVENTS_H