#include "Garage.h"
#include "Users.h"
#include "pch.h"
Garage::Garage()
{
	FILE* file_r = fopen("db_garage.txt", "r");
	if (file_r != NULL)
	{
		LoadCars(file_r);
		fclose(file_r);
	}
	else
	{
		MaxSize = 5;
		CurrentSize = 0;
		Car = new Cars * [MaxSize];
	}
	
}


Garage::~Garage()
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		delete[] Car[i];
	}
	delete[] Car;
}

void Garage::AddCar(Cars* car)
{
	if (CurrentSize < MaxSize)
	{
		Car[CurrentSize++] = car;
	}
	else
	{
		size_t new_size = MaxSize + 3;
		//cout << "Resize garage." << endl;
		Cars** new_car = new Cars*[new_size];
		size_t i = 0;
		for (; i < CurrentSize; i++)
		{
			new_car[i] = Car[i];
		}

		new_car[i] = car;
		delete[] Car;
		Car = new_car;
		MaxSize = new_size;
		CurrentSize++;
	}
}

bool Garage::DeleteCarUser(int index, const char* login) // удаление авто пользователя по индексу 
{
	if (index >= 0 && index < CurrentSize && strcmp(login, Car[index]->GetLogin()) == 0)
	{
		delete Car[index];
		for (size_t i = index; i < CurrentSize; i++)
		{
			Car[i] = Car[i + 1];
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
bool Garage::Remove(unsigned index)
{
	if (index >= 0 && index < CurrentSize)
	{
		delete Car[index];

		for (size_t i = index; i < CurrentSize; i++)
		{
			Car[i] = Car[i + 1];
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

void Garage::DeleteCarUserAll(const char* login) // удаление всех авто пользователя
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		if (strcmp(login, Car[i]->GetLogin()) == 0)
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
		delete Car[index];
		for (size_t i = index; i < CurrentSize; i++)
		{
			Car[i] = Car[i + 1];
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
	FILE* file_w = fopen("db_garage.txt", "w");
	if (file_w != NULL)
	{
		for (size_t i = 0; i < CurrentSize; i++)
		{
			fprintf(file_w, "%s %s %d %s\n", Car[i]->GetBrand(), Car[i]->GetModel(), Car[i]->GetMaxSpeed(), Car[i]->GetLogin());
		}
		fclose(file_w);
		return true;
	}
	else
	{
		throw exception("Error");
		return false;
	}
}

bool Garage::LoadCars(FILE* file_r)
{
	if (file_r != NULL)
	{
		// удаляем машины в наличии.
		for (size_t i = 0; i < CurrentSize; i++)
		{
			delete[] Car[i];
		}

		CurrentSize = 0;
		while (!feof(file_r))
		{
			char brand[40] = "";
			char model[40] = "";
			char login[40] = "";
			unsigned maxSpeed;

			int res = fscanf(file_r, "%s %s %d %s", brand, model, &maxSpeed, login);
			if (strlen(brand) > 0 && strlen(model) > 0 && strlen(login) > 0)
			{
				Cars* new_car = new Cars(brand, model, login, maxSpeed);
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
		Car[i]->Print();
		cout << endl;
	}
}