//David Gusmao
//Elephant Extraction
//CD1 Travis Meade

//Include statemnts
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct Prototypes
typedef struct Node Node;
typedef struct Stack Stack;
typedef struct Elephant Elephant;

// Struct definitions
struct Node{
    int row, col;
    Node *next;
};

struct Stack{
    Node *head;
    int size;
};

struct Elephant{
    Stack memory;
    int row, col;
};

// Fuction Prototypes:

//Creates new bait
Node *createNode(int row, int col){
    // Allocate memomoy to Node
    Node *res = (Node *)malloc(sizeof(Node));
    //Sanity Check
    if (res == NULL) {
        exit(EXIT_FAILURE);
    }
    //Initialize row and col
    res -> row = row;
    res -> col = col;
    res -> next = NULL;
    //Return new node
    return res; 
}

//Adds to the stack a new head using linked list functions
void push(Stack *stk, int row, int col)
{
    //Allocates memory to new head
    Node * newHead = createNode(row, col);
    newHead -> next = stk -> head;
    stk -> head = newHead;
    stk -> size++;
}

// Remove the top (head) using linked list functions
void pop(Stack *stk)
{
    //Sanity Check
    if (stk -> head == NULL) {
        exit(EXIT_FAILURE);
    }
    Node * temp = stk -> head; 
    stk -> head = stk -> head -> next;
    free(temp); //Frees old head from stack space
    stk -> size--;
    
}

// Return the top (head) of the stack for row and col. The most recent bait.
void top(Stack *stk, int *rowPtr, int *colPtr)
{
    if (stk -> head == NULL) {
        return;
    }
    //Updates the columns and rows to the most recent input 
    *rowPtr = stk -> head -> row;
    *colPtr = stk -> head -> col;
}

// Adds a new bait to the grid
void addBait(int **grid, int row, int col, int amt)
{
    //Add's amount of bait to inputed location to the grid
    grid[row][col] += amt;
}

//Eats bait at specified locadtion returns amount eaten
int eatBait(int ** grid, int row, int col) {
    int ate = grid[row][col];
    //Resets grid after elephant eats food
    grid[row][col] = 0;
    return ate;
}

//Moves the elephant to bait or retraces steps depeing on bait location
void moves(Elephant * elePtr, int ** grid) {
    //Declare varibles:
    Stack * stk = &(elePtr -> memory);//Retrieves memory
    //Update rows and col declarations 
    int row, col;
    top(stk, &row, &col); 
    //Locations and checks for each direction
    int right = grid[row][col + 1];//Right loc
    int rightC = 0; //variable for checking bait right
    int left = grid[row][col - 1];//left loc
    int leftC = 0; //variable for checking bait left
    int up = grid[row + 1][col];//up loc
    int upC = 0; //variable for checking bait up
    int down = grid[row - 1][col];//down loc
    int downC = 0; //variable for checking bait down
    
    //Sanity check
    //If input is off grid or nagative default to 0 bait level
    if(left < 0){
        left = 0;
    }
    if(down < 0){
        down = 0;
    }
    
    //Checks for each location as valid
    if (left > right && left > down && left > up){//If left has more bait than other directions
        leftC = 1;
    }
    else if (right > left && right > down && right > up){//If right has more bait than other directions
        rightC = 1;
    }
    else if (down > right && down > left && down > up){//If up has more bait than other directions
        downC = 1;
    }
    else if (up > right && up > down && up > left){//If down has more bait than other directions
        upC = 1;
    }

    // Check if there's bait in current and surrounding cells and push onto stack if true
    if(grid[row][col] > 0){// Check right cell
        //Update rows and columns
        elePtr -> row = row; 
        elePtr -> col = col; 
    }
    else if (col + 1 < 501 && grid[row][col + 1] > 0 && rightC == 1){// Check right cell
        //Moves elephant by adding new location to stack
        push(stk, row, col + 1);
        //Update rows and columns
        elePtr -> row = row; 
        elePtr -> col = col + 1; 
    }
    else if (col - 1 >= 0 && grid[row][col - 1] > 0 && leftC == 1){// Check left cell
        //Moves elephant by adding new location to stack
        push(stk, row, col - 1);
        //Update rows and columns
        elePtr -> row = row; 
        elePtr -> col = col - 1; 
    }
    else if (row - 1 >= 0 && grid[row - 1][col] > 0 && downC == 1){ // Check top cell
        //Moves elephant by adding new location to stack
        push(stk, row - 1, col);
        //Update rows and columns
        elePtr -> row = row - 1; 
        elePtr -> col = col; 
    }
    else if (row + 1 < 501 && grid[row + 1][col] > 0 && upC == 1){ // Check bottom cell
        //Moves elephant by adding new location to stack
        push(stk, row + 1, col);
        //Update rows and columns
        elePtr -> row = row + 1; 
        elePtr -> col = col; 
    }
    else{//If there is no bait then elephant retraces steps
        if (stk -> size > 1){
            //Removes current stack head
            pop(stk);
            //Retraces elephant steps given current placement 
            top(stk, &(elePtr -> row), &(elePtr -> col));
        }
    }
}


