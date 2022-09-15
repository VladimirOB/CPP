#pragma once
#include "Cars.h"
class Garage
{
	Cars** Car; // массив машин.
	unsigned MaxSize;
	unsigned CurrentSize;
public:

	Garage(size_t size);
	~Garage();
	void  AddCar(Cars* car);
	void Print();
	Garage& DeleteCarUser(int index, const char* login);
	Garage& DeleteCarUserAll(const char* login);
	Garage& DeleteCarAdmin(int index);
	Garage& Remove(unsigned index);
	bool SaveCars();
	bool LoadCars();
	
};

