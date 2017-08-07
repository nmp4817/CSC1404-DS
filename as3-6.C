#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct list
{ int info;
  struct list *link;
}*top,*top1;

typedef struct list stack;
void PUSH(char);
char POP();
void push(int);
int pop();
char* postfix(char*);
int getvalue(char*);
void VIEW();
void view();

main()
{ int value;
  char P[80],Q[80];
  
  top=NULL;
  top1=NULL;

  printf("\n ENTER INFIX EXPRESSION : ");
  gets(Q);


  strcpy(P,postfix(Q));
  printf("\n\n P : %s",P);
  
  value=getvalue(P);
  printf("\n\n value : %d",value);
  
}

void push(int item)
{ stack *New;
  New=(stack*)malloc(sizeof(stack));
  New->info=item;
  if(top1==NULL)
  { New->link=NULL;
    top1=New;
  }
  else
  { New->link=top1;
    top1=New;
  }
}

int pop()
{ int item;
  stack *temp;
  item=top1->info;
  temp=top1;
  top1=top1->link;
  free(temp);
  return item;
}

int getvalue(char *P)
{ int I,J,A,B,value;
  strcat(P,")");
  printf("\n\n SYMBOL   stack");
  for(I=0;P[I]!=')';)
  { printf("\n   %c  ",P[I]);
 
    if(P[I]=='+' || P[I]=='-' || P[I]=='*' || P[I]=='/' || P[I]=='%' || P[I]=='^')
    { A=pop();
      B=pop();
      switch(P[I])
      { case '+' :value=B+A; break;
	case '-' :value=B-A; break;
	case '*' :value=B*A; break;
	case '/' :value=B/A; break;
	case '%' :value=B%A; break;
	case '^' :value=1;
		  for(J=1;J<=A;J++)
		  { value=value*B;
		  }
		  break;
      }
      push(value);
      I++;
    }
    else
    {  B=1;
       A=0;
    A=B*A+(P[I]-48);
	B=B*10;
	I++;

      push(A);
    }
   view();
  }
  return value;
}

void view()
{ stack *ptr;
  if(top1==NULL)
  { return;}
  else
  { ptr=top1;
    while(ptr!=NULL)
    { printf(" %5d",ptr->info);
      ptr=ptr->link;
    }
  }
}

char* postfix(char *Q)
{ char P[80],T;
  int I,J;
  stack *ptr;
  PUSH('(');
  strcat(Q,")");
  I=0;
  J=0;
  while(top!=NULL)
  { VIEW();
    if(Q[I]=='(')
    { PUSH(Q[I]);
      I++;
    }
    else if(Q[I]=='+' || Q[I]=='-' || Q[I]=='*' || Q[I]=='/' || Q[I]=='^')
    {   if(Q[I]=='+' || Q[I]=='-')
	{ T=' ';
	  do
	  { T=POP();
	    if(T=='*' || T=='/' || T=='^')
	    { P[J]=T;
	      J++;
	    }
	    else
	    { PUSH(T);
	      goto Push;
	    }
	 }while(T!='(');
	 Push:
	 {PUSH(Q[I]);
	 I++; }
	}
	else
	{ PUSH(Q[I]);
	  I++;
	}
    }
    else if(Q[I]==')')
    { T=' ';
      do
      { T=POP();
	if(T!='(')
	{P[J]=T;
	J++;}
      }while(T!='(');
	I++;
    }
    else
    { P[J]=Q[I];
      I++;
      J++;
    }
  }
  P[J]=NULL;
  return P;
}

void VIEW()
{ stack *ptr;
  printf("\n");
  for(ptr=top;ptr!=NULL;ptr=ptr->link)
  { printf(" %c",ptr->info);
  }
}

void PUSH(char item)
{ stack *New;
  New=(stack*)malloc(sizeof(stack));
  New->info=item;
  if(top==NULL)
  { New->link=NULL;
    top=New;
  }
  else
  { New->link=top;
    top=New;
  }
}

char POP()
{ char item;
  item=top->info;
  top=top->link;
  return item;
}