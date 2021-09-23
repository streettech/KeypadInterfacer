#pragma once
#ifndef RTMODULE_H
#define RTMODULE_H

#include <Windows.h>
#include <iostream>

class RTModule {
public:
	bool isconnected;

	RTModule();
	~RTModule();
	void begin(char* portname);
private:
	HANDLE hcomm;
};

#endif // !RTMODULE_H

