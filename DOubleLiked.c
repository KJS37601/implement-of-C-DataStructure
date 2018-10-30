#include "Node.h"


/*
  i)
         ------------------
  NULL <-| pre| data| next| ->NULL
         ------------------

*/

//������,����ּ� ��ȯ
Node *create_node(item data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->next= NULL;
	newNode->pre = NULL;
	newNode ->data =data;
	return newNode;
}
//���� ����߰�
/*
    i)          head           
	      ------------------
  NULL <-| pre| data| next| ->NULL
          ------------------

   ii)                        move
              head   tail  ----------->   tail                 
               ��     ��                   ��                  
	      ------------------      --------------------  
  NULL <-| pre| data| 0x02 | ->   | 0x01| data | NULL |   .........    
          ------------------ <--  --------------------
		       0x01                       0x02 
			                             newNode

*/
void appned_node(Node ** head,Node * newNode)
{
	  if(*head == NULL)
	  {
		  *head = newNode;

	  }else
	  {
		  Node * tail = *head;	
		  //tail != NULL ���� �߻�
		  // tail �� NULL�ǰ� �ݺ��� ����
		  // tail�� NULL�̴�.
		  // �׷��Ƿ� �Ʒ� ���ǹ����� ���� �ؾ� �Ѵ�.
		  while(tail->next !=NULL)
		  {
			   tail = tail->next;
		  }		 
		    tail->next = newNode;
			newNode->pre = tail;
	  }

}

void print_revers(Node ** head)
{
	Node * cur = *head;
	//cur�� ������ �̵�
	while(cur->next !=NULL )
	{
		cur = cur->next;
	}
	  // �������� ���
	 while(cur != NULL)
	 {
		 printf("<- %d ",cur->data);
		 cur =cur->pre;
	 }
	 puts(" ");
}

//��� ���
void print(Node **head)
{
	 Node * cur = *head;
	 Node * pre = *head;

	 while(cur !=NULL /*&&  pre->next != NULL*/ )
	 {		 
		 printf(" %d ->",cur->data);
		 cur = cur->next;
	}
	   puts(" ");

}
//�߰��� ��� �߰�
void middel_insert(Node **head, Node * newNode,item number)
{
	Node * cur = *head;
	Node * pre = NULL;
	
	int i;
	for(i=0;i<number;i++)
	{
		pre = cur;
		cur = cur->next; 
	}

	// �߰��� ��� ���� �ϴ� �ٽ� !!
	 cur->pre = newNode;
	 newNode->next =cur;
	 newNode->pre = pre;
	 pre->next = newNode;
}

Node * find_node(Node **head, item data)
{
	Node * cur = *head;
	Node * node = NULL;

	while(cur != NULL)
	{
		if(cur->data == data)
		{
			node = cur;
		}
		cur= cur->next;
	}

	 return  node;
}


void delete_node(Node ** head, item data)
{
     Node * del = find_node(head,data);
	 Node * fro = del;//������� �� ���
	 Node * pre = *head;//������� ���� ���
	 
	if(del)
	{
	   // �߰� ����� ���
		/*
		       ������尡 �������� ������尡 
			   NULL�� �ƴϿ����� �߰��� �ִ� ��� �̴�.

		*/
		if(del->next != NULL && del->pre != NULL)
	    {
		  while(pre->next !=del )
		  {
			 pre = pre->next;
		  }
		     fro = fro->next;
            
			 pre->next = fro;
			 fro->pre = pre;
			 free(del);
		}

		// ó�� ����� ���
		/*
		      �������� ����尡 ������ ó�� ���
			  head�� ����Ű�� ��尡 �縮���� �ǹǷ�
			  ���ǳ��� �̵��Ͽ� head�� ����Ű�� �ϰ�
			  �ش� ��� ����
		*/
		if(del == pre)
		{
			fro = fro->next;
			fro->pre = NULL;
			*head = fro;
			free(del);
		}
		 // ������ ����� ���
		if(del->next == NULL)
		{
			//del�� ���� ��尡 �Ǳ��������� �̵�
			while(pre->next !=del)
			{
				pre = pre->next;
			}
			  pre->next = del->next;// pre->next =NULL;
			  free(del);

		}



   }

}

