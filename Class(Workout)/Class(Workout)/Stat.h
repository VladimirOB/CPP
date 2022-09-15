#pragma once
class Stat
{
	char* Login;
	unsigned Year;
	unsigned Month;
	unsigned Day;
	unsigned Hour;
	unsigned Min;
	unsigned Podhod;
	unsigned Summ;

public:
	Stat(const char* login,unsigned year, unsigned month, unsigned day, unsigned hour, unsigned min, unsigned podhod, unsigned summ);
	~Stat();
	char* GetLogin();
	int GetYear();
	int GetMonth();
	int GetDay();
	int GetHour();
	int GetMin();
	int GetPodhod();
	int GetSumm();
	void Print();
};

