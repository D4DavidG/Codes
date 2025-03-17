//David Gusmao
//Dr. Steinberg
//COP3223 Section 001
//Small Program 3

#include<stdio.h>
#include<math.h> 

int creditCheck(double x); //prototype for creditCheck
void universityAdmission(double gpa, int ts); //prototype for universityAdmission 
void keyPad(); //prototype for keyPad
double carpenter(); //prototype for carpenter

int main()
{
	//probelm 1 Start ----------------------
	double x;
	printf("Enter the price: ");
	scanf("%lf", &x); 
	//Credit Check conditions:
	if(x > 0)
	{
		if(creditCheck(x) == 1) //Call funtion
		{
			printf("Approved!\n");
		}
		else
		{
			printf("Not Approved!\n");
		}
	}
	else
	{
		printf("Error!\n");
	}
	//problem 1 End ------------------------
	
	
	
	//problem 2 Start ----------------------
	printf("Welcome to the University Admission System!\n");
	//GPA intput
	double gpa;
	printf("Enter the GPA: ");
	scanf("%lf", &gpa);
	
	//Test score input
	int ts;
	printf("Enter the test score: ");
	scanf("%d", &ts); 
	
	//Call funtion
	universityAdmission(gpa, ts);
	//problem 2 End -------------------------
	
	
	
	//Problem 3 Start ------------------------
	keyPad();
	//Problem 3 End --------------------------
	
	
	
	//Problem 4 Start ------------------------
	double total = carpenter();
	if(total > 0)
	{
		printf("Bruce will charge $%0.2lf.\n", total);
	}
	else
	{
		printf("Could not compute cost...\n");
	}
    //Problem 4 End --------------------------
	
	
    return 0;
}

//function definition for creditCheck
int creditCheck(double x)
{
	
	if(x < 9000.00)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//function definition for universityAdmission
void universityAdmission(double gpa, int ts)
{
	if((gpa > 0.00 ) && (ts > 0)) //If inputs are valid
	{
		if((gpa >= 3.00) && (ts >= 60))//First criteria for students
		{
			printf("Admissions is Approved!\n");
			if((gpa >= 3.50 ) && (ts >= 70)) //Consider a scholarship award
			{
				printf("Consider for Scholarship Award!\n");
			}
		}
		else if((gpa < 3.00 ) && (gpa >= 2.00) && (ts >= 80)) //Second criteria for students
		{
			printf("Admissions is Approved!\n");
		}
		else //Deny Admission
		{
			printf("Admissions is Denied!\n");
		}
	}
	else //Invalid input
	{
		printf("Invalid Input!\n");
	}
}

//function definition for keyPad
void keyPad()
{
	printf("Welcome to the Crazy Keypad!\n");
	printf("Select one of the following options for a message.\n");
	printf("Option 1\n");
	printf("Option 2\n");
	printf("Option 3\n");
	printf("Option 4\n");
	printf("Option 5\n");
	printf("Option Selected: ");
	int option;
	scanf("%d", &option); 
	
	
	switch(option)
		{
			case 1:
				printf("Opening Vault 712...\n");
				break;
				
			case 2:
				printf("Opening Secret Elevator...\n");
				break;
				
			case 3:
				printf("Calling the Boss...\n");
				break;
				
			case 4:
				printf("Backup on the way...\n");
				break;
				
			case 5:
				printf("Alarm activated...\n");
				break;
				
			default:
			printf("System Locked...\n");

		}


}

//function definition for problem 4
double carpenter()
{
	//Declaring Variables
	int price;
    int oak = 15;
    int gL = 12;
    int ltrs;
    char O;
	char G;
    
	
	//Printf Statements
    printf("Welcome to Bruce's Carpentry Services!\n");
    
    printf("Would you like the sign made out of oak?\n");
    printf("Enter y for yes or n for no: ");
    scanf(" %c", &O); //Scans for oak responce
    
	//Determine valid input
    if ((O == 'y') || (O == 'Y') || (O == 'n') || (O == 'N'))
    {
        printf("Enter the number of characters on the sign: "); //Input for charecters
        scanf("%d", &ltrs);
        if (ltrs >= 0)
        {
            printf("Would you like gold-leaf lettering?\n"); //scans for gold leaf response
            printf("Enter y for yes or n for no: ");
            scanf(" %c", &G);
            
            if ((G == 'y') || (G == 'Y') || (G == 'n')|| (G == 'N'))
            {
                price = 1;
            }
            else
            {
                price = -1; //Error check
            }
        }
        else
        {
            price = -1;  //Error check
        }
    }
    else
    {
        price = -1;  //Error check
    }
    
	
	//Calculations
    if(price > 0)
    {
        price = 30;
        if ((O == 'y')|| (O == 'Y'))
        {
            price = price + oak;
        }
        if ((G == 'y') || (G == 'Y'))
        {
            price = price + gL;
        }
        if (ltrs > 5)
        {
            ltrs = ltrs - 5;
            price = price + (ltrs * 2);
        }
    }
    
    return price;
}