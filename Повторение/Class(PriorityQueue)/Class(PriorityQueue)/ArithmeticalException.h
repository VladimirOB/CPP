#pragma once
class ArithmeticalException
{
	int ErrorCode;
	char massage[123];
public:
	ArithmeticalException(const int code, const char* massage);
	void Print();
};

