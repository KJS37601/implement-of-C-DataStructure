#include"Stack_Node.h"
#include<string.h>


//stack ����� �����
void create_stack(LinkedListStack ** stack)
{
	 *stack = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*stack)->List = NULL;
	(*stack)->top = NULL;

}

//������
StackNode * CreateNode(string * data)
{
	StackNode * newNode = (StackNode*)malloc(sizeof(StackNode));
	newNode->c = (string*)malloc(sizeof(data)+1);
	strcpy(newNode->c ,data);
	newNode->next =NULL;

	return newNode;

}
//
void push(LinkedListStack * stack , StackNode * Newnode)
{
	if (stack->List == NULL)
	{
		stack->List = Newnode;
	}
	else
	{
		//�ֻ��� ��带 ã��  NewNode�� ����  
		StackNode * oldTop = stack->List;
		while(oldTop->next != NULL)
		{
			oldTop = oldTop->next;
		}
		   oldTop->next = Newnode;

	}
	   // ���ο��� top���� ����
	  stack->top = Newnode;
}

//top ���
StackNode * pop(LinkedListStack * stack)
{
	StackNode * TopNode    = stack->top;
	

	if(stack->List == stack->top)
	 {
		 stack->List = NULL;
		 stack->top  = NULL;
	 }
	 else
	 {
	      //���� top���� ������������ ����
		  StackNode * CurrentTop = stack->List; 
		  
		  while(CurrentTop !=NULL && CurrentTop->next !=stack->top)
		  {
			  CurrentTop =  CurrentTop->next;

		  }

		  stack->top = CurrentTop;
		  CurrentTop->next = NULL;
	 }

	 return  TopNode;
}

int isEmpty(LinkedListStack * stack)
{
	return (stack->List == NULL);
}

void destroyNode(StackNode * node)
{
	free(node->c);
	free(node);
}

StackNode * Top(LinkedListStack * stack)
{
	return stack->top;
}
void DestroyStack(LinkedListStack * stack)
{
	while(isEmpty(stack))
	{
		StackNode * Popped = pop(stack);
		destroyNode(Popped);
	}

	DestroyStack(stack);


}


