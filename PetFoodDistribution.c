//David Gusmao
//Pet Food Distribution
//Travis Meade's CS1

/*
Last Code I am ever sending in this class
Probably the hardest I have ever worked in a course and
The most I have learned, thank you.
-David G. 
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct Node Node;

struct Node {
    int subTrieAmount;
    int myAmount;
    Node * children[32];
};

// Prototypes
Node * add(Node * root, char * answer, int food);
void change(Node * root, char * oldAnswer, char * newAnswer);
int findAmount(Node * root, char * answer);
void sum(Node * root, char * answer);
int findMin(Node * root, char * answer);
int findMax(Node * root, char * answer, int total);
void removeFood(Node * root, char * answer, int food);


Node * add(Node * root, char * answer, int food) {
    // If root does not exist
    if (!root){
        // Make it
        root = (Node *)calloc(1, sizeof(Node));
        //set zero
        
    }

    // If answer is at end
    if (answer[0] == '\0') {
        // Flag answer is in trie
        root->myAmount += food;
        root->subTrieAmount += food;
    } else {
        //Increase subtrie Amount;
        root->subTrieAmount += food;
    
        // Determine child index
        int index;
        if(('a' <= answer[0]) && (answer[0] <= 'v')){//If alpha from a - v
            index = answer[0] - 'a'+ 10;
        }else{//is digit
            index = answer[0] - '0';
        }

        // Insert answer without first letter into child's trie
        root->children[index] = add(root->children[index], &answer[1], food);
    }

    // Return resulting root
    return root;
}

int findAmount(Node * root, char * answer) {
    // If root does not exist
    if (!root) {

        return 0;
    }

    // If answer is at end
    if (answer[0] == '\0') {

        // The flag stores if the answer is contained
        return root->myAmount;
    } else {
        // Determine child index
        int index;
        if(('a' <= answer[0]) && (answer[0] <= 'v')){//If alpha from a - v
            index = answer[0] - 'a'+ 10;
        }else{//is digit
            index = answer[0] - '0';
        }

        // Check containment in child with first letter of answer removed
        return findAmount(root->children[index], &answer[1]);
    }
}

void removeFood(Node * root, char * answer, int food) {
    // If root does not exist
    if (!root) {
        // Cannot remove answer
        return;
    }

    // If answer is at end
    if (answer[0] == '\0') {
        //Remove node's food and subtrie food
        root->myAmount -= food;
        root->subTrieAmount -= food;

    } else {
        //Decrease subtrie Amount;
        root->subTrieAmount -= food;

        // Determine child index
        int index;
        if(('a' <= answer[0]) && (answer[0] <= 'v')){//If alpha from a - v
            index = answer[0] - 'a'+ 10;
        }else{//is digit
            index = answer[0] - '0';
        }

        // Remove answer without first letter from child's trie
        removeFood(root->children[index], &answer[1], food);
    }
}

void change(Node * root, char * oldAnswer, char * newAnswer){
    //Find amount of food to subtract
    int oldFood = findAmount(root, oldAnswer);

    //Subtract food from old answer
    removeFood(root, oldAnswer, oldFood);

    //add new answer to trie with food
    add(root, newAnswer, oldFood);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------

//Find Sum-------------------------------------------------------------------------------------------------------------------------------------------
void sum(Node * root, char * answer){
    //Finds Minum Number
    int min = findMin(root, answer);

    //Decaares Total Max
    int total = 0;
    //Finds Maxium Number
    int max = findMax(root, answer, total);

    printf("%d %d\n", min, max);
}

int findMin(Node * root, char * answer) {
    // If root does not exist
    if (!root) {
        return 0;
    }

    // If answer is at end
    if (answer[0] == '\0') {
        // The flag stores if the answer is contained
        return root->subTrieAmount;
    } else {
        // Determine child index
        int index;
        if(('a' <= answer[0]) && (answer[0] <= 'v')){//If alpha from a - v
            index = answer[0] - 'a'+ 10;
        }else{//is digit
            index = answer[0] - '0';
        }

        // Check containment in child with first letter of answer removed
        return findMin(root->children[index], &answer[1]);
    }
}

int findMax(Node * root, char * answer, int total) {
    // If root does not exist
    if (!root) {
        return total;
    }

    // If answer is at end
    if (answer[0] == '\0') {
        //Add value
        total += root->subTrieAmount;
        return total;
    } else {
        //Add potential Values
        if(root->myAmount > 0){
            total += root->myAmount;
        }

        // Determine child index
        int index;
        if(('a' <= answer[0]) && (answer[0] <= 'v')){//If alpha from a - v
            index = answer[0] - 'a'+ 10;
        }else{//is digit
            index = answer[0] - '0';
        }

        // Check containment in child with first letter of answer removed
        return findMax(root->children[index], &answer[1], total);
    }
    //Degault return total (should never happen)
    return total;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------

void deleteTrie(Node * root) {
    // If trie is empty stop
    if (root == NULL) return;

    // Delete all the children
    for (int i = 0; i < 32; i++) {
        deleteTrie(root->children[i]);
    }

    // Delete the root last (post order)
    free(root);
}

int main(){
    Node * root = NULL;//Declare Root

    char keyAnswer[10]; // declare input variable
    char answer[100010];//Answer
    char newAnswer[100010];//New answer
    int food; //Initialize variables

    //Loop untill Quit or error
    while (scanf("%s", keyAnswer) != EOF){
        //Input conditions
        if (strcmp(keyAnswer, "ADD") == 0) {//If input is ADD
            scanf("%s %d", answer, &food);//Scan for answr and food
            root = add(root, answer, food);//Add Answer to Trie
        } 
        else if (strcmp(keyAnswer, "CHANGE") == 0) {//If input is CAPTURE
            scanf("%s %s", answer, newAnswer);//Scan for answr and food
            change(root, answer, newAnswer);//Add Answer to Trie
        } 
        else if (strcmp(keyAnswer, "SUM") == 0) {//If input is HAT
            scanf("%s", answer);//Scan for answer
            sum(root, answer);//Call sum
        } 
        else if (strcmp(keyAnswer, "QUIT") == 0) {//If input is STEAL
            break;
        } 
        else {//if Input is invalid exit loop
            exit(EXIT_FAILURE);
        }
    }
    deleteTrie(root);//Delete trie and free memeory. 

    return 0;
}