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

bool Cars::Save(FILE* file_w)
{
	if (file_w != NULL)
	{
		fprintf(file_w, "%s %s %d %s\n", Brand, Model, MaxSpeed, Name);
		return true;
	}
	else return false;
}

void Cars::Print()
{
	cout << "Brand: " << Brand << endl;
	cout << "Model: " << Model << endl;
	cout << "MaxSpeed: " << MaxSpeed << endl;
	cout << "Owner: " << Name << endl;
}