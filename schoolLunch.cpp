#include<iostream>
#include<string>

void line()
{
	std::cout << "................................................................................................................." << std::endl;
	//a pattern that can be used to make things look neat and make the app more readable
	//feel free to change pattern
}

struct login
{
	std::string username;  //a struct that can be used for the login form
	std::string email;
	std::string password;
};

void loginForm(login& userLogin)
{
	std::cout << "Great! Let's get you signed in" << std::endl;
	line();

	std::cout << "Username: ";
	std::cin >> userLogin.username;
	std::cout << "email: ";
	std::cin >> userLogin.email;
	std::cout << "Password: ";
	std::cin >> userLogin.password;

	//Display user info and navigate to menu order
	std::cout << std::endl;
	std::cout << "Welcome, " << userLogin.username << std::endl;

}

void newAccount() {

	//This will be questions we ask a new user

}

bool loginGetYN() //
{
	char answer;

	std::cout << "Welcome" << std::endl;
	std::cout << "Do you already have an account with us? (y/n)" << std::endl;
	std::cin >> answer; //asking the user if they have an account

	if (answer == 'y' || answer == 'Y')
	{
		login userLogin;
		loginForm(userLogin);
		return true;
	}
	else if (answer == 'n' || answer == 'N')
	{
		newAccount();
		return false;
	}
	else
	{
		std::cout << "Please only enter 'y' or 'n' " << std::endl;
		return false;
	}
}

int main()
{

	line();
	std::cout << "School Lunch" << std::endl; //Just a heading for that this app will be
	line();

	loginGetYN();

	return 0;

}