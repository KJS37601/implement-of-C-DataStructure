#include<stdio.h>
#include<stdlib.h>
#define item int
/*

     ------------------
     | pre| data| next|
     ------------------
	 DoubleLinkedList
	 �ΰ��� �����͸� ������ �ִ� ���´�
      
	  why? 
	   
      ���Ͽ��Ḯ��Ʈ�� �ܹ������� ��带 ���� �ϰ� �ȴ�.
	  ���������� ��带 ��� �� �� ����, �߰��� ��带 �ٽ� ã�� 
	  �ʹٸ� �ٽ� ó�� ���� �˻� �ϴ� ��ȸ ����� ������ �ִ�.
	  �̷��� ������ �ذ� �ϱ� ���ؼ� ���߿��� ����Ʈ�� ��� �ϴ°��̴�.


*/
//���� ��ũ����Ʈ 
typedef struct _node
{
    item data;
	struct _node * next; // ���ǳ�带
	struct _node * pre;  // ���� ��带

}Node;

//��� ����
Node * create_node(item data);
//������� �߰�
void appned_node(Node**head,Node * newNode);
//������ ���
void print(Node **head);
//��� �߰��� ����
void middel_insert(Node**head, Node*newNode,item number);
//��� ����
void delete_node(Node **head, item data);
//��� ã��
Node * find_Node(Node **head, item data);
//������ ���
void print_revers(Node **head);
