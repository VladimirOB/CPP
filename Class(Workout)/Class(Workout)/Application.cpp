#include "pch.h"
#include "Application.h"
#include "EasyUser.h"
#include "MediumUser.h"
#include "ProUser.h"
#include "Stat.h"
Application::Application()
{
	menu->Add('1', "Начать тренировку", &Application::StartTraining);
	menu->Add('2', "Статистика тренировок", &Application::PrintStat);
	menu->Add('3', "Очистить историю тренировок", &Application::P_DelHistory);
	menu->Add('4', "Изменить сложность тренировки", &Application::SetTraining);
	menu->Add('5', "Выйти из аккаунта", &Application::Logout);
	menu->Add('6', "Выйти из программы", &Application::Exit);



	FILE* file = fopen("db_users.txt", "r");
	if (file != NULL)
	{
		LoadUsers(file);
		fclose(file);
	}
	else
	{
	cout << "Users not found!" << endl;
	MaxSize = 10;
	CurrentSize = 0;
	User = new Users * [MaxSize];
	}

	FILE* file_stat = fopen("db_stat.txt", "r");
	if (file_stat != NULL)
	{
		LoadStatUsers(file_stat);
		fclose(file_stat);
	}
	else
	{
		cout << "Users Stats not found!" << endl;
		MaxSizeStat = 10;
		CurrentSizeStat = 0;
		StatUser = new Stat * [MaxSizeStat];
	}
	
}

Application::~Application()
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		delete[] User[i];
	}
	delete[] User;
	delete menu;
}

void Application::AddUser(Users* user)
{
	if (CurrentSize < MaxSize)
	{
		IndexCurrentLogin = CurrentSize;
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
		IndexCurrentLogin = i;
		new_users[i] = user;
		MaxSize = new_size;
		CurrentSize++;
		delete[] User; // старый указатель сносим
		User = new_users; // новый указатель заносим
	}
}

void Application::Run()
{
	int load=0;
	
	for (size_t i = 100; i > 0; i--)
	{
		while (load != 100)
		{
			cout << "\n\n\n\n\n\n\n\n\n" << endl;
			cout << "\t\t\t\tLoading (" << (load+=5) << ")";
			Sleep(10);
			system("cls");
		}
		
	}
		setlocale(LC_ALL, "Russian");
		while (1)
		{
			system("cls");
			cout << " \tПриветствую друг!" << endl;
			cout << "Добро пожаловать в программу тренировки отжиманий" << endl;
			cout << "Нажмите: (1) для авторизации" << endl;
			cout << "Нажмите: (5) для входа в меню упр. аккаунтами" << endl;
			cout << "Нажмите: (9) для создания нового пользователя" << endl;
			cout << "Нажмите: (0) для выхода" << endl;
			letter = _getch(); // ввод 1 символа с клавы.
			if (letter == '0')
				exit(0);
			if (letter == '1')
			{
				while (1)
				{
					system("cls");
					cout << "Введите имя пользователя: ";
					cin >> Current_Login;
					cout << "Введите пароль: ";
					cin >> password;
					for (size_t i = 0; i < CurrentSize; i++)
					{
						if (User[i]->CheckLogin(Current_Login, password))
						{
							IndexCurrentLogin = i;
							menu->Run();
						}
					}
					cout << "Неверное имя пользователя или пароль." << endl;
					cout << "Повторить попытку? (y/n)" << endl;
					letter = _getch();
					if (letter == 'n')
						break;
					else
						continue;
					system("pause");
				}
			}

			if (letter == '5')
			{
				int index,ch;
				cout << "Все пользователи:" << endl;
				PrintUsers();
				cout << "Желаете удалить пользователя?" << endl;
				cout << "Нажмите 1 выбрать и удалить пользователя" << endl;
				cout << "Нажмите 9 чтоб вернуться в главное меню" << endl;
				cin >> ch;
				if (ch == 1)
				{
					cout << "Выберите по ID кого удалить" << endl;
					cin >> index;
					DelUser(index);
				}
			}

			if (letter == '9')
			{
				while (1)
				{
					int cnt = 0;
					system("cls");
					cout << "Введите имя пользователя: ";
					cin >> Current_Login;
					cout << "Введите пароль: ";
					cin >> password;
					for (size_t i = 0; i < CurrentSize; i++)
					{
						if (strcmp(Current_Login,User[i]->GetLogin())==0)
						{
							cnt++;
							
						}
					}
					if (cnt == 0)
					{
						NewMember();
						SaveUsers();
						menu->Run();
						break;
					}
					else
					{
						cout << "Это имя занято, попробуйте другое." << endl;
						cout << "Повторить попытку? (y/n)" << endl;
						letter = _getch();
						if (letter == 'n')
							break;
						else
							continue;
						system("pause");
					}
					
				}
			}
		}
		
	
}

