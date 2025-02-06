/*============================================================================
| Assignment: pa01 - Encrypting a plaintext file using the Hill cipher
|
| Author: David Gusmao
| Language: c, c++, Java, go, python, rust
| To Compile: javac pa01.java
| gcc -o pa01 pa01.c
| g++ -o pa01 pa01.cpp
| go build pa01.go
| rustc pa01.rs
| To Execute: java -> java pa01 kX.txt pX.txt
| or c++ -> ./pa01 kX.txt pX.txt
| or c -> ./pa01 kX.txt pX.txt
| or go -> ./pa01 kX.txt pX.txt
| or rust -> ./pa01 kX.txt pX.txt
| or python -> python3 pa01.py kX.txt pX.txt
| where kX.txt is the keytext file
| and pX.txt is plaintext file
| Note:s
| All input files are simple 8 bit ASCII input
| All execute commands above have been tested on Eustis
|
| Class: CIS3360 - Security in Computing - Fall 2024
| Instructor: McAlpin
| Due Date: 9/29/2024
+===========================================================================*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

//Extra Function
void printArray(char textarr[10000], int len);

//Main Function
int main(int argc, char **argv){
    //Key
    char* keyName = argv[1];
    FILE *keyFile = fopen(keyName, "r");
    int keySize; //size of key
    fscanf(keyFile, "%d", &keySize); //scan for key size
    int keyArr[keySize][keySize];

    //Fills key matrix
    for(int x = 0; x < keySize; x++){
        for(int y = 0; y < keySize; y++){
            fscanf(keyFile, "%d", &keyArr[y][x]);
        }
    }
    
    //Print key matrix
    printf("\nKey matrix:\n");
    for(int x = 0; x < keySize; x++){
        for(int y = 0; y < keySize; y++){
            printf("%4d", keyArr[y][x]);
        }
        printf("\n");
    }
    printf("\n");

    //Plaintext
    char* plainName = argv[2];
    FILE * plainFile = fopen(plainName, "r");

    //char arrays
    char cphrtxt[10000]; //ciphertext
    char plaintxt[10000]; //plaintext

    //Fill plaintext array
    int txtlen; //len of ciphertext
    char scanChar; //sanned letter;
    while((scanChar = fgetc(plainFile)) != EOF){
        if((isalpha(scanChar)) && (scanChar != '\n')){//checks if char is alpha
            plaintxt[txtlen] = tolower(scanChar);//sets as lowercase
            txtlen++;
        }
    }

    //Pad plaintext
    int checker = txtlen % keySize;//Calculates the mod of the two lengths. 
    if(checker > 0){
        int pad = keySize - (checker);
        for(int x = txtlen; x < (pad + txtlen); x++){
            plaintxt[x] = 'x';
        }
        txtlen += pad;
    }

    //File close
    fclose(plainFile);
    fclose(keyFile);

    //Variables for Encoding
    int blockarr[keySize];
    int tempsum = 0;
    int cindex = 0;
    int plainIndex = 0;
    //Encoding Plaintext
    while(plainIndex < txtlen){//loop untill no more blocks can be made
        //Block update
        for(int b = 0; b < keySize; b++){
            blockarr[b] = plaintxt[b + plainIndex] - 'a';
        }
        plainIndex += keySize;//move to next block of code

        //Matrix multiplication
        for(int r = 0; r < keySize; r++){//for each row of key
            for(int c = 0; c < keySize; c++){//for each column of key
                tempsum +=(blockarr[c] * keyArr[c][r]);
            }
            cphrtxt[cindex] = (tempsum % 26) + 'a';//adds encrypted block to cyphertext.
            cindex++;
            tempsum = 0;
        }
    } 

    //Print plaintext
    printf("Plaintext:\n");
    printArray(plaintxt, txtlen);

    printf("\n");

    //Print cphyertext
	printf("Ciphertext:\n");
    printArray(cphrtxt, txtlen);

    return 0;
}

void printArray(char textarr[10000], int len){//Print array function
    int printIndex = 0;
    for(int p = 0; p < len; p++){
        printf("%c", textarr[p]);
        printIndex++;

        if(printIndex >= 80){
            printIndex = 0;
            printf("\n");
        }
    }
    printf("\n");
}

/*=============================================================================
| I David Gusmao (da045393) affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/