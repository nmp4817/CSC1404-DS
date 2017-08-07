#include<stdio.h>
#include<stdlib.h>

struct list
{ int info;
  struct list *left;
  struct list *right;
}*root;

typedef struct list bst;

void insert(int);
void caseA(bst*,bst*);
void caseB(bst*,bst*);
void delet(int);
bst* search(int,int);
void print(bst*);

main()
{ int N,choice;
  char ch;
  root=NULL;
   do
   {
    printf("\n MENU");
    printf("\n 1. insert \n 2. delet \n 3. print \n 4. exit");
    printf("\n\n ENTER YOUR CHOICE : ");
    scanf("%d",&choice);
    switch(choice)
    { case 1 : do{
	       printf("\n ENTER NO : ");
	       scanf("%d",&N);
	       insert(N);
	       printf("\n DO YOU WANT TO ENTER MORE?(y.yes/n.no)::");
	       scanf("%s",&ch);
		 }while(ch!='n');
	       break;

      case 2 : printf("\n\n ENTER ITEM TO DELETE : ");
	       scanf("%d",&N);
	       delet(N);
	       break;

      case 3 : print(root);
	       break;
    }
    
  }while(choice!=4);
  
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
  { par=search(N,2);
    if(N<par->info)
    { par->left=New; }
      else
    { par->right=New; }
  }

}

void print(bst *T)
{
   if(T->left!=NULL)
   { print(T->left); }
   printf("\n %d",T->info);
   if(T->right!=NULL)
   { print(T->right); }
}

bst* search(int N,int C)
{ bst *ptr,*save,*loc,*par;
  if(root==NULL)
  { loc=NULL;
    par=NULL;
  }
  else
  { if(N<root->info)
    { ptr=root->left;
      save=root;
    }
    else
    { ptr=root->right;
      save=root;
    }
    while(ptr!=NULL)
    { if(N<ptr->info)
      { save=ptr;
	ptr=ptr->left;
      }
      else if(N==ptr->info)
      { break;
      }
      else
      { save=ptr;
	ptr=ptr->right;
      }
    }
    if(ptr==NULL)
    { loc=NULL;
      par=save;
    }
    else
    { loc=ptr;
      par=save;
    }
  }
  if(C==1)
  {  return loc; }
  else if(C==2)
  {  return par; }
}

void caseA(bst *loc,bst *par)
{ if(loc->left==NULL && loc->right==NULL && par!=NULL)
  { if(par->left==loc)
    { par->left=NULL; }
    else
    { par->right=NULL; }
  }
  else if(loc->left!=NULL)
  { if(par->left==loc)
    { par->left=loc->left; }
    else
    { par->right=loc->left; }
  }
  else if(loc->right!=NULL)
  { if(par->left==loc)
    { par->left=loc->right; }
    else
    { par->right=loc->right; }
  }
}

 void caseB(bst *loc,bst *par)
{ bst *suc,*parsuc,*ptr,*save;
  ptr=loc->right;
  save=loc;
  while(ptr->left!=NULL)
  { save=ptr;
    ptr=ptr->left; }
  suc=ptr;
  parsuc=save;
  caseA(suc,parsuc);
  if(par!=NULL)
  { if(par->left==loc)
    { par->left=suc; }
    else
    { par->right=suc; }
  }
  else
  { root=suc; }
  suc->left=loc->left;
  suc->right=loc->right;
}

void delet(int item)
{ bst *loc,*par;
  if(root==NULL)
  { printf("\n UNDERFLOW"); }
  else
  { loc=search(item,1);
    par=search(item,2);
    if(loc==NULL)
    { printf("\n\n ITEM NOT FOUND, CAN'T DELETE"); }
    else
    { if(loc->right!=NULL && loc->left!=NULL)
      { caseB(loc,par); }
      else
      { caseA(loc,par); }
    }
  }
}