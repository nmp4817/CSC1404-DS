#include<stdio.h>
#include<stdlib.h>

struct list
{ int index;
  int info;
  struct list *link;
}*start;
typedef struct list node;

int N;

int maxdig(int*);
void insert(int,int);
int pop();
void radix(int*);
int getdig(int,int);
void view();

main()
{ int *A,i,D,max,J,p;
  start=NULL;
  printf("\n ENTER NO OF ELMENTS : ");
  scanf("%d",&N);
  
  A=(int*)malloc(N*sizeof(int));
  
  printf("\n ENTER ELEMETS : \n");
  for(i=0;i<N;i++)
  { printf(" A[%02d] : ",i+1);
    scanf("%d",&A[i]);
  }
  
  radix(A);
  
}

int maxdig(int *P)
{ int i,d,max;
  max=P[0];
  for(i=0;i<N;i++)
  { if(P[i]>max)
    { max=P[i]; }
  }
  d=max;
  i=0;
  while(d!=0)
  { d=d/10; i++; }
  return i;
}

int getdig(int no,int dno)
{ int i,dig,d;
  d=no;
  while(d!=0)
  { d=d/10;
    i++;
  }
  d=no;
  for(i=1;i<dno;i++)
  { d=d/10; }
  dig=d%10;
  return dig;
}

void insert(int I,int NO)
{ node *New,*ptr,*save;
  New=(node*)malloc(sizeof(node));
  New->index=I;
  New->info=NO;
  if(start==NULL)
  { New->link=NULL;
    start=New;
  }
  else if(start->link==NULL)
  { if(start->index>I)
    { New->link=start;
      start=New;
    }
    else  if(start->index<=I)
    { start->link=New;
      New->link=NULL;
    }
  }
  else
  { ptr=start;
    save=NULL;
    while(ptr!=NULL)
    { if(ptr->index>I)
      { break; }
      else
      { save=ptr;
	ptr=ptr->link;
      }
    }
    if(save==NULL)
    { New->link=start;
      start=New;
    }
    else if(save->link==NULL)
    { New->link=NULL;
      save->link=New;
    }
    else
    { New->link=save->link;
      save->link=New;
    }
  }
}

int pop()
{ int item;
  if(start==NULL)
  { return -1; }
  else
  {item=start->info;
   start=start->link;
   return item;
  }
}

void radix(int *A)
{ int max,J,D,i,p;
  max=maxdig(A);
  for(J=1;J<=max;J++)
  { start=NULL;
    for(i=0;i<N;i++)
    { D=getdig(A[i],J);
      insert(D,A[i]);
    }
  printf("\n\n PASS : %d",J);
  if(J==max)
  { printf(" SORTED ARRAY : "); }
  view();
  getch();
   for(i=0;i<N;i++)
   { p=pop();
     if(p==-1)
     { break; }
     else
     { A[i]=p;}
   }
 }
}
void view()
{ node *ptr;
  for(ptr=start;ptr!=NULL;ptr=ptr->link)
  { printf("\n %d",ptr->info);}
}
