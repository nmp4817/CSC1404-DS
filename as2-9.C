#include<stdio.h>
#include<stdlib.h>

struct dlist
{
	int info;
	struct dlist *fw,*bw;
};

typedef struct dlist node;

node *start=NULL;

node *create(node *,int);
void print(node *);

void main()
{
	char ch;
	int choice,num,loc;
	clrscr();
	while(choice!=3)
	{
		printf("\n        MENU      \n");
		printf("\n 1.create \n 2.print \n 3.exit");

	printf("\n enter your choice:");
		scanf("%d",&choice);


		switch(choice)

		{
			case 1:

			do
			{
				printf("\n enter no:");
				scanf("%d",&num);
				start=create(start,num);
				printf("\n do you want to enter more?(y.yes/n.no)::");
				scanf("%s",&ch);
			}while(ch!='n');
			break;

			case 2:
			print(start);
			break;

			case 3:
			break;
		}
	}
}

node *create(node *list1,int no)
{
	node *ptr;
	ptr=list1;

	if(list1==NULL)
	{
		ptr=(node *)malloc(sizeof(node));
		ptr->info=no;
		ptr->fw=NULL;
		ptr->bw=NULL;

		list1=ptr;
	}

	else
	{
		while(ptr->fw!=NULL)
		{
			ptr=ptr->fw;
		}

		ptr->fw=(node *)malloc(sizeof(node));
		ptr->fw->info=no;
		(ptr->fw)->bw=ptr;
		ptr->fw->fw=NULL;
	}
	return list1;
}

void print(node *list1)
{
	node *ptr;
	ptr=list1;
	if(list1==NULL)
	{
		printf("\n list is empty!");
	}

	else
	{
		printf("\n list in forward direction::");

		while(ptr!=NULL)
		{
			printf("\n %d",ptr->info);
			ptr=ptr->fw;
		}

		printf("\n list in backward direction::");

		ptr=list1;
		while(ptr->fw!=NULL)
		{
			ptr=ptr->fw;
		}

		while(ptr!=NULL)
		{
			printf("\n %d",ptr->info);
			ptr=ptr->bw;
		}

	}

}
