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
node *ins1st(node *,int);
void insaft(node *,int,int);
void inslast(node *,int);
node *del1st(node *);
void delaft(node *);
void dellast(node *);



void main()
{
	char ch;
	int choice,num,loc;
	clrscr();
	while(choice!=9)
	{
		printf("\n        MENU      \n");
		printf("\n 1.create \n 2.print \n 3.insert 1st \n 4.insert after \n 5.insert last \n 6.delete 1st \n 7.delete after \n 8.delete last \n 9.exit");

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
			printf("\n enter no to insert:");
			scanf("%d",&num);
			start=ins1st(start,num);
			break;
			
			case 4:
			printf("\n enter no and location:");
			scanf("%d %d",&num,&loc);
			insaft(start,loc,num);
			break;

			case 5:
			printf("\n enter no to insert:");
			scanf("%d",&num);
			inslast(start,num);
			break;

			case 6:
			start=del1st(start);
			break;

			case 7:
			delaft(start);
			break;
	
			case 8:
			dellast(start);
			 
			case 9:
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

node *ins1st(node *list1,int no)
{
	node *ptr;
	ptr=list1;

	ptr=(node *)malloc(sizeof(node));
	ptr->info=no;
	list1->bw=ptr;
	ptr->fw=list1;
	ptr->bw=NULL;
	list1=ptr;

	return list1;
}

void inslast(node *list1,int no)
{
	node *ptr,*temp;
	temp=list1;

	while(temp->fw!=NULL)
	{
		temp=temp->fw;
	}

	ptr=(node *)malloc(sizeof(node));
	ptr->info=no;
	ptr->fw=NULL;
	ptr->bw=temp;
	temp->fw=ptr;
}

void insaft(node *list1,int loc,int no)
{
	int i;
	node *ptr,*temp;
	temp=list1;


	for(i=1;i<loc;i++)
	{
		temp=temp->fw;
		if(temp==NULL)
		{
			printf("\n location is not exists! give proper location!");
			break;
		}
	}
	ptr=(node *)malloc(sizeof(node));
	ptr->info=no;
	(temp->fw)->bw=ptr;
	ptr->fw=temp->fw;
	temp->fw=ptr;
	ptr->bw=temp;
}

node *del1st(node *list1)
{
	node *ptr;
	ptr=list1;
	list1=ptr->fw;
	list1->bw=NULL;
	free(ptr);
	return list1;
}

void dellast(node *list1)
{

	node *ptr;
	node *temp;

	ptr=list1;

	while(ptr->fw!=NULL)
	{
		temp=ptr;
		ptr=ptr->fw;
	}

	temp->fw=NULL;
	free(ptr);

}


void delaft(node *list1)
{
	int i,loc;
	node *ptr,*temp;
	ptr=list1;

	printf("\n enter location of node:");
	scanf("%d",&loc);


	for(i=1;i<=loc;i++)
	{
		temp=ptr;
		ptr=ptr->fw;
		if(ptr==NULL)
		{
			printf("\n location is not exists! give proper location!");
			break;
		}
	}

	(ptr->fw)->bw=temp;
	temp->fw=ptr->fw;
	free(ptr);

}