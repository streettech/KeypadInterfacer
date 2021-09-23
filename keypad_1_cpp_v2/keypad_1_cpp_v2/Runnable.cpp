#include "Runnable.h"
#include <iostream>

Runnable::Runnable() {
	isrunning = false;
}

Runnable::~Runnable() {

}

bool Runnable::init() {
	static bool oldisrunning = true;
	this->isrunning = true;
	return true;
}

void Runnable::begin() {
	// items to run once at start of run sequence
	char comm[] = "\\\\.\\COM3";
	rt.begin(comm);
}

void Runnable::update() {
	// items to run each cycle of the run sequence
}

void Runnable::updatemAll() {
	// member items updated during run
	char g;
	std::cin >> g;
	if (g == 'q') {
		isrunning = false;
	}
}

void Runnable::run() {
	begin();
	while (isrunning) {
		update();
		updatemAll();
	}
}