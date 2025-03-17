//David Gusmao
//Dr. Steinberg
//COP3223 Section 001
//Small Program 6

#include<stdio.h>

void salesInfo(int sales[]); //prototype for problem 1
void testScoreInfo(double arr[], int n); //prototype for problem 2
int removeDuplicates(int arr[]); //prototype for problem 3
void sort(int arr[]);
void mergeValues(int arr1[], int arr2[], int arr3[]); //prototype for problem 4

int main()
{
	//Problem 1
	//declares array with 9 integers of 0
    int sales[9]; //initalizes the array
	for(int x = 0; x < 9; ++x)
	{
		sales[x] = 0;
	}
	//calls Funtion
	salesInfo(sales);


	
	//Problem 2
	double arr2[250];
	int index = 0;
	double input = 1;
	
	//loop for requesting valid inputs untill negative input
	while((input >= 0) && (index < 250))
	{
		printf("Enter a score: ");
		scanf("%lf", &input); //Scans for gross Salary
		
		
		//If input is valid add it to the array
		if(input >= 0)
		{
			arr2[index] = input;
			++index;
		}
		
	}
	//Call funtion
	testScoreInfo(arr2, index);
	
	
	//Problem 3
	int arr3[15];
	
	//loop for requesting inputs
	for(int a = 0; a < 15; ++a)
	{
		printf("Enter an integer: ");
		scanf("%d", &arr3[a]); //puts inputs in array
	}
	
	
	printf("Array before removing duplicates.\n");
	//Prints each value in array
	for(int b = 0; b < 15; ++b)
	{
		printf("nums[%d] = %d\n", b, arr3[b]);
	}
	
	
	//Call function and creates new length
	int y = removeDuplicates(arr3);
	
	
	printf("Array after removing duplicates.\n");
	//Prints each value in array
	for(int c = 0; c < y; ++c)
	{
		printf("nums[%d] = %d\n", c, arr3[c]);
	}
	
	
	//problem 4
	int arra[5];
	int arrb[5];		
	int arrc[5];
	
	
	//loop for requesting valid inputs 
	for(int f = 0; f < 5; ++f)
	{
		printf("Enter an integer for array1: ");
		scanf("%d", &arra[f]); //puts inputs in array
	}
	//loop for requesting valid inputs 
	for(int g = 0; g < 5; ++g)
	{
		printf("Enter an integer for array2: ");
		scanf("%d", &arrb[g]); //puts inputs in array
	}
	
	mergeValues(arra, arrb, arrc);
	
	for(int h = 0; h < 5; ++h)
	{
		printf("arr1[%d] = %d\t", h, arra[h]);
		printf("arr2[%d] = %d\t", h, arrb[h]);
		printf("arr3[%d] = %d\n", h, arrc[h]);
	}

	return 0;
}
 
//function definition for problem 1
//The function takes an array of integers
void salesInfo(int sales[])
{
	//Intialises the input
	double gross = 0;
	while (gross >= 0)
	{
		printf("Enter gross sale: "); //collects intput from user
		scanf("%lf", &gross);
		
		//adds 1 to array depending on user input
		if (200 + (gross * 0.09) >= 200 && (200 + (gross * 0.09) <= 299))
		{
			sales[0]++;
		}
		else if (200 + (gross * 0.09) >= 300 && (200 + (gross * 0.09) <= 399))
		{
			sales[1]++;
		}
		else if (200 + (gross * 0.09) >= 400 && (200 + (gross * 0.09) <= 499))
		{
			sales[2]++;
		}
		else if (200 + (gross * 0.09) >= 500 && (200 + (gross * 0.09) <= 599))
		{
			sales[3]++;
		}
		else if (200 + (gross * 0.09) >= 600 && (200 + (gross * 0.09) <= 699))
		{
			sales[4]++;
		}
		else if (200 + (gross * 0.09) >= 700 && (200 + (gross * 0.09) <= 799))
		{
			sales[5]++;
		}
		else if (200 + (gross * 0.09) >= 800 && (200 + (gross * 0.09) <= 899))
		{
			sales[6]++;
		}
		else if (200 + (gross * 0.09) >= 900 && (200 + (gross * 0.09) <= 999))
		{
			sales[7]++;
		}
		else if (200 + (gross * 0.09) >= 1000)
		{
			sales[8]++;
		}
	}
	
	for(int x = 0; x < 9; x++) //prints values
	{
		printf("sales[%d] = %d\n", x, sales[x]);
	}
}

//function definition for problem 2
void testScoreInfo(double arr[], int n)
{
	//Declares variables
	double max = arr[0];
	double min = arr[0];
	double sum = 0;
	
	//Look for maxium and minium
	for(int x = 1; x < n; ++x)
	{
		//Maximum
		if(arr[x] > max)
		{
			max = arr[x];
		}
		
		//Minum
		if(arr[x] < min)
		{
			min = arr[x];
		}
	}
	
	
	
	//the sum
	for(int y = 0; y < n; ++y)
	{
		sum = sum + arr[y];
	}
	
	//The avaerage
	double avrg = sum / n;
	
	printf("Highest Score: %1.2lf\n", max);
	printf("Lowest Score: %1.2lf\n", min);
	printf("Average: %1.2lf\n", avrg);
	
}


//function definition for problem 3
int removeDuplicates(int arr[])
{
	
	//Sorts array
	sort(arr);
	
	//initiates changing length
	int newLength = 15;
	
	//Moves duplicates to the end of the array
	for(int x = 0; x < newLength-1; ++x)
	{
		if(arr[x] == arr[x + 1])
		{
			
			for(int y = x; y < newLength; ++y)
			{
				arr[y] = arr[y + 1];
			}
			newLength--;
			x--;
		}
		
	}

	return newLength;
}

void sort(int arr[])
{
	
	int temp;
	
	//Sorts array from smalles to largest value
	for(int x = 0; x < 15; ++x)
	{
		for(int y = x+1; y < 15; ++y)
		{
			//if value above is greater than value below we swap
			if(arr[x] > arr[y])
			{
				temp = arr[x]; 
				arr[x] = arr[y]; 
				arr[y] = temp; 
			}
		}
	}
}

//function definition for problem 4
void mergeValues(int arr1[], int arr2[], int arr3[])
{
	//the sum each value in arr1 and arr2 is arr3
	for(int x = 0; x < 5; x++)
	{
		arr3[x] = arr2[x] + arr1[x];
	}
}
