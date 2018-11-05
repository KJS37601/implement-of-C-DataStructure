#include"CricleQueue.h"

void CreateQueue(CircleQueue ** queue,int cap)
{
             	
	*queue  =(CircleQueue*)malloc(sizeof(CircleQueue)); 
	(*queue) -> Capacity = cap;
	(*queue) -> Front    = 0;
	(*queue) -> Rear     = 0;

	/* ���� ��带 ���ؼ� ����ť�� ��ȭ �������� �ƴ����� �˼� �ֱ⿡ Capacity ���� +1 �� ������ �����.*/
	(*queue) -> Nodes    = (Node*)malloc(sizeof(Node)* (cap+1));// ��ȭ�������� ������ ���� ��带 ���� 
 
}

void Enqueue(CircleQueue * queue, data item)
{
	//���迭�� ������ �ε���
	int position = 0;
	
	/*
	   Queue�� ���� �ϱ� ���ؼ��� 
	   1) �켱  ť�� ��ȭ���������� Ȯ���Ѵ�.
	   2) ��ȭ���°� �ƴϸ� Rear�� ���̳�忡 ���� �ߴ����� Ȯ��
	   3) Rear�� ���� ��忡 ���� ���� ���� ���� ���
	*/
	
	if(IsFull(queue))
	{
		printf("��ȭ �����Դϴ�.");
		return;
	}
	// ���̳�忡 ���� ���� ��� �ٽ� ȸ��
	if(queue->Rear == queue->Capacity+1)
	{
		queue->Rear = 0;
		position    = 0;
	}
	else
	{
		//�ƴ� ��� Rear�� 1������
		position = queue->Rear++;

	}
	
	// �ε����� ���� ������� �� ������ ����
	queue->Nodes[position].Element = item;
}


data Dequeue(CircleQueue * queue)
{
	
	//���� �ε����� ����
	int position = queue->Front;
    // ���� ��忡 ���� �Ұ�� �ٽ� ȸ��	
	if(queue->Front == queue->Capacity)
	{
		queue->Front = 0;
	}
	else
	{
		//�ε��� 1�� ����
		queue->Front++;
	}
	return queue->Nodes[position].Element;

}

int IsFull(CircleQueue *queue)
{
	/*
	    �ΰ��� ��츦 ���� �غ��� �Ѵ�.
		1) Front�� Rear �տ� �������
		2) Front�� Rear �ڿ� �������

		1)    Front            Rear
	        --------------------------
	        |  1    |  2   |         |
		    --------------------------
	          [0]      [1]     [2]
 
           ���� á������ ��� �˱�? ...
		   �ʱ⿡ ť�� ũ�⸦ ���� �Ͽ���... �翬�� Capactiy ���� �������� Ȯ�� �ϸ� �ȴ�.
		   ��.. ��� �˾� ���� �ϴ� �ɱ�? �츮�� Rear�� Front�� �������� Ȯ�� ���� ���Ѵ�.
		   Rear�� Front�� ���� �������� �˾ƺ� �ʿ�� ���� Rear�� Front�� �̿� �ϸ� �ȴ�.
		   ù��° ��츦 �ٽ� ���÷� ����
		   Front�� Rear �տ� ���� ��� �̴�. �׷��� Fornt���� Rear ���� ���� �� �ۿ� ����.
		   (Rear - Front)�� �ϸ� �츮�� ����ϰ� �ִ� ũ�⸦ �˾Ƴ� �� �ִ�.
		   (Rear - Front)���� Capactiy�� ������  ��ȭ ���� �ΰ��̴�.




		   2)         Rear
   	      	          Front           
	        --------------------------
	        |    3   |  2   |         |
		    --------------------------
	          [0]      [1]     [2]

               


			Rear�� ������ ��尡 ����á���� �ƴ����� �׳� �ϸ� �ȵɱ�? �翬�� �ȵȴ�.


	*/


	if(queue->Front < queue->Rear)
	{
		return (queue->Rear - queue->Front) == queue->Capacity;
	}else
	{
		return (queue->Rear + queue->Front )  == queue->Capacity;
	}
}

int GetSize(CircleQueue * queue)
{
	//Front�� Rear�� �������� Front���� Rear�� �տ� ���� ��� 
	if(queue->Front <= queue->Rear)
	{
		return (queue->Rear - queue->Front);
	}else
		return  queue->Capacity - queue->Rear-1;


}
int IsEmty(CircleQueue * queue)
{
	// Rear �� Front ���� ���
	if(queue->Rear == queue->Front)
		return  1;
	else
		return 0;
}

void Destroy(CircleQueue * queue)
{
	free(queue->Nodes);
	free(queue);

}