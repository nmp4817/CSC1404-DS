#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{ int *A,N,i,j,t;
  clrscr();
  printf(" ENTER NO OF ELEMENTS : ");
  scanf("%d",&N);
  A=(int*)calloc(N,2);
  printf("\n ENTER ELEMENTS: : \n");
  for(i=0;i<N;i++)
  { printf(" A[%d] : ",i+1);
    scanf("%d",&A[i]);
  }
  for(i=N-1;i>=0;i--)
  { for(j=0;j<i;j++)
    { if(A[j+1]<A[j])
      { t=A[j];
	A[j]=A[j+1];
	A[j+1]=t;
      }
    }
  }
  printf("\n SORTED ARRAY : ");
  for(i=0;i<N;i++)
  { printf("\n A[%d] : %d",i+1,A[i]); }
  getch();
  free(A);
}