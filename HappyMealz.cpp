#include<iostream>
#include<string>
#include<string.h>
#include <vector>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<sstream>
#include <limits>
using namespace std;

void Line() //MJ
{
	std::cout << "................................................................................................................." << std::endl;
}

struct MenuItem //Richard
{
	int unitNumber;
	std::string name;
	double price;

	//elements in menuItems vector are initialized with only one string argument, so this is how we can initialize it
	MenuItem(const std::string& itemString, double itemPrice) 
	{
		std::istringstream iss(itemString);
		iss >> unitNumber;
		std::getline(iss, name);
		price = itemPrice;
	}
};

MenuItem newItem("1 Cheeseburger 2.99", 2.99);

bool loginGetYN(); //MJ

struct controlLogin  //MJ //creating a struct for the admin login
{
	std::string username;
	std::string password;
};

std::vector<MenuItem> cart; // Richard // to create and empty cart vector

bool ordering = true; //Richard

void payment(double total) //MJ
{
	//code a way to pay for the items in the cart
	std::cout << "How would you like to pay?" << std::endl;
	std::cout << "1. Cash" << std::endl;
	std::cout << "2. Credit Card" << std::endl;
	std::cout << "3. Debit Card" << std::endl;
	std::cout << "4. Put it on my tab" << std::endl;
	int choice;
	std::cin >> choice;

	if (choice == 1)
	{
		double cash;
		// total from cart
		std::cout << "Please enter the amount of cash you are paying with" << std::endl;
		std::cin >> cash;
		if (cash < total)
		{
			std::cout << "Sorry, you do not have enough money to pay for your order" << std::endl;
		}
		else
		{
			std::cout << "Your change is : " << cash - total << std::endl;
		}
	}
	else if (choice == 2)
	{
		std::cout << "Please swipe your card" << std::endl;

	}
	else if (choice == 3)
	{
		std::cout << "Please swipe your card" << std::endl;
	}
	else if (choice == 4)
	{
		std::cout << "Charge has been added to your account : " << std::endl;
		//add total to database.txt
	}
	else
	{
		std::cout << "Invalid choice" << std::endl;
	}
}

void printCart(const std::vector<MenuItem>& cart, double total)
{
	total = 0; // Richard // this is to initialize the total price to 0

	std::cout << std::endl;
	std::cout << "Your Cart:" << std::endl;   // Richard // used to display the cart header
	std::cout << "----------------------------" << std::endl;

	for (const auto& item : cart)
	{
		std::cout << item.name << " -$" << item.price << std::endl;
		total += item.price;
	}

	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "Total price : $" << total << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;
	//adding a way to go back to the menu to order more items or to checkout

	std::cout << "Press 'Esc' to continue shopping" << std::endl;
	std::cout << "Press 'Enter' to checkout" << std::endl;
	char choice;
	std::cin >> choice;
	//choice may only be backspace or enter
	for (; choice != 27 && choice != 13; std::cin >> choice)
	{
		Line();
		std::cout << std::endl;
		std::cout << "Sorry, you choice is invalid. Press backspace to go back to the menu or press enter to checkout";
		std::cout << std::endl;
		Line();
	}

	if (choice == 27) //MJ // if the user presses backspace
	{
		ordering = true; //MJ  // to set the ordering to true to go back to the ordering loop

		if (ordering = true)
		{
			payment(total);
		}
	}
	else if (choice == 13) //MJ  // if the user presses enter
	{
		ordering = false; //MJ // Richard // to set the ordering to false to exit the loop
	}
}

void addToCart(std::vector<MenuItem>& cart, const MenuItem& item)
{
	cart.push_back(item);                                              // Richard // this is to add the item to the end of the cart vector
	std::cout << item.name << " added to cart." << std::endl;
}

void printMenu(const std::vector<MenuItem>& menu) 
{
	cout << "\nThis is our menu for today, please remember to order before 11am to have the orders ready for the next day:" << endl;
	cout << "-----------------------------------------------------------\n";
	cout << "| Unit # | Product Description            | Price           |\n";
	cout << "-----------------------------------------------------------\n";
	for (const auto& item : menu) {
		printf("| %-7d| %-30s| $%-15.2f|\n", item.unitNumber, item.name.c_str(), item.price);
	}
	cout << "-----------------------------------------------------------\n";
}

