#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Search(int*a,int n,int v)
{ int l=0, r=n-1, m;
  while(l<r)
  { m=(l+r)/2; //printf("l=%d r=%d m=%d\n",l,r,m);
  if(a[m]<v) l=m+1; else r=m;}
 return l;
}
 
void randomize()
{ long a=time(0); 
  srand(a);
}

int main()
{  randomize();
 int *M, n, i, v, m;
 printf("Inpun n=");
 scanf("%d",&n);
 M=new int[n];
 printf("Source array:\n");
 printf("M[0]=%d ",M[0]=rand()%100+1);
 for(i=1;i<n;i++)
 { M[i]=M[i-1]+rand()%100;
  printf("M[%d]=%d ",i,M[i]);
 } printf("\n\n");
do{
printf("Input number for search v=");
scanf("%d",&v);
 m=Search(M,n,v);
 printf("Index for v=%d\n",m);
 if(M[m]==v) printf("Element exists.\n"); 
 else printf("No such element.\n");
  } while(v);
 return 0;
}

