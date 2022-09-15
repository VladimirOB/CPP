#pragma once
#include "LuckyCriteria.h"

class LuckySums : public LuckyCriteria
{

public:

	bool isLucky(Ticket& ticket) override; // override говорит о переопределении вирт функции
};

