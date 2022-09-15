#pragma once
#include "pch.h"
class Cars
{
protected:
	char* Brand;
	char* Model;
	char* Name;
	unsigned MaxSpeed;

public:
	Cars(const char* brand, const char* model, const char* name, unsigned maxSpeed);
	virtual ~Cars();
	void Print();
	bool Save(FILE*);
	char* GetLogin();
};

