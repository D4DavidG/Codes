n//David Gusmao
//Currupt Captors
//Travis Meade CS1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declare Node struct
typedef struct Node Node;

struct Node {
    Node * left, * right, * parent; //Nodes for left right and parent nodes
    int hat;//Hat level
    int location;//Location counter
    long long int food;//Food counter
};

Node * createNode(int location, int hatSize);//------------------------DONE
Node * insertRaccoon(Node * root, int location, int hatSize);//--------DONE
Node * captureRaccoon(Node * root, int location);//--------------------DONE
Node * findReplacement(Node * current);//------------------------------DONE
void stealFood(Node * root, int location, int foodAMT);//--------------DONE
void stealHat(Node * root, int location, int hatLVL);//----------------DONE
Node * findClosest(Node * root, int location);//-----------------------DONE
Node * rotateLeft(Node * current);//-----------------------------------DONE
Node * rotateRight(Node * current);//----------------------------------DONE
void printTree(Node * root);//-----------------------------------------DONE
//Main-----------------------------------------------------------------WIP

Node * createNode(int location, int hatSize)//Creates new node
{
    Node * newnode = (Node *)malloc(sizeof(Node));//

    newnode->hat = hatSize;//Assigns hat location
    newnode->location = location;//Assigns location location

    newnode->left = newnode->right = newnode->parent = NULL;
    newnode->food = 0;//Initializes food level

    return newnode;//Returns the new node
}

Node * insertRaccoon(Node * root, int location, int hatSize){
    // Empty tree case
    if (root == NULL){
        return createNode(location, hatSize);
    }
    // Child the parent for the insertion
    Node *parent = NULL;
    Node *child = root;
    while (child) {
        if (child->location < location) {
            // Go right
            parent = child;
            child = parent->right;
        } else if (child->location > location) {
            // Go left
            parent = child;
            child = parent->left;
        } else {
            // Duplicate node avoid
            return root;
        }
    }

    // Insert at the location with parent as parent
    if (parent->location < location) {
        parent->right = createNode(location, hatSize);
        parent->right->parent = parent;
        child = parent->right;//Assigns child as the created node
        
    } else {
        parent->left = createNode(location, hatSize);
        parent->left->parent = parent;
        child = parent->left;//Assigns child as the created node
        
    }

    //Sort Tree function.
    while((parent->hat < child->hat)){//while parent hat is smaller than child
        if((parent->location < child->location) && (parent->right == child)){//If location is bigger than parent
            rotateLeft(parent);//left rotaion
        }
        else if((parent->location > child->location) && (parent->left == child)){//If location is smaller than parent
            rotateRight(parent);//Right rotaion
        }
        parent = parent->parent;
    }


    // Find the new root
    while (root->parent) {
        root = root->parent;
    }

    return root;
}

Node * captureRaccoon(Node * root, int location){
    //Seaches for racoon to be captured
    Node *racoon = root;
    while(racoon && racoon->location != location){//While racoon exists loop 
        if (racoon->location > location) {//Racoon Moves to the Left
        racoon = racoon->left;
        } else if (racoon->location < location) {
        racoon = racoon->right;//Racoon Moves to the right
        }
    }
    if (!racoon){//Sanity Check for racoon not existing.
        return root;
    }
    Node *racoonParent = racoon->parent;//Declares Racoon's parent.

    //Collects captured racoons food
    int capturedFood = racoon->food;//Assign it to BTS
    printf("%d\n", capturedFood);

    //Removes Node
    //0 Children Case
    if (racoon->left == NULL && racoon->right == NULL){//If racoon has no Children
        free(racoon);//Free pointer
        if (!racoonParent){//If no parents Exist
            return NULL;
        }
        if (racoonParent->left == racoon){//If raccon is a right child
            racoonParent->left = NULL;//Remove Racoon
        } else {//Racoon is Left Child
            racoonParent->right = NULL;//Remove Racoon
        }
        return root;
        
    }

    //Child Case works by finding the nearest Node,
    //Preforming a data transfer,
    //Then removing the nearest node from the tree
    Node * closest = findReplacement(racoon);//Finds the closest Node
    //Transfer Data to node
    racoon->food = closest->food;
    racoon->location = closest->location;

    //Remove Closest Node
    Node * closestParent = closest->parent;//Declares new Parent
    Node *child = closest->right;//Declares Right Child
    if (!child) {//If child doesn't exist
        child = closest->left;//Declare child as Left Child
    }
    free(closest);//Removes closest node
    
    //Assign Parents
    if (child){//If Child exists
        child->parent = closestParent;//Assign Captured Racoon's Parent to Child
    }
    if (!closestParent){//If no Parent, tree's root is now child
        return child;
    }
    if (closestParent->left == closest){//If parent left child == raccon assign new child
        closestParent->left = child;
    } else {//If parent Right child == raccon assign new child
        closestParent->right = child;
    }

    return root;
}

