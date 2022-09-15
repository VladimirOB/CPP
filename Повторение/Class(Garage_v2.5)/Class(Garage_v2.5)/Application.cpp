#define _CRT_SECURE_NO_WARNINGS
#include "Application.h"
#include "Users.h"
#include "Admin.h"
#include "SimpleUser.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;
Application::Application()
{
	MaxSizeItems = 20;
	CurrentSizeItems = 0;
	Items = new MenuItem * [MaxSizeItems];

	ifstream file("db_users.txt", ios::in);
	if (!file.fail())
	{
		LoadUsers(file);
		file.close();
		garage = new Garage;
	}
	else
	{
		cout << "Users not found!" << endl;
		MaxSize = 10;
		CurrentSize = 0;
		garage = new Garage;
		User = new Users * [MaxSize];
	}
}

Application::~Application()
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		delete[] User[i];
	}
	delete[] User;
	delete garage;
	for (size_t i = 0; i < CurrentSizeItems; i++)
	{
		delete[] Items[i];
	}
	delete[] Items;
}

void Application::AddUser(Users* user)
{
	if (CurrentSize < MaxSize)
	{
		User[CurrentSize++] = user;
	}
	else
	{
		size_t new_size = MaxSize + 3;
		Users** new_users = new Users * [new_size];

		size_t i = 0;
		for (; i < CurrentSize; i++)
		{
			new_users[i] = User[i];
		}
		// i плюсанулся и вышел, добавили в новую ячейку нового юзера
		new_users[i] = user;
		MaxSize = new_size;
		CurrentSize++;
		delete[] User; // старый указатель сносим
		User = new_users; // новый указатель заносим
		
	}
}

void Application::GoAddUser()
{
	int cnt = 0, new_user = 0;
	while (true)
	{
		system("cls");
		cout << "*account creation menu.*" << endl;
		cout << "If you want add user press 1" << endl;
		cout << "If you want add admin press 2" << endl;
		cin >> new_user;
		if (new_user < 1 || new_user > 2)
		{
			cout << "Error choise!" << endl;
			continue;
		}
		cout << "Enter login: " << endl;
		cin >> login;
		cout << "Enter password: " << endl;
		cin >> password;
		for (size_t i = 0; i < CurrentSize; i++)
		{
			if (strcmp(login, User[i]->GetLogin()) == 0)
			{
				cnt++;
			}
		}
		if (cnt == 0)
		{

			if (new_user == 1)
			{
				Users* user = new SimpleUser(login, password);
				AddUser(user);
			}
			if (new_user == 2)
			{
				Users* user = new Admin(login, password);
				AddUser(user);
			}
			break;
		}
		else
		{
			cnt = 0;
			cout << "This login already exist." << endl;
			system("pause");
		}
	}
}

void Application::GoAddCar()
{
	char brand[40], model[40];
	unsigned  year, mileage, enginePower;
	cout << "Enter brand: " << endl;
	cin >> brand;
	cout << "Enter model: " << endl;
	cin >> model;
	cout << "Enter year: " << endl;
	cin >> year;
	cout << "Enter mileage: " << endl;
	cin >> mileage;
	cout << "Enter engine power: " << endl;
	cin >> enginePower;
	garage->AddCar(new Car(Current_Login, brand, model, year, mileage, enginePower));
	cout << "Car added" << endl;
	system("pause");
}

void Application::GoLogout()
{
	SaveUsers();
	garage->SaveCars();
	CurrentSizeItems = 0;
	Run();
}

void Application::GoExit()
{
	SaveUsers();
	garage->SaveCars();
	exit(0);
}

void Application::AddMenu(char letter, const char* title, menuitem_handler handler)
{
	// создали новый пункт
	MenuItem* item = new MenuItem(letter, title, handler);

	// добавить новый пункт в конец списка меню
	if (CurrentSizeItems < MaxSizeItems)
	{
		Items[CurrentSizeItems++] = item;
	}
	else
	{
		size_t new_size = MaxSizeItems + 3;
		size_t i = 0;
		MenuItem** new_item = new MenuItem*[new_size];
		for ( ; i < CurrentSizeItems; i++)
		{
			new_item[i] = Items[i];
		}
		new_item[i] = item;
		delete[] Items;
		MaxSizeItems = new_size;
		Items = new_item;
		CurrentSizeItems++;
	}
}

