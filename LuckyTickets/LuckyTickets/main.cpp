#include "pch.h"
#include "Ticket.h"
#include "LuckySums.h"
#include "Ascending.h"
#include "Descending.h"
#include "Alternation.h"
/*1. Задача о счастливых билетах
Все билеты шестизначные
Номера начинаются с 111111 и заканчиваются 999999
Счастливыми являются следующие паттерны:
123006 - сумма первых 3 чисел равна сумме последних 3 чисел
123456 - номера идут в порядке возрастания
987654 - номера идут в порядке убывания
111111 - все цифры одинаковые <<< бесполезный паттерн.
202020 - цифры чередуются

Задание:
- определить сколько всего счастливых билетов
- сохранить все номера билетов в файл
- при помощи полиморфизма дать возможность пользователям класса добавлять новые паттерны счастливых билетов
- использовать классы коллекций STL и алгоритмы*/

bool luckySum(const unsigned* items)
{
	unsigned sum = 0, sum1 = 0, count = Ticket::NUMBERS_COUNT;

	for (unsigned i = 0; i < count/2; ++i)
	{
		sum += items[i];
	}
	for (unsigned i = count/2; i < count; ++i)
	{
		sum1 += items[i];
	}

	return sum == sum1;
}

bool Ascend(const unsigned* ticket)
{
	for (int i = 0; i < Ticket::NUMBERS_COUNT - 1; ++i)
	{
		if (ticket[i] != ticket[i + 1] + 1) return false;
	}
	return true;
}
	

bool Descend(const unsigned* ticket)
{
	for (int i = 0; i < Ticket::NUMBERS_COUNT - 1; ++i) {
		if (ticket[i] != ticket[i + 1] - 1) return false;
	}
	return true;

}

bool Alternation2(const unsigned* ticket)
{
	if (ticket[0] == ticket[2] && ticket[2] == ticket[4] && ticket[1] == ticket[3] && ticket[3] == ticket[5])
		return true;
	else return false;
}


//auto LuckySum = [](const unsigned* ticket) -> bool
//{
//	unsigned sum = 0, sum1 = 0, count = Ticket::NUMBERS_COUNT;
//
//	for (unsigned i = 0; i < count / 2; ++i)
//	{
//		sum += ticket[i];
//	}
//	for (unsigned i = count / 2; i < count; ++i)
//	{
//		sum1 += ticket[i];
//	}
//	if (sum == sum1)
//		return true;
//	else return false;
//};
//
//
//auto LuckySequence = [](const unsigned* ticket) -> bool
//{
//	for (size_t i = 0; i < Ticket::NUMBERS_COUNT - 1; i++)
//	{
//		if (ticket[i] + 1 != ticket[i + 1])
//			return false;
//	}
//
//	return true;
//};
//
//
//auto LuckyBackSequence = [](const unsigned* ticket) -> bool
//{
//	for (size_t i = 0; i < Ticket::NUMBERS_COUNT - 1; i++)
//	{
//		if (ticket[i] - 1 != ticket[i + 1])
//			return false;
//	}
//	return true;
//};
//
//auto LuckyAlternation = [](const unsigned* ticket) -> bool
//{
//	if (ticket[0] == ticket[2] && ticket[2] == ticket[4] && ticket[1] == ticket[3] && ticket[3] == ticket[5])
//		return true;
//	else return false;
//};
//
//// лямбда
//void main() {
//
//	srand(time(0));
//	list<Ticket*> tickets;
//	list <function<bool(const unsigned*)>> lambdas;
//	unsigned countLuckyTicket = 0;
//	lambdas.push_back(LuckySum);
//	lambdas.push_back(LuckySequence);
//	lambdas.push_back(LuckyBackSequence);
//	lambdas.push_back(LuckyAlternation);
//
//	int i = 111111;
//	while (i != 1000000)
//	{
//		auto* ticket = new Ticket();
//		ticket->generateNumbers(i++);
//
//		if (ticket->IsLucky(lambdas))
//			tickets.push_back(ticket);
//
//		else delete ticket;
//	}
//
//	ofstream dest("resultLambda.txt");
//	if (!dest.fail())
//	{
//		auto iterator = tickets.begin();
//		while (iterator != tickets.end())
//		{
//			//(*iterator)->Print();
//			(**iterator).save(dest);
//			++iterator;
//			countLuckyTicket++;
//		}
//		dest << countLuckyTicket;
//		cout << countLuckyTicket << endl;
//		dest.close();
//	}
//	cout << "Time = " << (clock() / 100000.0) << endl;
//}


//указатели на функции
//int main(void)
//{
//	srand(time(nullptr));
//	unsigned countLuckyTicket = 0;
//	list<Ticket*> tickets;
//	list<Ticket::luckyFunctions> functions;
//
//	functions.push_back(luckySum);
//	functions.push_back(Ascend);
//	functions.push_back(Descend);
//	functions.push_back(Alternation2);
//	int i = 111111;
//	while (i != 1000000)
//	{
//		auto* ticket = new Ticket();
//		ticket->generateNumbers(i++);
//
//		if (ticket->isLucky(functions))
//			tickets.push_back(ticket);
//
//		else delete ticket;
//	}
//
//	ofstream dest("resultPointer.txt");
//	if (!dest.fail())
//	{
//		auto iterator = tickets.begin();
//		while (iterator != tickets.end())
//		{
//			//(*iterator)->Print();
//			(**iterator).save(dest);
//			++iterator;
//			countLuckyTicket++;
//		}
//		dest << countLuckyTicket;
//		cout << countLuckyTicket << endl;
//		dest.close();
//	}
//}


// Полиморфизм
int main(void)
{
	srand(time(nullptr));
	unsigned countLuckyTicket = 0;
	list<Ticket*> tickets;
	list<LuckyCriteria*> criteria;
	criteria.push_back(new LuckySums);
	criteria.push_back(new Ascending);
	criteria.push_back(new Descending);
	criteria.push_back(new Alternation);
	
	for (size_t i = 111111; i < 1000000; i++)
	{
		Ticket* ticket = new Ticket();
		ticket->generateNumbers(i);
		if (ticket->isLucky(criteria))
			tickets.push_back(ticket);
		else delete ticket;
	}
	
	ofstream dest("result.txt");
	if (!dest.fail())
	{
		auto iterator = tickets.begin();
		while (iterator != tickets.end())
		{
			//(*iterator)->Print();
			(**iterator).save(dest);
			++iterator;
			countLuckyTicket++;
		}
		dest << countLuckyTicket;
		cout  << countLuckyTicket << endl;
		dest.close();
	}
}