Node * findReplacement(Node * current){//Finds closest Node based on current Node
    Node * oldRacoon = current;//Root
    Node * leftRacoon = oldRacoon;//Closest Racoon to the left of root
    Node * rightRacoon = oldRacoon;//Closest Racoon to the right of root
    Node * closest = current;//Returned Closest Racoon

    //1 child
    if((oldRacoon->left != NULL) && (oldRacoon->right == NULL)){//Right Cild
        //Down to the closest point
        leftRacoon = oldRacoon->left;//Assign Left Racoon as Right child
        while(leftRacoon->right != NULL){
            leftRacoon = leftRacoon->right;
        }

        //Move up to the closest point
        while((rightRacoon == rightRacoon->parent->right) && (rightRacoon->parent != NULL)){//Finds closest parent that's bigger
            rightRacoon = rightRacoon->parent;
        }
        if(rightRacoon->parent != NULL){
            rightRacoon = rightRacoon->parent;
        }
    } else if((oldRacoon->left == NULL) && (oldRacoon->right == NULL)){//left Cild
        //Down to the closest point
        rightRacoon = oldRacoon->right;//Assign right Racoon as left child
        while(rightRacoon->left != NULL){
            rightRacoon = rightRacoon->left;
        }

        //Move up to the closest point
        while((leftRacoon == leftRacoon->parent->left) && (leftRacoon->parent != NULL)){//FindClosest parent that's smaller
            leftRacoon = leftRacoon->parent;
        }
        if(leftRacoon->parent != NULL){
            leftRacoon = leftRacoon->parent;
        }
    }

    //2 child
    if((oldRacoon->left != NULL) && (oldRacoon->right != NULL)){
        //Down to the closest point from the right
        leftRacoon = oldRacoon->left;//Assign Left Racoon as left child
        while(leftRacoon->right != NULL){
            leftRacoon = leftRacoon->right;
        }
    
        //Down to the closest point from the left
        rightRacoon = oldRacoon->right;//Assign right Racoon as left child
        while(rightRacoon->left != NULL){
            rightRacoon = rightRacoon->left;
        }
    }

    //Calculates closest Racoon
    int rightDistance = abs((current->location) - (rightRacoon->location));//Right distance from old racon
    int leftDistance = abs((current->location) - (leftRacoon->location));//left distance from old racoon

    //If no parents for one child case
    if(leftDistance == 0){
        return rightRacoon;
    } else if (rightDistance == 0){
        return leftRacoon;
    }

    //Closest Racoon
    if((rightDistance < leftDistance)){//If right is closer
        closest = rightRacoon;
    }
    else if(rightDistance > leftDistance){//if left is closer
        closest = leftRacoon;
    }
    else{//If same distance
        if(rightRacoon->hat < leftRacoon->hat){//If right hat is smaller it's "closer"
            closest = rightRacoon;
        } else if(rightRacoon->hat > leftRacoon->hat){//If left hat is smaller it's "closer"
            closest = leftRacoon;
        }
    }

    return closest;

}

Node * changeHat(Node * current, int hatSize){//Updates Hat Size
    current->hat = hatSize;//Assigns Racoon New Hat Size
    return current;//Returns Racoon with new hat. 
}

void stealFood(Node * root, int location, int foodAMT){//Searches For location and Seals Food
    Node * closest = findClosest(root, location);//Find closest Racoon
    int food = foodAMT;
    foodAMT = food;
    
    while ((foodAMT > 0)){//While there is food
        if(closest->parent != NULL){//If current has a parent
            closest->food += foodAMT/2;//current is given the lower half of the food
            foodAMT = (foodAMT - (foodAMT/2));//food is cut in half rounded up. 
            closest = closest->parent;//current is moved up the tree
        }
        else {//if current has no parent
            closest->food += foodAMT;//recieves all food
            break;//while loop ends
        }
    }
}

void stealHat(Node * root, int location, int hatLVL){//Searches For location and Seals hat from locaiton
    Node * closest = findClosest(root, location);//Find closest Racoon
    
    if(closest->hat < hatLVL){//Check if hat is larger
        closest->hat = hatLVL;//update closest hat hat level

        //Initialize parent and child
        Node * parent = closest->parent;
        Node * child;
        if(parent->left == closest){
            child = parent->left;
        }else{
            child = parent->right;
        }
        
        //Sort Tree function.
        while((parent->hat < child->hat)){//while parent hat is smaller than child
            if((parent->location < child->location) && (parent->right == child)){//If location is bigger than parent
                rotateLeft(parent);//left rotaion
            }
            else if((parent->location > child->location) && (parent->left == child)){//If location is smaller than parent
                rotateRight(parent);//Right rotaion
            }
            parent = parent->parent;
        }
    }

}

