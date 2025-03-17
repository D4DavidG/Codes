//Jan Doe
//Dr. Steinberg
//COP3223 Section 1
//Large Program 2

#include<stdio.h>

void greeting(); //welcome the user to the coffee shop
void order(double *balance); //user will make a purchase
void viewAccount(double *balance); //display current account balance of user
void transaction(double *balance, double price); //transaction with user account
void reload(double *balance); //reload your account balance
void displayMenu(); //display beverage/food options and prices


int main()
{
	greeting();
	
	char selection;
	int stopper = 1;
	double balance = 0.00;
	double *bPTR = &balance;
	
	while(stopper == 1)
	{
		printf("\n");
		printf("*****************************************************\n");
		printf("Please select one of the following options.\n");
		printf("O: Order\n");
		printf("V: View Account Summary\n");
		printf("D: Display Menu\n");
		printf("R: Reload Account\n");
		printf("E: Exit\n");
		printf("*****************************************************\n");
		printf("Please select what you would like to do.\n");
		printf("Option Selected: ");
		scanf(" %c", &selection);
		printf("\n");
		
		switch(selection)
			{
				case 'O':
				case 'o':
					printf("You selected View Order Option.\n");
					order(bPTR);
					printf("\n");
					break;
					
				case 'V':
				case 'v':
					printf("You selected View Account Summary Option.\n");
					viewAccount(bPTR);
					printf("\n");
					break;
					
				case 'D':
				case 'd':
					printf("You selected Display Menu Option.\n");
					printf("Here are the options!\n");
					displayMenu();
					printf("\n");
					break;
					
				case 'R':
				case 'r':
					printf("You selected View Account Reload Option.\n");
					reload(bPTR);
					break;
					
				case 'E':
				case 'e':
					printf("Exit\n");
					stopper = 0;
					break;
					
				default:
					printf("Try again\n");
					printf("\n");
				
			}
	}
	
	return 0;
}

void greeting()
{
	printf("\n");
	printf("*****************************************************\n");
	printf("Welcome to the Knightro's Coffee Shop!\n");
	printf("We serve delicious coffee and snacks!\n");
	printf("How can we help you today?\n");
	printf("*****************************************************\n");
	printf("\n");
}

void displayMenu()
{
	
	printf("*****************************************************\n");
	printf("1. Hot Coffee                            $3.53\n");
	printf("2. Iced Coffee                           $4.20\n");
	printf("3. Hot Latte                             $3.13\n");
	printf("4. Iced Latte                            $4.12\n");
	printf("5. Bagel (includes cream cheese)         $3.99\n");
	printf("6. Big Scone                             $4.99\n");
	printf("7. Frozen Coffee                         $5.03\n");
	printf("8. Bottle Water                          $1.50\n");
	printf("*****************************************************\n");
	
}

void viewAccount(double *balance)
{
	
	printf("*****************************************************\n");
	printf("Here is your current account balance.\n");
	printf("You have $%1.2lf in your account.\n", *balance);
	printf("*****************************************************\n");
	
}

void reload(double *balance)
{
	
	int choice;
	
	int loopy = 1;
	while(loopy == 1)
	{
		printf("*****************************************************\n");
		printf("How much would you like to reload to your account?\n");
		printf("1: $1.00\n");
		printf("2: $5.00\n");
		printf("3: $10.00\n");
		printf("Option Selected:"); 
		scanf("%d", &choice);
		printf("*****************************************************\n");
		
		if(choice == 1)
		{
			*balance = *balance + 1.00;
			printf("$1.00 has been added to your account successfully!\n");
			loopy = 0;
		}
		else if(choice == 2)
		{
			*balance = *balance + 5.00;
			printf("$5.00 has been added to your account successfully!\n");
			loopy = 0;
		}
		else if(choice == 3)
		{
			*balance = *balance + 10.00;
			printf("$10.00 has been added to your account successfully!\n");
			loopy = 0;
		}
		else
		{
			printf("Try Again Please.\n");
		}
	}
	printf("*****************************************************");
}

void order(double *balance)
{
	
	printf("*****************************************************\n");
	printf("Here are the options!\n");
	printf("*****************************************************\n");
	displayMenu();

	int option;
	int loop = 1;
	double price;
	
	while(loop == 1)
	{
		printf("What would you like today?\n");
		printf("Option Selected: \n");
		scanf("%d", &option);
		printf("\n");
		
		
		if(option == 1)
		{
			price = 3.53;
			printf("Hot Coffee has been selected. Total price is: $3.53\n");
			loop = 0;
		}
		else if(option == 2)
		{
			price = 4.20;
			printf("Iced Coffee has been selected. Total price is: $4.20\n");
			loop = 0;
		}
		else if(option == 3)
		{
			price = 3.13;
			printf("Hot Latte has been selected. Total price is: $3.13\n");
			loop = 0;
		}
		else if(option == 4)
		{
			price = 4.12;
			printf("Iced Latte has been selected. Total price is: $4.12\n");
			loop = 0;
		}
		else if(option == 5)
		{
			price = 3.99;
			printf("Bagel (includes cream cheese) has been selected. Total price is: $3.99\n");
			loop = 0;
		}
		else if(option == 6)
		{
			price = 4.99;
			printf("Big Scone has been selected. Total price is: $4.99\n");
			loop = 0;
		}
		else if(option == 7)
		{
			price = 5.03;
			printf("Frozen Coffee has been selected. Total price is: $5.03\n");
			loop = 0;
		}
		else if(option == 8)
		{
			price = 1.50;
			printf("Bottle Water has been selected. Total price is: $1.50\n");
			loop = 0;
		}
		else
		{
			printf("Try again\n");
			printf("\n");
		}
	}
	
	printf("Beginning Transaction Process.\n");
	transaction(balance, price);
	
}

void transaction(double *balance, double price)
{
	
	double newB = *balance - price; 
	
	if(newB < 0)
	{
		while(newB < 0)
		{
			printf("You do not have enough in your account.\n");
			printf("Please reload your account balance.\n");
			reload(balance);
			newB = *balance - price;
		}
	}
	else
	{
		printf("u have enough money\n");
		//transaction
	}
	
	printf("Your account balance before official transaction: $%1.2lf\n", *balance);
	printf("Billing $%1.2lf to your account.\n", price);
	*balance = *balance - price;
	printf("Transaction was successful!\n");
	printf("You have now $%1.2lf in your account balance.\n", *balance);

}