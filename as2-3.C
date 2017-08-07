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
void sort(node *);
node *delet(node *,int);
node *insert(node *,int,int);
node *update(node *,int,int);
void search(node *,int);
void main()
{
	char ch;
	int choice,num,no,loc;
	clrscr();
	

	while(choice!=7)
	{
		printf("\n        MENU      ");
		printf("\n 1.create \n 2.print \n 3.delete \n 4.insert \n 5.update \n 6.search \n 7.exit");

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
			sort(start);
			print(start);
			break;

			case 3:
			printf("\n enter location of node:");
			scanf("%d",&loc);
			start=delet(start,loc);
			print(start);
			break;

			case 4:
			printf("enter no and location:");
			scanf("%d %d",&no,&loc);
			start=insert(start,no,loc);
			print(start);
			break;

			case 5:
			printf("enter no and location:");
			scanf("%d %d",&no,&loc);
			start=update(start,no,loc);
			print(start);
			break;

			case 6:
			printf("enter location:");
			scanf("%d",&loc);
			search(start,loc);

			case 7:
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

void sort(node *list1)
{

	node *ptr,*temp;
	int tmp=0;

	for(ptr=list1;ptr!=NULL;ptr=ptr->link)
	{
		for(temp=ptr->link;temp!=NULL;temp=temp->link)
		{
			if(ptr->info > temp->info)
			{
				tmp=ptr->info;
				ptr->info=temp->info;
				temp->info=tmp;
			}
		}
	}
}

node *delet(node *list1,int loc)
{
	int i;
	node *ptr,*temp;
	ptr=list1;


	if(loc==1)
	{
		list1=ptr->link;
	}

	else
	{
		for(i=1;i<loc;i++)
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
	}

	free(ptr);

	return list1;

}

node *insert(node *list1,int no,int loc)
{
	int i;
	node *ptr,*temp;
	temp=list1;

	if(loc==1)
	{
		ptr=list1;

		ptr=(node *)malloc(sizeof(node));
		ptr->info=no;
		ptr->link=list1;
		list1=ptr;
	}

	else
	{
		for(i=1;i<loc-1;i++)
		{
			temp=temp->link;
			if(temp==NULL)
			{
				printf("\n location is not exists! give proper location!");
				break;
			}
		}

		ptr=(node *)malloc(sizeof(node));
		ptr->info=no;
		ptr->link=temp->link;
		temp->link=ptr;
	}

	return list1;
}


node *update(node *list1,int no,int loc)
{

	list1=delet(list1,loc);
	list1=insert(list1,no,loc);

	return list1;
}


void search(node *list1,int loc)
{
	int i;
	node *ptr;
	ptr=list1;
	for(i=1;i<loc;i++)
	{
		ptr=ptr->link;
		if(ptr==NULL)
		{
			printf("\n node is not exixt:");
		}
	}

	printf("\n data at %d node is %d",loc,ptr->info);

}