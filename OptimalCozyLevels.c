//Optimal Cozy Levels
//David Gusmao
//Travis Meade CS1

#include <stdio.h>
#include <stdlib.h>

//----------------------Golobal Values----------------------
//Initialize Values
int numCats, MaxCozy, MinCatCozy; //Total number of cats, maxium amoutn of cozieness of all cats, and coziest least cozy cat
//Arrays for code
int index[15]; //array of indexes
int familyArr[15][3]; //array of cat relationships
int cozyArr[15][15]; //array of cozy relations
//---------------------------------------------------------

//Initialize funtion declaration. 
void catculations(int perm); //Recursive Function takes in permutation

int main(void){
    // get amount of cats
    scanf("%d", &numCats);

    //Scan for cat cozieness level with families
    for (int row = 0; row < numCats; row++){//Rows are number of cats
        for (int col = 0; col < 3; col++) {//Columns are number of families
            scanf("%d", &familyArr[row][col]);
        }
    }

    //Scan for cat cozieness with other cats
    for (int row = 0; row <numCats; row++) {//Rows are number of cats
        for (int col = 0; col <numCats; col++){//Columns are number of cats
            scanf("%d", &cozyArr[row][col]);
        }
    }
    
    //Initialize both values as absurdly small numbers. 
    MaxCozy = -42069;//Abusurd number
    MinCatCozy = -42069; //Absurd number
    catculations(0); //Call recursive fucntion starting at 0
    
    //Print results
    printf("%d %d\n", MaxCozy, MinCatCozy);

    //Return 0
    return 0;
}

void catculations(int perm) //This fuction will calculate all permutations recursivly. 
{
    if (perm == numCats)
    {
        int sum = 0; //sum cozyness 
        int min = 42069; //Initial minimum as abrudly large number
        int familycat[3] = {0}; //Number of cats for each family 

        //Will check each family for a cat, add it, and update levels of cozyness. 
        for (int row = 0; row < numCats; row++){//Interaes throught the number cats.
            int currentFam = index[row]; //Family being checked
            familycat[currentFam]++; //Adds a cat to that family 
            int cozyLevel = familyArr[row][currentFam]; //Updates level of cozyness

            for (int col = 0; col < numCats; col++){ //Interates through the families. 
                if ((row != col) && (index[col] == currentFam)){ //Makes sure cat is in same family and not being compared ot itself. 
                    cozyLevel += cozyArr[row][col]; //Adds the coresponding cat's cozieness to the current cozy level.
                }
            }

            sum += cozyLevel;//Increases sum of cozyness

            if (cozyLevel < min){ //Updates miniumum cozy level if less than overall min
                min = cozyLevel;
            }
        }

        //Will scrap permutation if thers is a family without a cat
        for (int row = 0; row < 3; row++){ //Loops throught families
            if (familycat[row] == 0){//family has no cats
                return; //If a family has no cats then return
            }
        }

        //If a new maxium minimum cozy cat is found then the value will update
        if(min > MinCatCozy){
            MinCatCozy = min;
        }

        //If a new cumulative max cozyness is found then max cozy updates.
        if (sum > MaxCozy){ 
            MaxCozy = sum;
        }
        return; //End pemutaion
    }

    //recursive call
    for (int currentFam = 0; currentFam < 3; currentFam++){ //Interates through each family. 
        index[perm] = currentFam; //updates the index of the recurance.
        catculations(perm + 1); //Recurrs the next index and incremnts what cat we are on. 
    }
}