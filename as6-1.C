#include<stdio.h>
#include<stdlib.h>

struct list
{ int up,low;
  struct list *link;
}*top;
typedef struct list stack;

int N;

void push(int,int);
int* pop();
void print();
int quick(int*,int,int);
void sort(int*);

main()
{ int *A,I;
  top=NULL;
  
  printf("\n ENTER NO OF ELEMENTS : ");
  scanf("%d",&N);
  
  A=(int*)malloc(N*sizeof(int));
  
  printf("\n INSERT ELEMENTS \n");
  for(I=0;I<N;I++)
  { printf(" A[%02d] : ",I+1);
    scanf("%d",&A[I]);
  }

  sort(A);
  printf("\n SORTED ARRAY : ");
  for(I=0;I<N;I++)
  { printf("\n A[%02d] :  %d",I+1,A[I]);
  }
  
}

void push(int L,int U)
{ stack *New  ;
  New  =(stack*)malloc(sizeof(stack));
  New  ->low=L;
  New  ->up=U;
  if(top==NULL)
  { New  ->link=NULL;
    top=New  ;
  }
  else
  { New->link=top;
    top=New  ;
  }
}

int* pop()
{ stack *temp;
  int L[2];
    L[0]=top->low;
    L[1]=top->up;
    top=top->link;
    return L;
}

void print()
{ stack *ptr;
  if(top==NULL)
  { printf("\n stack EMPTY");}
  else
  { ptr=top;
    while(ptr!=NULL)
    { printf("\n %d %d",ptr->low,ptr->up);
      ptr=ptr->link;
    }
  }
}

int quick(int *A,int beg,int end)
{ int left,right,loc,T;
  left=beg; right=end; loc=beg;
  STEP2:
  { while(A[loc]<=A[right] && loc!=right)
    { right--; }
    if(loc==right)
    { return loc; }
    else if(A[loc]>A[right])
    { T=A[loc];
      A[loc]=A[right];
      A[right]=T;
    }
    loc=right;
    goto STEP3;
  }
  STEP3:
  { while(A[left]<=A[loc] && left!=loc)
    { left++; }
    if(loc==left)
    { return loc; }
    else if(A[left]>A[loc])
    { T=A[loc];
      A[loc]=A[left];
      A[left]=T;
    }
    loc=left;
    goto STEP2;
  }
}

void sort(int *A)
{ int beg,end,loc,*B;
   B=(int*)malloc(2*sizeof(int));
  if(N>1)
  { push(0,N-1);
    while(top!=NULL)
    { B=pop();
      beg=B[0];
      end=B[1];
      loc=quick(A,beg,end);
      if(beg<loc-1)
      { push(beg,loc-1);
      }
      if(loc+1<end)
      { push(loc+1,end); }
    }
  }
  else
  { return; }
}