#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void printArray(char textarr[10069], int len);//Print array
//Checksum calcualtors
int bit8(char textarr[10069], int len);
int bit16(char textarr[10069], int len);
int bit32(char textarr[10069], int len);
//Padding function
int pad(char textarr[10069], int len, int num);

int main(int argc, char **argv){
    //The first parameter
    char* fileName = argv[1];
    FILE* inFile = fopen(fileName, "r");


    //The second parameter
    int size; //size of checksum 8, 16, or 32
    char* checksize = argv[2];
    size = atoi(checksize);
    //Check is size valid
    if((size != 32) && (size != 16) && (size != 8)){
        fprintf(stderr, "Valid checksum sizes are 8, 16, or 32\n");
        exit;
    }


    //Collecting and filling the text array
    char textarr[10069]; //text array
    int index;//index of text array
    char r;//scanned char
    while((r = fgetc(inFile)) != EOF){
       textarr[index] = r;
       index++;//increase index of text 
    }
    int txtlen = index; //length of text array.

    
    //print file out to the console
    printf("\n");
    printArray(textarr, index);

    
    
    //options depending on bit size
    if(size == 8){//if size of bites are 8
        txtlen = bit8(textarr, txtlen); 
    } else if(size == 16){//if size of bites are 16
        txtlen = bit16(textarr, txtlen); 
    } else if(size == 32){//if size of bites are 32
        txtlen = bit32(textarr, txtlen); 
    }

    fclose(inFile);//end of file usage
  
    return 0;
}

int bit8(char textarr[10069], int len){
    printf("\n");
    unsigned long int checksum = 0;
    int checkSumSize = 8;

    int block = 0;
    for(int i = 0; i < len; i++){
        block = (unsigned long int)textarr[i];
        checksum += block;
        checksum = checksum & 0xFF;
    } 

    //update variables
    int characterCnt = len;
    printf("%2d bit checksum is %8lx for all %4d chars\n", checkSumSize, checksum, characterCnt);

    return len;
}

int bit16(char textarr[10069], int len){
    //Pad plaintext
    len = pad(textarr, len, 2);
    unsigned long int checksum = 0;
    int checkSumSize = 16;

    //easier math
    int block = 0;
    for(int i = 0; i < len; i += 2){
        block = ((unsigned long int)textarr[i] << 8) | ((unsigned long int)textarr[i+1]);
        checksum += block;
        checksum = checksum & 0xFFFF;
    }    

    //update variables
    int characterCnt = len;
    printf("%2d bit checksum is %8lx for all %4d chars\n", checkSumSize, checksum, characterCnt);

    return len;
}

int bit32(char textarr[10069], int len){
    //Pad plaintext
    len = pad(textarr, len, 4);
    unsigned long int checksum = 0;
    int checkSumSize = 32;

    //ugh math
    int block = 0;
    for(int i = 0; i < len; i += 4){
        block = ((unsigned long int)textarr[i] << 24) | ((unsigned long int)textarr[i+1] << 16) | ((unsigned long int)textarr[i+2] << 8)  | ((unsigned long int)textarr[i+3]);
        checksum += block;
        checksum = checksum & 0xFFFFFFFF;
    }

    //update variables
    int characterCnt = len;
	printf("%2d bit checksum is %8lx for all %4d chars\n", checkSumSize, checksum, characterCnt);

    return len;
}

int pad(char textarr[10069], int len, int num){
    //Pad's an array based on the num
    int checker = len % num;//Calculates the mod of the two lengths. 
    if(checker > 0){
        int pad =  num - (checker);//calculates how much you would need to pad
        for(int x = len; x < (pad + len); x++){
            textarr[x] = 'X';
            printf("X");//prints x's
        }
        printf("\n");
        len += pad;
    }
    else{
        printf("\n");//in case no padding
    }

    return len;
}

//My glorious print array function that i use all the time
void printArray(char textarr[10069], int len){
    int printIndex = 0;
    for(int p = 0; p < len; p++){
        printf("%c", textarr[p]);
        printIndex++;

        if(printIndex >= 80){
            printIndex = 0;
            printf("\n");
        }
    }
}
/*
“I David Gusmao (da045393) affirm that this program is entirely my own work and that I have neither developed 
my code with any another person, nor copied any code from any other person, nor permitted my code to be copied
or otherwise used by any other person, nor have I copied, modified, or otherwise used programs
created by others. I acknowledge that any violation of the above terms will be treated as
academic dishonesty.”
*/