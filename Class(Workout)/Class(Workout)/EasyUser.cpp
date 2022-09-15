#include "EasyUser.h"

EasyUser::EasyUser(const char* login, const char* password) : Users(login, password)
{
	Flag = 1;
}
EasyUser::~EasyUser()
{

}
int EasyUser::GetFlag()
{
	return Flag;
}

void EasyUser::SetFlag(unsigned flag)
{
	Flag = flag;
}