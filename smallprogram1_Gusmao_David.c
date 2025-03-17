// David Gusmao
// Dr. Steinberg
// COP3223 Section 001
// Small Program 1


#include<stdio.h>
#include<math.h> 

int main()
{
    //problem 1 beings...
	//no printf statements provided for this problem...
	//Here I used printf statemtents and "-" to create the "H" for problem one.
	//I also made sure to use "\n" to create new lines. 
	printf("--          --\n");
	printf("--          --\n");
	printf("--          --\n");
	printf("--          --\n");
	printf("--------------\n");
	printf("--------------\n");
	printf("--          --\n");
	printf("--          --\n");
	printf("--          --\n");
	printf("--          --\n");
	//problem 1 ends...

    //problem 2 begins...

	
	printf("Enter the amount of eggs laid for each of the 5 chickens.\n");
	
	int egg1, egg2, egg3, egg4, egg5;//Declare the variables 
	
	printf("Chicken 1: ");
	scanf("%d", &egg1); // scan for eggs
	
	printf("Chicken 2: ");
	scanf("%d", &egg2);// Egg 2
	
	printf("Chicken 3: ");
	scanf("%d", &egg3);// Egg 3
	
	printf("Chicken 4: ");
	scanf("%d", &egg4);// Egg 4
	
	printf("Chicken 5: ");
	scanf("%d", &egg5);// Egg 5
	
	// Now I will preform the calculations:
	int sum = egg1 + egg2 + egg3 + egg4 + egg5;
	int dozen = sum / 12;
	int remainder = sum % 12;
	printf("There are %d dozen(s) and %d egg(s) total.\n", dozen, remainder);
    //problem 2 ends...

    //problem 3 begins...

	printf("Let's calculate simple interest for an amount based on a duration of 5 years\nwith a rate of interest equal to 12.5%%.\n");
	//declare variables
	double amount;
	int years = 5;
	double interest = 12.5;
	
	printf("Enter the amount: ");
	scanf("%lf", &amount);
	//Now I will preform the calculations
	double result = ((amount * interest * years)/100);
	double total = result + amount;
	// output
	printf("The interest for a principal amount of $%0.2lf is $%0.2lf.\n", amount, result);
	printf("The total balance will be $%0.2lf.\n", total);
	
	
    //problem 3 ends...

    //problem 4 begins...
    
	
	printf("Let's calculate the area of the 2D car drawing.\n");
	
	printf("Let's start with the 4 circles.\n");
	double c1;// declare variable
	printf("Enter the radius: ");
	scanf("%lf", &c1);// Scan for the radius' of the circles
	
	printf("Now lets get the info on the parallelogram.\n");
	double basep, heightp;// declare variable
	
	printf("Enter the base: ");
	scanf("%lf", &basep);// Scan for the base of parallelogram
	
	printf("Enter the height: ");
	scanf("%lf", &heightp);// scan for the height of parallelogram
	
	printf("Last, lets enter the information on the triangle.\n");
	double baset, heightt;// declare variable
	
	printf("Enter the base: ");
	scanf("%lf", &baset);
	
	printf("Enter the height: ");
	scanf("%lf", &heightt);
	
	//Calculations:
	//Area of all four circles:
	double areacircle = 3.141592 * (c1 * c1);
	areacircle = areacircle * 4;
	
	//Area of all parallelogram
	double areaparallelogram = basep * heightp;
	
	//Area of Triangle
	double areatriangle = (baset * heightt)/2;
	
	//total area
	double area = areacircle + areaparallelogram + areatriangle;
	printf("The area of the 2D car is %1.5lf units.", area);
	
    //problem 4 ends...

    return 0;
}
