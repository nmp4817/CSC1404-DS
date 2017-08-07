#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct list
{ int PRN;
  char info[10];
  struct list *link;
}*front;
typedef struct list pque;

void insert(int,char*);
char* delet();
void view();

void main()
{ int ch,prn;
  char na[10];
  front=NULL;
  do
  { clrscr();
    printf("\n ******MENU******");
    printf("\n 1. NAME \n 2. NAME IN PROCESS \n 3. STATUS \n 4. EXIT");
    printf("\n\n ENTER YOUR CHOICE : ");
    scanf("%d",&ch);
    switch(ch)
    { case 1 : fflush(stdin);
	       printf("\n ENTER  NAME : ");
	       gets(na);
	       printf("\n PRIORITY NO : ");
	       scanf("%d",&prn);
	       insert(prn,na);
	       break;

      case 2 : strcpy(na,delet());
	       if(na[0]!=NULL)
	       { printf("\n NAME IN  PROCESS : %s",na);
	       }
	       break;

      case 3 : view(); break;
    }
    getch();
  }while(ch!=4);
  getch();
}

void insert(int N,char *ITEM)
{ pque *NEW,*PTR,*SAVE;
  NEW=(pque*)malloc(sizeof(pque));
  strcpy(NEW->info,ITEM);
  NEW->PRN=N;
  if(front==NULL)
  { NEW->link=NULL;
    front=NEW;
  }
  else if(front->link==NULL)
  { if(front->PRN>N)
    { NEW->link=front;
      front=NEW;
    }
    else if(front->PRN<=N)
    { front->link=NEW;
      NEW->link=NULL;
    }
  }
  else
  { PTR=front;
    SAVE=NULL;
    while(PTR!=NULL)
    { if(PTR->PRN>N)
      { break; }
      else
      { SAVE=PTR;
	PTR=PTR->link;
      }
    }
    if(SAVE==NULL)
    { NEW->link=front;
      front=NEW;
    }
    else if(SAVE->link==NULL)
    { NEW->link=NULL;
      SAVE->link=NEW;
    }
    else
    { NEW->link=SAVE->link;
      SAVE->link=NEW;
    }
  }
}

char* delet()
{ pque *TEMP;
  char *ITEM;
  if(front==NULL)
  { printf("\n UNDERFLOW");
    ITEM=NULL;
  }
  else
  { TEMP=front;
    strcpy(ITEM,front->info);
    front=front->link;
    free(TEMP);
  }
  return ITEM;
}

void view()
{ pque *PTR;
  if(front==NULL)
  { printf("\n NAME IS NOT EXIST! ");
  }
  else
  {
    printf("\n NAME    PRIORITY");
    for(PTR=front;PTR!=NULL;PTR=PTR->link)
    { printf("\n     %s        %d",PTR->info,PTR->PRN);
    }
 }
}