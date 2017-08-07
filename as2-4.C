#include<stdio.h>
#include<stdlib.h>

struct list
{
	int info;
	struct list * link;
};

typedef struct list node;

node *start1=NULL;
node *start2=NULL;

node *create(node *,int);
void print(node *);
node *join(node *,node *);


void main()
{
	char ch;
	int choice,num;
	clrscr();

	while(choice!=3)
	{
		printf("\n        MENU      ");
		printf("\n 1.create \n 2.join \n 3.exit");

		printf("\n enter your choice:");
		scanf("%d",&choice);

		switch(choice)

		{
			case 1:

			printf("enter list1:");
			do
			{
				printf("\n enter no:");
				scanf("%d",&num);
				start1=create(start1,num);
				printf("\n do you want to enter more?(y.yes/n.no)::");
				scanf("%s",&ch);
			}while(ch!='n');

			printf("\n enter list2:");
			do
			{
				printf("\n enter no:");
				scanf("%d",&num);
				start2=create(start2,num);
				printf("\n do you want to enter more?(y.yes/n.no)::");
				scanf("%s",&ch);
			}while(ch!='n');

			break;

			case 2:
			start1=join(start1,start2);
			printf("\n joint list:\n");
			print(start1);
			break;

			case 3:
			break;
		}
	}
}


node *create(node *list1,int no)
{
	node *ptr;
	ptr=list;

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

node *join(node *list2,node *list3)
{

	node *ptr1;
	node *ptr2;
	ptr1=list2;
	ptr2=list3;

	while(ptr1->link!=NULL)
	{
		ptr1=ptr1->link;
	}

	ptr1->link=ptr2;

	/*while(ptr2!=NULL)
	{
		ptr1=(node *)malloc(sizeof(node));
		ptr1->info=ptr2->info;
		ptr1->link=ptr2->link;
		ptr2=ptr2->link;
	}*/

	return list2;

}