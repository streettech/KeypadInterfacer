#pragma once
#ifndef RTMODULE_H
#define RTMODULE_H

#include <Windows.h>
#include <iostream>
#include "Helper.h"

class RTModule {
public:
	bool isconnected;

	RTModule();
	~RTModule();
	void begin(char* portname);
	int readport(char* buffer, uint buffersize);
	bool writeport(char* buffer, uint buffersize);
private:
	HANDLE hcomm;
	COMSTAT status;
	DWORD error;
};

#endif // !RTMODULE_H

