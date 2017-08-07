#include<stdio.h>
#include<stdlib.h>

struct list
{ int info;
  struct list *left;
  struct list *right;
}*root;

typedef struct list bst;

struct fifo
{ bst *info;
  struct fifo *link;
}*front,*rear;
typedef struct fifo que;


void insert(int);
void Qinsert(bst*);
bst* Qdelet();
void bfs();

main()
{ int N;
  char ch;
  root=NULL;
  
  do{
  printf("\n ENTER NO : ");
  scanf("%d",&N);
  insert(N);
  printf("\n do you want to enter more?(y.yes/n.no)::");
  scanf("%s",&ch);
    }while(ch!='n');
 
  bfs();
  
}

void insert(int N)
{ bst *New,*par,*ptr;
  New=(bst*)malloc(sizeof(bst));
  New->info=N;
  New->left=NULL;
  New->right=NULL;
  if(root==NULL)
  { root=New; }
  else
  { if(N<root->info)
    { ptr=root->left;
      par=root;
    }
    else
    { ptr=root->right;
      par=root;
    }
    while(ptr!=NULL)
    { if(N<ptr->info)
      { par=ptr;
	ptr=ptr->left;
      }
      else
      { par=ptr;
	ptr=ptr->right;
      }
    }
    if(N<par->info)
    { par->left=New; }
    else
    { par->right=New; }
  }
}


void Qinsert(bst *I)
{ que *New;
  New=(que*)malloc(sizeof(que));
  New->info=I;
  if(front==NULL)
  { front=New;
    New->link=NULL;
  }
  else
  { New->link=NULL;
    rear->link=New;
  }
  rear=New;
}
bst* Qdelet()
{ bst *item;
  item=front->info;
  front=front->link;
  return item;
}

void bfs()
{ bst *ptr;
  ptr=root;
  front=NULL;
  rear=NULL;
  Qinsert(ptr);
  while(ptr!=NULL)
  { ptr=Qdelet();
    printf("\n %d",ptr->info);
    if(ptr->left!=NULL && ptr->right!=NULL)
    { Qinsert(ptr->left);
      Qinsert(ptr->right);
    }
    else if(ptr->left!=NULL && ptr->right==NULL)
    { Qinsert(ptr->left);
    }
    else if(ptr->right!=NULL && ptr->left==NULL)
    { Qinsert(ptr->right); }
    else
    { continue; }
  }
}