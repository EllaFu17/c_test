#include <stdio.h>
#include <stdlib.h>
#include <mm_malloc.h>

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

// definition of node structure of singly linked list
typedef struct L_node
{
	ElemType data;           // data field
	struct L_node *next;     // pointer field
}LNode, *LinkList;

//===========================================
// Create a singly linked list L with head node, and with n elements
//===========================================
Status CreateList_L(LinkList &L, int n)
{
	LinkList p, q;

	L = (LinkList)malloc(sizeof(LNode)); //create an empty list
	if (!L) return ERROR;
	L->next = NULL;
	q = L;
	for (int i = 0; i < n; i++){
		p = (LinkList)malloc(sizeof(LNode));    //make a new node
		if (!p) return ERROR;
		printf("please enter:\n"); 
		scanf("%d\n", &p->data);                    //enter element data from keyboard
		//p->next=L->next;
		// L->next=p;
		p->next = NULL;
		q->next = p;
		q = p;
	}
	//p->next=NULL;
	return OK;
}

//======================================
// print the list
//=======================================
void LinkedListPrint(LinkList L)
{  
	printf("\nthe list is:\n");
	LinkList A=(LinkList)malloc(sizeof(LNode));
    A=L;
	while(NULL!=A->next)
	{
		A=A->next;
		printf("%d\n", A->data);
	}
    printf("\n");
}

//=========================================
// get the length of the linklist
//=========================================
int ListLength_L(LinkList L)
{   LinkList A=(LinkList)malloc(sizeof(LNode));
    A=L;
    int i=0;
	while(NULL!=A->next){
		A=A->next;
		i++;
	}
  return i;
}

//=========================================
//find the maximum element
//=========================================
int GetMax(LinkList L)
{  LinkList A=(LinkList)malloc(sizeof(LNode));
    A=L;
    int m=0;
	while(NULL!=A->next){
		A=A->next;
		if(A->data>m){
			m=A->data;
		}
	}
return m;
}

//=========================================
// Move the maximum node to the front of the list
// pMax is the pointer to the MaxNode
//=========================================
void MoveMax(LinkList L, LinkList pMax)
{
	LinkList A=(LinkList)malloc(sizeof(LNode));
	LinkList a=(LinkList)malloc(sizeof(LNode));
    A=L;
    int m=0;
	while(NULL!=A->next){
		a=A;
		A=A->next;
		if(A->data>m)
		{
			m=A->data;
		}
	}
	pMax=L->next;
	while(NULL!=pMax->next)
	{
		if(pMax->data!=m){
		pMax=pMax->next;}
		else break;
	}
	a->next=pMax->next;
	pMax->next=L->next;
	L->next=pMax;
}

int main(void)
{

	LinkList LA;
	LinkList pMaxNode;
	int len;

	// Create a singly linked list with elements of 21, 18, 30, 75, 42, 56
	
	CreateList_L(LA, 6);

// print out the linked list
	LinkedListPrint(LA);

	// get the length
	len = ListLength_L(LA);
	printf("the length of the list is %d\n", len);

	//get the max
	int maxVal;
	maxVal = GetMax(LA);
	printf("the maximum value is %d\n", maxVal);//original one is minimum here
	//Move the maximum node to the front of the list
	MoveMax(LA, pMaxNode);
	LinkedListPrint(LA);

}
