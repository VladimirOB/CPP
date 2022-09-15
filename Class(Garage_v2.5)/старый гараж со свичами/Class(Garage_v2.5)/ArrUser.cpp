#include "ArrUser.h"
#include "Users.h"
#include "pch.h"
#include "Admin.h"
#include "SimpleUser.h"
ArrUser::ArrUser(const size_t maxSize)
{
	User = new Users * [maxSize];
	MaxSize = maxSize;
	CurrentSize = 0;
}

ArrUser::~ArrUser()
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		delete[] User[i];
	}
	delete[] User;
}

void ArrUser::AddUser(Users* user)
{
	if (CurrentSize < MaxSize)
	{
		User[CurrentSize++] = user;
	}
	else
	{
		size_t new_size = MaxSize + 3;
		//cout << "Resize user arr" << endl;

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

ArrUser& ArrUser::DeleteUser(const char* login)
{
	/*int cnt = 0;
	char admin[6] = "admin";
	for (size_t i = 0; i < 5; i++)
	{
		if (login[i] == admin[i])
			cnt++;
	}
	if (cnt == 5)
	{
		cout << "Can't delete master admin!" << endl;
		system("pause");
		return *this;
	}*/
	bool flag = false;
	for (size_t i = 0; i < CurrentSize; i++)
	{
		if (strcmp(login, User[i]->GetLogin()) == 0)
		{
			delete[] User[i];
			User[i] = User[i + 1];
			flag = true;
		}
		if (flag)
		{
			User[i] = User[i + 1];
		}
	}
	if (flag)
	CurrentSize--;
	return *this;
}

int ArrUser::CheckUser(const char* login, const char* password)
{
	int cnt = 0, admin = 0;
	for (size_t i = 0; i < CurrentSize; i++)
	{
		if (strcmp(login, User[i]->GetLogin()) == 0)
			cnt++;
		if (strcmp(password, User[i]->GetPassword()) == 0)
			cnt++;
		if (User[i]->GetFlag() == 1)
			admin = 1;
		if (cnt == 2 && admin == 1)
		{
			return 2; // всё ок, админ
		}
		if (cnt == 2 && admin == 0)
		{
			return 1; // всё ок, симпл
		}
		cnt = 0;
		admin = 0;
	}
	return 0;
}

bool ArrUser::CheckLogin(const char* login)
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		if (strcmp(login, User[i]->GetLogin()) == 0)
			return false;
	}
	return true;
}

void ArrUser::SimpleUserMenu()
{
	cout << "Welcome to user menu." << endl;
	cout << "Press 1 if you want add a new car" << endl;
	cout << "Press 2 if you want view all cars" << endl;
	cout << "Press 3 if you want delete your cars" << endl;
	cout << "Press 4 to logout" << endl;
	cout << "Press 5 to exit" << endl;
}

void ArrUser::AdminMenu()
{
	cout << "Welcome to admin menu." << endl;
	cout << "Press 1 to add a new car." << endl;
	cout << "Press 2 to view all cars." << endl;
	cout << "Press 3 to delete any car." << endl;
	cout << "Press 4 to view users." << endl;
	cout << "Press 5 to add a new user." << endl;
	cout << "Press 6 to delete user(with cars)." << endl;
	cout << "Press 7 to logout" << endl;
	cout << "Press 8 to exit." << endl;
}

bool ArrUser::SaveUsers()
{
	FILE* file_w = fopen("db_users.txt", "w");
	if (file_w != NULL)
	{
		for (size_t i = 0; i < CurrentSize; i++)
		{

			if (User[i]->GetFlag()== 1)
			{
				char admin[40] = "";
				strcpy(admin, User[i]->GetLogin());
				strcat(admin, "(A)");
				fprintf(file_w, "%s %s \n", admin, User[i]->GetPassword());
			}
			else
				fprintf(file_w, "%s %s \n", User[i]->GetLogin(), User[i]->GetPassword());
		}
		fclose(file_w);
		return true;
	}
	else
	{
		cout << "Error opening file." << endl;
		return false;
	}
}

bool ArrUser::LoadUsers()
{
	FILE* file_r = fopen("db_users.txt", "r");
	if (file_r != NULL)
	{
		// перед загрузкой нужно очистить всех. Нужно было ли оставить 1 админа?
		for (size_t i = 0; i < CurrentSize; i++)
		{
			delete[] User[i]; // [] - ?
		}
		
		CurrentSize = 0;
		while (!feof(file_r))
		{
			char login[40] = "";
			char login_a[40] = "";
			char password[40] = "";
			int res = fscanf(file_r, "%s %s ", login, password);
			if (strlen(login) > 0 && strlen(password) > 0)
			{
				if (login[strlen(login)-2] == 'A')
				{
					for (size_t i = 0; i < strlen(login)-3; i++)
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
		fclose(file_r);
		return true;
	}
	else
	{
	cout << "Error opening file." << endl;
	return false;
	}
}

void ArrUser::Print()
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		User[i]->Print();
	}
}