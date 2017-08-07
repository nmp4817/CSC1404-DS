#include<stdio.h>
#include<stdlib.h>

struct list
	{
		int cof,exp;
		struct list *link;
	};

typedef struct list node;

node *start1=NULL;
node *start2=NULL;
node *start3=NULL;
node *start4=NULL;


node *create(node *,int,int);
void print(node *);
node *sum(node *,node *);
node *mul(node *,node *);
node *sort(node *);

void main()
{
	int ex,co,choice;
	char ch;
	clrscr();

	while(choice!=4)
	{
		printf("\n        MENU      ");
		printf("\n 1.create \n 2.addition \n 3.multiplication\n 4.exit");

		printf("\n enter your choice:");
		scanf("%d",&choice);

		switch(choice)

		{
			case 1:

			printf("\n enter polynomial1:");
			do
			{
				printf("\n enter coefficient and exponential::");
				scanf("%d %d",&co,&ex);
				start1=create(start1,co,ex);
				printf("\n do you want to enter more?(y.yes/n.no)::");
				scanf("%s",&ch);
			}while(ch!='n');
			start1=sort(start1);
			printf("\n polynomial 1 ::");
			print(start1);


			printf("\n enter polynomial2:");
			do
			{
				printf("\n enter coefficient and exponential::");
				scanf("%d %d",&co,&ex);
				start2=create(start2,co,ex);
				printf("\n do you want to enter more?(y.yes/n.no)::");
				scanf("%s",&ch);
			}while(ch!='n');
			start2=sort(start2);
			printf("\n polynomial 2 ::");
			print(start2);

			break;

			case 2:
			start3=sum(start1,start2);
			start3=sort(start3);
			printf("answer of addition ::");
			print(start3);
			break;


			case 3:
			start4=mul(start1,start2);
			start4=sort(start4);
			printf("\n answer of multiplication ::");
			print(start4);
			break;

			case 4:
			break;
		}
	}
}


node *create(node *list1,int co,int ex)
{
	node *ptr;
	ptr=list1;

	if(list1==NULL)
	{
		ptr=(node *)malloc(sizeof(node));
		ptr->cof=co;
		ptr->exp=ex;
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
		ptr->link->cof=co;
		ptr->link->exp=ex;
		ptr->link->link=NULL;
	}
	return list1;
}


node *sum(node *list1,node *list2)
{
	node *poly,*ptr,*ptr1,*ptr2;

	ptr1=list1;
	ptr2=list2;

	poly=(node *)malloc(sizeof(node));
	ptr=poly;

	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->exp==ptr2->exp)
		{
			ptr->cof=ptr1->cof+ptr2->cof;
			ptr->exp=ptr1->exp;
		
			ptr1=ptr1->link;
			ptr2=ptr2->link;
		}

		else if(ptr1->exp<ptr2->exp)
		{
			ptr->cof=ptr1->cof;
			ptr->exp=ptr1->exp;

			ptr1=ptr1->link;
		}	

		else if(ptr2->exp < ptr1->exp)
		{
			ptr->cof=ptr2->cof;
			ptr->exp=ptr2->exp;

			ptr2=ptr2->link;
		}	
		
		ptr=ptr->link;
			

			if(ptr1->link==NULL && ptr2->link==NULL)
			ptr->link=NULL;

			else
			ptr->link=(node *)malloc(sizeof(node));	
	
	}

	return poly;

}

node *mul(node *list1,node *list2)
{
	node *poly,*ptr,*ptr1,*ptr2;

	poly=(node *)malloc(sizeof(node));
	ptr=poly;

	for(ptr1=list1;ptr1!=NULL;ptr1=ptr1->link)
	{
		for(ptr2=list2;ptr2!=NULL;ptr2=ptr2->link,ptr=ptr->link)
		{
			ptr->cof=ptr1->cof*ptr2->cof;
			ptr->exp=ptr1->exp+ptr2->exp;

			if(ptr1->link==NULL && ptr2->link==NULL)
			ptr->link=NULL;

			else
			ptr->link=(node *)malloc(sizeof(node));


		}
	}
	poly=sort(poly);
	return poly;
}

node *sort(node *list1)
{
	node *ptr,*temp;
	int tmp=0;

	for(ptr=list1;ptr!=NULL;ptr=ptr->link)
	{
		for(temp=ptr->link;temp!=NULL;temp=temp->link)
		{
			if(ptr->exp < temp->exp)
			{
				tmp=ptr->cof;
				ptr->cof=temp->cof;
				temp->cof=tmp;

				tmp=ptr->exp;
				ptr->exp=temp->exp;
				temp->exp=tmp;
			}

			else if(ptr->exp==temp->exp)
			{
				ptr->cof=ptr->cof+temp->cof;
				ptr->link=temp->link;
				temp->link=NULL;
			}
		}
	}
	return list1;
}

void print(node *list1)
{       int f=0;
	node *ptr;
	ptr=list1;
	if(list1==NULL)
	{
		printf("\n list is empty!");
	}

	else
	{

		while(ptr!=NULL)
		{       if(f!=0)
			printf("+");
			f=1;
			printf("  %d X^%d ",ptr->cof,ptr->exp);
			ptr=ptr->link;
		}
		printf("=0\n");
	}

}