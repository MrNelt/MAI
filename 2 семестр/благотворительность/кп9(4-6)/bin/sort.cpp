
#include <stdio.h>
// #include <conio.h>
// #include <dos.h>
#include <stdlib.h>
#include <time.h>

#define N 14000

void SortSwap1(int*,int n);
void SortSwap2(int*,int n);
void SortSwap3(int*,int n);
void SortSearchMin1(int*,int n);
void SortSearchMin2(int*,int n);
void SortBubble1(int*,int n);
void SortBubble2(int*,int n);
void BinSort(int *,int n);
void SortShell1(int*,int n);
void SortShell2(int*,int n);
void SortTree1(int*,int n);
void SortTree2(int*,int n);
void SortHoare(int*,int,int);

main()
{
int a[N],i,j; long  s,f;
for (j=1;j<=13;j++) {
 srand(2);
 for (i=0;i<N;i++)
  a[i]=rand()/10000;

 s=clock();
 printf("\n s%d=%ld  ",j,s);

 switch (j) {
  case 1 : SortSwap1(a,N); break;
  case 2 : SortSwap2(a,N); break;
  case 3 : SortSwap3(a,N); break;
  case 4 : SortSearchMin1(a,N); break;
  case 5 : SortSearchMin2(a,N); break;
  case 6 : SortBubble1(a,N); break;
  case 7 : SortBubble2(a,N); break;
  case 8 : BinSort(a,N); break;
  case 9 : SortShell1(a,N); break;
  case 10 : SortShell2(a,N); break;
  case 11 : SortTree1(a,N); break;
  case 12 : SortTree2(a,N); break;
  case 13 : SortHoare(a,0,N-1); break;
 }
 f=clock();
 printf(" f%d=%ld  ",j,f);
 printf(" time%d=%ld  ",j,f-s);
 } printf("\n");
} //main

void SortSwap1(int *a, int n)
{ int i,j,m;              // The worst algorithm (Swap)
 for (i=0;i<n-1;i++)
 for (j=0;j<n-1;j++)
 if (a[j]>a[j+1])
 { m=a[j]; a[j]=a[j+1]; a[j+1]=m; }
}

void SortSwap2(int *a, int n)
{ int i,j,m;   		   //  Algorithm 2 (Swap)
 for (i=0;i<n-1;i++)
 for (j=0;j<n-1-i;j++)
 if (a[j]>a[j+1])
 { m=a[j]; a[j]=a[j+1]; a[j+1]=m; }
}

void SortSwap3(int *a, int n)
{ int j,m,k;   	            //  Algorithm 3 (Swap)
 n=N; k=0;
 while(k==0)
 { k=1; --n;
  for (j=0;j<n;j++)
  if (a[j]>a[j+1])
  { m=a[j]; a[j]=a[j+1]; a[j+1]=m; k=0;}
 }
}

void SortSearchMin1(int *a, int n)
{ int i,j,m;   		   //  Algorithm 6 (by-min)
 for (i=0;i<n-1;i++)
 for (j=i+1;j<n;j++)
 if (a[i]>a[j])
 { m=a[j]; a[j]=a[i]; a[i]=m; }
}

void SortSearchMin2(int *a, int n)
{ int i,j,m,k;   	   //  Algorithm 7 (improved by-min)
 for (i=0;i<n-1;i++)
 { m=a[i];
  for (j=i+1;j<n;j++)
   if (m>a[j])
  { m=a[j]; k=j; }
  a[k]=a[i]; a[i]=m;
 }
}

void SortBubble1(int *a, int n)
{ int i,j,m;   		    //  Algorithm 4 (Bubble)
 for (i=0;i<n-1;i++)
 for (j=i+1;j>0;j--)
 if (a[j-1]>a[j])
 { m=a[j]; a[j]=a[j-1]; a[j-1]=m; }
 else break;
}

void SortBubble2(int *a, int n)
{ int i,j,m;   		//  Algorithm 5 (improved bubble)
 for (i=0;i<n-1;i++)
 { m=a[i+1];
 for (j=i;j>=0;j--)
 if (a[j]>m)
  a[j+1]=a[j];
 else break;
  a[j+1]=m;
 }
}

