#pragma once
#include "LuckyCriteria.h"

class Ascending : public LuckyCriteria
{
public:
	bool isLucky(Ticket& ticket) override; // override говорит о переопределении вирт функции
};

