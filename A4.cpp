#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE  0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int SElemType;

#define STACK_INIT_SIZE   100        //Initial size for memory allocation
#define STACKINCREMENT  10          //incremental size 

typedef struct SqStack
{
	SElemType  *base;    //base pointer
	SElemType  *top;      //top pointer
	int        stacksize;     //current size
}SqStack;

//==================================================
// Initialize a stack
//====================================================
Status InitStack(SqStack &S)
{
	S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!S.base) return ERROR;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

//==============================================
//test empty stack
//===============================================
Status StackEmpty(SqStack S)
{
	return (S.top == S.base);   //empty stack
}

//===================================
// Get the length of a stack
//==================================
int  StackLength(SqStack S)
{
	return (S.top - S.base);
}

//=================================
//Get the element at the top end
//==================================
Status GetTop(SqStack S, SElemType &e)
{
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}

//==================================
//delete the element at the top end 
//=====================================
Status Pop(SqStack &S, SElemType &e)
{
	if (S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}
//==================================
//Insert an element
//=================================
Status Push(SqStack &S, SElemType e)
{
	if (S.top - S.base >= S.stacksize) //stack is full, increase the size
	{      
		S.base = (SElemType *)realloc(S.base, (S.stacksize +
			STACKINCREMENT)*sizeof(SElemType));
		if (!S.base) return ERROR;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

void myFunc(int A[], int B[]){
	SqStack s;
	InitStack(s);
	for(int i=0;i<8;i++){
		if(A[i]==0){
			for(int j=i;j>=0;j--){
				*(s.base+j+1)=*(s.base+j);
			}
			*(s.base)=0;
		}
		else{
			*(s.base+i)=A[i];
		}
		s.top=s.base+i;
	}
		for(int k=0;k<8;k++){
		B[k]=*(s.base+k); 
	}
	
}

int main()
{
	int A[8] = {1,0,0,1,1,0,1,0};
	int B[8];
	
	myFunc(A, B);
	
	for (int i = 0; i < 8;i++)
	{
		printf("%d ", B[i]);
	}
}
