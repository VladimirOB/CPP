#pragma once
#include "LuckyCriteria.h"
class Alternation : public LuckyCriteria
{
public:
	bool isLucky(Ticket& ticket) override; // override ������� � ��������������� ���� �������
};

