#include "SimpleUser.h"
#include "Application.h"
#include "pch.h"

SimpleUser::SimpleUser(const char* login, const char* password) : Users(login,password)
{
	
}

SimpleUser::~SimpleUser()
{	
}


int SimpleUser::GetFlag()
{
	return 0;
}


void SimpleUser::Menu(Application* app)
{
	app->AddMenu('1', "Add a new car", &Application::GoAddCar);
	app->AddMenu('2', "View all cars", &Application::PrintCars);
	app->AddMenu('3', "Delete my cars", &Application::GoDeleteUserCar);
	app->AddMenu('4', "Logout", &Application::GoLogout);
	app->AddMenu('5', "Exit", &Application::GoExit);

	app->Menu(app);
}