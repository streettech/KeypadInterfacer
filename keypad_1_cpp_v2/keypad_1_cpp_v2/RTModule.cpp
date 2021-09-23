#include "RTModule.h"

RTModule::RTModule() {
    isconnected = false;
}

RTModule::~RTModule() {
    if (isconnected) {
        CloseHandle(hcomm);
        this->isconnected = false;
        std::cout << "Serial port closed" << "\n";
    }
}

void RTModule::begin(char* portname) {
	this->hcomm = CreateFileA(static_cast<LPCSTR>(portname),
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		0,
		NULL);
	if (hcomm == INVALID_HANDLE_VALUE)
		std::cout << "Error openning serial port" << "\n";
	else {
		std::cout << "Serial port successfully openned" << "\n";

        DCB dcbSerialParameters = { 0 };

        if (!GetCommState(hcomm, &dcbSerialParameters)) {
            printf("failed to get current serial parameters");
        }
        else {
            dcbSerialParameters.BaudRate = CBR_115200;
            dcbSerialParameters.ByteSize = 8;
            dcbSerialParameters.StopBits = ONESTOPBIT;
            dcbSerialParameters.Parity = NOPARITY;
            dcbSerialParameters.fDtrControl = DTR_CONTROL_ENABLE;

            if (!SetCommState(hcomm, &dcbSerialParameters))
            {
                printf("ALERT: could not set Serial port parameters\n");
            }
            else {
                this->isconnected = true;
                PurgeComm(this->hcomm, PURGE_RXCLEAR | PURGE_TXCLEAR);
                Sleep(1000);
            }
        }
	}
}