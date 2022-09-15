#include "Admin.h"
#include "Application.h"

Admin::Admin(const char* login, const char* password) : Users(login, password)
{
}

Admin::~Admin()
{
	
}

int Admin::GetFlag()
{
	return 1;
}




void Admin::Menu(Application* app)
{
	
		app->AddMenu('1', "Add a new car", &Application::GoAddCar);
		app->AddMenu('2', "View all cars", &Application::PrintCars);
		app->AddMenu('3', "Delete any cars", &Application::DeleteCars);
		app->AddMenu('4', "Print users", &Application::PrintUsers);
		app->AddMenu('5', "Add a new user", &Application::GoAddUser);
		app->AddMenu('6', "Delete user(with cars)", &Application::GoDeleteUser);
		app->AddMenu('7', "Logout", &Application::GoLogout);
		app->AddMenu('8', "Exit", &Application::GoExit);

		app->Menu(app);
	
	

}