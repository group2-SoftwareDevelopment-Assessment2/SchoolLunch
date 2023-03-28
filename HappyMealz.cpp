#include<iostream>
#include<string>
#include<string.h>
#include <vector>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<sstream>
using namespace std;

void Line() //MJ
{
	std::cout << "................................................................................................................." << std::endl;
}

struct MenuItem //Richard
{
	std::string name;
	double price;
};

bool loginGetYN(); //MJ

void addToCart(std::vector<MenuItem>& cart, const MenuItem& item) {
	cart.push_back(item);                                              // Richard // this is to add the item to the end of the cart vector
	std::cout << item.name << " added to cart." << std::endl;
}

std::vector<MenuItem> cart; // Richard // to create and empty cart vector

bool ordering = true;

void printCart(const std::vector<MenuItem>& cart) {
	double total = 0;                               // Richard // this is to initialize the total price to 0
	std::cout << "cart:" << std::endl;              // Richard // used to display the cart header
	for (const auto& item : cart)
	{
		std::cout << item.name << " -$" << item.price << std::endl;
		total += item.price;
	}
	std::cout << "Total price : $" << total << std::endl;
}

void printMenu(const std::vector<MenuItem>& menu) {
	std::cout << "Menu:" << std::endl;                 // Richard // Displaying the menu header
	for (const auto& item : menu) {
		std::cout << item.name << " -$" << item.price << std::endl;  // Richard // Display the item name and price
	}
}

std::vector<MenuItem> menuItems()  //Richard
{
	std::vector<MenuItem> menu = {
		{"1. Vegan mac n cheese", 6.00},
		{"2. Chicken and mayo wrap", 7.50},
		{"3. Mince and cheese toasty", 5.50},
		{"4. Sushi roll", 7.00},
		{"5. Fruit Cup", 4.50},
		{"6. Muffin", 5.00},
		{"7. Bag of veggie chips", 3.00},
		{"8. Vegetarian paella", 8.00},
		{"9. Chicken Salad and roll", 6.00},
		{"10. Crackers and cheese with apple", 3.00},
	};
	return menu;
}

void Ordering(const std::vector<MenuItem>& menu)
{
	while (ordering)// Richard
	{ //  loop while the user is still ordering
		std::cout << std::endl;
		printMenu(menu);
		std::cout << std::endl;
		std::cout << "Enter the number of items you would like to order, or enter 0 to check out:" << std::endl;
		int choice;
		std::cin >> choice;
		if (choice > 0 && choice <= menu.size()) {     //Richard // If the user entered a valid menu item number
			addToCart(cart, menu[choice - 1]);         // Richard // to add the selected product to the cart
		}
		else if (choice == 0) {
			ordering = false;                          // Richard // to set the ordering to false to exit the loop
		}
		else {                                        // Richard // // If the user entered an invalid input
			std::cout << "Invalid choice, please enter a number between 1 and " << menu.size() << std::endl;
		}
	}
}

struct login //MJ 
{
	std::string username;  //a struct that can be used for the login form
	std::string email;
	std::string password;
	std::string allergy;
	std::string diet;
};

void newAccount(login& userLogin);   //MJ

void accountRecover(); //MJ

void loginForm(login& userLogin) //MJ 
{
	std::string name, mail, pass;
	bool userFound = false;
	fstream database;

	std::cout << "Great! Let's get you logged in" << std::endl;
	Line();

	int attempt = 0, exist = 0;

	do
	{
		std::cout << "Username: ";
		std::cin.ignore();
		std::getline(std::cin, userLogin.username); //username inputs are exceppting to spaces

		while (true) //adding a condition that forces user to use the @ symbol in email input field
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

		std::ifstream input("database.txt");

		std::string line;


		while (std::getline(input, line))
		{
			if (line == userLogin.username)
			{
				getline(input, line); // read email
				if (line == userLogin.email)
				{
					getline(input, line); // read password
					if (line == userLogin.password)
					{
						userFound = true;
						getline(input, line); // read allergies
						cout << "Your allergies: " << line << endl;
						getline(input, line); // read special diets
						cout << "Your special diets: " << line << endl;

						std::cout << std::endl;
						Line();
						std::cout << "Hello" << " " << userLogin.username << std::endl;
						std::cout << std::endl;
						std::cout << "This will be the Menu for today" << std::endl;
						Line();
						Ordering(menuItems());

						break;
					}
				}
			}
			// skip the rest of the user information
			getline(input, line); // read email
			getline(input, line); // read password
			getline(input, line); // read allergies
			getline(input, line); // read special diets
		}
		input.close();
		if (!userFound)
		{
			attempt++;
			std::cout << std::endl;
			std::cout << "Login failed. Please try again." << std::endl;
			std::cout << "............................................................" << std::endl;
		}
	} while (!userFound && attempt++ < 3);

	if (attempt == 3)
	{
		std::cout << std::endl;
		std::cout << "You have exceeded the maximum number of attempts." << std::endl;
		std::cout << "Please try again later." << std::endl;
		std::cout << "............................................................" << std::endl;
	}
}

