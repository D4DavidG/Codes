//David Gusmao
//Dr. Steinberg
//COP3223 Section 001
//Small Program 5

#include<stdio.h>

void pickButton(int *num);
void match();
void blockbuster();
void numberFacts();


int main()
{
    
	//Problem 1
	int num = 0;
	
	pickButton(&num);
	
	//Selects Buttons
	switch(num)
		{
			case 1:
				printf("Blue Button Selected!\n");
				break;
			case 2:
				printf("Green Button Selected!\n");
				break;
			case 3:
				printf("Yellow Button Selected!\n");
				break;
			case 4:
				printf("Red Button Selected!\n");
				break;
			case 5:
				printf("Gold Button Selected!\n");
				break;
			case 6:
				printf("Black Button Selected!\n");
				break;
			case 7:
				printf("White Button Selected!\n");
				break;
			default:
				printf("Invalid Button Selected!\n");
				break;
		}
		
	//Problem 2
	match();
	
	//Problem 3
	blockbuster();
	
	//Problem 4
	numberFacts();
	
    return 0;
}

//function definition for problem 1
void pickButton(int *num)
{
	//Prints out options
	printf("Choose a button.\n");
	printf("1. Blue Button\n");
	printf("2. Green Button\n");
	printf("3. Yellow Button\n");
	printf("4. Red Button\n");
	printf("5. Gold Button\n");
	printf("6. Black Button\n");
	printf("7. White Button\n");
	printf("Selection: ");
	scanf("%d", num);
				
}

//function definition for problem 2
void match()
{
	//Declare files 
	FILE * f1ptr;
	FILE * f2ptr;
	FILE * f3ptr;
	
	//Open Files
	f1ptr = fopen("grades1.txt", "r");
	f2ptr = fopen("grades2.txt", "r");
	f3ptr = fopen("grades3.txt", "r");
	
	//Declaring Variables
	char g1, g2, g3;
	int fls = 0;
	int mtchs = 0;
	
	//Checks every line of files
	while((fscanf(f1ptr, " %c", &g1) != EOF) && (fscanf(f2ptr, " %c", &g2) != EOF) && (fscanf(f3ptr, " %c", &g3) != EOF))
	{
		if((g1 == g2) && (g2 == g3))
		{
			mtchs++;
		}
		else
		{
			fls++;
		}
	}
	
	//Determines Match
	if(fls > 0)
	{
		printf("No Match!\n");
	}
	else
	{
		printf("Match!\n");
	}
	
	fclose(f1ptr);
	fclose(f2ptr);
	fclose(f3ptr);
}

//function definition for problem 3
void blockbuster()
{

	//Declare Files
	FILE * salesptr;
	FILE * recordsale;
	
	//Open Files
	salesptr = fopen("sales.txt", "r");
	recordsale = fopen("recordsales.txt", "w");
	
	//Decalre Variables
	int customer;
	int movies;
	double cost;
	double profit;
	
	printf("Retrieving the Records from today's sale!\n");
	
	//fprintf and printf statements
	while(fscanf(salesptr, "%d%d", &customer, &movies) != EOF)
	{
		cost = (double) movies * 2.99;
		profit = profit + cost;
		printf("Customer: %d\t", customer); //yes a tab character was used
		printf("Spent: $%.2lf\n", cost);
		fprintf(recordsale, "Customer: %d\t", customer);
		fprintf(recordsale, "Spent: $%.2lf\n", cost);
	}

	printf("-----------------------------\n");
	printf("$%.2lf was made today.\n", profit);
	fprintf(recordsale, "-----------------------------\n");
	fprintf(recordsale,"$%.2lf was made today.\n", profit);
	
}


//function definition for problem 4
void numberFacts()
{
	
	//Declares Varibales and files
	int num = 1;
    FILE *numptr = fopen("numfact.txt", "w");

    printf("Number\tPart A\tPart B\tPart C\n");
    fprintf(numptr, "Number\tPart A\tPart B\tPart C\n");

	//loop that repeats until 0 or 
	//untill the input is negative
    while(num > 0) 
    {
		//ask for imput
        printf("Enter a positive integer: ");
        scanf("%d", &num); 
		
		
		//Determines if input is valid and
		//if the number is a multiple of 7, 11 or 13
        if(num > 0) 
        {
            printf("%d\t", num); 
            fprintf(numptr, "%d\t", num); 

            if((num % 7 == 0 ) || (num % 11 == 0) || (num % 13 == 0)) //if num is a multiple of 7, 11 or 13
            {
                printf("Yes!\t");
                fprintf(numptr, "Yes!\t");
            }
            else
            {
                printf("No!\t");
                fprintf(numptr, "No!\t");
            }
            if(num % 2 == 0) //if num is even or odd
            {
                printf("Even\t");
                fprintf(numptr, "Even\t");
            }
            else
            {
                printf("Odd\t");
                fprintf(numptr, "Odd\t");
            }
            int d = 0;
            int nd = 0;

            //checks for the amount of numbers 
			//that num is divisible by
            for(int x = 1; x <= num; x++) 
            {
                if(num % x == 0)
                {
                    d++;
                }
                else
                {
                    nd++;
                }
            }
			
			//chekcs if num is prime
            if(d > 2)
            {
                printf("Composite\n");
                fprintf(numptr, "Composite\n");
            }
            else
            {
                printf("Prime\n");
                fprintf(numptr, "Prime\n");
            }
        }
    }
    fclose(numptr); 
}
