#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"
#include <iostream>
using namespace std;

Car::Car(const char* owner, const char* brand, const char* model, unsigned year, unsigned mileage, unsigned enginePower)
{
	Brand = new char[strlen(brand) + 1];
	strcpy(Brand, brand);
	Model = new char[strlen(model) + 1];
	strcpy(Model, model);
	Owner = new char[strlen(owner) + 1];
	strcpy(Owner, owner);
	Year = year;
	Mileage = mileage;
	EnginePower = enginePower;
}

Car::~Car()
{
	delete[] Brand, Model, Owner;
}

char* Car::GetOwner()
{
	return Owner;
}


char* Car::GetBrand()
{
	return Brand;
}
char* Car::GetModel()
{
	return Model;
}

unsigned Car::GetYear()
{
	return Year;
}
unsigned Car::GetMileage() 
{
	return Mileage;
}

unsigned Car::GetEnginePower()
{
	return EnginePower;
}

void Car::Print()
{
	cout << "Owner: " << Owner << endl;
	cout << "Brand: " << Brand << endl;
	cout << "Model: " << Model << endl;
	cout << "Year: " << Year << endl;
	cout << "Mileage: " << Mileage << endl;
	cout << "EnginePower: " << EnginePower << endl;
}