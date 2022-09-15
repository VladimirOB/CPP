#include "Garage.h"
#include "Users.h"
#include <iostream>
#include <fstream> // для работы с файловыми потоками
using namespace std;
Garage::Garage()
{
	ifstream file("db_garage.txt", ios::in);

	if (!file.fail())
	{
		LoadCars(file);
		file.close();
	}
	else
	{
		MaxSize = 5;
		CurrentSize = 0;
		car = new Car * [MaxSize];
	}
}

Garage::~Garage()
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		delete[] car[i];
	}
	delete[] car;
}

void Garage::AddCar(Car* car)
{
	if (CurrentSize < MaxSize)
	{
		this->car[CurrentSize++] = car;
	}
	else
	{
		size_t new_size = MaxSize + 3;
		Car** new_car = new Car * [new_size];
		size_t i = 0;
		for (; i < CurrentSize; i++)
		{
			new_car[i] = this->car[i];
		}
		new_car[i] = car;
		delete[] this->car;
		this->car = new_car;
		MaxSize = new_size;
		CurrentSize++;
	}
}

bool Garage::DeleteCarUser(int index, const char* login) // уд. авто по логину
{
	if (index >= 0 && index << CurrentSize && strcmp(login, this->car[index]->GetOwner()) == 0)
	{
		delete this->car[index];
		for (size_t i = index; i < CurrentSize; i++)
		{
			car[i] = car[i + 1]; // смещение.
		}
		CurrentSize--;
		return true;
	}
	else
	{
		cout << "Car ID not found!" << endl;
		return false;
	}
}

bool Garage::Remove(int index) // для DeleteCarUserAll
{
	if (index >= 0 && index < CurrentSize)
	{
		delete car[index];
		for (size_t i = index; i < CurrentSize; i++)
		{
			car[i] = car[i + 1];
		}

		CurrentSize--;
		return true;
	}
	else
	{
		throw exception("Error");
		return false;
	}
}

void Garage::DeleteCarUserAll(const char* login)
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		if (strcmp(login, car[i]->GetOwner()) == 0)
		{
			Remove(i);
			i--;
		}
	}
}

bool Garage::DeleteCarAdmin(int index)
{
	if (index >= 0 && index < CurrentSize)
	{
		delete car[index];
		for (size_t i = 0; i < CurrentSize; i++)
		{
			car[i] = car[i + 1];
		}
		CurrentSize--;
		return true;
	}
	else
		cout << "Car not found!" << endl;
	return false;
}


bool Garage::SaveCars()
{
	ofstream file("db_garage.txt", ios::out);
	if (!file.fail())
	{
		for (size_t i = 0; i < CurrentSize; i++)
		{
			file << car[i]->GetOwner() << " " << car[i]->GetBrand() << " " << car[i]->GetModel() << " " << car[i]->GetYear() << " " << car[i]->GetMileage() << " " << car[i]->GetEnginePower() << "\n";
		}
		file.close();
		return true;
	}
	else
	{
		throw exception("Error");
		return false;
	}
	return false;
}
bool Garage::LoadCars(ifstream& file)
{
	if (!file.fail())
	{
		for (size_t i = 0; i < CurrentSize; i++)
		{
			delete[] car[i];
		}
		CurrentSize = 0;

		while (!file.eof())
		{
			char owner[40] = "", brand[40] = "", model[40] = "";
			unsigned  year, mileage, enginePower;

			file >> owner >> brand >> model  >> year >> mileage >> enginePower;

			if (strlen(brand) > 0 && strlen(model) > 0 && strlen(owner) > 0)
			{
				Car* new_car = new Car(owner, brand, model, year, mileage, enginePower);
				AddCar(new_car);
			}
		}
		return true;
	}
	else
	{
		throw exception("Error");
		return false;
	}
}

void Garage::Print()
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		cout << "Car ID: " << i << endl;
		car[i]->Print();
		cout << endl;
	}
}