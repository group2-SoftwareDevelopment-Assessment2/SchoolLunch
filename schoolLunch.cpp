#include<iostream>

void line()
{
	std::cout << "................................................................................................................." << std::endl;
	//a pattern that can be used to make things look neat and make the app more readable
	//feel free to change pattern
}

struct login
{
	string username;  //a struct that can be used for the login form
	string email;
	string password;
};

void loginForm ()
{
	
	//this will be the login form for exsisting accounts
}

void newAccount() {

	//This will be questions we ask a new user

}

bool loginGetYN() //
{
	char answer;

	std::cout << "Welcome" << sdt::endl; 
	std::cout << "Do you already have an account with us? (y/n)" << std::endl;
	std::cin >> answer; //asking the user if they have an account

	if (answer == "y" || answer == "Y")
	{
		loginForm();
	}
	else if (answer == "n" || answer == "N")
	{
		newAccount();
	}
	else
	{
		std::cout << "Please only enter 'y' or 'n' " << std::endl;
	}
}

int main()
{

	line();
	std::cout << "School Lunch" << std::end; //Just a heading for that this app will be
	line();

	loginGetYN();


}