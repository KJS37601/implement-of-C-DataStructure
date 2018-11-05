//#ifndef __Stack__Node__
#define __Stack__Node__
#define string char
#include<stdio.h>
#include<stdlib.h>

typedef struct Stack_Node
{
	char * c;
	struct Stack_Node * next;

}StackNode;

typedef struct _LinkedListStack
{
	StackNode * List;
	StackNode * top;// �ֻ��� ��带 ����Ű�� ������

}LinkedListStack;


StackNode * CreateNode(string* data);
void create_stack(LinkedListStack ** stack);
void push(LinkedListStack * stack,StackNode * Newnode);
StackNode * pop(LinkedListStack * stack);
int isEmpty(LinkedListStack *stack);
void destroyNode(StackNode * stack);
void DestroyStack(LinkedListStack * stack);
StackNode * Top(LinkedListStack * stack);

//#endif