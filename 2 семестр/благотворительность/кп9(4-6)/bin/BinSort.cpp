#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void binsort(int mas[], int n)
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
} // binsort

int main()
{ int *k,n,v,i,j,m;
  long a;  srand(time(&a)); 
  printf("Vvedite chislo elementov massiva: ");
  scanf("%d",&n);
  k=new int[n];
  printf("\nIshodnyj massiv:\n");
  for(i=0;i<n;i++)
  { k[i]=rand()%100; printf("%4d",k[i]); }
 binsort(k,n);
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
