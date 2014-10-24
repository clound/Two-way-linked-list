#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define FALSE 0
#define TRUE 1
typedef unsigned int bool;
int main(int argc, char const *argv[])
{
	int num;
	int data,pos;
	bool flag = FALSE;
	DLinkList pnode;
	DLinkList list = createlist(0);
	while(flag == FALSE)
	{
		printf("Main Menu\n");
		printf("1. Insert\n");
		printf("2. Delete Node\n");
		printf("3. Find\n");
		printf("4. Length\n");
		printf("5. Positive print\n");
		printf("6. Negative print\n");
		printf("7. Delete list\n");
		printf("8. Insert data where are you hope\n");
		scanf("%d",&num);
		switch(num)
		{
			case 1: printf("Input the data to Insert:\n");
				scanf("%d",&data);
				list = create(list,data);
				printlist(list);
				printf("\n");break;
			case 2: printf("Input the data to Delete:\n");
				scanf("%d",&data);
				deletenode(list,data);
				printlist(list);
				printf("\n");break;
			case 3: printf("Input the data to Find:\n");
				scanf("%d",&data);
				pnode = findnode(list,data);
				if (NULL != pnode)
				{
					printf("find succeed! position is %d\n",pnode->data);
					printf("\n");
				}
				else{
					printf("Find failed\n");
					printf("\n");
				}
				break;
			case 4: printf("The list's length is %d\n",getlength(list));
				printf("\n");break;
			case 5: printlist(list);
				//printf("\n");
				break;
			case 6: reverprint(list);
				printf("\n");break;
			case 7: deletelist(list);
				printf("\n");break;
			case 8:  printf("Input the data to Insert:\n");
				scanf("%d,%d",&pos,&data);
				list = crdata(list,pos,data);
				printlist(list);
				printf("\n");break;
			case 0: deletelist(list);
				flag = TRUE;
		}
	}
	return 0;
}