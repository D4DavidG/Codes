//David Gusmao
//Dr. Steinberg
//COP3223 Section 001
//Small Program 2

#include<stdio.h>
#include<math.h>
//any macro constants needed

int calcHypotenuse(double a, double b); //prototype for calcHypotenuse
void rentalPrices(); //prototype for rentalPrices
int timeDisplay(int t); //prototype for timeDisplay
void mathFunction(int n); //prototype for problem 4

int main()
{
    //Call for calcHypotenuse
	double a, b; //declaring variables
	printf("Enter the value for a: ");
	scanf("%lf", &a); // scans for variables
	printf("Enter the value for b: ");
	scanf("%lf", &b); // scans for variables
	calcHypotenuse(a, b);
	
	//Call for rentalPrices
	rentalPrices();
	
	//Call for timeDisplay
	int time;
	printf("Enter the seconds: ");
	scanf("%d", &time);
	timeDisplay(time);
	
	//Call for mathFunction
	int number;
	printf("Enter the value for n: ");
	scanf("%d", &number);
	mathFunction(number);
	
    return 0;
}

//function definition for calcHypotenuse
int calcHypotenuse(double a, double b)
{
   double c = sqrt(pow(a, 2) + pow(b, 2)); //computes the length of the hypotenuse
   printf("If a = %0.3lf and b = %0.3lf, then that means the hypotenuse is %0.3lf.\n", a, b, c);
   
}

//function definition for rentalPrices
void rentalPrices()
{
	int days;//declaring variable
	//print statment
	printf("Hello Luis!\n");
	printf("Thank you for considering Hertz for your car rental needs.\n");
	printf("You have asked to compare prices for three vehicles.\n");
	printf("Please enter the number of days you plan to rent the vehicle: ");
	scanf("%d", &days);
	printf("Here are the prices excluding tax.\n");
	
	//declaring variables and calculations
	double tesla = 46.48 * days; 
	double chevy = 49.53 * days;
	double nissan = 50.72 * days;
	
	//print statments:
	printf("Tesla Model 3 Standard Range: $%0.2lf\n", tesla);
	printf("Chevrolet Malibu: $%0.2lf\n", chevy);
	printf("Nissan Rogue: $%0.2lf\n", nissan);
	
}

//function definition for problem 3
int timeDisplay(int t)
{
	//declaring variables:
	int sec = t;
	
	int hours = t / 3600; // Hour calculations
	
	t = t % 3600;
	int mins = t / 60; //Minute Calculations
	
	t = t % 60; // Second calculations
	
	printf("%d seconds is %d hours, %d minutes, and %d seconds.\n", sec, hours, mins, t);
}

//function definition for problem 4
void mathFunction(int n)
{
  //some code for problem 4
	double n1 = pow(n,n) - pow(2,n);
	double n2 = sqrt(n) * pow(n,4);
	
	double d2 = exp(n-2) + 9;
	
	double f = (n1 / (n2 / d2)) - (n * 8);
	printf("The function computes the value %0.3lf.\n", f);
	
  
}