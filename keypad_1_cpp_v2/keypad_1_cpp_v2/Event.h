#pragma once
#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include "Helper.h"

enum class EventType {
	NONE = 0,
	KEYPRESSED, KEYRELEASED, KEYLONGPRESSED, KEYOVERPRESSED,
	NEWDEVICE, DEVICECONNECTED, DEVICEDISCONNECTED,
	DATASAVE, DATALOAD
};

enum EventCat {
	NONE = 0,
	KEYEVENTCAT = BIT(0),
	DEVICEEVENTCAT = BIT(0),
	DATAEVENTCAT = BIT(2)
};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::type;}\
																virtual EventType GetEventType() const override {return GetStaticType();}\
																virtual const char* GetEventName() const override {return #type;}
#define EVENT_CLASS_CAT(cat) virtual int GetCatFlags() const override {return cat;}

class Event {
public:
	bool m_Handled;

	Event();
	virtual EventType GetEventType() const = 0;
	virtual const char* GetEventName() const = 0;
	virtual int GetCatFlags() const = 0;
	virtual std::string ToString() const { return GetEventName();}

	inline bool IsInCat(EventCat cat) {
		return GetCatFlags() & cat;
	}
};

class EventDispatcher {
public:
	EventDispatcher(Event& event) : m_Event(event) {}
	template<typename T, typename F>
	bool Dispatch(const F& f) {
		if (m_Event.GetEventType() == T::GetStaticType()) {
			m_Event.m_Handled |= f(static_cast<T&>(m_Event));
			return true;
		}
		return false;
	}
private:
	Event& m_Event;
};

inline std::ostream& operator<<(std::ostream& os, const Event& e) {return os << e.ToString();}

#endif // !EVENT_H