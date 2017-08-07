#include<stdio.h>
void main()
{
int n,c,a,value,position,array[50];
clrscr();
printf("\n enter the number of elements in array \n");
scanf("%d",&n);
printf("\n Enter the %d elements\n",n);
for(c=0;c<n;c++)
scanf("%d",&array[c]);
while(a!=3)
{
	printf("\n\n 1.Insertion\t2.Deletion\t3.Exit \n");
	scanf("%d",&a);

	switch(a)
{
	case 1:
	printf("Enter the location where you wish to insert element \n");
	scanf("%d",&position);
	printf("enter the value to insert \n");
	scanf("%d",&value);
	for(c=n-1;c>=position-1;c--)
	array[c+1]=array[c];
	array[position-1]=value;
	printf("Array is \n");
	for(c=0;c<=n;c++)
	printf("%d\t\n",array[c]);
	getch();
	break;

	case 2:
	printf("Enter the location where you wish to delete element\n");
	scanf("%d",&position);
	if(position>=n+1)
	printf("Deletion not possible \n");
	for(c=position-1;c<n;c++)
	array[c]=array[c+1];
	printf("Array after delition is \n ");
	for(c=0;c<n-1;c++)
	printf("%d\t\n",array[c]);
	getch();
	break;
}

}

}