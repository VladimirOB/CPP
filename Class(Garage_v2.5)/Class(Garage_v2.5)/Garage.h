#pragma once
#include "Cars.h"
class Garage
{
	Cars** Car; // массив машин.
	unsigned MaxSize;
	unsigned CurrentSize;
public:

	Garage();
	~Garage();
	void  AddCar(Cars* car);
	void Print();
	bool DeleteCarUser(int index, const char* login);
	void DeleteCarUserAll(const char* login);
	bool DeleteCarAdmin(int index);
	bool Remove(unsigned index);
	bool SaveCars();
	bool LoadCars(FILE* file_r);
	
};

