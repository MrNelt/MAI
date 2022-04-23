#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef char tdata;
int i,r,q;
tdata m;

struct node ;

typedef node * link;

struct node 
{ tdata data;
  link son;
  link brother;
};

  void printtree(link t)
  { static int l=0;
    // l++;
    if(t)
     { printtree(t->brother);
       for(i=0;i<l;i++)printf("    ");
       printf("\\__%c\n",t->data);
      l++; printtree(t->son); l--;
     }
    // l--;
   } // printtree----------------------------------

  link search(link tree, tdata c)
{ if(tree)
  { if(tree->data==c) return tree;
    link t=search(tree->son,c);
    if(!t) t=search(tree->brother,c);
    return t;
  } return 0;
} // search----------------------------------------

   link searchfather(link tree, tdata c)
{ link t;
  if(tree)
  { if(tree->son&&tree->son->data==c) return tree;
    t=tree->son; 
    while(t) { if(t->brother&&t->brother->data==c) return tree; 
                             t=t->brother;
                  }
     t=0;  t=searchfather(tree->son,c); 
     if(!t) t=searchfather(tree->brother,c);
             return t;
  } return 0;
}

   link searchbrother(link tree, tdata c)
{  if(tree)
  { if(tree->brother&&tree->brother->data==c) return tree;
     link t=searchbrother(tree->brother,c);
          if(!t) t=searchbrother(tree->son,c);
    return t;
  } return 0;
}

  void insertbrother(link &t,tdata v)
  { if(!t) {t=new node ; t->data=v;
	    t->son=0; t->brother=0;
	   }
      else
   insertbrother(t->brother,v);
  } // insertbrother-----------------------------------

  void insertson(link &t,tdata v)
  { if(!(t->son)) {t->son=new node ; t->son->data=v;
	    t->son->son=0; t->son->brother=0;
	   }
      else
   insertbrother(t->son,v);
  } // insertbrother-----------------------------------

  void inserttree(link &t,tdata v)  // (tr*&t,tdata v)
  { if(!t) {t=new node ; t->data=v; // printf("%d\n",t->data);
	    t->son=0; t->brother=0;
	   }
      else {  r=rand()%2;
	    if(r) inserttree(t->son,v);
	     else inserttree(t->brother,v);
	   }
  } // inserttree-----------------------------------

  void action(link tree)
  {if(tree)
   {
    if(tree->son==0&&tree->brother==0)q++;
    action(tree->son);
    action(tree->brother);
   }
  }
   void mix(tdata *m, int n)
   { int r; tdata s; 
      for(i=0;i<n;i++)
             {r=rand()%n; s=m[i]; m[i]=m[r]; m[r]=s;}
    } 

  main(){
  //  clrscr();// randomize();
  long a;  srand(time(&a)); 
  int k,n; tdata *m, f, s;
  link tree=0,t;
  for(;;)
  {
   printf("MENU:\n0. Exit"
	       "\n1. Generation random tree"
	       "\n2. Print tree"
	       "\n3. Insert root"
	       "\n4. Insert son"
	       "\n5. Insert brother"
	       "\n6. Find father"
               "\n7. Find older brother"
               "\n8. Delete node"
               "\n9. Delete tree"
               "\n10. Action\nInput number ==>"); scanf("%d",&k);
              
   if(k==0)break;

   if(k==1){ printf("\nInput number of nodes ==>"); scanf("%d",&n);
                   m=new tdata[n];	    
                for(i=0;i<n;i++)  m[i]=100+i; mix(m,n);
		for(i=0;i<n;i++) inserttree(tree,m[i]);
	       }
else 
   if(k==2){ if(!tree) printf("\nTree is empty\n");
	     else printtree(tree);
	   }
else 
   if(k==3){ printf("\nInput value of root ==>"); scanf(" %c",&f);
	     t=new node ; t->data=f;
	     t->son=0; t->brother=0;
	     if(!tree) tree=t;
	     else { t->son=tree; tree=t; }
	   }
else 
   if(k==4){ printf("\nInput value of father ==>"); scanf(" %c",&f);
	     t=search(tree,f);
	     if(!t) printf("\nFather not found\n");
	     else { printf("\nInput value of son ==>"); scanf(" %c",&s);
		    insertson(t,s);
		  }
	   } // if(k==4)
else 
   if(k==5){ printf("\nInput value of node ==>"); scanf(" %c",&f);
	     t=search(tree,f);
	     if(!t) printf("\nNode not found\n");
	     else { printf("\nInput value of brother ==>"); scanf(" %c",&s);
		    insertbrother(t,s);
		  }
	   } // if(k==5)
else 
  if(k==6){ printf("\nInput value of node ==>"); scanf(" %c",&f);
             t=searchfather(tree,f);
	     if(!t) printf("\nNode not found\n");
	     else  printf("\nValue of father = %c\n",t->data);
	  } // if(k==6)
else 
  if(k==7){ printf("\nInput value of node ==>"); scanf(" %c",&f);
             t=searchbrother(tree,f);
	     if(!t) printf("\nNode not found\n");
	     else  printf("\nValue of older brother = %c\n",t->data);
	  } // if(k==7)
else 
   if(k==8){ printf("\nInput value of node ==>"); scanf(" %c",&f);
	     if(tree->data==f)if(tree->brother==0){tree=0; continue;}
			       else tree=tree->brother;
	     else {   t=searchbrother(tree,f);
		   if(t) t->brother=t->brother->brother;
		   else { t=searchfather(tree,f);
			  if(t) if(t->son->brother) t->son=t->son->brother;
				else t->son=0;
			  else printf("\nNode not found\n");
			}
		  }
	  } // if(k==8)
else 
    if(k==9) tree=0;
else 
    if(k==10){q=0; action(tree);
	     printf("\nNumber of nodes without sons and younger brothers = %d\n",q);
	    }
else break;
  } //for(;;)
}//main


