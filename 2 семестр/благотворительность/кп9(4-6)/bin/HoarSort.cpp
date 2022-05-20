#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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


int main()
{ int *k,n,v,i,j,m;
  long a;  srand(time(&a)); 
  printf("Vvedite chislo elementov massiva: ");
  scanf("%d",&n);
  k=new int[n];
  printf("\nIshodnyj massiv:\n");
  for(i=0;i<n;i++)
  { k[i]=rand()%100; printf("%4d",k[i]); }
 SortHoare(k,0,n-1);
   printf("\nPoluchennyj massiv:\n");
   for(i=0;i<n;i++) printf("%4d",k[i]);
   printf("\n");
 return 0;
}

/* Result:
Vvedite chislo elementov massiva: 25

Ishodnyj massiv:
  88  13  11  18  26   8  10  32  39   6  55  16  55   6   5  10  56  31  61  76  56  68  88  44  25
Poluchennyj massiv:
   5   6   6   8  10  10  11  13  16  18  25  26  31  32  39  44  55  55  56  56  61  68  76  88  88
*/
