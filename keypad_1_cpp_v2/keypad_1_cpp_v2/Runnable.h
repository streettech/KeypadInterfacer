#pragma once
#ifndef RUNNABLE_H
#define RUNNABLE_H

#include "Event.h"
#include "RTModule.h"

class Runnable {
public:
	RTModule rt;

	Runnable();
	~Runnable();
	bool init();
	void begin();
	void update();
	void updatemAll();
	void run();
private:
	bool isrunning;
};

#endif // !RUNNABLE_H

