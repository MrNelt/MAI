#include <stdlib.h> // Удаление повторяющихся столбцов матрицы
#include <stdio.h>  //  (оставить только первый из них)
#include <time.h>
int main()
{	float xd, yd;
	int a[9][9],n,m,k,p,i,j,i1,j1;
	printf ("Input size of matrix <10: n=");
	scanf ("%d",&n);
              srand(time(0));
	for(j=0;j<n;j++)
	 { k=rand()%7+15;  srand(k);
	    for(i=0;i<n;i++) a[i][j]=rand()%10;
	 }

	printf ("Started matrix:a\n");
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

Input size of matrix <10: n=5
Started matrix:
   0    0    0    0    0
   4    1    1    1    1
   3    9    9    9    9
   2    8    8    8    8
   8    4    4    4    4
Finish matrix:
   0    0 
   4    1 
   3    9 
   2    8 
   8    4    

*/


