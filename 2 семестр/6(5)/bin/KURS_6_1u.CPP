#include<stdio.h>                          // IN UNIX WORKS
//#include<conio.h>
#include<string.h>
int main(int argc, char *argv[])
{ FILE *fi,*fo;  printf("argc=%d\n",argc);
if(argc==1)                                      
 { if((fi=fopen("in.txt","r"))==NULL) 
    {printf("Cannot input 1"); //getch();
                                                        return 1;}   
  if((fo=fopen("Base.dat","wb"))==NULL)
    {printf("Cannot output"); //getch(); 
                                                        return 1;}
 }
 else
 if(argc==2)                                
 { puts(argv[1]); printf("%s\n",argv[1]);               
  if((fi=fopen(argv[1],"r"))==NULL)
    {printf("Cannot input 2"); //getch(); 
                                                        return 1;}
  if((fo=fopen("Base.dat","wb"))==NULL)
    {printf("Cannot output"); //getch(); 
                                                        return 1;}
 }
 else
 { if((fi=fopen(argv[1],"r"))==NULL)
    {printf("Cannot input 3"); //getch(); 
                                                        return 1;}
  if((fo=fopen(argv[2],"wb"))==NULL)
    {printf("Cannot output"); //getch(); 
                                                        return 1;}
 }

struct  S
  { char fam[20];
    int g_r;
     float rost;
  } s,s1;
//  clrscr();
int l=sizeof(S); // printf("l=%d\n",l); //  getch();
//char c,*p=(char*)&s;
int n=0;
while(!feof(fi))
  {
  fscanf(fi,"%s %d %f",s.fam,&s.g_r,&s.rost);
   fwrite(&s,sizeof(s), 1,fo); /* write struct s to file */
   n++;
  }
fclose(fi);
fclose(fo);  printf("n=%d\n",n);

if(argc<3)
 { if((fi=fopen("Base.dat","rb"))==NULL)
    {printf("Cannot input"); //getch(); 
                                                      return 1;}
  if((fo=fopen("out.txt","w"))==NULL)
    {printf("Cannot output"); //getch(); 
                                                      return 1;}
 }
 else if(argc==3)
 { if((fi=fopen(argv[2],"rb"))==NULL)
    {printf("Cannot input"); //getch(); 
                                                      return 1;}
  if((fo=fopen("out.txt","w"))==NULL)
    {printf("Cannot output"); //getch(); 
                                                      return 1;}
 } else
{ if((fi=fopen(argv[2],"rb"))==NULL)
    {printf("Cannot input"); //getch(); 
                                                      return 1;}
  if((fo=fopen(argv[3],"w"))==NULL)
    {printf("Cannot output"); //getch(); 
                                                      return 1;}
 }

 printf("========================================\n");
 printf("|  Familija   |God rozhdenija|  Rost   |\n");
 printf("========================================\n");
 fprintf(fo,"All in Base:\n");
 while(!feof(fi))
 {
  s1=s;
 fread(&s,l, 1,fi);
  if(strcmp(s.fam,s1.fam)) //BECAUSE REPEATES LAST RECORD IN OUT.DAT ?
   { fprintf(fo,"fam=%s g_r=%d rost=%.2f\n",s.fam,s.g_r,s.rost);
     printf("|  %-10s |     %4d     |  %.2f   |\n",s.fam,s.g_r,s.rost);
    }
 }
   printf("========================================\n");
                return 0;
}

