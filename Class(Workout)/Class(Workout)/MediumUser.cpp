#include "MediumUser.h"

MediumUser::MediumUser(const char* login, const char* password) : Users(login, password)
{
	Flag = 2;
}
MediumUser::~MediumUser()
{

}
int MediumUser::GetFlag()
{
	return Flag;
}
void MediumUser::SetFlag(unsigned flag)
{
	Flag = flag;
}