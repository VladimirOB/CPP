#include <iostream>
using namespace std;

int main() 
{
	cout << "Task 1" << endl;
   int a, b, c, d, sum = 0;
   cout << "Enter a:";
   cin >> a;
   cout << "Enter b:";
   cin >> b;
   cout << "Enter c:";
   cin >> c;
   cout << "Enter d:";
   cin >> d;
   if (a>b || c > b || c>d || a>d)
	   cout << "Ranges don't intersect" << endl;
   else
   {
if (c>a && d > b) if
			for (int i = c; i <= b; i++)
		   {
			   sum += i;
			   cout << i << endl;
		   }
		 if (b > d && a >c)
		   for (int i = a; i <= d; i++)
		   {
			  sum += i;
			   cout << i << endl;
		   }
			 if (b > d && c>a)
		   for (int i = c; i <= d; i++)
		   {
			   sum += i;
			   cout << i << endl;
		   }
		 if (d > b && a>c)
		   for (int i = a; i <= b; i++)
		   {
			   sum += i;
			   cout << i << endl;
		   }
		    cout << "Sum =" << sum << endl;
   }

}