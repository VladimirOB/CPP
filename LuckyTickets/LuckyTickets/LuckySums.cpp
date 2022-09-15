#include "LuckySums.h"
#include "Ticket.h"

bool LuckySums::isLucky(Ticket& ticket)
{
	unsigned sum = 0, sum1 = 0, count = Ticket::NUMBERS_COUNT;

	for (unsigned i = 0; i < count / 2; ++i)
	{
		sum += ticket[i];
	}
	for (unsigned i = count / 2; i < count; ++i)
	{
		sum1 += ticket[i];
	}
	if (sum == sum1)
		return true;
	else return false;
}