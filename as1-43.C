#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int N;

void SELECTION(int*);
int MIN(int*,int);

void main()
{ int *A,i;
  clrscr();
  printf("\n\n ENTER NO OF ELEMENTS : ");
  scanf("%d",&N);
  A=(int*)malloc(N*sizeof(int));
  printf("\n ENTER ELEMENTS : \n");
  for(i=0;i<N;i++)
  { printf(" A[%d] : ",i+1);
    scanf("%d",&A[i]);
  }
  SELECTION(A);
  printf("\n SORTED ARRAY :\n");
  for(i=0;i<N;i++)
  { printf("\n A[%d] : %d",i+1,A[i]);
  }
  getch();
}

void SELECTION(int *P)
{ int LOC,I,T;
  for(I=0;I<N-1;I++)
  { LOC=MIN(P,I+1);
    T=P[I];
    P[I]=P[LOC];
    P[LOC]=T;
  }
}

int MIN(int *X,int LB)
{ int I,M,L;
  M=X[LB];
  L=LB;
  for(I=LB;I<N;I++)
  { if(X[I]<M)
    { M=X[I];
      L=I;
    }
  }
  return L;
}