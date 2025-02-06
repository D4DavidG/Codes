//David Gusmao
//CS1 Travid Meade
//Buisness Buyout

#include <stdio.h>
#include <stdlib.h>

// Default length of the shops array
#define SHOPS 500000
// Default maximum value of an element of the array
#define WEALTH 1000000000

//Struct to hold eatable shops
struct stack {
    long long int eatableShops[SHOPS];
    int top;//Index of the top of the stack
};

//Stack Functions
void initialize(struct stack* stckPTR) {//Initializes the top of the stack
    stckPTR->top = -1;
}
int full(struct stack* stckPTR) {//Returns true of stack is at max capacity. 
    return (stckPTR->top == SHOPS - 1);
}
// Returns true iff the stack pointed to by stckPTR is empty.
int empty(struct stack* stckPTR){//Returns true if stack is empty. 
    return (stckPTR->top == -1);
}
int push(struct stack* stckPTR, long long int value) {//pushes value into the stack.
    if (full(stckPTR)){ //IF stack is full returns 0
        return 0;
    }
    stckPTR->eatableShops[stckPTR->top+1] = value; // Add value to the top of the stack and adjust the value of the top.
    (stckPTR->top)++;
    return 1;
}
int top(struct stack* stckPTR) {//Acesses top of stack
    if (empty(stckPTR)){//stack is empty return nothing. 
        return -1;
    }
    // Return the desired item.
    return stckPTR->eatableShops[stckPTR->top];//Returns top
}
void pop(struct stack* stckPTR) {//Pops top of stack
    if (!(empty(stckPTR))){//Only if stack not empty
    (stckPTR->top)--;
    }
}

// Merge sort function
void mergeSort(long long int *shopwealth, int numShops) {
    // Base Case
    if (numShops <= 1) {
        return;
    }
    // Sort the 2 halves
    mergeSort(shopwealth, numShops / 2);
    mergeSort(shopwealth + (numShops / 2), numShops - (numShops / 2));
    // Merge the 2 halves into a temp array
    long long int *tmp = (long long int *)malloc(sizeof(long long int) * numShops);
    int fptr = 0;
    int bptr = numShops / 2;
    for (int i = 0; i < numShops; i++) {
         if ((bptr != numShops && shopwealth[bptr] < shopwealth[fptr]) || fptr == numShops / 2 ) {
        tmp[i] = shopwealth[bptr];
        bptr++;
        } else {
        tmp[i] = shopwealth[fptr];
        fptr++;
        }
    }
    // Move the contents into the original array
    for (int i = 0; i < numShops; i++) {
        shopwealth[i] = tmp[i];
    }
    // Clean up the temp array
    free(tmp);
}

//Function will eat all smaller compaies
//Returns number of campies eaten else returns 0
int eat(long long int *shopwealth, int numShops, long long int btsWealth) {

    //Initialize values
    int maxval = shopwealth[numShops-1];//Biggest store
    int companies = 0; //Number of comanies eaten

    //Immedialty checks if BTS is big enough to eat the larges company
    if(btsWealth > maxval){
        return companies;
    }

    //Initializes stack
    struct stack shopstack;
    initialize(&shopstack);

    //Index of where bts wealth is in relation to other stores
    int index = 0;

    //Locates BTS wealth in relation to other stores. 
    for (int i = 0; i < numShops; i++) {//Loops through sorted list.
        if(btsWealth  > shopwealth[i]){
            index = i;
            push(&shopstack, shopwealth[i]);
        }
        else{
            break;//Breaks when max value found
        }
    }
    
    //Main loop to eat all stores
    //If there index exists
    while((btsWealth <= maxval) && !(empty(&shopstack))){//Loops untill the biggest company is eatable. 
        //BTS eats the top of the stack
        btsWealth += top(&shopstack);
        companies += 1;
        pop(&shopstack);

        //Checks if maxval is now eatable
        if(btsWealth > maxval){
           return companies;
        }

        //Moves any eatable shops into the eat list.
        while(btsWealth > shopwealth[index+1]){//loops untill next value is NOT eatable
           if(!(btsWealth > shopwealth[index+1])){//Sanity Check
                break;
            }
            else{//Increases index and pushes new value in
                index++;
                push(&shopstack, shopwealth[index]);
            }
        }
    }

    //Saftey Check if wealth is big enough to eat the max value
    if(btsWealth > maxval){
        return companies;
    }

    //Default Return 
    return -1;
}

// The main function of the program
int main(){
    int numShops;//Initialize length of shop list at a Max value
    long long int btsWealth;//BTS initial Wealth (will be updated throughout program)

    //Scan for number of shops and btsWealth
    scanf("%d %lld", &numShops, &btsWealth);

    //Dynamically Allocate number of shops based on input
    long long int *shopwealth = (long long int *)malloc(sizeof(long long int) * numShops);
    for (int i = 0; i < numShops; i++) {//Inputs for number of shops
        scanf("%lld", &shopwealth[i]);
    }

    //Call Sort Function
    mergeSort(shopwealth, numShops);

    //Call eat function and initialize amount eaten
    int eaten = eat(shopwealth, numShops, btsWealth);

    //Print Value
    printf("%d", eaten);
    
    // Clean up memory
    free(shopwealth);

    // Exit
    return 0;
}