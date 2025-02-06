//David Gusmao
//CS1 Travid Meade
//Bandit Baiting

//any necessary preprocessor directive needed
#include<stdio.h>
#include<string.h>
#include<stdlib.h>s


//Create Structs for Placment, Location, and Array List:
//Struct Declaration
typedef struct placement placement; //placement struct
typedef struct location location; //location stuct
typedef struct arrlist arrlist; //Array List struct

//Placment Struct
struct placement{
	//ID for bait placement in location, Food level for location, taken from location
    long long int numberID, foodlevel, foodTaken; 
};
//location struct (holds placements)
struct location{
	long long int ttlfoodtaken; //Amount of food taken
	int length, limit; //length and limit of location
	char * locationname;//Name of each location | Might fix later
	placement *awway; //Array for each placement
};
//Array list struct Holds all locations
struct arrlist{
	int length, limit; //length and limit of location
	location *awway; //Array for each location
};

//Functions:
//function to create the Array list that holds locations and initializes the list
arrlist *makeArrList() {
	//Initilizes the array list
    arrlist * returnarray; 
    returnarray = (arrlist *)malloc(sizeof(arrlist));
	//declares initial length of array
    returnarray -> length = 0;
	//declares initial limit
    returnarray -> limit = 2;
    //allocate an array to hold all users
    returnarray -> awway = (location *)malloc(sizeof(location) * returnarray -> limit);

	//Returns created array
    return returnarray;
}

//intializes a new location
void initializelocation(location * location, char * locationname) {
	//Initializes length and limit of location
	location -> length = 0;
    location -> limit = 2;
	//allocate memory for an array of locations
	location -> awway = (placement *)malloc(sizeof(placement) * location -> limit);
	//allocates memory for location name
	location -> locationname = strdup(locationname); 
	//declares the total food taken to 0
	location -> ttlfoodtaken = 0;
}

//initializes a new placemnt
void initializePlacement(placement * placement, long long int numberID, long long int foodlevel){
	//Declares id, level of food, and amount of food taken for the placment
    placement -> numberID = numberID;
    placement -> foodlevel = foodlevel;
    placement -> foodTaken = 0;
}

//Append location for user input
void addLocation(location * localInput,char * locationname, long long int numberID, long long int foodlevel){
	//if input at the curret length is equal to the limit
    if(localInput -> length == localInput -> limit){
		//Double the limit
		localInput -> limit *= 2;
		//reallocate memory to the placment. 
    	localInput -> awway = (placement *)realloc(localInput -> awway, sizeof(placement)* localInput -> limit);
    }

	//Creates new placment for the new locations
    initializePlacement(&(localInput -> awway[localInput -> length]), numberID, foodlevel);
    localInput -> length++;
}

// Add a location to the list of locations
void appendArrayList(arrlist * arrlist, char *locationname, long long int numberID, long long int foodlevel){
	//if the array list at the curret length is equal to the limit
    if(arrlist -> length == arrlist -> limit){
		//Double array list limit
        arrlist -> limit *= 2;
		//reallocate memory to array list. 
        arrlist -> awway = (location *)realloc(arrlist -> awway, sizeof(location)* arrlist -> limit);
    }

	//create the new locations
    initializelocation(&(arrlist -> awway[arrlist -> length]), locationname);
	//Append the placements for the new locations
    addLocation(&(arrlist -> awway[arrlist -> length]), locationname, numberID, foodlevel); 
    arrlist -> length++;
}

//Searches for locations inputted
int checklocations(arrlist *arrlist, char *locationname, long long int numberID){
	//For length of the Array List
    for(int x = 0; x < arrlist -> length; x++){
		//If the inpuuted location == location that exists
        if(strcmp(locationname, arrlist -> awway[x].locationname) == 0){
			//for length locations
            for(int y = 0; y < arrlist -> awway[x].length; y++){
				//if inputted placement == a placments inputted 
                if(arrlist -> awway[x].awway[y].numberID == numberID) {
					//location and placement match
                    return 1; 
                }
            }
			//Only locations match
            return 2; 
        }
    }
	//New location
    return 0; 
}

