#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include<time.h>
#define N 20

typedef int tdata;

int i, s;

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

  void inserttree(link &t,tdata v)  // (node*&t,tdata v)
  { if(!t) {t=new node; t->data=v; // printf("%d\n",t->data);
	    t->left=0; t->right=0;
	   }
      else {  // printf("--%d\n",t->data);
	    if(v<t->data) inserttree(t->left,v);
	     else    if(v>t->data)  //
			   inserttree(t->right,v);
	   }
  } // inserttree-----------------------------------

  link q;

  void del(link &);

  void deletetree(link &tree, tdata v) {
    if (tree)
      if (v < tree->data)
        deletetree(tree->left, v);
      else if (v > tree->data)
        deletetree(tree->right, v);
      else if (!(tree->right))
        tree = tree->left;
      else if (!(tree->left))
        tree = tree->right;
      else {
        q = tree;
        del(q->left);
      }
  }

  void del(link &t) {
    if (t->right)
      del(t->right);
    else {
      q->data = t->data;
      q = t;
      t = t->left;
    }
  }

void addtree(link &t, int n)
{ for(i=0;i<n;i++) { int v=rand()%30+1;
		       inserttree(tree,v);
		     }
}

void count(link t)
  { if(t)
     { count(t->right);
       s++;
       count(t->left);
     }
   } // count----------------------------------

  int main(){
   // clrscr(); randomize();
   time_t t; srand(time(&t)); int k=1, n;
    // link tree;
    tree=0; tdata v;
while(k)
  { printf("\n    MENU\n 0 - exit\n 1 - add random tree"
  "\n 2 - print tree\n 3 - insert item"
  "\n 4 - delete item\n 5 - number of nodes"
  "\n 10 - action one"
  "\n 6 - clear tree\n ==>");
  scanf("%d",&k);
  if(!k) break;
  if(k==1)
   { printf("\nInput number of items: ==>"); scanf("%d",&n);
    addtree(tree,n);
   }
  if(k==2) if(tree) printtree(tree); else printf("\nTree is empty.\n");
  if(k==3) {printf("For insert Input v="); scanf("%d",&v);
                inserttree(tree,v);
               }
  if(k==4) {printf("For delete Input v="); scanf("%d",&v);
                deletetree(tree,v);
                } 
  if(k==5) {s=0; count(tree); printf("\nNumber of nodes =%d\n",s);}
  if(k==6) tree=0;
  //  printf("\n\n-----------------------\n\n");
  }//while k
  return 0;
    // getch();
}//main