Node * findClosest(Node * root, int location){//Finding Nearest Node to Location
    if (root != NULL){//If a raccoon is present
        Node * closest = root;//Start at root;
        int distance = abs(root->location - location);

        if(closest->location == location){
            return closest;
        }

        while(closest->location != location){
            //If distance of right child is less than distance of closest move right
            if((closest->right != NULL) && (abs(closest->right->location - location) < abs(closest->location - location))){
                closest = closest->right;
            }//If distance of right child is equadistant to the closest
            else if((closest->right != NULL) && (abs(closest->right->location - location) == abs(closest->location - location))){
                if(closest->right->hat < closest->hat){
                    return closest->right;
                } else if(closest->right->hat > closest->hat){
                    return closest;
                }
            }//If distance of left child is less than distance of closest move left
            else if((closest->left != NULL) && (abs(closest->left->location - location) < abs(closest->location - location))){
                closest = closest->left;
            }//If distance of left child is equadistant to the closest
            else if((closest->left != NULL) && (abs(closest->left->location - location) == abs(closest->location - location))){
                if(closest->left->hat < closest->hat){
                    return closest->left;
                } else if(closest->left->hat > closest->hat){
                    return closest;
                }
            }//If no children avalibale
            else if((closest->right != NULL) && (closest->left != NULL)){
                return closest;
            }
            else{
                //Neither children are closer;
                return closest;
            }
        }
        if(closest->location == location){
            return closest;
        }

    }
}

Node * rotateLeft(Node * current){
    if(current && current->right){

        // Get pointers to the parent, child, and grandchild
        Node *rotParent = current->parent;
        Node *rotChild = current->right;
        Node *rotGradChild = rotChild->left;

        // Top edge
        rotChild->parent = rotParent;
        // Check parent's existance
        if (rotParent) {
            // Check the side of the rotated node for its parent
            if (rotParent->right == current) {
            rotParent->right = rotChild;
            } else {
            rotParent->left = rotChild;
            }
        }

        // Middle edge
        rotChild->left = current;
        current->parent = rotChild;

        // Bottom edge
        current->right = rotGradChild;
        if (rotGradChild) { // Check grandchild's existance
            rotGradChild->parent = current;
        }

        return rotChild;
        }
    }

Node *rotateRight(Node * current){
    if(current && current->left){
        // Get pointers to the parent, child, and grandchild
        Node *rotParent = current->parent;
        Node *rotChild = current->left;
        Node *rotGrandChild = rotChild->right;

        // Top edge
        rotChild->parent = rotParent;
        // Check parent's existance
        if (rotParent) {
            // Check the side of the rotated node for its parent
            if (rotParent->right == current) {
            rotParent->right = rotChild;
            } else {
            rotParent->left = rotChild;
            }
        }

        // Middle edge
        rotChild->right = current;
        current->parent = rotChild;

        // Bottom edge
        current->left = rotGrandChild;
        if (rotGrandChild) { // Check grandchild's existance
            rotGrandChild->parent = current;
        }

        return rotChild;
    }
}

void printTree(Node *root){
    if (root == NULL)
    {
        return;
    }
    printf("%d %d\n", root->location, root->food);
    printTree(root->left);
    printTree(root->right);
}

int main(){
    Node *root = NULL; //Declares Root for Tree as Null

    char keyWord[10]; // declare input variable
    int location, hatSize, food; //Initialize variables

    while (scanf("%s", keyWord) != EOF){
        //Input conditions
        if (strcmp(keyWord, "ADD") == 0) {//If input is ADD
            scanf("%d %d", &location, &hatSize);//Scan for location and hatsize
            root = insertRaccoon(root, location, hatSize);//Add node to tree
        } 
        else if (strcmp(keyWord, "CAPTURE") == 0) {//If input is CAPTURE
            scanf("%d", &location);//Scan for location
            root = captureRaccoon(root, location);//Capture Raccon
        } 
        else if (strcmp(keyWord, "HAT") == 0) {//If input is HAT
            scanf("%d %d", &location, &hatSize);//Scan for location and hatsize
            stealHat(root, location, hatSize);//Steal Hat
        } 
        else if (strcmp(keyWord, "STEAL") == 0) {//If input is STEAL
            scanf("%d %d", &location, &food);//Scan for location and food
            stealFood(root, location, food);
        } 
        else if (strcmp(keyWord, "QUIT") == 0) {//If input is quit 
            break;
        } 
        else {//if Input is invalid exit loop
            exit(EXIT_FAILURE);
        }
    }
    printTree(root);
    return 0;
}