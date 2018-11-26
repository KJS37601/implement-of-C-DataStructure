#define __QUEUENODE_H__
#include<stdio.h>
#include<stdlib.h>

typedef int data;

typedef struct _node
{
	data Element;

}Node;

typedef struct cricleQueue
{

	int Capacity; // �뷮
    int Front;   // ������ �ε���
	int Rear;    // �Ĵ��� �ε���
	Node * Nodes;


}CircleQueue;

//Queue ����
void CreateQueue(CircleQueue ** queue, int cap);
//����
void Enqueue(CircleQueue * queue,data item);
//����
data Dequeue(CircleQueue * queue);
//��ȭ����
int IsFull(CircleQueue *queue);
//���� ����ϴ� size 
int GetSize(CircleQueue * queue);
//����ִ��� ����
int IsEmpty(CircleQueue * queue);
void Destroy(CircleQueue * queue);