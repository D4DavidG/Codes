//David Gusmao
//Dr. Steinberg
//COP3223 Section 1
//Large Program 4


//any necessary preprocessor directive needed
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

//Create Struct for each student
typedef struct{
	char name[100];
	int id;
	double homeworkAVG;
	double quizAVG;
	double examAVG;
	double weightedAVG;
}student_t;

//User Defined Functions
void addStudent(int numStdnts, student_t gradebookArr []);//Add student to gradebook
void removeStudent(int numStdnts, student_t gradebookArr []);//Removes student from gradebook
void printGrades(int numStdnts, student_t gradebookArr []);//prints grades
void updateGrades(int numStdnts, student_t gradebookArr []);//updates grades
void missingGrades(int numStdnts, student_t gradebookArr []);//prints names with missing grades
void printToFile(int numStdnts, student_t gradebookArr []);//prints all grades to file
void chomp(char word []);//Chomp
void clearBuffer();//Clears Buff

int main()
{
	//Initialises number of students and array
	int numStdnts = 0;
	student_t gradebookArr[5];
	
	
	//Input for switch
	char menuInpt; 
	int cond = 1; //Loop untill 0
	
	//Loop untill program end
	while(cond != 0)
	{
		//Print Menu
		printf("************************************\n");
		printf("What would you like to do in the gradebook?\n");
		printf("A: Add a Student to the Gradebook\n");
		printf("R: Remove a Student from the Gradebook\n");
		printf("P: Print Grades from the Gradebook\n");
		printf("U: Update a Student's Grade\n");
		printf("M: Determine who is missing Grades\n");
		printf("E: Exit\n");
		printf("************************************\n");
		printf("Selection: ");
		scanf(" %c", &menuInpt);
		
		switch(menuInpt)
		{
			//case a add students
			case 'a':
			case 'A':
				if(numStdnts < 5)//If less than 5 add students
				{
					addStudent(numStdnts, gradebookArr);
					numStdnts++;
				}
				else
				{
					printf("No room for student\n");
				}
				
				clearBuffer();
				break;
			
			//case r remove students
			case 'r':
			case 'R':
				if(numStdnts > 0)//if any students remove students
				{
					removeStudent(numStdnts, gradebookArr);
					numStdnts--;
				}
				else
				{
					printf("No students to remove\n");
				}
				
				clearBuffer();
				break;
				
			//case p print garades
			case 'p':
			case 'P':
				if(numStdnts > 0)//If any students
					{
						printGrades(numStdnts, gradebookArr);
					}
					else
					{
						printf("No Students\n");
					}
					
					clearBuffer();
					break;
				
			//case u update grades
			case 'u':
			case 'U':
				if(numStdnts > 0)//If any students update grades
				{
					updateGrades(numStdnts, gradebookArr);
				}
				else
				{
					printf("No Students\n");
				}
				
				clearBuffer();
				break;
				
			//case m determine missing grades
			case 'm':
			case 'M':
				if(numStdnts > 0)//If any students print grades
				{
					missingGrades(numStdnts, gradebookArr);
				}
				else
				{
					printf("No Students\n");
				}
				
				clearBuffer();
				break;
			
			//case e exit and print to file.
			case 'e':
			case 'E':
				cond = 0;
				printToFile(numStdnts, gradebookArr);
				printf("Goodbye\n");
				
				clearBuffer();
				break;
				
			//Default Invalid
			default:
				printf("Invalid Option\n");
				clearBuffer();
		}
	}


}
void addStudent(int numStdnts, student_t gradebookArr [])
{
	
	//Enter student name
	printf("Enter Student Name: ");
	getchar();
	fgets(gradebookArr[numStdnts].name, 100, stdin);
	//Enter Student Id
	printf("Enter Student ID: ");
	scanf("%d", &gradebookArr[numStdnts].id);
	
	//Declares all grades as invalid
	gradebookArr[numStdnts].homeworkAVG = -1;
	gradebookArr[numStdnts].quizAVG = -1;
	gradebookArr[numStdnts].examAVG = -1;
	
}

void removeStudent(int numStdnts, student_t gradebookArr [])
{
	
	//Initialize variables
	int removenStdnt;
	int condition = 1;
	
	//Prints names of students to choose from
	for(int x = 0; x < numStdnts; x++) 
	{
		printf("%d.  %s\n", x + 1, gradebookArr[x].name);
	}
	
	//Loop untill valid unput
	while(condition == 1)
	{
		//Print statemnt
		printf("Which Student do you wish to remove? ");
		scanf("%d", &removenStdnt);
		
		//Options for students
		switch(removenStdnt)
		{
			case 1:
			
				//Moves every student back to delte remove chosen student
				for(int x = 0; x < numStdnts; x++)
				{
					gradebookArr[x] = gradebookArr[x + 1];
				}
				condition = 0;
				break;
				
			case 2:
			
				//Moves every student back to delte remove chosen student
				for(int x = 1; x < numStdnts; x++)
				{
					gradebookArr[x] = gradebookArr[x + 1];
				}
				condition = 0;
				break;
				
			case 3:
			
				//Moves every student back to delte remove chosen student
				for(int x = 2; x < numStdnts; x++)
				{
					gradebookArr[x] = gradebookArr[x + 1];
				}
				condition = 0;
				break;
				
			case 4:
			
				//Moves every student back to delte remove chosen student
				for(int x = 3; x < numStdnts; x++)
				{
					gradebookArr[x] = gradebookArr[x + 1];
				}
				condition = 0;
				break;
				
			case 5:
			
				//Moves every student back to delte remove chosen student
				for(int x = 4; x < numStdnts; x++)
				{
					gradebookArr[x] = gradebookArr[x + 1];
				}
				condition = 0;
				break;
			
			//Default invalid
			default:
				printf("Invalid\n");
			
		}
	}
}

