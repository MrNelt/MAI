#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void SortBubble(int *a, int n)
{ int i,j,m;   		    //  Algorithm 4 (Bubble)
 for (i=0;i<n-1;i++)
 for (j=i+1;j>0;j--)
 if (a[j-1]>a[j])
 { m=a[j]; a[j]=a[j-1]; a[j-1]=m; }
 else break;
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
 SortBubble(k,n);
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
