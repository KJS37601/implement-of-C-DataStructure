/*
   ��ũ�� ť  VS ���� ť


    ��ũ�� ť�� ���� ��尡 ���� �� �ִ��� Ȯ�� ���ʿ䰡 ����.

  ���� ť)
   1. ũ�⸦ ���� ���ɰ��
   2. ������ �ʿ��� ���� ���
  ��ũ�� ť)
   1. ũ�⸦ ���� ���� ���� ���

   �ӵ� 
   ��ũ�� ť  <<  ���� ť

*/

#define __LINKEDQUEUE_H__
#include<stdio.h>

typedef struct _node
{
	char * data;
	struct _node * next;

}Node;

typedef struct likedqueue
{
	Node * Rear;
	Node * Front;
    int count;
}LikedQueue;

void Enqueue(LikedQueue * queue, Node * newNode);
Node * CreateNode(char * data);
void CreateLinkedQueue(LikedQueue ** queue);
Node * Dequeue(LikedQueue * queue);