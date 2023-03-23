#include <iostream>
#include <string>
#include <vector>

struct MenuItem {
    std::string name;
    double price;
};

void line() {
    std::cout << "................................................................................................................." << std::endl;
}
// a Pattern that can be used to make things look neat and make the app more readable

bool loginGetYN() { // Richard
    // Function to ask user if they have an account
    // and return true if they do and false if they don't
}

bool checkAccount() {  // Richard
    bool hasAccount = loginGetYN();
    if (hasAccount) {
        // Code to check if user has existing account
    } else {
        // Code to create a new account
    }
}

void addToCart(std::vector<MenuItem>& cart, const MenuItem& item) {
    cart.push_back(item);                                              // Richard // this is to add the item to the end of the cart vector
    std::cout << item.name << " added to cart." << std::endl;
}

std::vector<MenuItem> cart;             // Richard // to create and empty cart vector

bool ordering = true;
while (ordering) {                      // Richard //  loop while the user is still ordering
    printMenu(menu);                  
    std::cout << "Enter the number of items you would like to order, or enter 0 to check out:" << std::endl;
    int choice;
    std::cin >> choice;
    if (choice > 0 && choice <= menu.size()) {     //Richard // If the user entered a valid menu item number
        addToCart(cart, menu[choice - 1]);         // Richard // to add the selected product to the cart
    } else if (choice == 0) {                    
        ordering = false;                          // Richard // to set the ordering to false to exit the loop
    } else {                                        // Richard // // If the user entered an invalid input
        std::cout << "Invalid choice, please enter a number between 1 and " << menu.size() << std::endl;
    }
}

void printCart(const std::vector<MenuItem>& cart) {
    double total = 0;                               // Richard // this is to initialize the total price to 0
    std::cout << "cart:" << std::endl;              // Richard // used to display the cart header
    for (const auto& item : cart) {
        std::cout << item.name << " -$" << item.price << std::endl;
        total += item.price;
    }
    std::cout << "Total price : $" << total << std::endl;   // Richard // to display the total price
}

void printMenu(const std::vector<MenuItem>& menu) {
    std::cout << "Menu:" << std::endl;                 // Richard // Displaying the menu header
    for (const auto& item : menu) {
        std::cout << item.name << " -$" << item.price << std::endl;  // Richard // Display the item name and price
    }
}

void menuItems() {                       //  Richard // List of Menu items for the user to choose from
    std::vector<MenuItem> menu = {
        {"Vegan mac n cheese", 6.00},
        {"Chicken and mayo wrap", 7.50},
        {"Mince and cheese toasty", 5.50},
        {"Sushi roll", 7.00},
        {"Fruit Cup", 4.50},
        {"Muffin", 5.00},
        {"Bag of veggie chips", 3.00},
        {"Vegetarian paella", 8.00},
        {"Chicken Salad and roll", 6.00},
        {"Crackers and cheese with apple", 3.00},
    };
}

void printCart(const std::vector<MenuItem>& cart) //Richard
{
	// below is to print the contents of the cart
	double total = 0;
	std::cout << "cart:" << std::endl;
	for (const auto& item : cart)
	{
		std::cout << item.name << " -$" << item.price << std::endl;
		total += item.price;  // allowing the product/item price to be added to the total
	}
	std::cout << "Total price : $" << total << std::endl;
}


void addToCart(vector<MenuItem>& cart, const MenuItem& item) //Richard  // here you can add items to the cart from the menu
{
	cart.push_back(item);     // this is to add the item to the end of the cart
	cout << item.name << "The item has been added to your cart." << endl;
}

struct login //MJ 
{
	std::string username;  //a struct that can be used for the login form
	std::string email;
	std::string password;
}; 

void newAccount()   //MJ
{

	//This will be questions we ask a new user

} 

void loginForm(login& userLogin, const std::vector<MenuItem>& menu) //MJ& Richard codes incoparated  //Creating a function with parameters
{
	login userLogin1;    //an exsiting account
	userLogin1.username = "Jhonny Boy";
	userLogin1.email = "jb@gmail.com";
	userLogin1.password = "car";

	login userLogin2;
	userLogin2.username = "Suzie";  //another exsisting account
	userLogin2.email = "s88@gmail.com";
	userLogin2.password = "rock";

	std::cout << "Great! Let's get you signed in" << std::endl;
	line();

	int attempts = 0;

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

		if (userLogin.username == userLogin1.username && userLogin.email == userLogin1.email && userLogin.password == userLogin1.password)
		{
			std::cout << std::endl;
			std::cout << "Welcome, " << userLogin.username << std::endl;
			printMenu(menu);
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
			if (attempts < 3)
			{
				std::cout << std::endl;
				std::cout << "Login failed. Please try again." << std::endl;
				line();
				std::cout << "Maximum number of login attepmts has been reached." << std::endl;

				int chooseFollow;

				do
				{
					std::cout << "You can continue by choosing the following : " << std::endl;
					std::cout << "1. Retry." << std::endl;
					std::cout << "2. Create an account." << std::endl;
					std::cout << "3. Exit." << std::endl;
					std::cout << "Please enter your choice number : ";
					std::cin >> chooseFollow;

					switch (chooseFollow)
					{
					case 1:
						loginForm(userLogin, menu);
						break;
					case 2:
						newAccount();
						break;
					case 3:
						return;
						break;
					default:
						std::cout << "Invalid choice. Please only choose the numbers 1 or 2 or 3" << std::endl;
						break;
					}
				} while (chooseFollow != 3);
			}
		}
	} while (attempts < 3);

}

bool loginGetYN() //MJ
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
	std::cout << "The Happy Mealz" << std::endl; //Just a heading for that this app will be
	line();

	loginGetYN();

	return 0;
}
