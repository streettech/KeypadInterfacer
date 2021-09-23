#include "Runnable.h"

Runnable::Runnable() {
	starttime = 0;
	nowtime = 0;
	runtimer = 0;
}

void Runnable::init() {
	TSEC mtime;
	starttime = mtime.timer;
}

void Runnable::updateRunTimer() {
	TSEC mtime;
	nowtime = mtime.timer;
	runtimer = nowtime - starttime;
}

void Runnable::run() {
	updateRunTimer();
}

void Runnable::priorityRun() {

}