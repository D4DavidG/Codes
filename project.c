#include "spimcore.h"

/* ALU */
/* 10 Points */
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{

    switch((int)ALUControl){//Switch to control what opertion to use
    case 0:
        *ALUresult = A + B;
        break;
    
    case 1:
        *ALUresult = A - B;
        break;
    
    case 2:
        if(A < B){
            *ALUresult = 1;
        }
        else{
            *ALUresult = 0;
        }
        break;
    
    case 3://If a is less than B ALUresult is 1
        if((int)A < (int)B){//Cast A and B
            *ALUresult = 1;
        }
        else{
            *ALUresult = '0';
        }
        break;
    
    case 4://Perform A AND B
        *ALUresult = A & B;
        break;
    
    case 5://Perform A OR B
        *ALUresult = A | B;
        break;
    
    case 6://Shift B to the left 16 bits
        *ALUresult = B << 16;
        break;
    
    case 7://Perform bitwise not operation
        *ALUresult = ~A;
        break;
        
    default:
        break;
    }

    if(ALUresult == 0){//Set Zero to 1 of ALUresult is 0
        *Zero = 1;
    }
    else{//If ALUresult is 1 Zero is 0
        *Zero = 0;
    }
}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{
    if((!PC%4)){
        return 1;
    }
    *instruction =  Mem[(PC >> 2)];
    return 0;
}


/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{
    *op = (instruction >> 26);
    *r1 = (instruction >> 21)&(1<<5)-1;
    *r2 = (instruction >> 16)&(1<<5)-1;
    *r3 = (instruction >> 11)&(1<<5)-1;
    *funct = (instruction)&(1<<6)-1;
    *offset =(instruction)&(1<<16)-1;
    *jsec = (instruction)&(1<<26);
}


/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op,struct_controls *controls)
{
    controls->RegDst = 0;
    controls->Jump = 0;
    controls->Branch = 0;
    controls->MemRead = 0;
    controls->MemtoReg = 0;
    controls->ALUOp = 0;
    controls->MemWrite = 0;
    controls->ALUSrc = 0;
    controls->RegWrite = 0;

    switch((int)op){
        case 0:
            controls->RegDst = 1;
            controls->ALUOp = 7;
            controls->RegWrite = 1;
            break;
        
        case 2:
            controls->Jump = 1;
            break;
        
        case 4:
            controls->RegDst = 2;
            controls->MemtoReg = 2;
            controls->Branch = 1;
            controls->ALUOp = 1;
            break;

        case 8:
            controls->RegWrite = 1;
            controls->ALUSrc = 1;
            break;

        case 10:
            controls->RegDst = 1;
            controls->RegWrite = 1;
            controls->ALUOp = 2;
            break;
        
        case 11:
            controls->RegDst = 1;
            controls->RegWrite = 1;
            controls->ALUOp = 3;
            break;

        case 15:
            controls->RegWrite = 1;
            controls->ALUSrc = 1;
            controls->ALUOp = 6;
            break;

        case 35:
            controls->RegWrite = 1;
            controls->ALUSrc = 1;
            controls->MemRead = 1;
            controls->MemtoReg = 1;
            break;

        case 43:
            controls->RegDst = 2;
            controls->ALUSrc = 1;
            controls->MemWrite = 1;
            controls->MemtoReg = 2;
            break;
        
        default:
            return 1;
    }
    
    return 0;
}

/* Read Register */
/* 5 Points */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{
    *data1 = Reg[r1];
    *data2 = Reg[r2];
}


/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset,unsigned *extended_value)  
{   
    if((offset >> 15) == 1){
        *extended_value =( offset | 0xFFFF0000);
    }
    else{
        *extended_value = offset & 0x0000FFFF;
    }
}

/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{
    if (ALUSrc == 1) {
        data2 = extended_value;
    }
    
    if (ALUOp == 7) {
        
        switch(funct) {
            
            case 32:
                ALUOp = 0;
                break;
            
            case 34:
                ALUOp = 1;
                break;
            
            case 42:
                ALUOp = 2;
                break;
            
            case 43:
                ALUOp = 3;
                break;
            
            case 36:
                ALUOp = 4;
                break;
            
            case 37:
                ALUOp = 5;
                break;
            
            case 4:
                ALUOp = 6;
                break;
            
            case 39:
                ALUOp = 7;
                break;
            
            default:
                return 1;
        }

        ALU(data1, data2, ALUOp, ALUresult, Zero);
    } 
    else {
        ALU(data1, data2, ALUOp, ALUresult, Zero);
    }
    return 0;
}

/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem)
{
    if(MemRead == 1){
        if(!(ALUresult % 4)){
            *memdata = Mem[ALUresult >> 2];
        }
        else{
            return 1;
        }
    }
    
    if(MemWrite == 1){
        if(!(ALUresult % 4)){
            Mem[ALUresult >> 2] = data2;
        }
        else{
            return 1;
        }
    }

    return 0;
}


/* Write Register */
/* 10 Points */
void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg)
{
     if(RegWrite==1){
        if(MemtoReg == 1 && RegDst == 0){
            Reg[r2] = memdata;
        }
        else if(MemtoReg == 1 && RegDst == 1){
               Reg[r3] = memdata;
        }     
        else if(MemtoReg == 0 && RegDst == 0){
            Reg[r2] = ALUresult;
        }
        else if(MemtoReg == 0 && RegDst == 1){
            Reg[r3] = ALUresult;
        }   
    }
}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC)
{
    *PC += 4;
    
    if((Zero == 1) && (Branch == 1)){
        *PC += extended_value << 2;
    }
    
    if(Jump == 1){
        *PC = (jsec << 2) | (*PC & 0xf0000000);
    }
}