//David Gusmao
//Dr. Steinberg
//COP3223 Section 001
//Small Program 7

//any necessary preprocessor directive needed
#include<stdio.h>
#include<string.h>
#include<ctype.h>
//any macro constants needed

void lastWordLength(char arr[]); //prototype for problem 1
void truncateSentence(char arr2[], int n); //prototype for problem 2
int strongPasswordCheck(char arr3[]); //prototype for problem 3
int romanNumber(char arr4[]); //prototype for problem 4
void clearBuffer(); //Clears buffer
void chomp(char word []); //Chomp

int main()
{
	//Problem 1
	//Declare array
    char arr [500];
	
	printf("Enter a sentence: ");
	fgets(arr, 500, stdin); //Collects sentance
	lastWordLength(arr); //Call function
	
	
	//Problem 2
	//Declare array
	char arr2 [500];
	
	printf("Enter a sentence: ");
	fgets(arr2, 500, stdin); //Collects sentance
	
	//Declare number of words
	int n;
	printf("Truncate sentence to how many words: ");
	scanf("%d", &n);
	
	truncateSentence(arr2, n); //Call function
	

	//Problem 3
	clearBuffer(); //Cleares Buffer
	//Declare array
    char arr3 [100];
	
	printf("Enter your password: ");
	fgets(arr3, 100, stdin); //Collects sentance
	
	int result = strongPasswordCheck(arr3); //Call function
	
	
	if(result == 1)//If true strong passowrd
	{
		printf("%s is a strong password.\n", arr3);
	}
	else //If else weak passowrd
	{
		printf("%s is not a strong password.\n", arr3);
	}
	
	//Problem 4
	
	//Declare array
    char arr4 [30];
	
	printf("Enter a roman numeral: ");
	fgets(arr4, 30, stdin); //Collects sentance
	
	int num = romanNumber(arr4); //Call function
	
	printf("%s = %d\n", arr4, num);
	
	
    return 0;

}

void clearBuffer()
{
	while(getchar() != '\n');
}


void chomp(char word [])
{
	if(word[strlen(word) - 1] == '\n')
	word[strlen(word) - 1] = '\0';
}


//function definition for problem 1
void lastWordLength(char arr[])
{
	chomp(arr); //Call chomp
	
	//Define Variables
	int length = strlen(arr);
	int wordlength = 0;
	
	//Counts the length of last word in array
	for(int i = length-1; i >= 0; --i)//goes though array backwards
	{
		if(isalpha(arr[i]) != 0)
		{
			wordlength++;
		}
		else if((arr[i] == ' ') && (wordlength > 0))//Breaks if word ends
		{
			break;
		}
	}
	
	printf("Length of last word in \"%s\" is %d.\n", arr, wordlength);//Print statement
	
}

//function definition for problem 2
void truncateSentence(char arr2[], int n)
{
	chomp(arr2);//Call Chomp
	
	//Declare variables
	int length = strlen(arr2);
	int counter = 0;
	
	//Crounts the amount of words in array
	for(int i = 0; i < length; ++i)
	{
		if(arr2[i] == ' ')
		{
			++counter;
		}
		
		//When arrived at nth word break
		if(counter == n)
		{
			arr2[i] = '\0'; 
			break;
		}
	}
	
	//Printf statement
	printf("Truncated sentence is \"%s\"\n", arr2);
}

//function definition for problem 3
int strongPasswordCheck(char arr3[])
{
	chomp(arr3);//Call chomp
	
	//Declare Variables
	int condition1 = 0; //Length
	int condition2 = 0; //Types of Chars
	int condition3 = 0; //Repating Chars
	int length = strlen(arr3);
	int lowers = 0;//Lowercase letters
	int uppers = 0;//Uppercase letters
	int digis = 0;//digets
	int counter = 0;
	
	
	//password is between 6 characters and 20 (inclusive)
	if((length >= 6) && (length <= 20))
	{
		condition1 = 1; 
	}
	
	//contains at least one lowercase letter, two uppercase letters, and three digits
	for(int i = 0; i < length; i++)
	{
		if(islower(arr3[i]))
		{
			lowers++;
		}
		else if(isupper(arr3[i]))
		{
			uppers++;
		}
		else if(isdigit(arr3[i]))
		{
			digis++;
		}
	}
	
	if((lowers >= 1) && (uppers >= 2) && (digis >= 3))
	{
		condition2 = 1;//If input is valid
	}
	else
	{
		condition2 = 0;//input is invalid
	}
	
	
	//string doesn't have three repeating characters in a row
	//copying arr3 to copied
	char copied[100];
	strcpy(copied, arr3);
	int newlength = strlen(copied);
	
	//Changes each letter to lowercase
	for(int x = 0; x < newlength; x++)
	{
		copied[x] = tolower(copied[x]);
	}

	//Searches for duplicates
	for (int x = 1; x < newlength; x++) 
	{
		if((copied[x - 1] == copied[x]) && (copied[x] == copied[x + 1]))
		{
			counter++;
		}
    }
	
	//If no duplicates true, else false
	if(counter == 0)
	{
		condition3 = 1;
	}
	else
	{
		condition3 = 0;
	}
	
	int result;
	
	//If all condtions true funtion is true
	if((condition1 == 1) && (condition2 == 1) && (condition3 == 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

//function definition for problem 4
int romanNumber(char arr4[])
{
	chomp(arr4);//Call chomp
	
	//Declare Variabbles
	int length = strlen(arr4);
	int sum = 0;
	
	//Checks for each type of roman numeral
	for(int i = 0; i < length; i++)
	{
		if(arr4[i] == 'I')
		{
			if(arr4[i + 1] == 'V')
			{
				sum += -1;
			}
			else if(arr4[i + 1] == 'X')
			{
				sum += -1;
			}
			else
			{
				sum += 1;
			}
		}
		else if(arr4[i] == 'V')
		{
			sum += 5;
		}
		else if(arr4[i] == 'X')
		{
			if(arr4[i + 1] == 'L')
			{
				sum += -10;
			}
			else if(arr4[i + 1] == 'C')
			{
				sum += -10;
			}
			else
			{
				sum += 10;
			}
		}
		else if(arr4[i] == 'L')
		{
			sum += 50;
		}
		else if(arr4[i] == 'C')
		{
			if(arr4[i + 1] == 'D')
			{
				sum += -100;
			}
			else if(arr4[i + 1] == 'M')
			{
				sum += -100;
			}
			else
			{
				sum += 100;
			}
		}
		else if(arr4[i] == 'D')
		{
			sum += 500;
		}
		else if(arr4[i] == 'M')
		{
			sum += 1000;
		}
	}
	
	return sum;
	
	
}