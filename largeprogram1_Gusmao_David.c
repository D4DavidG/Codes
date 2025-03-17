//David Gusmao
//Dr. Steinberg
//COP3223
//Large Program 1 Skeleton

#define ROUNDS 5
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void greeting(); //display welcome message to user
void playRound(int round); //play one round
int pickOne(); //retrieve the user's guess
int computerPick(); //computer makes its pick
int battle(int player1, int player2); //battle rock...paper...scissor
void result(int player1, int player2); //overall winner of round

int main()
{
	greeting(); //display greeting message
	
	//setup random generator
	int seed;
	printf("Before we start, pick a number to determine how random I will be.\n");
	scanf("%d", &seed);
    srand(seed);
	printf("All set now!\n");
	
	
	for(int x = 0; x < ROUNDS; ++x)
	{
		playRound(x + 1);
	}
	
	printf("********************************************************\n");
	printf("Thank you for playing!\n");
	printf("********************************************************\n");
	return 0;
}


void greeting()
{
	printf("********************************************************\n");
	printf("Welcome to rock paper scissor game!\n");
	printf("Here are the rules.\n");
	printf("You and I will get to choose rock, paper, or scissor.\n");
	printf("After we made a decision we will reveal it and determine the winner based on these rules.\n");
	printf("Rock beats Scissor!\n");
	printf("Paper beats Rock!\n");
	printf("Scissor beats Paper!\n");
	printf("If we both pick the same option, then it is a tie.\n");
	printf("Ready to play?...Here we go!\n");
	printf("********************************************************\n");
}

void playRound(int round)//must win three times to win an entire round
{
	printf("Welcome to a new round %d!\n", round);
	printf("Best out of three...Let's go!\n");
	
	int p1wins = 0;
	int p2wins = 0;
	
	
	//loop that keeps track of wins until respective player reaches 3. we will learn about conditional loops soon :)
	while(p1wins != 3 && p2wins != 3)
	{
		//Code inside this control structure repeats until someone wins 3 games
		printf("********************************************************\n");
		//Display for number of wins so far:
		printf("Player 1 has won %d times\n", p1wins);
		printf("Player 2 has won %d times\n", p2wins);
		
		//Call pick one:
		int p1 = pickOne(); //retrieve the user's guess
		//Call computer pick:
		int p2 = computerPick(); //reterieve random number
		
		//If choice is invalid
		if(p1 > 0 && p1 < 4)
		{
			//States the results of the each player's picks. 
			if(p1 == 1)
			{
				printf("Player 1 used Rock and ");
			}
			else if(p1 == 2)
			{
				printf("Player 1 used Paper and ");
			}
			else
			{
				printf("Player 1 used Scissor and ");
			}
			
			if(p2== 1)
			{
				printf("Player 2 used Rock.\n");
			}
			else if(p2 == 2)
			{
				printf("Player 2 used Paper.\n");
			}
			else
			{
				printf("Player 2 used Scissor.\n");
			}
			
			//Call battle function
			int wins = battle(p1, p2);
			
			if(wins == 2)
			{
				++p1wins;
			}
			else if(wins == 3)
			{
				++p2wins;
			}
		}
		else
		{
			printf("Someone made an invalid choice.\n");
			printf("********************************************************\n");
		}
	}
	//End of while loop
	
	//Calls Result
	result(p1wins, p2wins);
	
}

int pickOne()
{
	int pick1; //Variable for Player 1's picks
	printf("1---Rock\n");
	printf("2---Paper\n");
	printf("3---Scissor\n");
	printf("Make your selection: ");
	scanf("%d", &pick1);
	
	return pick1;
}

int computerPick()
{
	
	printf("I'm making my selection now.\n");
	//Generates a random number between 1 and 3
	int pick2 = (rand() % 3) + 1;

	return pick2;
}

int battle(int player1, int player2)
{

	if(player1 == 1 && player2 == 2)
	{
		printf("Paper Beats Rock!\n");
		printf("********************************************************\n");
		return 3;
	}
	else if(player1 == 1 && player2 == 3)
	{
		printf("Rock Beats Scissors!\n");
		printf("********************************************************\n");
		return 2;
	}
	else if(player1 == 2 && player2 == 1)
	{
		printf("Paper Beats Rock!\n");
		printf("********************************************************\n");
		return 2;
	}
	else if(player1 == 2 && player2 == 3)
	{
		printf("Scissors Beats Paper\n");
		printf("********************************************************\n");
		return 3;
	}
	else if(player1 == 3 && player2 == 1)
	{
		printf("Rock Beats Scissors!\n");
		printf("********************************************************\n");
		return 3;
	}
	else if(player1 == 3 && player2 == 2)
	{
		printf("Scissors Beats Paper\n");
		printf("********************************************************\n");
		return 2;
	}
	else
	{
		printf("TIE!\n");
		printf("********************************************************\n");
		return 1;
	}
	
}

void result(int player1, int player2)
{
	//compares the number of wins
	//determiens who won
	if(player1 == 3)
	{
		printf("You won! I’ll let you have this one.\n");
	}
	else if(player2 == 3)
	{
		printf("I won! Haha better luck next time!\n");
	}
}