#include<time.h> // Перестановка в обратном порядке элементов каждого столбца,
#include<stdio.h> //  содержащего максимальный элемент матрицы
#include<stdlib.h>

int main()
{ 
int **A,n,k,max,t;
int i=0,j=0;
printf("Input size of matrix: n=");
scanf("%d",&n);
srand(time(0));

 A= new int*[n];
 for(i=0;i<n;i++) A[i]=new int[n];

 printf("\nMatrix:\n");
 for(i=0;i<n;i++)
 { for(j=0;j<n;j++)
   { A[i][j]=rand()%15;
     printf(" %3d",A[i][j]);
   } printf("\n");
 }

 max=A[0][0];
 for(i=0;i<n;i++)
   for(j=0;j<n;j++)
     if (A[i][j]>max) max=A[i][j];

 printf("\nmax=%d",max);

     for(j=0;j<n;j++)
	for(i=0;i<n;i++)
	  if (A[i][j]==max)
		{ for(k=0;k<n/2;k++)
		    { t=A[k][j]; A[k][j]=A[n-k-1][j]; A[n-k-1][j]=t;}
		  break;
		}

 printf("\nNew matrix:\n");

 for(i=0;i<n;i++)
 { for(j=0;j<n;j++)
    printf(" %3d",A[i][j]);
    printf("\n");
 }

return 0;
}
/* Result:
Input size of matrix: n=6
Matrix:
  12   7  14   6  12   0
  13  11   9   5   4  11
  14   1  14   7   6   4
  10   0   9   0   8   6
   8  12  14   0   5   3
   9  10  11   0   8   8

max=14
New matrix:
   9   7  11   6  12   0
   8  11  14   5   4  11
  10   1   9   7   6   4
  14   0  14   0   8   6
  13  12   9   0   5   3
  12  10  14   0   8   8
*/  
