#include <iostream>
using namespace std;
#include "Person.h"
#include "Staff.h"
#include "Worker.h"
#include "FreeLancer.h"
int main()
{
	Staff staff(20);
	staff.Add(new Worker(1200, 777));
	staff.Add(new FreeLancer(100, 8));
	staff.Print();
	cout << "Salary = " << staff.GetS();
	return 0;
}