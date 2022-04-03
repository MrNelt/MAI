#include <stdio.h> // IN UNIX WORKS
//#include<conio.h>
#include <string.h>
int main(int argc, char *argv[])
{
  FILE *fi, *fo;
  printf("argc=%d\n", argc);
  struct S
  {
    char fam[20];
    int g_r;
    float rost;
  } s, s1;
  //  clrscr();
  int l = sizeof(S); // printf("l=%d\n",l); //  getch();
  // char c,*p=(char*)&s;
  int n = 0;

  if (argc == 1)
  {
    if ((fi = fopen("Base.dat", "rb")) == NULL)
    {
      printf("Cannot input"); // getch();
      return 1;
    }
    if ((fo = fopen("out.txt", "w")) == NULL)
    {
      printf("Cannot output"); // getch();
      return 1;
    }
  }
  else if (argc == 2)
  {
    if ((fi = fopen(argv[1], "rb")) == NULL)
    {
      printf("Cannot input"); // getch();
      return 1;
    }
    if ((fo = fopen("out.txt", "w")) == NULL)
    {
      printf("Cannot output"); // getch();
      return 1;
    }
  }
  else
  {
    if ((fi = fopen(argv[1], "rb")) == NULL)
    {
      printf("Cannot input"); // getch();
      return 1;
    }
    if ((fo = fopen(argv[2], "w")) == NULL)
    {
      printf("Cannot output"); // getch();
      return 1;
    }
  }

  float r = 1;
  while (r)
  {
    printf("Input rost (r=1.60-1.80, for end r=0): r=");
    scanf("%f", &r);
    if (r)
    {
      fprintf(fo, "Query %d (For rost>=%.2f):\n", ++n, r);
      printf("========================================\n");
      printf("|  Familija   |God rozhdenija|  Rost   |\n");
      printf("========================================\n");
    }
    rewind(fi);
    while (!feof(fi))
    {
      s1 = s;
      fread(&s, l, 1, fi);

      if (strcmp(s.fam, s1.fam)) // BECAUSE REPEATES LAST RECORD IN OUT.DAT ?
        if (r && s.rost >= r)
        {
          fprintf(fo, "fam=%s g_r=%d rost=%.2f\n", s.fam, s.g_r, s.rost);
          printf("|  %-10s |     %4d     |  %.2f   |\n", s.fam, s.g_r, s.rost);
        }
    }
    if (r)
      printf("========================================\n");

  } // while(r)
    // getch();
  return 0;
}
