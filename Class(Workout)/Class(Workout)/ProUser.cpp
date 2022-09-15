#include "ProUser.h"
ProUser::ProUser(const char* login, const char* password) : Users(login, password)
{
	Flag = 3;
}
ProUser::~ProUser()
{

}
int ProUser::GetFlag()
{
	return Flag;
}

void ProUser::SetFlag(unsigned flag)
{
	Flag = flag;
}