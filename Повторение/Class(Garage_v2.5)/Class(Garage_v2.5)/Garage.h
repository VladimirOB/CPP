#pragma once
#include "Car.h"
#include <iostream>
#include <fstream> // для работы с файловыми потоками
using namespace std;
class Garage
{
	Car** car;
	size_t CurrentSize;
	size_t MaxSize;
public:
	Garage();
	~Garage();
	void AddCar(Car* car);
	void Print();
	bool DeleteCarUser(int index, const char* login);
	void DeleteCarUserAll(const char* login);
	bool DeleteCarAdmin(int index);
	bool Remove(int index);
	bool SaveCars();
	bool LoadCars(ifstream& file);

};

