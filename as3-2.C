#include<stdio.h>
#include<stdlib.h>

structlist
{ int info;
  struct list *link;
}*front,*rear;
typedef struct list queue;

void insert(int);
int delet();
void print();

void main()
{ int N,ch;
  front=NULL;
  rear=NULL;

  do
  { clrscr();
    printf("\n MENU");
    printf("\n 1. insert \n 2. delete \n 3. print \n 4. exit");
    printf("\n\n enter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    { case 1 : 
               printf("\n enter no : ");
	       scanf("%d",&N);
	       insert(N);
	       break;

      case 2 : N=delet();
	       if(N!=-1)
	       { printf("\n NO. deleted : %d",N); }
	       break;

      case 3 : print();
	       break;
    }
    getch();
  }while(ch!=4);
  getch();
}

void insert(int NO)
{ queue *ptr;
  ptr=(queue*)malloc(sizeof(queue));
  ptr->info=NO;
  if(front==NULL)
  { front=ptr;
    ptr->link=NULL;
  }
  else
  { rear->link=ptr;
    ptr->link=NULL;
  }
   rear=ptr;
}

int delet()
{ int item;
  if(front==NULL)
  { printf("\n underflow!");
    return -1;
  }
  else
  { item=front->info;
    front=front->link;
    return item;
  }
}

void print()
{ queue *ptr;
  if(front==NULL)
  { printf("\n\nlist empty");
  }
  else
  {  ptr=front;
    while(ptr!=NULL)
    { printf("\n %d",ptr->info);
      ptr=ptr->link;
    }
  }
}

