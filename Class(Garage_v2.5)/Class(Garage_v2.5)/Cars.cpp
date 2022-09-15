#include "Cars.h"
#include "pch.h"

Cars::Cars(const char* brand, const char* model, const char* name, unsigned maxSpeed)
{
	Brand = new char[strlen(brand) + 1];
	strcpy(Brand, brand);
	Model = new char[strlen(model) + 1];
	strcpy(Model, model);
	Name = new char[strlen(name) + 1];
	strcpy(Name, name);

	MaxSpeed = maxSpeed;
}

Cars::~Cars()
{
	delete[] Brand;
	delete[] Model;
	delete[] Name;
}

char* Cars::GetLogin()
{
	return Name;
}


char* Cars::GetBrand()
{
	return Brand;
}
char* Cars::GetModel()
{
	return Model;
}

unsigned Cars::GetMaxSpeed()
{
	return MaxSpeed;
}

void Cars::Print()
{
	cout << "Brand: " << Brand << endl;
	cout << "Model: " << Model << endl;
	cout << "MaxSpeed: " << MaxSpeed << endl;
	cout << "Owner: " << Name << endl;
}