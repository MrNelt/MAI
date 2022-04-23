#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include<time.h>
#define N 7
		   // tree of symmetric form
int M[100];

typedef int tdata;

int i,k;
tdata m;

struct node;

typedef node * link;

struct node
{ tdata data;
  link left;
  link right;
} *tree;

  void printtree(link t)
  { static int l=0;
    l++;
    if(t)
     { printtree(t->right);
       for(i=0;i<l;i++)printf("    ");
       printf("\\__%d\n",t->data);
       printtree(t->left);
     }
    l--;
   } // printtree----------------------------------

  void Mtree(link t)
  { if(t)
    { // printf("%d(",t->data);
      M[k++]=1;
      Mtree(t->left); // printf(",");
      M[k++]=2;
      Mtree(t->right); // printf(")");
      M[k++]=3;
    }
  }

  void Mprint()
  { printf("m: ");
    for(i=0;i<k;i++) printf("%d ",M[i]);
    printf("\n");
  }

  void inserttree(link &t,tdata v)
  { if(!t) {t=new node; t->data=v;
	    t->left=0; t->right=0;
	   }
      else { if(v<t->data) inserttree(t->left,v);
	     else   if(v>t->data)
			   inserttree(t->right,v);
	   }
  } // inserttree-----------------------------------

  void symm()
  { for(i=0;i<k/2;i++)
    if(4-M[i]!=M[k-i-1])
    { printf("Tree is not symmetric.\n"); return;}
      printf("Tree is symmetric.\n");
  }

  int main(){
  //  clrscr(); randomize();
   time_t t; srand(time(&t)); 
    // link tree;
    tree=0;  inserttree(tree,15);

    for(i=0;i<N;i++) { m=rand()%15+1;
		       inserttree(tree,15+m);
		       inserttree(tree,15-m);
		     }
    printtree(tree);
    printf("\n\n-----------------------\n\n");
    k=0; Mtree(tree); printf("k=%d\n",k);
    Mprint(); symm();
		       m=rand()%30+1;
		       inserttree(tree,m);
    printf("\n\n-----------------------\n\n");
    printtree(tree);
    printf("\n\n-----------------------\n\n");
    k=0; Mtree(tree); printf("k=%d\n",k);
    Mprint(); symm();

  //  getch();
   return 0;
}//main

/* Result:

		\__29
	    \__27
			\__25
		    \__21
		\__18
	\__16
    \__15
	\__14
		\__12
		    \__9
			\__5
	    \__3
		\__1


-----------------------

k=39
m: 1 1 1 1 2 3 2 1 1 1 2 3 2 3 2 3 3 2 3 2 1 2 1 1 2 1 2 1 2 3 3 3 2 1 2 3 3 3 3
Tree is symmetric.


-----------------------

		\__29
	    \__27
			\__25
		    \__21
		\__18
	\__16
    \__15
	\__14
		\__12
		    \__9
			\__5
	    \__3
		    \__2
		\__1


-----------------------

k=42
m: 1 1 1 1 2 1 2 3 3 2 1 1 1 2 3 2 3 2 3 3 2 3 2 1 2 1 1 2 1 2 1 2 3 3 3 2 1 2 3 3 3 3
Tree is not symmetric.

*/