#include<stdio.h>
#include<stdlib.h>

struct list
{ int info;
  struct list *left;
  struct list *right;
}*root;

typedef struct list bst;

struct lifo
{ bst *info;
  struct lifo *link;
}*top;
typedef struct lifo stack;


void insert(int);
void push(bst*);
bst* pop();
void dfs();

void main()
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
  dfs();

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


void push(bst *I)
{ stack *New;
  New=(stack*)malloc(sizeof(stack));
  New->info=I;
  if(top==NULL)
  { top=New;
    New->link=NULL;
  }
  else
  { New->link=top;
    top=New;
  }
}
bst* pop()
{ bst *item;
  item=top->info;
  top=top->link;
  return item;
}

void dfs()
{ bst *ptr;
  ptr=root;
  push(ptr);
  while(ptr!=NULL)
  { ptr=pop();
    printf("\n %d",ptr->info);
    if(ptr->left!=NULL && ptr->right!=NULL)
    { push(ptr->left);
      push(ptr->right);
    }
    else if(ptr->left!=NULL && ptr->right==NULL)
    { push(ptr->left);
    }
    else if(ptr->right!=NULL && ptr->left==NULL)
    { push(ptr->right); }
    else
    { continue; }
  }
}