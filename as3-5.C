#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct list
{ int info;
  struct list *link;
}*top;

typedef struct list stack;
void push(int);
int pop();
int find_value(char*);
void view();

void main()
{ int value;
  char P[80];
  clrscr();
  top=NULL;
  printf("\n ENTER REVERSE POLISH EXPRESSION (put , between two char.): ");
  gets(P);
  value=find_value(P);
  printf("\n\n value : %d",value);
  getch();
}

void push(int item)
{ stack *ptr;
  ptr=(stack*)malloc(sizeof(stack));
  ptr->info=item;
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
{ int item;
  stack *temp;
  item=top->info;
  temp=top;
  top=top->link;
  free(temp);
  return item;
}

int find_value(char *P)
{ int i,j,A,B,value;
  strcat(P,")");
  printf("\n\n SYMBOL   stack");
  for(i=0;P[i]!=')';)
  { printf("\n   %2c  ",P[i]);
    if(P[i]==',')
    { i++;
      continue;
    }
    else if(P[i]=='+' || P[i]=='-' || P[i]=='*' || P[i]=='/' || P[i]=='%' || P[i]=='^')
    { A=pop();
      B=pop();
      switch(P[i])
      { case '+' :value=B+A; break;
	case '-' :value=B-A; break;
	case '*' :value=B*A; break;
	case '/' :value=B/A; break;
	case '%' :value=B%A; break;
	case '^' :value=1;
		  for(j=1;j<=A;j++)
		  { value=value*B;
		  }
		  break;
      }
      push(value);
      i++;
    }
    else
    {  B=1;
       A=0;
      while(P[i]!=',')
      { A=B*A+(P[i]-48);
	B=B*10;
	i++;
      }
      push(A);
    }
   view();
  }
  return value;
}

void view()
{ stack *ptr;
  if(top==NULL)
  { return;}
  else
  { ptr=top;
    while(ptr!=NULL)
    { printf(" %5d",ptr->info);
      ptr=ptr->link;
    }
  }
}