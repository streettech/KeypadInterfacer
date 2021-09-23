#pragma once
#include "GLibs.h"

struct TSEC {
	std::time_t timer = std::time(nullptr);
};

class Runnable {
public:
	unsigned long int starttime;
	unsigned long int nowtime;
	unsigned long int runtimer;

	Runnable();
	void init();
	void run();
	void priorityRun();
	void updateRunTimer();
};
