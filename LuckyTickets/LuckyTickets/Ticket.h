#pragma once
#include "pch.h"
#include "LuckyCriteria.h"

class Ticket
{
	unsigned* numbers;
public:
	typedef bool (*luckyFunctions)(const unsigned*);
	static const unsigned NUMBERS_COUNT = 6;
	Ticket();
	Ticket(int numbers);
	~Ticket();
	void generateNumbers(int num);
	void Print();

	bool isLucky(list<luckyFunctions>);

	bool isLucky(list<LuckyCriteria* > criteria);

	bool IsLucky(list<function<bool(const unsigned*)>> lambdas);

	void save(ofstream& fileStream);

	unsigned operator[] (const unsigned& i);
};

