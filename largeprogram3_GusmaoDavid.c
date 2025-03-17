//David Gusmao
//Dr. Steinberg
//COP3223 Section 1
//Large Program 3


//any necessary preprocessor directive needed
#include<stdio.h>
#include<string.h>
#include<ctype.h>
//any macro constants needed
#define STRIKES 6
#define SIZE 20


void maskWord (char starword[], int size); //mask word with stars to display
int playRound(char starword[], char answer[]); //play a round of hangman
int occurencesInWord(char userguess, char answer[]); //times letter occurs in word
void updateStarWord(char starword[], char answer[], char userguess); //replace respective *
int guessTheWord(char answer []); //guess the word
void playAgain(int *play); //ask user to play again


int main()
{
	//Greeting Lines
	printf("Welcome to the Hangman Game!\n");
	printf("************************************************************************\n");
	printf("Here are the rules.\n");
	printf("I will provide you a set of * characters for each round.\n");
	printf("Each * represents a letter in the English Alphabet\n");
	printf("You must figure out each letter of the missing word.\n");
	printf("For every correct letter guessed, I will reveal its place in the word.\n");
	printf("Each mistake will result in a strike.\n");
	printf("strikes will result in a loss that round.\n");
	printf("Are you ready? Here we go!\n");
	printf("************************************************************************\n");
	
	
	
	//Declare file
	FILE * wordsptr;
	
	//Declare Array + length + variables
	char answer [SIZE + 1];
	char starword [SIZE + 1];
	int size;
	int game = 1;
	int play = 1;
	

	
	//Open Files
	wordsptr = fopen("words.txt", "r");
	
	while((fscanf(wordsptr, "%s", answer) != EOF) && (play == 1))
	{
		
		//Length of size
		size = strlen(answer);
		
		//Call Maskword
		maskWord(starword, size);
		
		//Win or Loss
		game = playRound(starword, answer);
			
		//If Loss print this statment
		if(game == 0)
		{
			printf("************************************************************************\n");
			printf("Sorry you did not win the round. The word was staircase.\n");
			
		}
		
		//Call play Again
		playAgain(&play);
		
	}
	
	//Good bye
	printf("Thank you for playing today.\n");
	
	
	
	return 0;
}

void maskWord (char starword[], int size)
{
	//Changes each letter to a star
	int x;
	for(x = 0; x < size; x++)
	{
		starword[x] = '*';
	}
	
	starword[x] = '\0';
}

int playRound(char starword[], char answer[])
{
	//Welcomes to round
	printf("Welcome to the Round!\n");
	
	//Collects size of starword
	int size = size = strlen(starword);
	printf("the size of the word has %d letters.\n\n", size);

	//Initialize variables
	int strikes = 0;
	int correctg = 0;
	char letters [40] = {};
	int counter = 0;
	char userguess;
	int occurcheck;
	int guess;
	int result;
	
	//While loop for playround
	while(strikes < STRIKES)
	{
		//Amount of Strikes
		printf("You currently have %d strike(s).\n", strikes);
		
		//Print list of guessed letters
		printf("Letter(s) you have guessed: %s\n\n", letters);
		
		//List of guessed words
		updateStarWord(starword, answer, userguess);
		printf("%s\n\n", starword);
		
		//Guess input
		printf("Enter your guess: ");
		scanf(" %c", &userguess);
		
		//Update Star word
		updateStarWord(starword, answer, userguess);
		
		//If guess is valid
		if(isalpha(userguess))
		{
			//Check for duplicate letters
			if(occurencesInWord(userguess, letters) == 0)
			{
				letters[counter] = userguess;
				counter++;
				
				//Lowercase Letters
				for(int x = 0; x < strlen(letters); x++)
				{
					letters[x] = tolower(letters[x]);
				}
			}
			
			//call occurencesInWord
			occurcheck = occurencesInWord(userguess, answer);
			
			//If letter is in word
			if(occurcheck == 1)
			{
				//If letter is in word
				printf("The letter %c is in the word.\n\n", userguess);
				correctg++;
			}
			else
			{
				//Letter is not in word so we add 1 stike
				printf("The letter %c is NOT in the word.\n\n", userguess);
				strikes++; 
				//Reset amount of correct respences in a row. 
				correctg = 0;
			}
			
			//When user get 2 consecutive correct guesses.
			if(correctg == 2 && strcmp(starword, answer) != 0)
			{
				printf("You have made at least 2 consecutive correct guesses. Would you like to to guess the word (0 for no and 1 for yes):");
				scanf("%d", &guess);
				
				//Clear Buffer
				while(getchar() != '\n');
				
				printf("\n");
				
				//If guess is yes
				if(guess == 1)
				{
					result = guessTheWord(answer);
					if(result == 1)
					{
						printf("Congratulations! You won! The word was %s\n", answer);
						strikes = 6;
					}
					else
					{
						printf("Sorry. That is not the word.");
					}
				}
				else
				{
					//Reset amount of correct respences in a row.
					correctg = 0;
				}
			}
			//If user guessed all the words
			if(strcmp(starword, answer) == 0)
			{
				printf("Congratulations! You won! The word was %s\n", answer);
				strikes = 6;
			}
			
			
		}
		else
		{
			//User misunput
			printf("You did not enter a letter from the alphabet\n");
		}
		
		
	}
	
	//Win
	if(result == 1)
	{
		return 1;
	}
	else if(starword == answer)
	{
		//Win
		return 1;
	}
	else
	{
		//Loss
		return 0;
	}
}

int occurencesInWord(char userguess, char answer[])
{
	//Counts number of occurances
	int occr = 0;
	
	//Searches for matches in answer
	for(int x = 0; x < strlen(answer); x++)
	{
		if(answer[x] == userguess)
		{
			occr++;
		}
	}


	
	//If any matches return 1, if else return 0
	if(occr > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

void updateStarWord(char starword[], char answer[], char userguess)
{
	//For length of answer update matching charecters
	for(int x = 0; x < strlen(answer); x++)
	{
		if(answer[x] == userguess)
		{
			starword[x] = userguess;
		}
	}
}

int guessTheWord(char answer [])
{
	
	//Guess at full word
	char useranswer [SIZE];
	
	printf("Enter your guess: ");
	scanf("%s", useranswer);
	while(getchar() != '\n');
	
	//If correct return 1, else return 0
	if(strcmp(useranswer, answer) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void playAgain(int *play)
{
	//Clear Buff
	while(getchar() != '\n');
	
	//Ask to play new round
	printf("************************************************************************\n");
	printf("Would you like to play another round?\n");
	printf("1: Yes\n");
	printf("2: No\n");
	printf("Choice: ");
	scanf("%d", play);
	printf("************************************************************************\n");
}