#include<stdio.h>
#include<stdlib.h>
int main()

{
int *a, pos=-1, q, i, size, j, tmp, mid,high=size,low=1,choice;
clrscr();

printf("\n Enter Size : ");
scanf("%d", &size);

a=(int *)malloc(sizeof(int));

printf("\n Now Enter Array Elements : \n");

for(i=1;i<=size;i++)

{

	printf(" a[%d] : ",i);
	scanf("%d", &a[i]);

}

printf("\n Value to Search : ");
scanf("%d", &q);

while(choice!=3)

{
	printf("\n\n Search Method..? \n\t 1. Linear \n\t 2. Binary \n\t 3.exit \n\n\t\t Choice : ");

	scanf("%d", &choice);

	switch(choice)

	{

		case 1:
			printf("\n Linear Search RESULT : ");
			for(i=1;i<=size;i++)
			{
				if(a[i]==q)
				{
					pos=i;
				}
			}

		if(pos==-1)
		{
			printf("\n RESULT : NOT FOUND..!\n");
		}
		else
		{
			printf("\n Result : We found it on %dth Position.\n", pos);
		}


		break;



		case 2:

		printf("\n BINARY Search : \n");

		for(i=1;i<=size; i++)

		{

			for(j=1; j<=i;j++)

			{
				if(a[j]>a[i])
				{
					tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
				}
			}
		}
		printf("\n After Sorting, Array : \n");
		for(i=1; i<=size; i++)
		{
			printf("a[%d] : %d \n", i, a[i]);
		}

while(low<=high)
{       mid=(low+high)/2;

	if(a[mid] > q)
	{
		high=mid+1;
	}

	else if(a[mid] < q)
	{
		low=mid+1;
	}

	else
	{
	   pos = mid;
	}

}
	if(pos==-1)
	{
		printf("\n RESULT : NOT FOUND..!\n");
	}
	else
	{
		printf("\n Result : We found it on %dth Position.\n", pos);
	}

	break;
		case 3:
		break;



default : printf("\n Invalid Choice..!!\n");

}

}


getch();
return 0;
}
