#include "pch.h"
#include "DoubleLinkedList.h"

int main(void)
{
	DoubleLinkedList list;
	list.Add("big");
	list.Add("debug");
	list.Add("lector");
	list.Add("hour");
	list.Add("queue");
	list.Add("aloha");
	list.Add("integral");
	list.Add("zero");
	list.Add("keep");
	list.Add("joba");
	list.Add("apple");
	list.Add("sorting");
	list.Add("wow");
	list.Add("going");
	list.Add("end");
	list.Add("point");
	

	//list.Sort(); // � ������ ������� � ������� �������� F11 ���� ����� ������ 2 ������ 24���
	list.InsertionSort(); // � ������ ������� � ������� �������� F11 ���� ����� ������ 23.8���
	cout << list << endl;
	cout << "Time = " << (clock() / 10000.0) << endl;

}

