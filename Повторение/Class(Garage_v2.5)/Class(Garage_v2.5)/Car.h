#pragma once
class Car
{
	char* Owner;
	char* Brand;
	char* Model;
	unsigned Year;
	unsigned Mileage;
	unsigned EnginePower;
public:
	Car(const char* owner, const char* brand, const char* model, unsigned year, unsigned mileage, unsigned enginePower);
	virtual ~Car();
	void Print();
	char* GetOwner();
	char* GetBrand();
	char* GetModel();
	unsigned GetPhoneNumber();
	unsigned GetYear();
	unsigned GetMileage();
	unsigned GetEnginePower();
};

