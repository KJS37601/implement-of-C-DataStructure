#include<stdio.h>
#include<stdlib.h>
#define item int

typedef struct _node
{

    item data;
	struct _node * next;

}Node;

Node * create(item data)
{
	Node * NewNode=(Node*)malloc(sizeof(Node));
	NewNode->data=data;
	NewNode->next=NULL;

	return NewNode;
}

void append_node(Node **head, Node * newNode)
{
	if((*head) == NULL)
	{
		(*head) = newNode;
	}else
	{
		Node * tail = *head;	
		while(tail->next != NULL)
		{
			tail = tail->next;
		}
		 tail->next = newNode;
	}
}

void print(Node ** head)
{
	Node * cur = *head;
	if(*head == NULL)
	{
	   puts("�����ϴ�.");
	   exit(-1);
	}

	while( cur != NULL)
	{
		printf("%d  -> ",cur->data);
		cur = cur->next;
	}
	printf("\n");

}

void delete_tail_node(Node **head)
{
	Node * pre = NULL;
	Node* cur = *head;

	printf("������ �����մϴ�.\n");
	if(*head == NULL)
	{
		puts("�� �̻� �����ϴ�.");
		exit(-1);
	}
     

	while(cur != NULL)
	{  
	    pre = cur;
		cur = cur->next;
		
		printf("%d -> ",pre->data);
		free(pre);
	}
	printf("\n");
	*head = NULL;
	
     
        

}
//���� ����ּ� ��ȯ 
Node * current_node(Node ** head,item data)
{    
	 Node * cur = *head;
	 int count =1;
	 while(cur != NULL)
	 {
		 if(cur->data == data)
		 {  
			 printf("%d ��° ��忡 ���� :   ->",count);
			 return  cur;
		 }
		 count ++;
		 cur = cur->next;
	 }
	 return NULL;
}


Node* find_Node(Node **head ,item  data)
{
	Node * p = NULL;
	 if(p=current_node(head,data))
	 {
		 printf("%d \n",p->data);
		 return p;
	 }
	 else
	 {
		 puts("ã�� ���� �����ϴ�.");
		 return NULL;
	 }

	 free(p);

}

//�߰� ������ ���
void delete_middle_node(Node **head, item data)
{
	Node * pre = *head;
	Node * cur = find_Node(head,data);

 
	   // ��尡 ù��° ����� ���
	    if(cur == pre )
		{
			//printf("%x\n",cur);
		   pre = pre->next;
		 //  printf("%x\n",pre);
		  *head = pre;
		 // printf("%x\n",*head);
		  free(cur);
		  return;
		 
		}
		
	

	//�߰� ����� ��� or ����� �ϰ��
	while(pre !=NULL && pre->next != cur)
	{
		//printf("pre -> %x cur->%x\n",pre,cur);
		pre = pre->next;
		if(cur->next == NULL)
		{
			pre->next = cur->next;
			free(cur);
		}

	}

	   
	//printf("pre %x  cur %x \n",pre,cur);
	pre->next = cur->next;
	free(cur);
		
	

}





int main()
{
	//int a =10;
   
	Node * List =NULL;
	Node * newNode = NULL;


	newNode = create(117);
    append_node(&List, newNode);

   	newNode = create(118);
    append_node(&List, newNode);

	newNode = create(119);
    append_node(&List, newNode);

	newNode = create(120);
    append_node(&List, newNode);
	print(&List);

	find_Node(&List,120);
	//find_Node(&List,118);
	//find_Node(&List,0);



	//delete_tail_node(&List);
	//print(&List);

    delete_middle_node(&List,119);
	print(&List);
	
	delete_middle_node(&List,117);
	print(&List);
    
	delete_middle_node(&List,120);
	print(&List);


	//free(newNode);
	//free(List);
	

	return 0;
}