#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct LIST
{ int INFO,BF;
  struct LIST *LEFT;
  struct LIST *RIGHT;
}*ROOT;

typedef struct LIST AVL;

void INSERT(int);
void CASEA(AVL*,AVL*);
void CASEB(AVL*,AVL*);
void DELETE(int);
AVL* FIND(int,int);
void VIEW(AVL*);
int HEIGHT(AVL*);
void PROR1(AVL*);
int BALFACT(AVL*);
int ROTATION(AVL*);
int DELROTATE(AVL*);

void main()
{ int N,ch,ans;
   ROOT=NULL;
   do
   {clrscr();
    printf("\n MENU");
    printf("\n 1. INSERT \n 2. DELETE \n 3. DISPLAY \n 4. EXIT");
    printf("\n\n ENTER YOUR CHOICE : ");
    scanf("%d",&ch);
    switch(ch)
    { case 1 : printf("\n ENTER NO : ");
	       scanf("%d",&N);
	       INSERT(N);
	       break;

      case 2 : printf("\n\n ENTER ITEM TO DELETE : ");
	       scanf("%d",&N);
	       DELETE(N);
	       break;

      case 3 : printf("\n INORDER");
	       VIEW(ROOT);
	       printf("\n PREORDER");
	       PROR1(ROOT);
	       break;
    }
    getch();
  }while(ch!=4);
  getch();
}

void INSERT(int N)
{ AVL *NEW,*PAR,*PTR;
  int Y=0;
  NEW=(AVL*)malloc(sizeof(AVL));
  NEW->INFO=N;
  NEW->LEFT=NULL;
  NEW->RIGHT=NULL;
  if(ROOT==NULL)
  { ROOT=NEW; }
  else
  { PAR=FIND(N,2);
    if(N<PAR->INFO)
    { PAR->LEFT=NEW; }
      else
    { PAR->RIGHT=NEW; }
  }
  if(HEIGHT(ROOT)>2)
  {
    while(Y==0)
    { Y=ROTATION(NEW); }
  }
}

void VIEW(AVL *T)
{
   if(T->LEFT!=NULL)
   { VIEW(T->LEFT); }
   printf("\n %d",T->INFO);
   T->BF=BALFACT(T);
   printf("\t %d",T->BF);
   if(T->RIGHT!=NULL)
   { VIEW(T->RIGHT); }
}

AVL* FIND(int N,int C)
{ AVL *PTR,*SAVE,*LOC,*PAR;
  if(ROOT==NULL)
  { LOC=NULL;
    PAR=NULL;
  }
  else if(ROOT->INFO==N)
  { LOC=ROOT;
    PAR=NULL;
  }
  else
  { if(N<ROOT->INFO)
    { PTR=ROOT->LEFT;
      SAVE=ROOT;
    }
    else
    { PTR=ROOT->RIGHT;
      SAVE=ROOT;
    }
    while(PTR!=NULL)
    { if(N<PTR->INFO)
      { SAVE=PTR;
	PTR=PTR->LEFT;
      }
      else if(N==PTR->INFO)
      { break;
      }
      else
      { SAVE=PTR;
	PTR=PTR->RIGHT;
      }
    }
    if(PTR==NULL)
    { LOC=NULL;
      PAR=SAVE;
    }
    else
    { LOC=PTR;
      PAR=SAVE;
    }
  }
  if(C==1)
  {  return LOC; }
  else if(C==2)
  {  return PAR; }
}

void CASEA(AVL *LOC,AVL *PAR)
{ if(LOC->LEFT==NULL && LOC->RIGHT==NULL && PAR!=NULL)
  { if(PAR->LEFT==LOC)
    { PAR->LEFT=NULL; }
    else
    { PAR->RIGHT=NULL; }
  }
  else if(LOC->LEFT!=NULL)
  { if(PAR->LEFT==LOC)
    { PAR->LEFT=LOC->LEFT; }
    else
    { PAR->RIGHT=LOC->LEFT; }
  }
  else if(LOC->RIGHT!=NULL)
  { if(PAR->LEFT==LOC)
    { PAR->LEFT=LOC->RIGHT; }
    else
    { PAR->RIGHT=LOC->RIGHT; }
  }
}