void Application::PrintMenu()
{
	for (size_t i = 0; i < CurrentSizeItems; i++)
	{
		Items[i]->print();
	}
}
void Application::Menu(Application* app)
{
	while (1)
	{
		system("cls");
		PrintMenu();
		char letter = _getch(); // ввод 1 символа с клавы

		//пробежка по пунктам
		for (size_t i = 0; i < CurrentSizeItems; i++)
		{
			if (Items[i]->letter == letter)
			{
				// обработчик нажатия текущего пункта меню
				menuitem_handler handler = Items[i]->handler;

				// запуск метода класса Application, на который указывает handler
				(app->*handler)();
			}
		}
	}
}

void Application::GoDeleteUserCar()
{
	int index;
	cout << "Enter car id to delete: ";
	cin >> index;
	garage->DeleteCarUser(index, Current_Login);
	system("pause");
}

bool Application::DeleteUser()
{
	bool flag = false;
	for (size_t i = 0; i < CurrentSize; i++)
	{
		if (strcmp(login, User[i]->GetLogin()) == 0)
		{
			delete[] User[i];
			flag = true;
		}
		if (flag)
		{
			User[i] = User[i + 1];
		}
	}
	if (flag)
	{
		CurrentSize--;
		return true;
	}
	else
	{
		cout << login << " not found!" << endl;
		return false;
	}

}

void Application::GoDeleteUser()
{
	cout << "Enter login: ";
	cin >> login;
	if (strcmp(login, "admin") == 0)
	{
		cout << "Can't delete master admin!" << endl;
		system("pause");
	}
	if (strcmp(login, Current_Login) == 0)
	{
		cout << "Can't delete current user!" << endl;
		system("pause");
	}
	int temp = CurrentSize;
	DeleteUser();
	garage->DeleteCarUserAll(login);
	if (temp == CurrentSize + 1)
		cout << login << " deleted!" << endl;
	system("pause");
}

void Application::DeleteCars()
{
	int index;
	cout << "Enter car id to delete: ";
	cin >> index;
	garage->DeleteCarAdmin(index);
	cout << "Car deleted" << endl;
	system("pause");
}

void Application::PrintUsers()
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		if (User[i]->GetFlag() == 1)
		{
			cout << "(A)";
			User[i]->Print();
		}
		else
			User[i]->Print();
		cout << endl;
	}
	system("pause");
}

void Application::PrintCars()
{
	garage->Print();
	system("pause");
}


void Application::Run()
{
	while (1)
	{
		system("cls");
		cout << "Welcome to the garage buddy!" << endl;
		cout << "Enter login: " << endl;
		cin >> Current_Login;
		cout << "Enter password: " << endl;
		cin >> password;

		for (size_t i = 0; i < CurrentSize; i++)
		{
			if (User[i]->CheckLogin(Current_Login, password))
			{
				User[i]->Menu(this);
			}
		}
		cout << "Wrong login or password" << endl;
		system("pause");
	}
}

bool Application::LoadUsers(ifstream& file)
{
	if (!file.fail())
	{
		for (size_t i = 0; i < CurrentSize; i++)
		{
			delete[] User[i]; 
		}

		CurrentSize = 0;
		while (!file.eof())
		{
			char login[40] = "";
			char login_a[40] = "";
			char password[40] = "";
			file >> login >> password;
			if (strlen(login) > 0 && strlen(password) > 0)
			{
				if (login[strlen(login) - 2] == 'A')
				{
					for (size_t i = 0; i < strlen(login) - 3; i++)
					{
						login_a[i] = login[i];
					}
					Users* new_user = new Admin(login_a, password);
					AddUser(new_user);

				}
				else
				{
					Users* new_user = new SimpleUser(login, password);
					AddUser(new_user);
				}


			}
		}
		file.close();
		return true;
	}
	else
	{
		cout << "Error opening file." << endl;
		return false;
	}
}

bool Application::SaveUsers()
{
	ofstream file("db_users.txt", ios::out);
	if (!file.fail())
	{
		for (size_t i = 0; i < CurrentSize; i++)
		{

			if (User[i]->GetFlag() == 1)
			{
				char admin[40] = "";
				strcpy(admin, User[i]->GetLogin());
				strcat(admin, "(A)");
				file << admin << " " << User[i]->GetPassword() << "\n";
			}
			else
				file << User[i]->GetLogin() << " " << User[i]->GetPassword() << "\n";
		}
		file.close();
		return true;
	}
	else
	{
		cout << "Error opening file." << endl;
		return false;
	}
}