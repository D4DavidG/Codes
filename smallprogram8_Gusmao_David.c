//David Gusmao
//Dr. Steinberg
//COP3223 Section 1
//Small Progaram 8


//any necessary preprocessor directive needed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LIMIT 50

typedef struct{
    char * fname; //first name
	char * lname; //last name
	char * show; //favorite show
}record_t;

record_t * createArray(int maxsize);
record_t * insert(record_t *myarray, int *maxsize, int *currentsize); 
void display(record_t *myarray, int currentsize);
record_t * doubleIt(record_t *arr, int size); 
int removeRecord(record_t *arr, int size, int index); 
void freeRecords(record_t *arr, int size); 
void chomp(char word []);
void clearBuffer();//Clears Buff

int main(void)
{
	int maxsize;

	printf("Enter a size for the dynamic array: ");
	scanf("%d", &maxsize);


	record_t *myarray = createArray(maxsize);
	
	int currentsize = 0;
	int option = -1;
	
	while(option != 0)
    {
		printf("%d\n", maxsize);
		printf("%d\n", currentsize);
		printf("\n");
		
		
        printf("What would you like to do?\n");
        printf("1: Insert a record\n");
        printf("2: Display records\n");
        printf("3: Remove record\n");
        printf("4: Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Insert was selected...\n");
                myarray = insert(myarray, &maxsize, &currentsize);
				currentsize++;
                break;

            case 2:
                printf("Display was selected...\n");
                display(myarray, currentsize);
                break;

            case 3:
                printf("Remove was selected...\n");
                printf("Select an index of record to remove...\n");
                int index;
                scanf("%d", &index);
                currentsize = removeRecord(myarray,currentsize,index);
                break;

            case 4:
                printf("Exiting...\n");
                option = 0;
				break;

            default:
                printf("Invalid Selection...\n");


        }

    }
	
	freeRecords(myarray, currentsize);
	free(myarray);

	myarray = NULL;

	return 0;
}

record_t * createArray(int maxsize)
{
	record_t * arr = malloc(maxsize * sizeof(record_t));
	
	if(arr == NULL)
	{
		printf("malloc error in createArray...program exiting\n");
		exit(1);
	}
	
	return arr;
}



void display(record_t *myarray, int currentsize)
{
	printf("---------------------------------\n");

	for(int x = 0; x < currentsize; ++x)
	{
	    printf("myarray[%d].fname = %s\n", x, (x + myarray)->fname); //try it with myarray[x].name
		printf("myarray[%d].lname = %s\n", x, (x + myarray)->lname); //try it with myarray[x].name
		printf("myarray[%d].show = %s\n", x, (x + myarray)->show); //try it with myarray[x].show
	}

	printf("---------------------------------\n");
}

void chomp(char word [])
{
	if(word[strlen(word) - 1] == '\n')
		word[strlen(word) - 1] = '\0';
}

//Clears buffer
void clearBuffer()
{
	while(getchar() != '\n');
}

record_t * insert(record_t *myarray, int *maxsize, int *currentsize) //Instert new record
{
	
	//Checking if Need to double it
	if(*currentsize >= *maxsize)
	{
		printf("Array is full...Need to doubleIt...\n");

		//Doubling the max size before funtion call. 
		*maxsize = *maxsize * 2;
		myarray = doubleIt(myarray, *maxsize);
		
	}
	
	//Malloc Statements
	myarray[*currentsize].fname = malloc(LIMIT * sizeof(char));
	myarray[*currentsize].lname = malloc(LIMIT * sizeof(char));
	myarray[*currentsize].show = malloc(LIMIT * sizeof(char));
	
	//Checks for malloc error
	if((myarray[*currentsize].fname == NULL) ||(myarray[*currentsize].lname == NULL) ||(myarray[*currentsize].show == NULL))
	{
		printf("malloc error in insert...program exiting\n");
		exit(1);
	}
	
	//Inputs for name
	printf("Enter the first name: ");
	scanf("%s", myarray[*currentsize].fname);
	
	//Clear buff
	clearBuffer();

	//Inputs for name
	printf("Enter the last name: ");
	scanf("%s", myarray[*currentsize].lname);
	
	//Clear buff
	clearBuffer();
	
	//fgets for show
	printf("Enter favorite show: ");
	fgets(myarray[*currentsize].show, LIMIT, stdin);
	
	//Chomp
	chomp(myarray[*currentsize].show);

	//Return new array
	return myarray;
}

record_t * doubleIt(record_t *arr, int size)
{
	//Get the older size of arr
	int oldSize = size / 2;
	
	//Creating a new array
	record_t *myarray = createArray(size);
	
	//Check for malloc errors
	if(myarray == NULL)
	{
		printf("malloc error in doubleIt...program exiting\n");
		exit(1);
	}
	
	//Mallocs new components
	for(int x = 0; x < size; x++)
	{
		myarray[x].fname = malloc(LIMIT *sizeof(char));
		myarray[x].lname = malloc(LIMIT *sizeof(char));
		myarray[x].show = malloc(LIMIT *sizeof(char));
		
		
		//Check for malloc errors
		if((myarray[x].fname == NULL) ||(myarray[x].lname == NULL) ||(myarray[x].show == NULL))
		{
			printf("malloc error in doubleIt...program exiting\n");
			exit(1);
		}
	}
	
	
	//Copies over new values to new array
	for(int x = 0; x < oldSize; x++)
	{
		strcpy(myarray[x].fname, arr[x].fname);
		strcpy(myarray[x].lname, arr[x].lname); 
		strcpy(myarray[x].show, arr[x].show);
	}
	
	//Frees old values
	for(int x = 0; x < oldSize; x++)
	{
		free(arr[x].fname);
		free(arr[x].lname);
		free(arr[x].show);
	}
	
	//Frees array
	free(arr);
	
	//Retrun array
	return myarray;
}

int removeRecord(record_t *arr, int size, int index)
{
	
	//Checks if valid index
	if((index > (size - 1)) || (index < 0))
	{
		printf("Invalid Index\n");
	}
	else
	{
		//Frees index that will be romoved
		free(arr[index].fname);
		free(arr[index].lname);
		free(arr[index].show);
	
		//Replacs index by moveing each back
		for(int x = index; x < size - 1; x++)
		{
			arr[x].fname = arr[x + 1].fname;
			arr[x].lname = arr[x + 1].lname;
			arr[x].show = arr[x + 1].show;
		}
		
		//Shortens array length
		size--;
	}
	
	
	return size;
}

void freeRecords(record_t *arr, int size)
{
	//Frees each record for the length of array. 
	for(int x = 0; x < size; x++)
	{
		free(arr[x].fname);
		free(arr[x].lname);
		free(arr[x].show);
	}
}