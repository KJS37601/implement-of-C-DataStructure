#include"BinaryTreeNode.h"
#include<stdlib.h>

BinaryTreeNode * CreateNode(item data)
{
   BinaryTreeNode * newNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
   newNode->data =data;
   newNode->left = NULL;
   newNode->right = NULL;

   return  newNode;
}

void PreorderPrintTree(BinaryTreeNode * tree)
{

	if(tree == NULL)
		return;

	printf("%c  tree : [%p]  tree->right: [%p] \n",tree->data,tree->right);

	//���� �켱 ��ȸ
	PreorderPrintTree(tree->left);
	
	printf("trewew : [%p] \n",tree->right);

	//������ ��ȸ
	PreorderPrintTree(tree->right);
	
}


void InorderPrintTree(BinaryTreeNode * tree)
{


   if(tree == NULL)
	   return ;

   InorderPrintTree(tree->left);
   printf("%c \n",tree->data);
   InorderPrintTree(tree->right);


}

void PostderPrintTree(BinaryTreeNode * tree)
{


	if(tree ==NULL)
		return;

	PostderPrintTree(tree->left);
	//������ �ٷ� ����
	PostderPrintTree(tree->right);
	printf("%c  \n",tree->data);

}

void DestroyTree(BinaryTreeNode * tree)
{
	if(tree == NULL )return;


	DestroyNode(tree->left);
	DestroyNode(tree->right);
	DestroyNode(tree);

}

void DestroyNode(BinaryTreeNode * tree)
{
	free(tree);
}