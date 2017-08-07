#include<stdio.h>



int main()

{

int a[3][3], b[3][3], c[3][3], i, j;


printf("\n Enter Matrix A : \n");

for(i=0; i<3; i++)
{
	
for(j=0; j<3; j++)
	
{
		
printf(" Enter a[%d][%d] : ",i,j);
 scanf("%d", &a[i][j]);
	
}

}

printf("\n\n Enter Matrix B : \n");

for(i=0; i<3; i++)

{
        
for(j=0; j<3; j++)
        
{
                
printf(" Enter b[%d][%d] : ",i,j); 
scanf("%d", &b[i][j]);
        
}

}

printf("\n\n Answer C = AXB \n");

for(i=0; i<3; i++)

{
        
for(j=0; j<3; j++)
        
{
		
c[i][j] = a[i][0]*b[0][i] + a[i][1]*b[1][i] + a[i][2]*b[2][i];
                
printf(" c[%d][%d] : %d |", i, j, c[i][j]);
 
       
}
	
printf("\n");

}


return 0;

}

