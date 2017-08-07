#include<stdio.h>
#include<stdlib.h>

struct list
{
	int info;
	struct list * link;
};

typedef struct list node;

node *start=NULL;

node *create(node *,int);
void print(node *);

void main()
{
	char ch;
	int choice,num;
	clrscr();
	printf("\n        MENU      ");
	printf("\n 1.create \n 2.print \n 3.exit");

	while(choice!=3)
	{

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
		ptr->link=NULL;

		list1=ptr;
	}

	else
	{
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}

		ptr->link=(node *)malloc(sizeof(node));
		ptr->link->info=no;
		ptr->link->link=NULL;
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

		while(ptr!=NULL)
		{
			printf("\n %d",ptr->info);
			ptr=ptr->link;
		}
	}

}