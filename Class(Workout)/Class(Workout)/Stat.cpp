#include "Stat.h"
#include "pch.h"
Stat::Stat(const char* login, unsigned year, unsigned month, unsigned day, unsigned hour, unsigned min, unsigned podhod, unsigned summ)
{
	Login = new char[strlen(login) + 1];
	strcpy(Login, login);
	Year = year;
	Month = month;
	Day = day;
	Hour = hour;
	Min = min;
	Podhod = podhod;
	Summ = summ;
}

Stat::~Stat()
{
	delete[] Login;
}

char* Stat::GetLogin()
{
	return Login;
}

int Stat::GetYear()
{
	return Year;
}
int Stat::GetMonth()
{
	return Month;
}
int Stat::GetDay()
{
	return Day;
}

int Stat::GetHour()
{
	return Hour;
}
int Stat::GetMin()
{
	return Min;
}

int Stat::GetPodhod()
{
	return Podhod;
}
int Stat::GetSumm()
{
	return Summ;
}

void Stat::Print()
{
	if(Min < 10)
	cout <<"Тренировка была: " << Year << ".0" << Month <<"."<< Day << " в " << Hour << ":0" << Min << endl;
	else
	cout << "Тренировка была: " << Year << ".0" << Month << "." << Day << " в " << Hour << ":" << Min << endl;
	cout << "Количество подходов: " << Podhod << endl;
	cout << "Сумма отжиманий: " << Summ << endl << endl;
}