//Updates information for new location and placemnt in Array List
void updateInfo(arrlist *listinfo,char *locationname, long long int numberID, long long int foodlevel){
	//For length of arraylsit
    for(int x = 0; x < listinfo -> length; x++){
		//checks for location name
        if(0 == strcmp(locationname, listinfo->awway[x].locationname)){
			//for length of location
            for(int y = 0 ; y < listinfo -> awway[x].length; y++){
				//Checks for placement
                if(numberID == listinfo -> awway[x].awway[y].numberID){
					//Checks if inputted food level is less than existing good level
                    if(foodlevel < listinfo -> awway[x].awway[y].foodlevel){
						//Print updated food level
                        printf("%lld\n", listinfo -> awway[x].awway[y].foodlevel - foodlevel);
						//Food taken = foodlevel - user input
                        listinfo -> awway[x].awway[y].foodTaken = (listinfo->awway[x].awway[y].foodlevel - foodlevel);
						//update food level
                        listinfo -> awway[x].awway[y].foodlevel = foodlevel;
						//update food taken
                        listinfo -> awway[x].ttlfoodtaken += listinfo -> awway[x].awway[y].foodTaken;
                    }
					//else food level remains the same
                    else
                    {
                        listinfo -> awway[x].awway[y].foodlevel = foodlevel;
                        printf("0\n");
                    }
                }
            }
        }
    }
}

//Prints the array list after "END -1 -1"
void printFinalArray(arrlist * arrlist){
	//For length of array list
    for(int x = 0; x < arrlist -> length; x++){
        printf("%s %lld\n", arrlist -> awway[x].locationname, arrlist -> awway[x].ttlfoodtaken);
    }
}

//frees ArrayList
void freeArrList(arrlist * arrlist){
	//For length of arraylist
    for(int x = 0; x<arrlist -> length; x++){
		//frees each location in the array list
        free(arrlist -> awway[x].locationname);
        free(arrlist -> awway[x].awway);
    }
	//Frees array list array
    free(arrlist -> awway);
	//Frees arraylist
    free(arrlist);
}

//Main fuction
int main(){
	//Creates a list of locations & allocates memory
    arrlist *allLocations = makeArrList();

    //initializes variables
    char locName[20];//Name
    long long int numberID, foodlevel;//location identifier and food level

	//Scan for first location
    scanf("%s %lld %lld", locName, &numberID, &foodlevel);

	//Loop that runs untill false
    while(1){
		
		//Cheks for "End -1 -1" input
        if(numberID == -1 && foodlevel == -1 && strcmp("END", locName) == 0){
            break;
        }
		//If food level is less than -1 correct ot 0
        if(foodlevel < -1){
        	foodlevel = 0; 
        }
		//If location does not exist then create new location
        if((checklocations(allLocations, locName, numberID)) == 0){	
			//Print statment
            printf("New placement.\n");
			//Appends new location
            appendArrayList(allLocations, locName, numberID, foodlevel);
        }
		//If location and placemnt exists update info
        else if(checklocations(allLocations, locName, numberID) == 1){
            updateInfo(allLocations, locName, numberID, foodlevel);
        }
		//If location exists but placment is new
        else if(checklocations(allLocations, locName, numberID) == 2){
			//Print statement
            printf("New placement.\n");
			//For length of locations
            for(int x = 0; x < allLocations -> length;x++){
				//look for location name
                if(strcmp(allLocations -> awway[x].locationname, locName) == 0){
					//Append create placement
                    addLocation(&(allLocations -> awway[x]), locName, numberID, foodlevel);
                }
            }
        }
		//Scans for next location placement and food level
        scanf("%s %lld %lld", locName, &numberID, &foodlevel);
    }
	//Prints final array
    printFinalArray(allLocations);
	//Frees Array List
    freeArrList(allLocations);
    return 0;
}
