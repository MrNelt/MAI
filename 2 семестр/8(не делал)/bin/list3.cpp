#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct ls;
typedef ls * link;
typedef enum{Jan,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec,UNK} item;
char month[12][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug",
                "Sep","Oct","Nov","Dec"};
struct ls
{item body;
link pre, next;
} *list, *t,*f;

int i,n,k,c;
item m,m1;

void randomize()
{ long a=time(0); 
  srand(a);
}                       //    t->body  ~  *t.body
void add(item m)
{ if(!list){list=new ls; list->body=m; list->next=list; 
             list->pre=list;}
   else { t=new ls; t->body=m; f=list->pre; list->pre=t; 
           f->next=t; t->next=list; t->pre=f; }
}

void addfirst(item m)
{ if(!list){list=new ls; list->body=m; list->next=list; 
             list->pre=list;}
   else { t=new ls; t->body=m; f=list; list=t; list->next=f;
           list->pre=f->pre; f->pre->next=list; f->pre=list;
	    }
}

void genlist(int n)
{ for(i=0;i<n;i++)
  { m=item(rand()%12); add(m); }	
}

void printlist()
 { if(!list)printf("\nList is empty!\n");
  else { printf("\nList:\n[ "); t=list;
  do { printf("%s ",month[t->body]);
             t=t->next;
            } while(t!=list); printf("]\n");
       }
}

item read_val()
{ char b[4]; scanf("%s",b);
  for(i=0;i<12;i++) if(!strcmp(b,month[i])) return item(i);
  return UNK;

}

void deleting(item m)
{ if(list->body==m){f=list; if(list->next==list)list=0; else
                     {list=list->next; list->pre=f->pre;
                     f->pre->next=list;} delete f;}
  else { t=list; c=0;
         do
          { if(t->next->body==m)
            { f=t->next; t->next=f->next; f->next->pre=t;              
              delete f; c=1; break;
            } 
           t=t->next;
          } while(t->next!=list);
       if(!c) printf("\nItem with this value not exists!\n");
      } // else
} // deleting                                

void insert(item m, item m1)
{ t=list; c=0;
 do  { if(t->body==m)
       { f=new ls; f->body=m1; f->next=t->next; f->pre=t;
         t->next->pre=f; t->next=f; 
		  c=1; //if(t==list->pre) list=f; 
		  break; 
       } 
       t=t->next;
     } while(t!=list);
  if(!c) printf("\nItem with this value not exists!\n");
} // insert 

void action(item m)
{ t=list; c=0;
 do  { if(t->body==m)
       { m1=t->pre->body; t->pre->body=t->next->body;
    	  t->next->body=m1;  c=1; break;
       } 
       t=t->next;
     } while(t!=list);
  if(!c) printf("\nItem with this value not exists!\n");
} // action   

int main()
{ list=0; k=9;
  randomize();
 for(;;)
 { if(k==9) printf("\nInput from 1 to 10 or 0 for actions:\n"
          "1. Generation list.\n2. Addition new items in end of list.\n"
          "3. Addition new items in begin of list.\n"
          "4. Deleting from list.\n5. Print list.\n"
		  "6. Inserting in list.\n7. Erase list.\n"
		  "8. Lenght of list.\n9. Print this MENU\n"
		  "10. Main Action\n"
          "0. Exit out program.\n"); 
		   printf("\nInput number of MENU: k="); scanf("%d",&k);
  if(!k) break;
  if(k==1) {printf("\nInput number of new items of list: n="); scanf("%d",&n);
            genlist(n);
           }
else if(k==2) { printf("\nInput value of adding item: m="); //scanf("%d",&m);
                m=read_val(); add(m);
              }  
else if(k==3) { printf("\nInput value of adding item: m="); // scanf("%d",&m);
                m=read_val(); addfirst(m);
              }
else if(k==4) { if(!list) { printf("\nList is empty!\n"); continue;}
                printf("\nInput value of deleting item: m="); // scanf("%d",&m);
                m=read_val(); deleting(m);
              }  
else if(k==5) // if(!list)printf("\nList is empty!\n");else 
    printlist();
else if(k==6) {if(!list) { printf("\nList is empty!\n"); continue;}
                printf("\nInput value inserting item: m1="); //scanf("%d",&m1);
                 m1=read_val();
				 printf("\nInput value item after which to insert: m="); //scanf("%d",&m);
                 m=read_val();
			    insert(m,m1);}   
else if(k==7) { t=list; if(t)do{f=t; t=t->next; delete f;} while(t!=list); list=0; }
else if(k==8) { t=list; n=0; if(t)do{t=t->next; n++;} while(t!=list);
                printf("\nLenght of list=%d\n", n);
              } 
else if(k==10) { if(!list) { printf("\nList is empty!\n"); continue;}
                printf("\nInput value for main action: m="); //scanf("%d",&m);
                m=read_val(); action(m);} 
else if(k>10) printf("Have no such number of MENU\n");
  } // for
} // main 