void Application::NewMember()
{
	system("cls");
	int cnt = 0;
	setlocale(LC_ALL, "Russian");
	cout << Current_Login << " поздавляю с началом нового пути!" << endl << endl;
	cout << "Чтоб подобрать для вас оптимальную тренировку" << endl;
	cout << "Отожмитесь максимальное кол-во раз" << endl;
	cout << "И напишите сколько у вас получилось." << endl;
	cin >> cnt;
	if (cnt <= 13)
	{
		cout << "Неплохо. Добавляем вас в группу новичков." << endl;
		Users* user = new EasyUser(Current_Login, password);
		AddUser(user);
		system("pause");
	}
		
		
	if (cnt > 13 && cnt < 23)
	{
		cout << "Хороший результат! Добавляем вас в группу любителей." << endl;
		Users* user = new MediumUser(Current_Login, password);
		AddUser(user);
		system("pause");
	}
	if (cnt > 24)
	{
		cout << "Отлично! Добавляем вас в группу мастеров." << endl;
		Users* user = new ProUser(Current_Login, password);
		AddUser(user);
		system("pause");
	}
}

void Application::DelHistory(const char* log)
{
	for (size_t i = 0; i < CurrentSizeStat; i++)
	{
		if (strcmp(log, StatUser[i]->GetLogin()) == 0)
		{
			int index = i;
			delete StatUser[index];
			for (size_t i = index; i < CurrentSizeStat; i++)
			{
				StatUser[i] = StatUser[i + 1];
			}
			CurrentSizeStat--;
			i--;
		}
	}
	FILE* file = fopen("db_stat.txt", "w");
	if (file != NULL)
	{
		for (size_t i = 0; i < CurrentSizeStat; i++)
		{
			fprintf(file, "%s %d %d %d %d %d\n", StatUser[i]->GetLogin(), StatUser[i]->GetYear(), StatUser[i]->GetMonth(), StatUser[i]->GetDay(), StatUser[i]->GetPodhod(), StatUser[i]->GetSumm());
		}
		fclose(file);
	}
	else
	{
		cout << "Error file" << endl;
	}
	cout << "История ваших тренировок успешно очищена." << endl;
	system("pause");
}

void Application::P_DelHistory()
{
	DelHistory(Current_Login);
}

bool Application::DelUser(unsigned index)
{
	if (index >= 0 && index < CurrentSize)
	{
		strcpy(login, User[index]->GetLogin());
		DelHistory(login);
		delete User[index];
		for (size_t i = index; i < CurrentSize; i++)
		{
			User[i] = User[i + 1];
		}
		CurrentSize--;
		cout << "Пользователь успешно удалён" << endl << endl;
		SaveUsers();
		return true;
	}
	else
	{
		cout << "User not found!" << endl;
		return false;
	}
		
		
}

