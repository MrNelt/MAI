#include <stdlib.h> // Удаление повторяющихся столбцов матрицы
#include <stdio.h>  //  (оставить только первый из них)
#include <time.h>
int main()
{	float xd, yd;
	int **a,n,m,k,p,i,j,i1,j1;
	time_t t; // long s;
	 srand(time(&t)); //printf ("t=%ld\n",t);
	//  srand(s=clock()); printf ("s=%ld\n",s);
	printf ("Input size of matrix : ");
	scanf ("%d",&n);
	a=new int* [n];
	for(i=0;i<n;i++) a[i]=new int [n];

	for(j=0;j<n;j++)
	 { srand(j);
	   k=rand()%5+15; srand(k);
	    for(i=0;i<n;i++) a[i][j]=rand()%10;
	 }

	printf ("Started matrix\n");
	for(i=0;i<n;i++)
	 { for(j=0;j<n;j++) printf (" %3d ",a[i][j]);
	    printf ("\n");
	 }
	 m=n;                   // n - number of strings
				// m - number of columns
	    for(j=0;j<m-1;j++)
	     for(k=j+1;k<m;k++)
	       { for(i=0,p=1;i<m;i++)
		  if(a[i][j]!=a[i][k]) {p=0; break;}
		    if(p){				     // Deleting column
			  for(j1=k;j1<m-1;j1++)
			   for(i1=0;i1<m;i1++)
			    a[i1][j1]=a[i1][j1+1];
			   m--; k--;
			 }
	       }
	printf ("Finish matrix:\n");
	for(i=0;i<n;i++)
	{  for(j=0;j<m;j++)
		printf (" %3d ",a[i][j]);
		printf ("\n");
	}
  return 0;
}
/* Result:
Input size of matrix : 7
Started matrix
   9    3    5    4    8    5    4 
   6    0    7    3    0    7    3 
   8    7    9    7    5    9    7 
   2    5    7    2    7    7    2 
   7    6    9    9    6    9    9 
   5    5    9    3    8    9    3 
   1    4    5    7    7    5    7 
Finish matrix:
   9    3    5    4    8 
   6    0    7    3    0 
   8    7    9    7    5 
   2    5    7    2    7 
   7    6    9    9    6 
   5    5    9    3    8 
   1    4    5    7    7 
*/   
