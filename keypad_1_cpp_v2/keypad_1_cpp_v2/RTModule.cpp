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

int RTModule::readport(char* buffer, uint buffersize) {
    DWORD byteread;
    uint toread = 0;

    ClearCommError(this->hcomm, &this->error, &this->status);

    if (this->status.cbInQue > 0) {
        if (this->status.cbInQue > buffersize) {
            toread = buffersize;
        }
        else toread = this->status.cbInQue;
    }

    if (ReadFile(this->hcomm, buffer, toread, &byteread, NULL)) return byteread;

    return 0;
}

bool RTModule::writeport(char* buffer, uint buffersize) {
    DWORD bytewrite;

    if (!WriteFile(this->hcomm, (void*)buffer, buffersize, &bytewrite, 0)) {
        ClearCommError(this->hcomm, &this->error, &this->status);
        return false;
    }

    return true;
}