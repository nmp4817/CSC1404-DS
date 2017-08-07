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
node *delet(node *);

void main()
{
	char ch;
	int choice,num;
	clrscr();
	printf("\n        MENU      ");
	printf("\n 1.create \n 2.delet in range \n 3.print \n 4.exit");

	while(choice!=4)
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
			start=delet(start);
			break;

			case 3:
			print(start);
			break;

			case 4:
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

node *delet(node *list1)
{
	int f,l;
	node *ptr,*temp;
	ptr=list1;
	temp=list1;

	printf("enter range:");
	scanf("%d %d",&f,&l);

	while(temp->link!=NULL)
	{

		if(ptr->info>=f && ptr->info<=l)
		{
			ptr=ptr->link;

		}

		else
		{
			while((temp->link->info<f) || (temp->link->info>l))
			{
				temp=temp->link;
				if(temp->link==NULL)
				break;
			}
			temp->link=temp->link->link;
		}

		list1=ptr;
	}

return list1;
}