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
	struct L_node *next;    // pointer field
}LNode, *LinkList;

//===========================================
// Create a singly linked list L with head node, and with n elements
//===========================================
Status CreateList_L(LinkList &L, int n)
{
	LinkList p, q;
	int i;
	printf("please enter the numbers:\n");
	L = (LinkList)malloc(sizeof(LNode)); //create an empty list
	if (!L) return ERROR;
	L->next = NULL;
	q = L;
	if(i==0)
	{
		p = (LinkList)malloc(sizeof(LNode));
		if (!p) return ERROR;
		scanf("%d", &p->data);                    //enter element data from keyboard
		p->next=L->next;
		L->next=p;
		L->data=p->data;
	 } 
	for (i = 1; i < n; i++){
		p = (LinkList)malloc(sizeof(LNode));    //make a new node
		if (!p) return ERROR;
		scanf("%d", &p->data);                    //enter element data from keyboard
		p->next = NULL;
		q->next = p;
		q = p;
	}
	//p->next=NULL;
	return OK;
}

//====================================================
//test whether the data elements in a singly linked list are in ascending order 
//===================================================
Status IsAscendingOrder(LinkList L, int n)
{
	LinkList flag=L;
    
	for(int i = 1;i<n;i++)
	{
		if(flag->data > flag->next->data)
		{
			return 0;
			break;
		}
		else flag = flag->next;
	}
    return 1;
}

int main(void)
{

	LinkList LA;

	// Create a singly linked list with elements of 21, 18, 30, 75, 42, 56
	CreateList_L(LA, 6);
	if (IsAscendingOrder(LA,6))
	{
		printf("Elements in a singly linked list are in increasing order.\n");
	}
	else
	{
		printf("Elements in a singly linked list aren't in increasing order.\n");
	}

}
