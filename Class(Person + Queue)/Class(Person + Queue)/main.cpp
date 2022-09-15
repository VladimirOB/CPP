#include "pch.h"
#include "Person.h"
#include "Worker.h"
#include "Manager.h"
#include "FreeLancer.h"
#include "Staff.h"
#include "Queue.h"


int main()
{
	Staff staff(20);
	staff.Add(new Manager(1200, 500, 07, 1234));
	staff.Add(new FreeLancer(10, 8));
	staff.Print();
	cout << "All Salary: " << staff.GetS() << endl;

	/*Queue queue(10);
	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);
	queue.Enqueue(4);
	int res =  queue.Dequeue();
	queue.Print();
	cout << "res = " << res << endl;
	int show = queue.Show();
	cout << "Show = " << show << endl;*/

	return 0;
}