void Application::StartTraining()
{
	time_t seconds = time(NULL);
	tm* tt = localtime(&seconds);
	int year = tt->tm_year + 1900, month = tt->tm_mon + 1, day = tt->tm_mday, hour = tt->tm_hour, min = tt->tm_min;
	FILE* file = fopen("db_stat.txt", "a");
	system("cls");
	setlocale(LC_ALL, "Russian");
	int flag = 0, podhod=0,sum=0, ch = 0;
	for (size_t i = 0; i < CurrentSize; i++)
	{
		if (strcmp(Current_Login, User[i]->GetLogin()) == 0)
		{
			flag = User[i]->GetFlag();
			break;
		}
			
	}
	switch (flag)
	{
		case 1:
		{
			int cnt = 8;
			cout << "\tПриступим к разминке." << endl << endl; 
			cout << "1) Пробежка 2 минуты." << endl;
			cout << "Во время пробежки разминайте руки " << endl;
			cout << "Круговыми движениями в обе стороны" << endl;
			system("pause");

			while (cnt != 13)
			{
				system("cls");
				cout << "1) Пробежка 2 минуты." << endl;
				cout << "Во время пробежки разминайте руки " << endl;
				cout << "Круговыми движениями в обе стороны" << endl;
				for (size_t i = 120; i > 0; i--)
				{
					if(i != 10 && i != 5 && i != 1)
					Sleep(1000); 
					cout << i << endl;
					if(i == 10)
						Beep(800, 1000);
					if (i == 5)
						Beep(500, 1000);
					if (i == 1)
						Beep(200, 1000);
				}
				sum += cnt;
				system("cls");
				cout << "Отожмитесь " << cnt++ << " раз" << endl;
				podhod++;
				cout << "Хотите продолжить? (1-да | 9-нет)" << endl;
				cin >> ch;
				if (ch == 9)
				{
					Stat* new_stat = new Stat(Current_Login,year,month,day,hour,min, podhod, sum);
					AddStat(new_stat);
					SaveStatUsers();
					break;
				}
				if (ch == 1)
				{
					continue;
				}
			}
			break;
		}
		case 2:
		{
			int cnt = 17;
			cout << "\tПриступим к разминке." << endl << endl;
			cout << "1) Пробежка 3 минуты." << endl;
			cout << "Во время пробежки разминайте руки " << endl;
			cout << "Круговыми движениями в обе стороны" << endl;
			system("pause");

			while (cnt != 22)
			{
				system("cls");
				cout << "1) Пробежка 3 минуты." << endl;
				cout << "Во время пробежки разминайте руки " << endl;
				cout << "Круговыми движениями в обе стороны" << endl;
				for (size_t i = 180; i > 0; i--)
				{
					if (i != 10 && i != 5 && i != 1)
						Sleep(1000);
					cout << i << endl;
					if (i == 10)
						Beep(800, 1000);
					if (i == 5)
						Beep(500, 1000);
					if (i == 1)
						Beep(200, 1000);
				}
				sum += cnt;
				system("cls");
				cout << "Отожмитесь " << cnt++ << " раз" << endl;
				podhod++;
				cout << "Хотите продолжить? (1-да | 9-нет)" << endl;
				cin >> ch;
				if (ch == 9)
				{
					Stat* new_stat = new Stat(Current_Login, year, month, day, hour, min, podhod, sum);
					AddStat(new_stat);
					SaveStatUsers();
					break;
				}
				if (ch == 1)
				{
					continue;
				}
			}
			break;
		}
		case 3:
		{
			int cnt = 24;
			cout << "\tПриступим к разминке." << endl << endl;
			cout << "1) Пробежка 4 минуты." << endl;
			cout << "Во время пробежки разминайте руки " << endl;
			cout << "Круговыми движениями в обе стороны" << endl;
			system("pause");

			while (cnt != 29)
			{
				system("cls");
				cout << "1) Пробежка 4 минуты." << endl;
				cout << "Во время пробежки разминайте руки " << endl;
				cout << "Круговыми движениями в обе стороны" << endl;
				for (size_t i = 240; i > 0; i--)
				{
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\n" << endl;
					cout << "\t\t\t\t"<< i << endl;
					if (i != 10 && i != 5 && i != 1)
						Sleep(1000);
					if (i == 10)
						Beep(800, 1000);
					if (i == 5)
						Beep(500, 1000);
					if (i == 1)
						Beep(200, 1000);
				}
				sum += cnt;
				system("cls");
				cout << "Отожмитесь " << cnt++ << " раз" << endl;
				podhod++;
				cout << "Хотите продолжить? (1-да | 9-нет)" << endl;
				cin >> ch;
				if (ch == 9)
				{
					Stat* new_stat = new Stat(Current_Login, year, month, day, hour, min, podhod, sum);
					AddStat(new_stat);
					//SaveStatUsers();
					break;
				}
				if (ch == 1)
				{
					continue;
				}
			}
			break;
		}
	}
	if (podhod == 5)
	{
		Stat* new_stat = new Stat(Current_Login, year, month, day, hour, min, podhod, sum);
		AddStat(new_stat);
		//SaveStatUsers();
	}
}

void Application::PrintStat()
{
	for (size_t i = 0; i < CurrentSizeStat; i++)
	{
		if (strcmp(Current_Login, StatUser[i]->GetLogin()) == 0)
		{
			StatUser[i]->Print();
		}
		
	}
	system("pause");
}

void Application::PrintUsers()
{
	for (size_t i = 0; i < CurrentSize; i++)
	{
		cout << "ID пользователя = " << i << endl;
		User[i]->Print();
		cout << endl;
	}
}

void Application::SetTraining()
{
	cout << "Выберите сложность" << endl;
	cout << "1) Легко" << endl;
	cout << "2) Средне" << endl;
	cout << "3) Тяжело" << endl;
	int ch;
	cin >> ch;
	if (ch > 0 && ch < 4)
	{
		User[IndexCurrentLogin]->SetFlag(ch);
		SaveUsers();
		cout << "Сложность успешно изменена на "<< ch << endl;
		system("pause");
	}
	
	
}