void BinSort(int mas[], int n)
{ int i,j,left,right,med,tmp;
  for(i=1;i<n;i++)
  { tmp=mas[i];
    left=0; right=i;
    while(left<right)
    { med=(left+right)/2;
      if(mas[med]<tmp) left=med+1;
       else right=med;
    } // while
    for(j=i;j>right;j--) mas[j]=mas[j-1];
    mas[right]=tmp;
  } // for i
} // BinSort

void SortShell1(int *a, int n)
{ int i,j,m,s;             //  Algorithm 8 (Shell)
 s=1;
 while(s<n) s*=2;
 while(s>0)
 { s=(s-1)/2;
  for (i=0;i<n-s;i++)
  for (j=i+s;j-s>=0;j-=s)
   if (a[j-s]>a[j])
    { m=a[j]; a[j]=a[j-s]; a[j-s]=m; }
   else break;
 }
}

void SortShell2(int *a, int n)
{ int i,j,m,s;             //  Algorithm 9 (Shell)
 s=1;
 while(s<n) s=3*s+1;
 while(s>0)
 { s=s/3;
  for (i=0;i<n-s;i++)
  for (j=i+s;j-s>=0;j-=s)
   if (a[j-s]>a[j])
    { m=a[j]; a[j]=a[j-s]; a[j-s]=m; }
   else break;
 }
}
				//  Algorithm  Sorttree
void subtree(int *a, int n, int k)
{ int r, l, t;
 r=a[k]; t=k; l=2*k+1;
 while (l<n)
 { if (l<n-1 && a[l]<a[l+1]) l++;
   if (r>a[l]) break;
   a[t]=a[l];
   t=l; l=2*t+1;
  }
  a[t]=r;
}

void treeup(int *a, int n)
{ int k, i;
 k=n/2;
 for (i=k; i>=0; i--)
 subtree(a,n,i);
}

void SortTree1(int *a, int n)
{ int i, r;
  treeup(a,n);
  for (i=n-1; i>0; i--)
  { r=a[0]; a[0]=a[i]; a[i]=r;
    subtree(a,i,0);
  }
}
				//  Algorithm  Sorttree (compact)
void SortTree2(int *a, int n)
{ int k, i, r, l, t;
 k=n/2;
 for (i=k; i>=0; i--)
 {
  r=a[i]; t=i; l=2*i+1;
  while (l<n)
  { if (l<n-1 && a[l]<a[l+1]) l++;
    if (r>a[l]) break;
    a[t]=a[l];
    t=l; l=2*t+1;
  }
   a[t]=r;
 }
 for (i=n-1; i>0; i--)
 { r=a[i];  a[i]=a[0]; a[0]=r;
  t=0; l=1;
  while (l<i)
  { if (l<i-1 && a[l]<a[l+1]) l++;
    if (r>a[l]) break;
    a[t]=a[l];
    t=l; l=2*t+1;
  }
  a[t]=r;
 }
}

void SortHoare(int *a, int l, int r)
 {                      	//  Algorithm of Hoare
   int i,j,x,w;
   i=l; j=r;
   x=a[(l+r)/2];
   do
   {
    while(x>a[i]) i++;
    while(x<a[j]) j--;
     if (i<=j)
     { w=a[i]; a[i++]=a[j]; a[j--]=w; }
   } while (i<=j);
   if(l<j) SortHoare(a,l,j);
   if(i<r) SortHoare(a,i,r);
 }




/* Result:
 s1=   3   f1=1340   time1=1337  
 s2=1343   f2=2172   time2=829  
 s3=2175   f3=2959   time3=784  
 s4=2962   f4=3533   time4=571  
 s5=3535   f5=3854   time5=319  
 s6=3857   f6=4515   time6=658  
 s7=4518   f7=4869   time7=351  
 s8=4871   f8=4875   time8=  4  
 s9=4878   f9=4882   time9=  4  
 s10=4885   f10=4888   time10=  3  
 s11=4890   f11=4892   time11=  2  
 s12=4895   f12=4897   time12=  2  
*/
