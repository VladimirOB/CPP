#include "Alternation.h"
#include "Ticket.h"
bool Alternation::isLucky(Ticket& ticket)
{
	if (ticket[0] == ticket[2] && ticket[2] == ticket[4] && ticket[1] == ticket[3] && ticket[3] == ticket[5])
		return true;
	else return false;
}