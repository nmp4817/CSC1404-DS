/* MERGE SORT*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void MERGE(int*,int,int,int*,int,int,int*,int);
void MERGEPASS(int*,int,int*);
void MERGESORT(int*);
void VIEW(int*,int);
int N;

void main()
{ int i,*A;
  clrscr();
  printf("\n\n ENTER NO. OF ELEMENTS : ");
  scanf("%d",&N);
  A=(int*)calloc(N,sizeof(int));
  printf("\n ENTER ELEMENTS\n");
  for(i=0;i<N;i++)
  { printf(" A[%02d] : ",i+1);
    scanf("%d",&A[i]);
  }
  MERGESORT(A);
  printf("\n\n SORTED ARRAY :");
  VIEW(A,N);
  getch();
  free(A);
}

void MERGESORT(int *A)
{ int L,*B;
  L=1;
  B=(int*)calloc(N,sizeof(int));
  while(L<N)
  {  MERGEPASS(A,L,B);
     MERGEPASS(B,2*L,A);
    L=L*4;
  }
}

void MERGEPASS(int *A,int L,int *B)
{ int Q,S,R,J,LB;
  Q=N/(2*L);
  S=2*L*Q;
  R=N-S;
//  printf("\n Q,S,R,L : %d,%d,%d,%d ",Q,S,R,L);
  for(J=1;J<=Q;J++)
  { LB=(2*J-2)*L;
    MERGE(A,L,LB,A,L,LB+L,B,LB);
  }
  if(R<=L)
  { for(J=0;J<R;J++)
    { B[S+J]=A[S+J];
    }
  }
  else
  { MERGE(A,L,S,A,R-L,S+L,B,S);}
}


void MERGE(int *A,int R,int LBA,int *B,int S,int LBB,int *C,int LBC)
{ int NA,NB,PTR,UBA,UBB,K;
  NA=LBA;
  NB=LBB;
  UBA=LBA+R-1;
  UBB=LBB+S-1;
  PTR=LBC;
//  printf("\n LBA,UBA,LBB,UBB,PTR : %d,%d,%d,%d,%d",LBA,UBA,LBB,UBB,PTR);
  while(NA<=UBA && NB<=UBB)
  { if(A[NA]<B[NB])
    { C[PTR]=A[NA];
      NA++; PTR++;
    }
    else
    { C[PTR]=B[NB];
      PTR++; NB++;
    }
  }
  if(NA>UBA)
  { for(K=0;K<=(UBB-NB);K++)
    { C[PTR+K]=B[NB+K];
    }
  }
  else
  { for(K=0;K<=(UBA-NA);K++)
    { C[PTR+K]=A[NA+K];
    }
  }
}

void VIEW(int *NO,int no)
{ int i;
  printf("\n\n");
  for(i=0;i<no;i++)
  { printf("\n %d",NO[i]); }
  getch();
}