
#include <stdio.h>
//#include <conio.h>
//#include <stdlib.h>

void prn_matrix(int **, int, int);

void prn_sh_mtrx(int *, int *, int);

void ftosh(int **, int, int, int *, int *, int &);

void shtof(int *, int *, int, int **, int, int);

void umnmtrs(int **, int **, int **, int, int, int);

void umnshmtrs(int *, int *, int, int *, int *, int,
               int *, int *, int &, int, int, int);

main()
{
  //  clrscr(); randomize();
  int **mtr1, *a1, *ind1, k1, n, m, p, i, j,
      **mtr2, *a2, *ind2, k2,
      **mtr3, *a3, *ind3, k3;
  printf("Input n=");
  scanf("%d", &n);
  printf("Input m=");
  scanf("%d", &m);
  printf("Input p=");
  scanf("%d", &p);

  mtr1 = new int *[n];
  for (i = 0; i < n; i++)
    mtr1[i] = new int[m];

  mtr2 = new int *[m];
  for (i = 0; i < m; i++)
    mtr2[i] = new int[p];

  mtr3 = new int *[n];
  for (i = 0; i < n; i++)
    mtr3[i] = new int[p];

  printf("Input k1=");
  scanf("%d", &k1);
  printf("Input k2=");
  scanf("%d", &k2);
  a1 = new int[k1];
  ind1 = new int[k1];
  a2 = new int[k2];
  ind2 = new int[k2];
  a3 = new int[k1 * k2];
  ind3 = new int[k1 * k2];

  for (i = 0; i < k1; i++)
  {
    scanf("%d", &a1[i]);
    scanf("%d", &ind1[i]);
  }

  for (i = 0; i < k2; i++)
  {
    scanf("%d", &a2[i]);
    scanf("%d", &ind2[i]);
  }

  umnshmtrs(a1, ind1, k1, a2, ind2, k2,
            a3, ind3, k3, n, m, p);

  prn_sh_mtrx(a1, ind1, k1);
  prn_sh_mtrx(a2, ind2, k2);
  prn_sh_mtrx(a3, ind3, k3);

  shtof(a1, ind1, k1, mtr1, n, m);
  shtof(a2, ind2, k2, mtr2, m, p);
  shtof(a3, ind3, k3, mtr3, n, p);
  prn_matrix(mtr1, n, m);
  prn_matrix(mtr2, m, p);
  prn_matrix(mtr3, n, p);
  umnmtrs(mtr1, mtr2, mtr3, n, m, p);
  prn_matrix(mtr3, n, p);

  //  getch();
}

void prn_matrix(int **matrix, int size_x, int size_y)
{
  int x, y;
  printf("\nFull array:\n");
  for (x = 0; x < size_x; x++)
  {
    printf("\n");
    for (y = 0; y < size_y; y++)
      printf("%3d ", matrix[x][y]);
    printf("\n");
  }
}

void prn_sh_mtrx(int *a, int *ind, int k)
{
  int i;
  printf("\nShort array:\n");
  for (i = 0; i < k; i++)
    printf("%3d ", a[i]);
  printf("\n");
  for (i = 0; i < k; i++)
    printf("%3d ", ind[i]);
  printf("\n");
}

void ftosh(int **mtr, int n, int m, int *a, int *ind, int &k)
{
  int i, j;
  k = 0;

  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (mtr[i][j] != 0)
      {
        a[k] = mtr[i][j];
        ind[k] = i * m + j;
        k++;
      }
}

void shtof(int *a, int *ind, int k, int **mtr, int n, int m)
{
  int i, j, l;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      mtr[i][j] = 0;

  for (l = 0; l < k; l++)
  {
    i = ind[l] / m;
    j = ind[l] % m;
    mtr[i][j] = a[l];
  }
}

void umnmtrs(int **matr1, int **matr2, int **matr3, int n, int m, int p)
{
  int i, j, l;
  for (i = 0; i < n; i++)
    for (l = 0; l < p; l++)
    {
      matr3[i][l] = 0;
      for (j = 0; j < m; j++)
        matr3[i][l] += matr1[i][j] * matr2[j][l];
    }
}

void umnshmtrs(int *a1, int *ind1, int k1, int *a2, int *ind2, int k2,
               int *a3, int *ind3, int &k3, int n, int m, int p)
{
  int i, i1, j, j1, l, l1, t1, t2, s;
  k3 = 0;
  for (i = 0; i < n; i++)
    for (l = 0; l < p; l++)
    {
      s = 0;
      for (t1 = 0; t1 < k1; t1++)
      {
        i1 = ind1[t1] / m;
        j = ind1[t1] % m;
        for (t2 = 0; t2 < k2; t2++)
        {
          j1 = ind2[t2] / p;
          l1 = ind2[t2] % p;
          if (i == i1 && j == j1 && l == l1)
            s += a1[t1] * a2[t2];
        }
      }
      if (s)
      {
        a3[k3] = s;
        ind3[k3] = i * p + l;
        k3++;
      }
    }
}