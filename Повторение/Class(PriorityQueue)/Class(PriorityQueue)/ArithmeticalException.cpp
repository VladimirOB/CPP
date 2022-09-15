#include "ArithmeticalException.h"
#include "pch.h"

ArithmeticalException::ArithmeticalException(const int code, const char* massage)
{
	ErrorCode = code;
		strncpy(this->massage, massage, 122);
}

void ArithmeticalException::Print()
{
	cout << "Error: " << massage << ", Code: " << ErrorCode << endl;
}
