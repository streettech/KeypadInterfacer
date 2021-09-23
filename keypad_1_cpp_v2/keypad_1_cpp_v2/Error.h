#pragma once
#ifndef ERROR_H
#define ERROR_H

#include "Helper.h"

enum class ErrorType {
	NONE = 0,
	SYSTEMSETERROR, SYSTEMGETERROR,
	SERIALOPENERROR, SERIALCLOSEERROR, SERIALPARAMERROR, SERIALREADERROR,
};

enum ErrorCat {
	NONE = 0,
	SYSTEMERRORCAT = BIT(0),
	SERIALERRORCAT = BIT(1)
};

#define ERROR_CLASS_TYPE(type) static ErrorType GetStaticType() {return ErrorType::type;}\
																virtual ErrorType GetErrorType() const override {return GetStaticType();}\
																virtual const char* GetErrorName() const ovveride {return #type;}
#define ERROR_CLASS_CAT(cat) virtual int GetCatFlags() const override {return cat;}

class Error {
public:
	Error();
	virtual ErrorType GetErrorType() const = 0;
	virtual int GetCatFlags() const = 0;

	inline bool IsInCat(ErrorCat cat) {
		return GetCatFlags() & cat;
	}
private:
	char* errorcode;
};

class ErrorHandler {
public:
	ErrorHandler();
};

#endif // !ERROR_H

