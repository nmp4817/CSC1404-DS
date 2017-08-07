#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int N;

void INSERT(int*);

void main()
{ int *A,i;
  clrscr();
  printf("\n\n ENTER NO OF ELEMENTS : ");
  scanf("%d",&N);
  A=(int*)malloc((N+1)*sizeof(int));
  printf("\n ENTER ELEMENTS : \n");
  A[0]=-100;
  for(i=1;i<=N;i++)
  { printf(" A[%02d] : ",i);
    scanf("%d",&A[i]);
  }
  INSERT(A);
  printf("\n SORTED ARRAY :\n");
  for(i=1;i<=N;i++)
  { printf("\n A[%d] : %d",i,A[i]);
  }
  getch();
}

void INSERT(int *A)
{ int i,t,j;
  for(i=2;i<=N;i++)
  { t=A[i];
    j=i-1;
    while(t<A[j])
    { A[j+1]=A[j];
      j--;
    }
    A[j+1]=t;
  }
}