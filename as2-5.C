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
node *app(node *,int);

void main()
{
	char ch;
	int choice,num,loc;
	clrscr();
	printf("\n        MENU      ");
	printf("\n 1.create \n 2.delete & append at 1st \n 3.exit");

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
			printf("\n enter location of node which u want to append at 1st:");
			scanf("%d",&loc);
			start=app(start,loc);
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

node *app(node *list1,int loc)
{
	node *ptr,*temp;
	int i;
	ptr=list1;
	for(i=0;i<loc-1;i++)
	{
		temp=ptr;
		ptr=ptr->link;
		if(ptr==NULL)
		{
			printf("\n location is not exists! give proper location!");
			break;
		}
	}
		temp->link=ptr->link;
		ptr->link=list1;
		list1=ptr;
		return list1;

}