#pragma once
#include "LuckyCriteria.h"
class Descending : public LuckyCriteria
{

public:
	bool isLucky(Ticket& ticket) override; // override ������� � ��������������� ���� �������
};

