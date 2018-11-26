#include<stdio.h>
#include<stdlib.h>

/*
  Heap�� ��ũ�� ����Ʈ���� �迭�� ���� �ϴ°��� ����.
  LinkedList �� �� ���� �ϴ� ��带 ��� ã�� ��? ���
  ȿ������ ����� ��ƴ�.
*/

typedef int Data;

/* heap ��� */
typedef struct HeapNode
{
	Data data;

}Node;

/* �� ����ü Ʋ*/

typedef struct heap
{
	Node * node;
	int Capacity; // �� ũ��
	int UsedSize; //  ��� ��


}Heap;


Heap * Heap_Create(int Capacity);
void   Heap_Destroy(Heap * h);
void   Heap_Insert(Heap *h, Data data);
void   Heap_DeleteMin(Heap *h , Node * root);
int    Heap_GetParent(int index);
int    Heap_GetLeftChild(Heap * h,int index, int index2);
void   Heap_SwapNodes(Heap * h,int index, int index2);
void   Heap_PrintNodes(Heap *h);