#pragma once
#include "LuckyCriteria.h"
class Alternation : public LuckyCriteria
{
public:
	bool isLucky(Ticket& ticket) override; // override говорит о переопределении вирт функции
};

