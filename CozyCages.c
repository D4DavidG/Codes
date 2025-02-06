//David Gusmao
//Cozy Cages
//Travis Meade
//If anything else is wrong here I will be greatly surprised.

//any necessary preprocessor directive needed
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Family Family;
//Create Struct for each student
struct Family{
    char * fam[3];
};


//initialize functions
void addCat(int cages, char ** catarray);
void schedule(int cages, int weeks, char ** catarray);

int main(){

	int cages; //number of cages to be determined. 
	int weeks; //number of weeks to go though. 

	
	
	scanf("%d %d", &cages, &weeks); //Asks for the amount 
	
	if((cages >= 3 && cages <= 500) && (weeks >= 1 && weeks <= 500)){ //If parameters are true. 
		char * catarray[cages];//Declares cats array. 
		addCat(cages, catarray); //Enter cat name
		schedule(cages, weeks, catarray);//Begins Schedule

		//Free memory
		for(int i = 0; i < cages; i++){
			free(catarray[i]);
		}
		for(int i = 0; i < 3; i++){
			free(Family.fam[i]);
		}
	}
	
  return 0;
}

//Add's cages to cat array
void addCat(int cages, char ** catarray){
	
	for(int x = 0; x < cages; x++)//For number of cages
	{
		catarray[x]=(char *)malloc(30 * sizeof(char));//Allocate memory
		scanf("%s", catarray[x]);//adds cages catarray to array.
	}

}

void schedule(int cages, int weeks, char ** catarray){

	//Family Positions
	int positionF1 = 0;
	int positionF2 = 1;
	int positionF3 = 2;

	//Name lenths


	//Amount of moves each family can make
	int movesF1 = 2;
	int movesF2 = 3;
	int movesF3 = 5;
	
	//Allocate memory for all three families
	Family.fam[0]=(char *)malloc(sizeof(char) * 20);//Initiallize Name length for family 1
	Family.fam[1]=(char *)malloc(sizeof(char) * 20);//Initiallize Name length for family 2
	Family.fam[2]=(char *)malloc(sizeof(char) * 20);//Initiallize Name length for family 3

	for(int w = 1; w <= weeks; w++){//Loop for inputed amount ofweeks.
		//Checker if family has adopted cat
		int checkf1 = 0;
		int checkf2 = 0;
		int checkf3 = 0;
		//Family one
		//If family 2 or 3 does not have the cat
		if((strcmp(catarray[positionF1], Family.fam[1]) != 0) && (strcmp(catarray[positionF1], Family.fam[2]) != 0)){
			catarray[positionF1] = (char *)realloc(catarray[positionF1], ((strlen(catarray[positionF1])+ 4) * sizeof(char)));//Increase Name length
			strcat(catarray[positionF1], "Lee");//Append suffix
			Family.fam[0] = (char *)realloc(Family.fam[0], ((strlen(catarray[positionF1])+ 4) * sizeof(char)));//Increase Name length
			strcpy(Family.fam[0], catarray[positionF1]);//Give Family cat
			checkf1++;//Family has adopted
		}
		if(!checkf1){//If no adoption return cat to cage
			strcpy(Family.fam[0], " ");
		}
		//Family two
		//If family 1 or 3 does not have the cat
		if((strcmp(catarray[positionF2], Family.fam[0]) != 0) && (strcmp(catarray[positionF2], Family.fam[2]) != 0)){
			catarray[positionF2] = (char *)realloc(catarray[positionF2], ((strlen(catarray[positionF2])+ 4) * sizeof(char)));//Increase Name Length
			strcat(catarray[positionF2], "Lyn");//Append suffix
			Family.fam[1]=(char *)realloc(Family.fam[1], ((strlen(catarray[positionF2])+ 4) * sizeof(char)));//Increase Name Length
			strcpy(Family.fam[1], catarray[positionF2]);//Give Family cat
			checkf2++;//Family has adopted
		}
		if(!checkf2){//If no adoption return cat to cage
			strcpy(Family.fam[1], " ");
		}
		//Family three
		//If family 1 or 2 does not have the cat
		if((strcmp(catarray[positionF3], Family.fam[0]) != 0) && (strcmp(catarray[positionF3], Family.fam[1]) != 0)){
			catarray[positionF3] = (char *)realloc(catarray[positionF3], ((strlen(catarray[positionF3])+ 4) * sizeof(char)));//Increase Name Length
			strcat(catarray[positionF3], "Eve");//Append suffix
			Family.fam[2]=(char *)realloc(Family.fam[2], ((strlen(catarray[positionF3])+ 4) * sizeof(char)));//Increase Name Length
			strcpy(Family.fam[2], catarray[positionF3]);//Give Family cat
			checkf3++;//Family has adopted
		}
		if(!checkf3){//If no adoption return cat to cage
			strcpy(Family.fam[2], " ");
		}

		if(!(w == weeks)){
			positionF1 = (positionF1 + movesF1) % cages; //Updates postion for Family 1
			positionF2 = (positionF2 + movesF2) % cages; //Updates postion for Family 2
			positionF3 = (positionF3 + movesF3) % cages; //Updates postion for Family 3
		}
	}

	//Loop trough index 0 if cat name == F1 || F2 || F3, print cat not found, else print cat name.
	for(int c = 0; c < cages; c++){//Loop for inputed amount ofweeks.
		//IF cat is held by family
		if(!strcmp(catarray[c], Family.fam[0]) || !strcmp(catarray[c], Family.fam[1]) || !strcmp(catarray[c], Family.fam[2])){
			printf("No cat found.\n");
		} else{//Cat is still in cage
			printf("%s\n", catarray[c]);
		}
	}
	
}