void updateGrades(int numStdnts, student_t gradebookArr [])
{
	//initialize variables
	int updateStdnt;
	int condition = 1;
	double newH;
	double newQ;
	double newE;
	
	//Print out options
	for(int x = 0; x < numStdnts; x++) 
	{
		printf("%d.  %s\n", x + 1, gradebookArr[x].name);
	}
	
	//While input valid
	while(condition == 1)
	{
		printf("Which Student do you wish to update grades? ");
		scanf("%d", &updateStdnt);
		
		switch(updateStdnt)
		{
			case 1:
				//Collects information for student
				printf("Enter Homework Average:");
				scanf("%lf", &gradebookArr[0].homeworkAVG);
				
				printf("Enter Quiz Average:");
				scanf("%lf", &gradebookArr[0].quizAVG);
				
				printf("Enter Exem Average:");
				scanf("%lf", &gradebookArr[0].examAVG);
				condition = 0;
				break;
				
			case 2:
				//Collects information for student
				printf("Enter Homework Average:");
				scanf("%lf", &gradebookArr[1].homeworkAVG);
				
				printf("Enter Quiz Average:");
				scanf("%lf", &gradebookArr[1].quizAVG);
				
				printf("Enter Exem Average:");
				scanf("%lf", &gradebookArr[1].examAVG);
				condition = 0;
				break;
				
			case 3:
				//Collects information for student
				printf("Enter Homework Average:");
				scanf("%lf", &gradebookArr[2].homeworkAVG);
				
				printf("Enter Quiz Average:");
				scanf("%lf", &gradebookArr[2].quizAVG);
				
				printf("Enter Exem Average:");
				scanf("%lf", &gradebookArr[2].examAVG);
				condition = 0;
				break;
				
			case 4:
				//Collects information for student
				printf("Enter Homework Average:");
				scanf("%lf", &gradebookArr[3].homeworkAVG);
				
				printf("Enter Quiz Average:");
				scanf("%lf", &gradebookArr[3].quizAVG);
				
				printf("Enter Exem Average:");
				scanf("%lf", &gradebookArr[3].examAVG);
				condition = 0;
				break;
				
			case 5:
				//Collects information for student
				printf("Enter Homework Average:");
				scanf("%lf", &gradebookArr[4].homeworkAVG);
				
				printf("Enter Quiz Average:");
				scanf("%lf", &gradebookArr[4].quizAVG);
				
				printf("Enter Exem Average:");
				scanf("%lf", &gradebookArr[4].examAVG);
				condition = 0;
				break;
			
			default:
				//invalid input
				printf("Invalid\n");
			
		}
	}
}


void printGrades(int numStdnts, student_t gradebookArr [])
{
	//For each student print out information
	for(int x = 0; x < numStdnts; x++)
	{
		if((gradebookArr[x].homeworkAVG >= 0) && (gradebookArr[x].quizAVG >= 0) && (gradebookArr[x].examAVG >= 0))
		{
			printf("Name: %s\n", gradebookArr[x].name);
			printf("ID: %d\n", gradebookArr[x].id);
			printf("Homework Average: %1.2lf\n", gradebookArr[x].homeworkAVG);
			printf("Quiz Average: %1.2lf\n", gradebookArr[x].quizAVG);
			printf("Exam Average: %1.2lf\n", gradebookArr[x].examAVG);
			
			//Collects weighted avaerage
			gradebookArr[x].weightedAVG = (gradebookArr[x].homeworkAVG * .5) + (gradebookArr[x].quizAVG * .2) +(gradebookArr[x].examAVG * .3);
			printf("Weighted Average: %1.2lf\n", gradebookArr[x].weightedAVG);
		}
	}
}

void missingGrades(int numStdnts, student_t gradebookArr [])
{
	//Print statemnt
	printf("These Students are Missing Grades \n");
	
	//Prints out every name missing grades. 
	for(int x = 0; x < numStdnts; x++)
	{
		if((gradebookArr[x].homeworkAVG < 0) && (gradebookArr[x].quizAVG < 0) && (gradebookArr[x].examAVG < 0))
		{
			printf("Name: %s\n", gradebookArr[x].name);
		}
	}
}

void printToFile(int numStdnts, student_t gradebookArr [])
{
	//File open
	FILE *gradesptr;
	gradesptr = fopen("gradebook.txt", "a");
	
	//Prints all values into file
	for(int x = 0; x < numStdnts; x++)
	{
		fprintf(gradesptr,"************************************************************\n");
		fprintf(gradesptr,"Name: %s\n", gradebookArr[x].name);
		fprintf(gradesptr,"ID: %d\n", gradebookArr[x].id);
		fprintf(gradesptr,"Homework Average: %1.2lf\n", gradebookArr[x].homeworkAVG);
		fprintf(gradesptr,"Quiz Average: %1.2lf\n", gradebookArr[x].quizAVG);
		fprintf(gradesptr,"Exam Average: %1.2lf\n", gradebookArr[x].examAVG);
		
		//Collects wieghted average
		gradebookArr[x].weightedAVG = (gradebookArr[x].homeworkAVG * .5) + (gradebookArr[x].quizAVG * .2) +(gradebookArr[x].examAVG * .3);
		fprintf(gradesptr,"Weighted Average: %1.2lf\n", gradebookArr[x].weightedAVG);
		fprintf(gradesptr,"************************************************************\n");
	}
	
	//File close
	fclose(gradesptr);
}

//Chomp
void chomp(char word [])
{
	if(word[strlen(word) - 1] == '\n')
	word[strlen(word) - 1] = '\0';
}

//Clearbuff
void clearBuffer()
{
	while(getchar() != '\n');
}