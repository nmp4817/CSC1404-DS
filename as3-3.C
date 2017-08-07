#include<stdio.h>
#include<stdlib.h>

struct list
{ int info;
  struct list *link;
}*front,*rear;
typedef struct list cque;

void insert(int);
int delet();
void print();

void main()
{ int N,ch;
  rear=NULL;
  front=NULL;
  clrscr();
  while(ch!=4)
  { clrscr();
    printf("\n MENU");
    printf("\n 1. insert \n 2. delet \n 3. print \n 4. exit");
    printf("\n\n enter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    { case 1 : printf("\n enter no : ");
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
  }
  getch();
}

void insert(int NO)
{ cque *ptr,*temp;
  temp=(cque*)malloc(sizeof(cque));
  temp->info=NO;
  if(front==NULL)
  { front=temp;
    temp->link=front;
  }
  else
  { rear->link=temp;
    temp->link=front;
  }
  rear=temp;
}

int delet()
{ cque *ptr,*temp;
  int item;
  if(front==rear+1)
  { printf("\n underflow");
    return -1;
  }
  else
  { item=front->info;
    ptr=front;
    while(ptr!=rear)
    { ptr=ptr->link; }
    ptr->link=front->link;
    front=front->link;
    rear=ptr;
    return item;
  }
}

void print()
{ cque *ptr;
  if(front==NULL)
  { printf("\n\n list empty");
  }
  else
  {  ptr=front;
    do
    { printf("\n %d",ptr->info);
      ptr=ptr->link;
    }while(ptr!=front);
    
  }
}