bool Application::LoadUsers(FILE* file)
{
	if (file != NULL)
	{
		for (size_t i = 0; i < CurrentSize; i++)
		{
			delete[] User[i]; // [] - ?
		}

		CurrentSize = 0;
		while (!feof(file))
		{
			char login[40] = "";
			char login_a[40] = "";
			char password[40] = "";
			int res = fscanf(file, "%s %s ", login, password);
			if (strlen(login) > 0 && strlen(password) > 0)
			{
				if (login[strlen(login) - 2] == 'E')
				{
					for (size_t i = 0; i < strlen(login) - 3; i++)
					{
						login_a[i] = login[i];
					}
					Users* new_user = new EasyUser(login_a, password);
					AddUser(new_user);
				}
				if (login[strlen(login) - 2] == 'M')
				{
					for (size_t i = 0; i < strlen(login) - 3; i++)
					{
						login_a[i] = login[i];
					}
					Users* new_user = new MediumUser(login_a, password);
					AddUser(new_user);
				}
				if (login[strlen(login) - 2] == 'P')
				{
					for (size_t i = 0; i < strlen(login) - 3; i++)
					{
						login_a[i] = login[i];
					}
					Users* new_user = new ProUser(login_a, password);
					AddUser(new_user);
				}
			}
		}
		fclose(file);
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
	char check[40] = "";
	FILE* file_w = fopen("db_users.txt", "w");
	if (file_w != NULL)
	{
		for (size_t i = 0; i < CurrentSize; i++)
		{
			if (User[i]->GetFlag() == 1)
			{
				strcpy(check, User[i]->GetLogin());
				strcat(check, "(E)");
				fprintf(file_w, "%s %s \n", check, User[i]->GetPassword());
			}

			if (User[i]->GetFlag() == 2)
			{
				strcpy(check, User[i]->GetLogin());
				strcat(check, "(M)");
				fprintf(file_w, "%s %s \n", check, User[i]->GetPassword());
			}
			if (User[i]->GetFlag() == 3)
			{
				strcpy(check, User[i]->GetLogin());
				strcat(check, "(P)");
				fprintf(file_w, "%s %s \n", check, User[i]->GetPassword());
			}
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

void Application::AddStat(Stat* userStat)
{
	if (CurrentSizeStat < MaxSizeStat)
	{
		StatUser[CurrentSizeStat++] = userStat;
	}
	else
	{
		size_t new_size = MaxSizeStat + 3;
		Stat** new_stat = new Stat * [new_size];
		size_t i = 0;
		for (; i < CurrentSizeStat; i++)
		{
			new_stat[i] = StatUser[i];
		}
		new_stat[i] = userStat;
		delete[] StatUser;
		StatUser = new_stat;
		MaxSizeStat = new_size;
		CurrentSizeStat++;
	}
}

void Application::Logout()
{
	Run();
}
void Application::Exit()
{
	exit(0);
}

bool Application::LoadStatUsers(FILE* file)
{
	if (file != NULL)
	{
		for (size_t i = 0; i < CurrentSizeStat; i++)
		{
			delete[] StatUser[i];
		}
		CurrentSizeStat = 0;
		while (!feof(file))
		{
			char login[40] = "";
			unsigned year=0;
			unsigned month=0;
			unsigned day=0;
			unsigned hour = 0;
			unsigned min = 0;
			unsigned podhod=0;
			unsigned summ=0;
			int res = fscanf(file, "%s %d %d %d %d %d %d %d", login, &year, &month, &day, &hour,&min, &podhod, &summ);
			if (strlen(login) > 0)
			{
				Stat* new_stat = new Stat(login, year, month, day,hour,min, podhod, summ);
				AddStat(new_stat);
			}
		}
		fclose(file);
		return true;
	}
	else
	{
		cout << "Error opening file!" << endl;
		return false;
	}
}

bool Application::SaveStatUsers()
{
	FILE* file = fopen("db_stat.txt", "a");
	if (file != NULL)
	{
		for (size_t i = 0; i < CurrentSizeStat; i++)
		{
			if(strcmp(Current_Login, StatUser[i]->GetLogin())==0)
			fprintf(file, "%s %d %d %d %d %d %d %d\n", StatUser[i]->GetLogin(), StatUser[i]->GetYear(), StatUser[i]->GetMonth(), StatUser[i]->GetDay(), StatUser[i]->GetHour(),StatUser[i]->GetMin(), StatUser[i]->GetPodhod(), StatUser[i]->GetSumm());
		}
		fclose(file);
		return true;
	}
	else
	{
		cout << "Error file" << endl;
		return false;
	}
}