void CASEB(AVL *LOC,AVL *PAR)
{ AVL *SUC,*PARSUC,*PTR,*SAVE;
  PTR=LOC->RIGHT;
  SAVE=LOC;
  while(PTR->LEFT!=NULL)
  { SAVE=PTR;
    PTR=PTR->LEFT; }
  SUC=PTR;
  PARSUC=SAVE;
  CASEA(SUC,PARSUC);
  if(PAR!=NULL)
  { if(PAR->LEFT==LOC)
    { PAR->LEFT=SUC; }
    else
    { PAR->RIGHT=SUC; }
  }
  else
  { ROOT=SUC; }
  SUC->LEFT=LOC->LEFT;
  SUC->RIGHT=LOC->RIGHT;
}

void DELETE(int ITEM)
{ AVL *LOC,*PAR;
  int d;
  if(ROOT==NULL)
  { printf("\n UNDERFLOW"); }
  else
  { LOC=FIND(ITEM,1);
    PAR=FIND(ITEM,2);
    if(LOC==NULL)
    { printf("\n\n ITEM NOT FOUND, CAN'T DELETE"); }
    else
    { if(LOC->RIGHT!=NULL && LOC->LEFT!=NULL)
      { CASEB(LOC,PAR); }
      else
      { CASEA(LOC,PAR); }
    }
  }
  printf("\n AFETER DELETION");
  VIEW(ROOT);
  if(ROOT->BF>1 || ROOT->BF<-1)
  { if(ROOT->BF>0)
    { d=DELROTATE(ROOT->RIGHT);
    }
    else
    { d=DELROTATE(ROOT->LEFT); }
    if(d==1)
      { printf("\n BALANCING DONE");
	VIEW(ROOT);
    }
  }
}

int HEIGHT(AVL *A)
{ if(A==NULL)
  { return 0; }
  else if(A->LEFT==NULL && A->RIGHT==NULL)
  { return 1; }
  else
  { int L,R;
    L=HEIGHT(A->LEFT);
    R=HEIGHT(A->RIGHT);
    if(L>R)
    {return (L+1);}
    else
    { return (R+1); }
  }
}

void PROR1(AVL *P)
{ printf("\n %d \t %d",P->INFO,BALFACT(P));
  if(P->LEFT!=NULL)
  { PROR1(P->LEFT);}
  if(P->RIGHT!=NULL)
  { PROR1(P->RIGHT); }
}

int BALFACT(AVL *NODE)
{ int bf;
  bf=HEIGHT(NODE->LEFT)-HEIGHT(NODE->RIGHT);
  return bf;
}