std::vector<MenuItem> menuItems()  //Richard
{
	std::vector<MenuItem> menu = 
	{
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

void Ordering(const std::vector<MenuItem>& menu, double total)
{
	vector<MenuItem> cart;
	while (true) {
		cout << endl;
		printMenu(menu);
		cout << endl;
		cout << "Enter the unit number of the item you would like to order, or enter 0 to check out and exit, or enter 9 to check out and continue ordering:" << endl;
		int choice;
		cin >> choice;
		if (choice > 0 && choice <= menu.size()) {
			addToCart(cart, menu[choice - 1]);
		}
		else if (choice == 0) {
			printCart(cart, total);
			return;
		}
		else if (choice == 9) {
			printCart(cart, total);
			cart.clear();
		}
		else {
			cout << "Invalid choice, please enter a number between 1 and " << menu.size() << endl;
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

//create a structure for admin login

struct adminLogin //MJ
{
	std::string adminUsername;
	std::string adminPassword;
};

void newAccount(login& userLogin);   //MJ

void accountRecover(); //MJ

void loginForm(login& userLogin) //MJ 
{
	double total = 0;
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
						Ordering(menuItems(), total);

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
			if (attempt < 4)
			{
				std::cout << std::endl;
				std::cout << "Login failed. Please try again." << std::endl;
				std::cout << "............................................................" << std::endl;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "You have exceeded the maximum number of attempts." << std::endl;
				std::cout << "Please try again later." << std::endl;
				std::cout << "............................................................" << std::endl;

				//menu displays if attempts are exceeded

				int chooseFollow;

				do
				{
					std::cout << "You can continue by choosing the following : " << std::endl;
					std::cout << std::endl;
					std::cout << "1. Retry." << std::endl;
					std::cout << "2. Create an account." << std::endl;
					std::cout << "3. Need help to recover account." << std::endl;
					std::cout << "4. Exit." << std::endl;
					std::cout << "Please enter your choice number : ";
					std::cin >> chooseFollow;
					std::cout << std::endl;

					switch (chooseFollow)
					{
					case 1:
					{
						attempt = 0;
						loginForm(userLogin);
						break;
					}
					case 2:
					{
						newAccount(userLogin);
						break;
					}
					case 3:
					{
						accountRecover();
						break;
					}
					case 4:
					{
						//exit out o the program
						std::cout << "Thank you for using our program. Goodbye!" << std::endl;
						exit(0);
						break;
					}
					default:
					{
						std::cout << "Invalid choice. Please only choose the numbers 1 or 2 or 3" << std::endl;
						break;
					}
					}

				} while (attempt < 4);
			}
		}

	} while (!userFound && attempt++ < 4);
}

void accountRecover()
{
	login userLogin; //to help define the parameters of other used funtions

	int choice;
	std::string userN, mail, passw, allerG, strictdiet, mailInput;
	bool accountFound = false;
	ifstream searchU("database.txt");
	std::string line;
	std::string passLine;

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

		std::cout << std::endl;
		std::cout << "\nAccount that matched your descrpition:\n\n";
		while (getline(searchU, line))
		{

			string name = line;

			std::cout << "Username :" << " " << line;
			std::cout << std::endl;
			getline(searchU, line); //read email

			if (line == mailInput)
			{
				std::cout << "Email :" << " " << line;
				std::cout << std::endl;
				getline(searchU, passLine); // read password
				string password = passLine;
				getline(searchU, line); // read allergies
				string allergies = line;
				std::cout << "Allergies :" << " " << line;
				std::cout << std::endl;
				getline(searchU, line); // read special diets
				string diets = line;
				std::cout << "Diet requirements :" << " " << line;
				std::cout << std::endl;
				accountFound = true;

				if (accountFound = true)
				{
					std::cout << std::endl;
					char confirm;
					std::cout << "Is this you?\n";
					std::cout << "y/n : ";
					std::cin >> confirm;

					if (confirm == 'y' || confirm == 'Y')
					{
						std::cout << "This is your password :" << passLine;
						std::cout << std::endl;
						std::wcout << "Press ENTER to continue...";
						std::cin.get();
						std::cin.get();
						std::cout << std::endl;
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
			}
			else if (accountFound = false)
			{
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

void controlUserAccounts(login& userLogin, controlLogin& control)
{
	std::string line;
	std::ifstream database("database.txt");
	bool userFound = false;

	//allow user to be able to log into user accounts by just typing in the username
	std::cout << "Enter the username of the account you want to access : ";
	std::cin >> userLogin.username;
	//compare the username input with the username in the database

	while (std::getline(database, line))
	{
		if (line == userLogin.username)
		{
			getline(database, line); // read email
			if (line == userLogin.email)
			{
				userFound = true;
				// read the rest of the user information
				std::cout << "Hello" << " " << userLogin.username << std::endl;

				getline(database, line); //read password
				std::cout << "User password: " << line << endl;
				getline(database, line); // read allergies
				std::cout << "User allergies: " << line << endl;
				getline(database, line); // read special diets
				cout << "User special diets: " << line << endl;

				// prompt admin to choose an action
				int choice;
				std::cout << "Choose an action:" << std::endl;
				std::cout << "1. Edit account" << std::endl;
				std::cout << "2. Delete account" << std::endl;
				std::cout << "3. Exit" << std::endl;
				std::cin >> choice;

				switch (choice)
				{
				case 1:
					// edit account
					// prompt admin for account information and modify database
					break;
				case 2:
					// delete account
					// prompt admin for account information and remove account from database
					break;
				case 3:
					// exit admin access
					break;
				default:
					std::cout << "Invalid choice. Please choose again." << std::endl;
					controlUserAccounts(userLogin, control);
					break;
				}
				break;
			}
		}
	}
	database.close();
}

void adminStartMenu(controlLogin& control, std::vector<MenuItem>& menu, MenuItem& newItem); //MJ //StratMenu for the admin

//create a login form for admin

void adminLoginForm(adminLogin& admin, controlLogin& control, std::vector<MenuItem>& menu, MenuItem& newItem)
{
	//the admin username and password is hardcoded

	admin.adminUsername = "admin";
	admin.adminPassword = "lunch";
	std::string userName, passWord;
	int attempt = 0; //going to add a max attempt of 3

	do
	{
		Line();
		Line();
		std::cout << std::endl;
		std::cout << "Admin Login" << std::endl;
		std::cout << std::endl;
		Line();
		Line();
		std::cout << std::endl;
		std::cout << "Username : ";
		std::cin >> userName;
		std::cout << "Password :  ";
		std::cin >> passWord;

		if (userName == admin.adminUsername && passWord == admin.adminPassword)
		{
			Line();
			std::cout << std::endl;
			std::cout << "Welcome Admin" << std::endl;
			std::cout << std::endl;
			Line();
			adminStartMenu(control, menu, newItem);
		}
		else
		{
			std::cout << "Invalid username or password" << std::endl;
			std::cout << "Please try again" << std::endl;
		}

		attempt++;

	} while (attempt < 3);

}

void controlLogForm(controlLogin& control, std::vector<MenuItem>& menu, MenuItem& newItem) //MJ //admin login form
{
	std::string username, password;
	int attempt = 0;

	do
	{
		std::cout << "Please enter your username" << std::endl;
		std::cin >> username;
		std::cout << "Please enter your password" << std::endl;
		std::cin >> password;

		if (control.username == username && password == control.password)
		{
			Line();
			std::cout << std::endl;
			std::cout << "You are logged in" << std::endl;
			std::cout << std::endl;
			adminStartMenu(control, menu, newItem);
		}
		else
		{
			std::cout << "Invalid username or password" << std::endl;
		}
		attempt++;

		if (attempt < 4)
		{
			std::cout << std::endl;
			std::cout << "Error! You have reached the maximum attempts" << std::endl;
			std::cout << std::endl;
			std::cout << "Please hit Enter to Exit out of program" << std::endl;
			exit(0);
		}

	} while (attempt < 3);
}

void adminOrUser(adminLogin& admin, controlLogin& control, std::vector<MenuItem>& menu, MenuItem& newItem)  //MJ // to ask the user if they are an admin or a user
{
	std::cout << "Are you an admin or a user?" << std::endl;
	std::cout << "1. Admin" << std::endl;
	std::cout << "2. User" << std::endl;

	std::string input;
	std::getline(std::cin, input); // read input as a string

	int choice;
	std::stringstream ss(input);
	if (ss >> choice)
	{ // check if input is a valid integer
		if (choice == 1)
		{
			adminLoginForm(admin, control, menu, newItem);
		}
		else if (choice == 2)
		{
			loginGetYN();
		}
		else
		{
			std::cout << "Invalid choice" << std::endl;
			adminOrUser(admin, control, menu, newItem);
		}
	}
	else
	{ // handle invalid input (non-integer)
		std::cout << "Invalid input. Please enter a number." << std::endl;
		adminOrUser(admin, control, menu, newItem);
	}
}

//write a funtion that allows the admin to change MenuItems

std::vector<MenuItem> modifyMenu(std::vector<MenuItem> menu, MenuItem& newItem)
{
	controlLogin control; //create an instance of the controlLogin class

	//print menu for admin to see
	Line();
	std::cout << "This is you current menu" << std::endl;
	Line();
	std::cout << std::endl;
	printMenu(menu);
	std::cout << std::endl;
	Line();
	int choice;

	std::cout << "Enter the number of the item you would like to modify" << std::endl;
	std::cin >> choice;

	//check if the choice is in the range of the menu items

	if (choice <1 || choice > menu.size())
	{
		std::cout << "Invalid choice. Please choose a number between 1 and " << menu.size() << std::endl;
		return menu;
	}

	//grab the updated name and price

	std::string newName;
	double newPrice;

	std::cout << "Enter the new name of the item" << std::endl;
	std::cout <<"Pro Tip : Add the number of the item to the name to make it easier to find" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, newName);


	//the user can only input a int value and no $ signs, ect...
	while (true)
	{
		std::cout << "Enter the new price of the item" << std::endl;
		std::cin >> newPrice;

		if (std::cin.fail())
		{
			std::cout << "Invalid input. Please enter a number.\n";
			std::cin.clear(); //clear the error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //this should irnore the invalid input
		}
		else
		{
			break; //if the input is valid then break out of the loop
		}
	}

	//Update the menu item
	menu[choice - 1].name = newName;
	menu[choice - 1].price = newPrice;

	std::cout << "Item was modified successfully." << std::endl;
	std::cout << std::endl;
	//print updated menu
	Line();
	printMenu(menu);
	Line();
	std::cout << "Press Enter to continue to Start Menu" << std::endl;
	std::cin.get();
	std::cin.get();
	adminStartMenu(control, menu, newItem);
}

//creating a way for the admin to add a new menu items or remove an existing one
std::vector<MenuItem> addOrExtractMenu(std::vector<MenuItem> menu, MenuItem& newItem)
{
	controlLogin control; //create an instance of the controlLogin class

	Line();
	std::cout << "This is you current menu" << std::endl;
	Line();
	std::cout << std::endl;
	printMenu(menu);
	std::cout << std::endl;
	Line();

	//aks admin if they'd like to add or remove an item
	std::cout << "Would you like to add or remove an item?" << std::endl;
		std::cout << "1. Add" << std::endl;
		std::cout << "2. Remove" << std::endl;
		int choice;
		std::cin >> choice;

		//if the admin wants to add an item
		if (choice == 1)
		{    //this part is close to the code from the modifymenu vector I created above
			//get the name and price of the new item
			std::string newName;
			double newPrice;
			std::cout << "Enter the name of the item" << std::endl;
			std::cin.ignore();
			std::getline(std::cin, newName);
			//the user can only input a int value and no $ signs, ect...
			while (true)
			{
				std::cout << "Enter the price of the item" << std::endl;
				std::cin >> newPrice;
				//this is for incase the admin a $ sign for a double value

				if (std::cin.fail())
				{
					std::cout << "Invalid input. Please enter a number.\n";
					std::cin.clear(); //clear the error flag
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //this should irnore the invalid input
				}
				else
				{
					break; //if the input is valid then break out of the loop
				}
			}

			newItem.name = newName;
			newItem.price = newPrice;
			//add the new item to the menu
			menu.push_back(newItem);
			std::cout << "Item was added successfully." << std::endl;
			std::cout << std::endl;
			//print updated menu
			Line();
			printMenu(menu);
			Line();
			std::cout << "Press Enter to continue to Start Menu" << std::endl;
			std::cin.get();
			std::cin.get();
			adminStartMenu(control, menu, newItem);
		}

		//if the admin wants to remove an item

		else if (choice == 2)
		{
			//print the menu so the admin can see
			Line();
			std::cout << "This is you current menu" << std::endl;
			Line();
			std::cout << std::endl;
			printMenu(menu);
			std::cout << std::endl;
			Line();
			//ask the admin which item they'd like to remove
			std::cout << "Enter the number of the item you would like to remove" << std::endl;
			int index;
			std::cin >> index;
			//check if the index is in the range of the menu items
			if (index <1 || index > menu.size())
			{
				std::cout << "Invalid choice. Please choose a number between 1 and " << menu.size() << std::endl;
				return menu;
			}
			//remove the item from the menu
			menu.erase(menu.begin() + choice - 1);
			std::cout << "Item was removed successfully." << std::endl;
			std::cout << std::endl;
			//print updated menu
			Line();
			printMenu(menu);
			Line();
			std::cout << "Press Enter to continue to Start Menu" << std::endl;
			std::cin.get();
			std::cin.get();
			adminStartMenu(control, menu, newItem);
		}

		//don't forget about invalid choices
		else
		{
			std::cout<<"Error. Please only select 1 or 2"<<std::endl;
			return menu;
		}

		return menu;
}

//create a way for the admin to view all users

void adminViewUsers(controlLogin& control, std::vector<MenuItem>& menu, MenuItem& newItem)
{
	// Open database.txt
	std::ifstream file("database.txt");
	if (!file)
	{
		std::cout << "Error: Unable to open file." << std::endl;
		return;
	}

	// Read and display each line in the file
	std::string line;
	int lineNumber = 1;
	std::cout << "All users in the database:" << std::endl;
	while (std::getline(file, line))
	{
		std::cout << lineNumber << ". " << line << std::endl;
		lineNumber++;
	}

	// Close the file
	file.close();

	// Pause the program
	std::cout << "Press Enter to continue to Start Menu" << std::endl;
	std::cin.get();
	std::cin.get();
	adminStartMenu(control,menu,newItem);
}

int main()
{
	adminLogin admin; //creating an instance of the adminLogin class
	controlLogin control; //adding the structure for the admin
	std::vector<MenuItem> menu = menuItems(); // create the menu vector

	cout << "***********************************************\n"
		<< "*                                             *\n"
		<< "*                                             *\n"
		<< "*                                             *\n"
		<< "*                                             *\n"
		<< "*           Welcome to HappyMealz!            *\n"
		<< "*                                             *\n"
		<< "*                                             *\n"
		<< "*                                             *\n"
		<< "*                                             *\n"
		<< "*   We hope you enjoy using our new platform  *\n"
		<< "***********************************************\n";

	adminOrUser(admin, control, menu, newItem);

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

void adminStartMenu(controlLogin& control, std::vector<MenuItem>& menu, MenuItem& newItem) //MJ //StratMenu for the admin
{
	std::cout << std::endl;
	std::cout << "This is your start menu :" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Modify an item in the menu" << std::endl;
	std::cout << "2. Remove or add an item from the menu" << std::endl; 
	std::cout << "3. View the orders" << std::endl; 
	std::cout << "4. View the users" << std::endl; 
	std::cout << "5. Log out" << std::endl;
	//have admin choose
	int choice;
	std::cin >> choice;
	if (choice == 1)
	{
		// Call modifyMenu function
		menu = modifyMenu(menu, newItem);
	}
	else if (choice == 2)
	{
        // Call addOrExtractMenu
		menu = addOrExtractMenu(menu, newItem);
	}
	else if (choice == 3)
	{
		//view orders
	}
	else if (choice == 4)
	{
		//call view users function
		adminViewUsers(control, menu, newItem);
	}
	else if (choice == 5)
	{
		//exit the program
		Line();
		Line();
		std::cout << std::endl;
		std::cout << "You have been logged out" << std::endl;
		std::cout << std::endl;
		Line();
		Line();
		std::exit(0);
	}
	else
	{
		std::cout << "Invalid choice" << std::endl;
	}

}