//Returns amount of food eaten
int eat(Elephant *elePtr, int **grid)
{
    //Calls eatbait at given position
    int foodEaten = eatBait(grid, elePtr -> memory.head -> row, elePtr -> memory.head -> col); 
    return foodEaten;//Return food eaten
}


// Main progression function.
int progressHour(Elephant *eleArr, int numEle, int **grid)
{
    //Initialize food eaten
    int totalFoodEaten = 0;

    for (int x = 0; x < numEle; ++x){//Loops through elephants
        //Counts amount of food eaten
        int ated = eat(&(eleArr[x]), grid);
        totalFoodEaten += ated;
    }
    return totalFoodEaten;//Returns total food eaten
}

// Stack functions
void initializeStack(Stack *stk)
{
    stk -> size = 0;    // No values in new stack
    stk -> head = NULL; // Empty list
}

int main()
{
    int numOfEle; //Number of elephants
    scanf("%d", &numOfEle); //Scan for number of elephants
    
    // Declare and initialize elephant array
    Elephant eleArr[1000];

    //Loop through number of elephants
    for (int x = 0; x < numOfEle; x++) {
        //Initialize memory
        initializeStack(&(eleArr[x].memory));
        // Read initial position of each elephant
        scanf("%d %d", &(eleArr[x].row), &(eleArr[x].col));
        //Pushes in each elephant 
        push(&(eleArr[x].memory), eleArr[x].row, eleArr[x].col);
    }
  
    // Declare and initialize the grid dynamically
    int **grid = (int **)malloc(501 * sizeof(int *));
    //Sanity Check
    if (grid == NULL) {
        exit(EXIT_FAILURE);
    }

    for (int x = 0; x < 501; ++x) {//loops through memory allocation and checks for error
        grid[x] = (int *)malloc(501 * sizeof(int));
        if (grid[x] == NULL) {
            exit(EXIT_FAILURE);
        }
        memset(grid[x], 0, 501 * sizeof(int)); //Initialize row with zeros
    }

    char keyWord[10]; // declare input variable
    
    
    while (scanf("%s", keyWord) != EOF){ //Loops for inputs untill exit

        //Input conditions
        if (strcmp(keyWord, "BAIT") == 0) {//If input is Bait
            int row, col, amt; //Initialize variables
            scanf("%d %d %d", &row, &col, &amt); //Scan for coordinates and amount of bait
            addBait(grid, row, col, amt);
        } 
        else if (strcmp(keyWord, "HOUR") == 0) {//If input is hour
            for (int x = 0; x < numOfEle ; ++x){//Loop though elephants
                moves(&(eleArr[x]), grid);//All actions take place in moves function
            }
            int totalBaitEaten = progressHour(eleArr, numOfEle, grid);//Progresses Hour
            printf("%d\n", totalBaitEaten);//Prints total bait eaten after an hour passes and moves are made
        } 
        else if (strcmp(keyWord, "QUIT") == 0) {//If input is quit 
            for (int x = 0; x < numOfEle; ++x) {//Loops through elephants
                printf("%d %d\n", eleArr[x].row, eleArr[x].col); // Print the resulting locations of the elephants
            }
            break; //Exit the while loop
        } 
        else {//if Input is invalid exit loop
            exit(EXIT_FAILURE);
        }
    }

    // Clean up the memory:
    // Free dynamically allocated memory for the grid
    for (int x = 0; x < 501; ++x) {
        free(grid[x]);
    }
    //Free grid
    free(grid);

    return 0;
}