int ROTATION(AVL *C)
{ AVL *A,*B,*TEMP,*PAR,*TEMP2;
  int x=0,bal;
  B=FIND(C->INFO,2);
  do
  { A=FIND(B->INFO,2);
    if(A==NULL)
    { break; }
    bal=BALFACT(A);
    if(bal>1||bal<-1)
      { if(A->LEFT==B)
	{ if(B->LEFT==C)
	  { x=1; }
	  else if(B->RIGHT==C)
	  { x=3; }
	}
	else if(A->RIGHT==B)
	{ if(B->LEFT==C)
	  { x=4; }
	  else if(B->RIGHT==C)
	  { x=2; }
	}
      break;
     }
    else
    { C=B; B=A; }
  }while(A!=NULL);
  if(A==NULL)
  { return -1; }
  else
  { printf("\n\n ROTATION REQUIRED");
    switch(x)
    { case 1 : PAR=FIND(A->INFO,2);        /*LL*/
	       if(PAR==NULL)
	       { ROOT=B; }
	       else
	       { if(PAR->RIGHT==A)
		 { PAR->RIGHT=B; }
		 else if(PAR->LEFT==A)
		 { PAR->LEFT=B; }
	       }
	       TEMP=B->RIGHT;
	       B->RIGHT=A;
	       A->LEFT=TEMP;
	       break;
     case 2 : PAR=FIND(A->INFO,2);
	       if(PAR==NULL)
	       { ROOT=B; }                     /*RR*/
	       else
	       { if(PAR->RIGHT==A)
		 { PAR->RIGHT=B; }
		 else if(PAR->LEFT==A)
		 { PAR->LEFT=B; }
	       }
	       TEMP=B->LEFT;
	       B->LEFT=A;
	       A->RIGHT=TEMP;
	       break;

     case 3 : PAR=FIND(A->INFO,2);
	       if(PAR==NULL)
	       { ROOT=C; }                    /*LR*/
	       else
	       { if(PAR->RIGHT==A)
		 { PAR->RIGHT=C; }
		 else if(PAR->LEFT==A)
		 { PAR->LEFT=C; }
	       }
	       TEMP=C->RIGHT;
	       TEMP2=C->LEFT;
	       C->LEFT=B;
	       C->RIGHT=A;
	       B->RIGHT=TEMP2;
	       A->LEFT=TEMP;
	       break;

     case 4 :  PAR=FIND(A->INFO,2);
	       if(PAR==NULL)
	       { ROOT=C; }
	       else                                /*RL*/
	       { if(PAR->RIGHT==A)
		 { PAR->RIGHT=C; }
		 else if(PAR->LEFT==A)
		 { PAR->LEFT=C; }
	       }
	       TEMP=C->RIGHT;
	       TEMP2=C->LEFT;
	       C->LEFT=A;
	       C->RIGHT=B;
	       B->LEFT=TEMP;
	       A->RIGHT=TEMP2;
	       break;

     default : break;
    }
    printf("\n AFTER ROTATION \n");
    VIEW(ROOT);
    return 0;
  }
}

int DELROTATE(AVL *A)
{ AVL *PAR,*B,*TEMP,*TEMP2,*TC;
  int x;
  if(ROOT->RIGHT==A)
  { B=ROOT->LEFT;
    if(B==NULL)
    { PAR=ROOT;
      DELETE(PAR->INFO);
      INSERT(PAR->INFO);
    }
    else
    {
    if(A->BF==0 && B->BF==0) /*R0 ROTATION*/
    { PAR=ROOT;
      TEMP=B->RIGHT;
      B->RIGHT=PAR;
      PAR->LEFT=TEMP;
      ROOT=B;
    }
    else if(A->BF==0 && B->BF==1) /*R1 ROTATION*/
    { PAR=ROOT;
      TEMP=B->RIGHT;
      B->RIGHT=PAR;
      PAR->LEFT=TEMP;
      ROOT=B;
    }
    else if(A->BF==0 && B->BF==-1) /*R-1 ROTATION */
    {  PAR=ROOT;
       TC=B->RIGHT;
       ROOT=TC;
       TEMP=TC->LEFT;
       TEMP2=TC->RIGHT;
       TC->LEFT=B;
       TC->RIGHT=PAR;
       B->RIGHT=TEMP;
       PAR->LEFT=TEMP2;
    }
    return 1;
   }
  }
  else if(ROOT->LEFT==A)
  { B=ROOT->RIGHT;
     if(B==NULL)
     { PAR=ROOT;
	DELETE(PAR->INFO);
	INSERT(PAR->INFO);
     }
    else
    {
     if(A->BF==0 && B->BF==0) /*L0 ROTATION*/
    { PAR=ROOT;
      TEMP=B->LEFT;
      B->LEFT=PAR;
      PAR->RIGHT=TEMP;
      ROOT=B;
    }
    else if(A->BF==0 && B->BF==1) /*L1 ROTATION*/
    { PAR=ROOT;
      TEMP=B->LEFT;
      B->LEFT=PAR;
      PAR->RIGHT=TEMP;
      ROOT=B;
    }
    else if(A->BF==0 && B->BF==-1) /*L-1 ROTATION */
    {   PAR=ROOT;
	ROOT=TC;
	TC=B->LEFT;
	TEMP=TC->LEFT;
	TEMP2=TC->RIGHT;
	TC->LEFT=PAR;
	TC->RIGHT=A;
	A->LEFT=TEMP2;
	PAR->RIGHT=TEMP;
    }
    return 1;
   }
 }
}