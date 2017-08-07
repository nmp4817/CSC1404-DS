#include<stdio.h>
#include<stdlib.h>

int N,*tree;

void insheap(int,int);
int delheap(int);

main()
{ int *A,i,j;
  
  printf(" ENTER NO OF ELEMENTS : ");
  scanf("%d",&N);
  
A=(int*)malloc((N+1)*sizeof(int));
 
 tree=(int*)malloc((N+1)*sizeof(int));

  A[0]=0;

  tree[0]=0;

  printf("\n ENTER ELEMENTS: : \n");
  for(i=1;i<N+1;i++)
  { printf(" A[%d] : ",i);
    scanf("%d",&A[i]);
    insheap(A[i],i);
  }

  for(i=N,j=1;i>=1;i--,j++)
  { A[j]=delheap(i); }

  printf("\n\n SORTED LiST");
  for(i=1;i<N+1;i++)
  { printf("\n A[%02d] : %05d",i,A[i]); }
  
}

void insheap(int NO,int i)
{ int ptr,par,T;
  tree[i]=NO;
  if(i==1)
  { return; }
  else if((i==2 || i==3) && tree[i]>tree[1])
  {   T=tree[1];
      tree[1]=tree[i];
      tree[i]=T;
  }
  else
  { ptr=i;
    while(ptr>1)
    { par=ptr/2;
      if(tree[par]<tree[ptr])
      { T=tree[par];
	tree[par]=tree[ptr];
	tree[ptr]=T;
      }
      ptr=par;
    }
  }
}

int delheap(int N)
{ int item,last,ptr,left,right,T;
  item=tree[1];
  tree[1]=tree[N];
  tree[N]=0;
  N--;
  ptr=1;
  left=2; right=3;
  while(right<=N)
  { if(tree[ptr]>=tree[right] && tree[ptr]>=tree[left])
    { break; }
    else if(tree[right]<=tree[left])
    {  T=tree[left];
       tree[left]=tree[ptr];
       tree[ptr]=T;
       ptr=left;
    }
    else
    { T=tree[right];
      tree[right]=tree[ptr];
      tree[ptr]=T;
      ptr=right;
    }
    left=2*ptr;
    right=left+1;
  }
  if(left==N && tree[ptr]<tree[left])
  { T=tree[ptr];
    tree[ptr]=tree[left];
    tree[left]=T;
  }
  return item;
}