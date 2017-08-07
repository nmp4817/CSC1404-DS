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
void inor(bst*);
void pror(bst*);
void postor(bst*);
void PRE();
void IN();
void POST();
void push(bst*,int);
bst* pop();

main()
{ int N,choice;
  char ch;
   root=NULL;
   do
   {
    printf("\n MENU");
    printf("\n 1. INSERT \n 2. INORDER (RECURSION) \n 3. PREORDER(RECURSION) \n 4. POSTORDER (RECURSION)");
    printf("\n 5. PREORDER (ITERATIVE) \n 6. INORDER(ITERATIVE) \n 7. POSTORDER(ITERATIVE) ");
    printf("\n 8. EXIT");
    printf("\n\n ENTER YOUR CHOICE : ");
    scanf("%d",&choice);
    switch(choice)
    { case 1 : do{
	       printf("\n ENTER NO : ");
	       scanf("%d",&N);
	       insert(N);
	       printf("\n do you want to enter more?(y.yes/n.no)::");
	       scanf("%s",&ch);
		}while(ch!='n');
	       break;

      case 2 : inor(root);
	       break;
      case 3 : pror(root);
	       break;
      case 4 : postor(root);
	       break;
      case 5 : PRE(); break;
      case 6 : IN(); break;
      case 7 : POST(); break;
    }
    
  }while(choice!=8);
  
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

void inor(bst *T)
{
   if(T->left!=NULL)
   { inor(T->left); }
   printf("\n %d",T->info);
   if(T->right!=NULL)
   { inor(T->right); }
}

void pror(bst *P)
{ printf("\n %d",P->info);
  if(P->left!=NULL)
  { pror(P->left);}
  if(P->right!=NULL)
  { pror(P->right); }
}

void postor(bst *P)
{ if(P->left!=NULL)
  { postor(P->left); }
  if(P->right!=NULL)
  { postor(P->right); }
  printf("\n %d",P->info);
}

void PRE()
{ bst *ptr;
  top=NULL;
  push(NULL,0);
  ptr=root;
  while(ptr!=NULL)
  { printf("\n %d",ptr->info);
    if(ptr->right!=NULL)
    { push(ptr->right,0); }
    if(ptr->left!=NULL)
    { ptr=ptr->left; }
    else
    { ptr=pop(); }
  }
}

void IN()
{ bst *ptr,*ptr1;
  top=NULL;
  push(NULL,0);
  ptr=root;
  while(ptr!=NULL)
  { push(ptr,0);
    ptr=ptr->left;
  }
  ptr1=pop();
  while(ptr1!=NULL)
  { printf("\n %d",ptr1->info);
    if(ptr1->right!=NULL)
    { ptr1=ptr1->right;
      while(ptr1!=NULL)
      { push(ptr1,0);
	ptr1=ptr1->left;
      }
    }
    ptr1=pop();
  }
}

void POST()
{ bst *ptr;
  top=NULL;
  ptr=root;
  push(NULL,0);
  STEP2 : while(ptr!=NULL)
	  { push(ptr,0);
	  if(ptr->right!=NULL)
	  { push(ptr->right,1); }
	   ptr=ptr->left;
	  }
  ptr=pop();
  while(ptr->info>0)
  { printf("\n %d",ptr->info);
    ptr=pop();
  }
  if(ptr->info<0)
  { ptr->info=(-1)*ptr->info;
    goto STEP2;
  }
}

void push(bst *I,int ch)
{ stack *New;
  New=(stack*)malloc(sizeof(stack));
  New->info=I;
  if(ch==1)
  { New->info->info=(-1)*New->info->info; }
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
{ bst *ITEM;
  ITEM=top->info;
  top=top->link;
  return ITEM;
}