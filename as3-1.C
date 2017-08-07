#include<stdio.h>
#include<stdlib.h>

struct list
{ int info;
  struct list *link;
}*top;
typedef struct list stack;

void push(int);
int pop();
void print();

void main()
{ int N,ch;
  clrscr();
  top=NULL;


  do
  { clrscr();
    printf("\n\t MENU ");
    printf("\n 1. push\n 2. pop\n 3. print\n 4. exit");
    printf("\n\n enter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    { case 1 :	
		printf("\n\n enter no : ");
	        scanf("%d",&N);
	        push(N);
		break;

      case 2 : N=pop();
	       if(N!=-1)
	       { printf("\n no. poped : %d",N); }
	       break;
      case 3 : print();
	       break;
    }
    getch();
  }while(ch!=4);
}

void push(int num)
{ stack *ptr;
  ptr=(stack*)malloc(sizeof(stack));
  ptr->info=num;
  if(top==NULL)
  { ptr->link=NULL;
    top=ptr;
  }
  else
  { ptr->link=top;
    top=ptr;
  }
}

int pop()
{ stack *ptr;
  int num;
  if(top==NULL)
  { printf("\n\n underflow, stack empty ");
    return -1;
  }
  else
  { num=top->info;
    ptr=top;
    top=top->link;
    free(ptr);
    return num;
  }
}

void print()
{ stack *ptr;
  if(top==NULL)
  { printf("\n stack empty");}
  else
  { ptr=top;
    while(ptr!=NULL)
    { printf("\n %d",ptr->info);
      ptr=ptr->link;
    }
  }
}