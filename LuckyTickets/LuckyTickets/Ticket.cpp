#include "Ticket.h"
#include "pch.h"

Ticket::Ticket()
{
	this->numbers = new unsigned[Ticket::NUMBERS_COUNT];
	for (int i = 0; i < Ticket::NUMBERS_COUNT; ++i)
	{
		this->numbers[i] = 0;
	}
}

Ticket::Ticket(int num)
{
	this->numbers = new unsigned[Ticket::NUMBERS_COUNT];
	string buffer = to_string(num);
	for (size_t i = 0; i < Ticket::NUMBERS_COUNT; i++)
	{
		this->numbers[i] = buffer[i]-48;
	}
}

Ticket::~Ticket()
{
	delete[] this->numbers;
}

void Ticket::generateNumbers(int num)
{
	// мат  = 0.06565
	// to_string = 0.08038
	// _itoa = 0.06845

	/*this->numbers[0] = (num / 100000) % 10;
	this->numbers[1] = (num / 10000) % 10;
	this->numbers[2] = (num / 1000) % 10;
	this->numbers[3] = (num / 100) % 10;
	this->numbers[4] = (num / 10) % 10;
	this->numbers[5] = num % 10;*/


	/*string buffer = to_string(num);
	for (int i = 0; i < Ticket::NUMBERS_COUNT; i++)
	{
		this->numbers[i] = buffer[i]-48;
	}*/
	
	char buffer[25];
	_itoa(num, buffer, 10);
	for (int i = 0; i < Ticket::NUMBERS_COUNT; i++)
	{
		this->numbers[i] = buffer[i] - 48;
	}
}

void Ticket::Print()
{
	for (int i = 0; i < Ticket::NUMBERS_COUNT; ++i)
	{
		cout << this->numbers[i];
	}
	cout << endl;
}

bool Ticket::isLucky(list<luckyFunctions> functions)
{
	for (auto & functions : functions)
	{
		if (functions(this->numbers)) 
			return true;
	}
	return false;
}


bool Ticket::isLucky(list<LuckyCriteria*> criteria)
{
	for (auto& criterion : criteria)
	{
		if (criterion->isLucky(*this)) return true;
	}
	return false;
}

bool Ticket::IsLucky(list<function<bool(const unsigned*)>> lambdas)
{
	for (auto& function : lambdas)
	{
		if (function(this->numbers))
			return true;
	}
	return false;
}

void Ticket::save(ofstream& fileStream)
{
	for (int i = 0; i < Ticket::NUMBERS_COUNT; ++i) {
		fileStream << this->numbers[i];
	}
	fileStream << endl;
}

unsigned Ticket::operator[](const unsigned int& i) {
	if (i >= 0 && i < Ticket::NUMBERS_COUNT)
		return this->numbers[i];
	else throw exception("Invalid index!");
}