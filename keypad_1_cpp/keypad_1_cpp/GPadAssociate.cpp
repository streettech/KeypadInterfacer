#include "srcHeaders/GPadAssociate.h"

char output[MAX_DATA_LENGTH];
char port [] = "\\\\.\\COM3";
char incoming[MAX_DATA_LENGTH];
bool isboard = false;  // has board been recognized
char version[6];
string hello = "hello";

int main() {
	for (int i = 0; i < 6; i++) {
		version[i] = '#';
	}
	SerialPort device(port);
	if (device.isConnected()) {
		cout << "Connection Established";
		char* charArray = new char[hello.size() + 1];
		copy(hello.begin(), hello.end(), charArray);
		charArray[hello.size()] = '\n';
		device.writeSerialPort(charArray, MAX_DATA_LENGTH);
		while (!isboard) {
			// check the serial for board hello
			char ini = '<';  // openning parameter
			char end = '>';  // closing parameter
			int buff = 0;
			device.readSerialPort(output, MAX_DATA_LENGTH);
			for (int i = 0; i < MAX_DATA_LENGTH; i++) {
				if (output[i] == ini) {
					buff = i;
					break;
				}
			}
			int i = 0;
			buff++;
			while (output[buff] != end) {
				version[i++] = output[buff++];
				if (output[buff + 1] == end)
					isboard = true;
			}
		}
	}
	else {
		cout << "Error in port name";
	}
	while (device.isConnected()) {

		device.readSerialPort(output, MAX_DATA_LENGTH);
		cout << output;
		string command;
		cin >> command;
		char* charArray = new char[command.size() + 1];
		copy(command.begin(), command.end(), charArray);
		charArray[command.size()] = '\n';

		device.writeSerialPort(charArray, MAX_DATA_LENGTH);
		delete[] charArray;

		/*
		string command;
		cin >> command;
		char* charArray = new char[command.size() + 1];
		copy(command.begin(), command.end(), charArray);
		charArray[command.size()] = '\n';

		device.writeSerialPort(charArray, MAX_DATA_LENGTH);
		device.readSerialPort(output, MAX_DATA_LENGTH);

		cout << output;

		delete[] charArray;
		*/
	}
	return 0;
}
