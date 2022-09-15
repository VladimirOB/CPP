#include "pch.h"
#include "Garage.h"
#include "Cars.h"
#include "Users.h"
#include "SimpleUser.h"
#include "ArrUser.h"
#include "Admin.h"
int main(void)
{
	ArrUser user(5);
	Garage garage(5);
	if (!user.LoadUsers()) // если файл не найден, создать админа.
		user.AddUser(new Admin("admin", "admin"));
	garage.LoadCars(); 
	char login[40], password[40], brand[40], model[40];
	char log[40], pass[40];
	int check = 0, ch=0, index=0, maxSpeed=0;

	while (1)
	{
		if (ch == -2)
		{
			garage.SaveCars();
			user.SaveUsers();
			break;
		}
		while (check == 0)
		{
			ch = 0;
			system("cls");
			cout << "Welcome to application garage!" << endl;
			cout << "Default log/pass *admin* *admin*" << endl;

			cout << "Enter login: " << endl;
			cin >> login;
			cout << "Enter password: " << endl;
			cin >> password;

			if (user.CheckUser(login, password) == 0)
			{
				cout << "Wrong login or password! Try again." << endl;
				system("pause");

			}
			else if (user.CheckUser(login, password) == 1)
			{
				check = 1; // simple
				break;

			}
			else if (user.CheckUser(login, password) == 2)
			{
				check = 2; // admin
				break;
			}

		}
		
		if (check == 1) // simple
		{
			while (true)
			{
				if (ch == -1 || ch == -2)
					break;
				system("cls");
				cout << "Hello " << login << "!" << endl << endl;
				user.SimpleUserMenu();
				cin >> ch;
				if (ch < 0 || ch > 5)
				{
					cout << "Error choise!" << endl;
					system("pause");
					continue;
				}
				switch (ch)
				{
					case 1:
					{
						cout << "Brand: ";
						cin >> brand;
						cout << "Model: ";
						cin >> model;
						cout << "maxSpeed: ";
						cin >> maxSpeed;
						garage.AddCar(new Cars(brand, model, login, maxSpeed));
						cout << "Car added." << endl;
						system("pause");
						break;
					}
					case 2:
					{
						garage.Print();
						system("pause");
						break;
					}
					case 3:
					{
						cout << "Enter car id to delete: ";
						cin >> index;
						garage.DeleteCarUser(index, login);
						system("pause");
						break;
					}
					case 4:
					{
						garage.SaveCars();
						ch = -1;
						check = 0;
						break;
					}
					case 5:
					{
						ch = -2;
						break;
					}
				}

			}
		}
		
		if (check == 2) // admin
		{
			while (true)
			{
				if (ch == -1 || ch == -2)
					break;
				system("cls");
				cout << "Hello " << login << "!" << endl << endl;
				user.AdminMenu();
				cin >> ch;
				if (ch < 0 || ch > 8)
				{
					cout << "Error choise!" << endl;
					system("pause");
					continue;
				}
				switch (ch)
				{
					case 1:
					{
						cout << "Brand: ";
						cin >> brand;
						cout << "Model: ";
						cin >> model;
						cout << "maxSpeed: ";
						cin >> maxSpeed;
						garage.AddCar(new Cars(brand, model, login, maxSpeed));
						cout << "Car added." << endl;
						system("pause");
						break;
					}
					case 2:
					{
						garage.Print();
						system("pause");
						break;
					}
					

					case 3:
					{
						cout << "Enter car id to delete: ";
						cin >> index;
						garage.DeleteCarAdmin(index);
						system("pause");
						break;
					}
					case 4:
					{
						user.Print();
						system("pause");
						break;
					}
					case 5:
					{	
						int new_user=0;
						cout << "If you want add user press 1" << endl;
						cout << "If you want add admin press 2" << endl;
						cin >> new_user;
						if (new_user < 1 && new_user > 2)
						{
							cout << "Error choise!" << endl;
							break;
						}
						cout << "Enter login: ";
						cin >> log;
						cout << "Enter password: ";
						cin >> pass;
						if (user.CheckLogin(log))
						{
							if (new_user == 1)
								user.AddUser(new SimpleUser(log, pass));
							if(new_user == 2)
								user.AddUser(new Admin(log, pass));
						}
						else
							cout << "This login already exist" << endl;
						system("pause");
						break;
					}
					case 6:
					{
						cout << "Enter login: ";
						cin >> log;
						if (strcmp(log, "admin") == 0)
						{
							cout << "Can't delete master admin!" << endl;
							system("pause");
							break;
						}
						user.DeleteUser(log);
						garage.DeleteCarUserAll(log);
						
						cout << log << " deleted!" << endl;
						system("pause");
						break;
					}
					case 7:
						garage.SaveCars();
						user.SaveUsers();
						ch = -1;
						check = 0;
						break;
					case 8:
						ch = -2;
						break;
				}

			}
		}
	}
}