#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
}Node,*DLinkList;
//创建结点
DLinkList createnode(int data)
{
	DLinkList pnode = (DLinkList)malloc(sizeof(Node));
	pnode->data = data;
	pnode->left = pnode->right = pnode;
	return pnode;
}
//创建链表
DLinkList createlist(int head)
{
	DLinkList pnode = (DLinkList)malloc(sizeof(Node));
	pnode->data = head;
	pnode->left = pnode->right = pnode;
	return pnode;
}
DLinkList create(DLinkList node ,int data)
{
	DLinkList pnode;
	pnode = node;
	pnode = createnode(data);
	node->left->right = pnode;
	pnode->right = node;
	pnode->left = node->left;
	node->left= pnode;
	return node;
}
//指定位置插入数值
DLinkList crdata(DLinkList node,int pos,int data)
{
	DLinkList pnode,qnode;
	int i = 0;
	pnode = node;
	while(pnode != NULL && i < pos - 1){
		pnode = pnode->right;
		i++;
	}
	qnode = createnode(data);
	qnode->left = pnode;
	qnode->right = pnode->right;
	pnode->right->left = qnode;
	pnode->right = qnode;
	return node;
}
//查找结点
DLinkList findnode(DLinkList node,int data)
{
	DLinkList pnode = node->right;
	while(pnode != node && pnode->data != data)
	{
		pnode = pnode->right;
	}
	if (pnode == node)
		return NULL;
	return pnode;
}
//删除满足的结点
DLinkList deletenode(DLinkList node,int data)
{
	DLinkList pnode = findnode(node,data);
	if(NULL == pnode)
		return NULL;
	pnode->left->right = pnode->right;
	pnode->right->left = pnode->left;
	free(pnode);
	return node;
}
//获取链表长度
int getlength(DLinkList node)
{
	int count = 0;
	DLinkList pnode = node->right;
	while(pnode != node)
	{
		pnode = pnode->right;
		count++;
	}
	return count;
}
//顺序打印整个链表
void printlist(DLinkList node)
{
	DLinkList pnode;
	if (NULL == node)
		return ;
	pnode = node->right;
	while(pnode != node)
	{
		printf("%2d",pnode->data );
		pnode = pnode->right;
	}
	printf("\n");
}
//将链表反序打印
void reverprint(DLinkList node)
{
	DLinkList pnode;
	if (NULL == node)
		return ;
	pnode = node->left;
	while(pnode != node)
	{
		printf("%2d",pnode->data);
		pnode = pnode->left;
	}
	printf("\n");
}
//删除链表
void deletelist(DLinkList node)
{
	DLinkList pnode = node->right;
	DLinkList ptmp;
	while(pnode != node)
	{
		ptmp = pnode->right;
		free(pnode);
		pnode = ptmp;
	}
	free(node);
}
