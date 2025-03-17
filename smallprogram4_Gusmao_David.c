//David Gusmao
//Dr. Steinberg
//COP3223 Section 001
//Small Program 4

#include<stdio.h>
#include<math.h> 

void countEvenOdd(); //prototype for problem 1
void drawShape(); //prototype for problem 2
void toyPhone(); //prototype for problem 3
void costPreview(int years, int rate); //prototype for problem 4

int main()
{
    
	//Problem 1
	countEvenOdd();
	
	//Problem 2 
	drawShape();
	
	//Problem 2
	toyPhone();
	
	//Problem 4
	int years;
	int rate; 
	int num = 1;
	
	while(num != 0)
	{
		printf("Enter the number years to observe: ");
		scanf("%d", &years);
		printf("Enter the percentage rate to increase by per year: ");
		scanf("%d", &rate);
		printf("Current Tuition: $20000.00\n");
		
		if(years >= 0)
		{
			costPreview(years, rate);
			--num;
		}
		else
		{
			printf("Invalid input.\n");
		}
	}
	
	
    return 0;
}

//function definition for problem 1
void countEvenOdd()
{
	//Declaring Variables
	int evenInput = 0; //Total of Even inputs
	int numOfEven = 0; //Total Amount of Even inputs
	int oddInput = 0; //Total of Odd inputs
	int numOfOdd = 0; //Total Amount of Odd inputs
	int input = 0; 
	int num; 
	int run = 1;


	//Will loop untill the user inputs 0
	while(run != 0)
	{
		//User Input
		printf("Enter a positive integer: ");
		scanf("%d", &input); 
		num = input % 2; //Determines whether input is odd or even
		
		//Determines Valid Input
		if(num == 0 && input > 0) 
		{
			evenInput = evenInput + input;
			++numOfEven;
		}
		else if(num != 0 && input > 0)
		{
			oddInput = oddInput + input;
			++numOfOdd;
		}
		else if(input == 0)
		{
			--run;
			
			double averageEven = (double)evenInput/(double)numOfEven;
			if(numOfEven == 0)
			{
				averageEven = 0;
			}
			printf("%d even numbers were entered and the average is %1.6lf\n", numOfEven, averageEven);
			
			double averageOdd = (double)oddInput/(double)numOfOdd;
			if(numOfOdd == 0)
			{
				averageOdd = 0;
			}
			printf("%d odd numbers were entered and the average is %1.6lf\n", numOfOdd, averageOdd);

			
		}
		else
		{
			printf("That's a negative number!\n");
		}
	}
}
//function definition for problem 2
void drawShape()
{
	
	int firstgap = 0;
	int in;
	int a;
	int b;
	int c;
	int d;
	int i = 1;
	
	while(i != 0)
	{
		printf("How many rows would you like the shape to have?: ");
		scanf("%d", &in);
		int secondgap = in - 3;
		
		if(in < 1)
		{

			printf("Invalid Input. Please try again.\n");
		}
		if(in > 1)
		{
			for(a = 0; a < in; a++)//	loop for top
			{
				printf("*");
			}
			printf("\n");
			
			for(int middleline = 2; middleline < in; middleline++)//	loop for middle 
			{
				printf("*");
				
				//  loop for gap
				for(b = 0; b < firstgap; b++)
				{
					printf(" ");
				}
				
				printf("*");
				
				for(c = 0; c < secondgap; c++) //  loop for second gap
				{
					printf(" ");
				}
				printf("*\n");
				
				firstgap++;
				secondgap--;
			}

			for(d = 0; d < in; d++)//	loop for bottom
			{
				printf("*");
			}
			printf("\n");
			
			--i;
		}
		if(in == 1)
		{
			printf("*");
			--i;
			
		}
	}
	
}

//function definition for problem 3
void toyPhone()
{
	int option;
	int condition = 0;
	printf("Welcome to the Toy Phone!\n");
	
	while(condition != 1)
	{
		printf("Enter a button: ");
		scanf("%d", &option);
		switch(option)
			{
				case 1:						
					printf("Hello!\n");
					break;
					
				case 2:
					printf("Loopy Loops!\n");
					break;
										
				case 3:
					printf("Programming is fun!\n");
					break;
					
				case 4:
					printf("Semicolons can be a pain to forget!\n");						
					break;
					
				case 5:
					printf("Are you ready for pointers?\n");
					break;
					
				case 6:						
					++condition;
					break;
					
				default:
				printf("Invalid option.\n");
				
		}
	}
	printf("Goodbye!\n");

}

//function definition for problem 4
void costPreview(int years, int rate)
{
	//Declare Variables
	double amount = 20000;
	double result;
	double numerator;
	
	//Now I will preform the calculations
	for(int y = 1; y <= years; y++)
	{
		numerator = (amount * rate * y);
		result = (numerator/100.00) + amount;
		printf("Year %d: $%1.2lf\n", y, result);
	}


}