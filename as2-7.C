//wap to add two polynomials

#include<stdio.h>
 
#include<malloc.h>
#include<stdlib.h>
typedef struct list node;
struct list
	{
		int cof,pow;
		node *lnk;
	};

node *create(node*);
node *sort(node*);
//node* add(node*,node*);
int cnt(node*);
void swap(int*,int*);
void print(node*);

void main()
	{
		node *poly1,*poly2,*poly;
		int c;
		 
		poly1=NULL;
		poly2=NULL;


		printf("\npolynomial 1:\n");
		printf("\npress any key to enter term or\npress 2 to end...");
		 ;
		scanf("%d",&c);
		while(c!=2)
			{
				 ;
				poly1=create(poly1);
				printf("\npress any to enter term or\npress 2 to end...");
				scanf("%d",&c);
			}
		poly1=sort(poly1);
		printf("\npolynomial 1: ");
		print(poly1);

		printf("\npolynomial 2:\n");
		printf("\npress any key to enter term or\npress 2 to end...");
		 ;
		scanf("%d",&c);
		while(c!=2)
			{
				 ;
				poly2=create(poly2);
				printf("\npress any to enter term or\npress 2 to end...");
				scanf("%d",&c);
			}
		poly2=sort(poly2);
		printf("\npolynomial 2: ");
		print(poly2);

	//	poly3=poly1;
		poly=poly1;
		while(poly->lnk!=NULL)
			poly=poly->lnk;
		poly->lnk=poly2;
		sort(poly1);
		printf("\nAnswer : ");
		print(poly1);
		/*
		poly3=add(poly1,poly2);
		printf("\nAnswer: ");
		print(poly3);*/
		 
	}

/*node* add(node *poly1,node *poly2)
	{
		node *poly,*pol,*ptr2,*ptr1;
		pol=NULL;

		for(ptr1=poly1;ptr1!=NULL;ptr1=ptr1->lnk)
			{
				for(ptr2=poly2;ptr2!=NULL;ptr2=ptr2->lnk)
					{
						if(ptr1->pow==ptr2->pow)
							{
								if(pol==NULL)
									{
										pol=(node*)malloc(sizeof(node));
										poly=pol;
										poly->cof=ptr1->cof+ptr2->cof;
										poly->pow=ptr1->pow;
										poly->lnk=NULL;
									}
								else
									{
										poly->lnk=(node*)malloc(sizeof(node));
										poly=poly->lnk;
										poly->cof=ptr1->cof+ptr2->cof;
										poly->pow=ptr1->pow;
										poly->lnk=NULL;
									}
							}
					}
			}
		pol=sort(pol);
		return pol;
	}*/

node *create(node *p)
	{
		node *ptr;
		int x,y;
		printf("\nEnter coefficient and power: ");
		scanf("%d %d",&x,&y);
		if(p==NULL)
			{
				p=(node*)malloc(sizeof(node));
				p->cof=x;
				p->pow=y;
				p->lnk=NULL;
			}
		else
			{
				ptr=p;
				while(ptr->lnk!=NULL)
					ptr=ptr->lnk;
				ptr->lnk=(node*)malloc(sizeof(node));
				ptr->lnk->cof=x;
				ptr->lnk->pow=y;
				ptr->lnk->lnk=NULL;
			}
		return p;
	}

node *sort(node *p)
	{
		node *ptr,*ptr1;
		int i,j,n=cnt(p);
		for(i=1;i<n;i++)
			{
				ptr1=p;
				ptr=ptr1->lnk;
				for(j=1;j<=n-1;j++)
					{
						if(ptr1->pow<ptr->pow)
							{
								swap(&ptr1->cof,&ptr->cof);
								swap(&ptr1->pow,&ptr->pow);
							}
						else if(ptr1->pow==ptr->pow)
							{
								ptr1->cof+=ptr->cof;
								ptr1->lnk=ptr->lnk;
								ptr->lnk=NULL;
								--n;
							}
						ptr1=ptr1->lnk;
						ptr=ptr1->lnk;
					}
			}
		return p;
	}

void swap(int *a,int *b)
	{
		*a=*a+*b;
		*b=*a-*b;
		*a=*a-*b;
	}

int cnt(node *p)
	{
		int i=0;
		node *ptr;
		ptr=p;
		if(p==NULL)
			i=0;
		else
			{
			for(i=0;ptr!=NULL;i++)
				ptr=ptr->lnk;
			}
		return i;
	}

void print(node *p)
	{
		node *ptr;
		int f=0;
		ptr=p;
		printf("\n");
		while(ptr!=NULL)
			{
				if(f!=0)
					printf("+");
				f=1;
				printf(" %dx^%d ",ptr->cof,ptr->pow);
				ptr=ptr->lnk;
			}
		printf("= 0\n");
	}