void accountRecover()
{
	login userLogin; //to help define the parameters of other used funtions

	int choice;
	std::string userN, mail, passw, allerG, strictdiet, mailInput;
	bool accountFound = false;
	std::string line;

		Line();
		std::cout << "Account Recovery\n";
		Line();

		std::cout << "1. Search for account by email\n";
		std::cout << "2. Go back to main menu\n";
		std::cout << "3. Exit\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
            ifstream database("database.txt");
			while (true)
			{
				std::cout << "\nWhat is your email adress?\nEmail :";
				std::cin >> mailInput;

				if (mailInput.find('@') != std::string::npos)
				{
					break;
				}
				else
				{
					std::cout << "Invalid email address. Please include '@' symbol." << std::endl;
				}
			}

			
			while (database >> userN >> mail >> passw >> allerG >> strictdiet) 
			{
				if (mailInput == mail)
				{
					accountFound = true;

					database.close();
					std::cout << std::endl;
					std::cout << "\nAccount that matched your descrpition:\n\n";
					std::cout << "Username :" << " " << userN;
					std::cout << "Email :" << " " << mail;
					std::cout << "Allergies :" << " " << allerG;
					std::cout << "Diet requirements :" << " " << strictdiet;

					std::cout << std::endl;
					char confirm;
					std::cout << "Is this you?\n";
					std::cout << "y/n : ";
					std::cin >> confirm;

					if (confirm == 'y' || confirm == 'Y')
					{
						std::cout << "This is your password :" << passw;
						std::cout << std::endl;
						std::wcout << "Press ENTER to continue...";
						loginForm(userLogin);
					}
					else if (confirm == 'n' || confirm == 'N')
					{
						char confirmA;
						std::cout << "Would you like to create an accout? (y/n) : ";
						std::cin >> confirmA;
						if (confirmA == 'y' || confirmA == 'Y')
						{
							newAccount(userLogin);
						}
						else if (confirmA == 'n' || confirmA == 'N')
						{
							Line();
							std::cout << std::endl;
							std::cout << "If you're having problems loggin in, please contact out IT Team:\n";
							std::cout << "\nMJ / Richard :\t itInfo@gmail.com\n";
							std::cout << std::endl;
							std::cout << std::endl;
							Line();
							accountRecover();
						}
						else
						{
							std::cout << "Please only enter 'y' or 'n' " << std::endl;
							return; //should return to question on wheather user wants to create account
						}
					}
					else
					{
						std::cout << "Please only enter 'y' or 'n' " << std::endl;
						return;
					}
					break;
				}
				else
				{
					accountFound = false;
                        std::cout << std::endl;
						std::cout << "No account found with that email address.\n";
						std::cout << std::endl;
						std::cout << "If you're having problems loggin in, please contact out IT Team:\n";
						std::cout << "\nMJ / Richard :\t itInfo@gmail.com\n";
						accountRecover();
				}
				}
			break;
			}
		case 2:
		{
			//back to start
			loginGetYN();
			break;
		}
		case 3:
		{
			//exit out of the program
			std::cout << "Thank you for using our program. Goodbye!" << std::endl;
			exit(0);
			return;
		}
		default:
		{
			std::cout << "Please only choose number '1' or '2' or '3'";
			accountRecover();
		}
		}
	}

int main()
{

	Line();
	std::cout << "The HappyMealz" << std::endl; //Just a heading for that this app will be
	Line();

	loginGetYN();

	return 0;
}

void newAccount(login& userLogin)   //MJ
{
	login newUser;
	newUser.username;
	newUser.email;
	newUser.password;
	newUser.allergy;
	newUser.diet;

	std::cout << "Let's create a new Account" << std::endl;
	Line();
	std::cout << "Enter an Username :";
	std::cin.ignore();
	std::getline(std::cin, newUser.username);
	std::cout << "Add your email address :";

	while (true) //adding a condition that forces user to use the @ symbol in email input field
	{

	std::getline(std::cin, newUser.email);

		if (newUser.email.find('@') != std::string::npos)
		{
			break;
		}
		else
		{
			std::cout << "Invalid email address. Please include '@' symbol." << std::endl;
		}
	}

	std::cout << "Choose your password :";
	std::getline(std::cin, newUser.password);
	std::cout << "Do you have any allergies :";
	std::getline(std::cin, newUser.allergy);
	std::cout << "Is there any special diets that we need to consider (lactose intolerance,etc.) : ";
	std::getline(std::cin, newUser.diet);

	std::ofstream regUser("database.txt", std::ios::app);
	regUser << newUser.username << "\n";
	regUser << newUser.email << "\n";
	regUser << newUser.password << "\n";
	regUser << newUser.allergy << "\n";
	regUser << newUser.diet << "\n";
	regUser.close();

	Line();
	std::cout << "REGISTERATION WAS SUCCESSFULL\n";
	Line();
	std::cout << "THANK YOU\n";
	std::cout << "PLEASE PRESS ENTER TWICE TO EXIT AND RESTART THE PROGRAM\n";
	std::cin.get();
	std::exit(0);
}

bool loginGetYN() //MJ
{
	char answer;
	login userLogin;

	std::cout << "Welcome" << std::endl;
	std::cout << "Do you already have an account with us? (y/n)" << std::endl;
	std::cin >> answer; //asking the user if they have an account

	if (answer == 'y' || answer == 'Y')
	{

		loginForm(userLogin);
		return true;
	}
	else if (answer == 'n' || answer == 'N')
	{
		newAccount(userLogin);
		return false;
	}
	else
	{
		std::cout << "Please only enter 'y' or 'n' " << std::endl;
		loginGetYN();
		return false;
	}
}
