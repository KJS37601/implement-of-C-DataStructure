/*
  �� ������ LinkedList ���ٴ� �迭�� ���� �ϴ� ���� ���ϴ�.
  LinkedList�� ���� �ϸ� ���� ���� �� ���� ��带 ��� ã�� ��
  �ΰ�? ��� ������ ȿ������ ����� ����.

*/
#include<stdio.h>
#include<stdlib.h>
typedef int Data;

/*
   �� ��� ǥ��
*/
typedef struct HeapNode
{
	Data data;

}Node;

/* �� ��ü ����ü Ʋ*/
typedef struct Heap
{
	Node * node;  
	int Capacity;  //�迭��ũ��
	int UsedSize;  // ��� ��
}Heap;

