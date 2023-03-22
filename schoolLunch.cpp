#include<iostream>
#include<string>
#include<string.h>

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

void newAccount() {

	//This will be questions we ask a new user

}


void loginForm(login& userLogin) //creating a function with parameters
{
	login userLogin1;    //an exsiting account
	userLogin1.username = "Jhonny Boy";
	userLogin1.email="jb@gmail.com";
	userLogin1.password="car";

	login userLogin2;
	userLogin2.username = "Suzie";  //another exsisting account
	userLogin2.email="s88@gmail.com";
	userLogin2.password="rock";

	std::cout << "Great! Let's get you signed in" << std::endl;
	line();

	int attempts =0;

do
{
	     std::cout << "Username: ";
	     std::cin.ignore();
         std::getline(std::cin, userLogin.username); //username inputs are exceppting to spaces

	     while(true) //adding a condition that forces user to use the @ symbol in email input field
	     {
           std::cout << "email: ";
	       std::cin >> userLogin.email;

         if (userLogin.email.find('@') != std::string::npos)
	       {
		     break;
	       }
	    else
	       {
		     std::cout << "Invalid email address. Please include '@' symbol." << std::endl;
	       }
	     }

	    std::cout << "Password: ";
	    std::cin >> userLogin.password;

        if (userLogin.username == userLogin1.username && userLogin.email == userLogin1.email && userLogin.password == userLogin1.password )
           {
             std::cout << std::endl;
	         std::cout << "Welcome, " << userLogin.username << std::endl;
			 break;
           }
        else if (userLogin.username == userLogin2.username && userLogin.email == userLogin2.email && userLogin.password == userLogin2.password)
           {
	         std::cout << std::endl;
	         std::cout << "Welcome, " << userLogin.username << std::endl;
			 break;
           }
        else 
           {
	         attempts++;
			 if (attempts <3)
			 {
				std::cout << std::endl;
                std::cout<<"Login failed. Please try again." << std::endl;
            }
			}
           } while (attempts<3);

   line();
   std::cout<<"Maximum number of login attepmts has been reached."<<std::endl;
   
   int chooseFollow;

   do 
   {
   std::cout<<"You can continue by choosing the following : "<<std::endl;
   std::cout<<"1. Retry."<<std::endl;
   std::cout<<"2. Create an account."<<std::endl;
   std::cout<<"3. Exit."<<std::endl;
   std::cout<<"Please enter your choice number : ";
   std::cin>> chooseFollow;

   switch (chooseFollow)
   {
	case 1:
	loginForm(userLogin);
	break;
	case 2:
	newAccount();
	break;
	case 3:
	return;
	break;
	default:
	std::cout<<"Invalid choice. Please only choose the numbers 1 or 2 or 3"<<std::endl;
	break;
   }
   }while (chooseFollow != 3);
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