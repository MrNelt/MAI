#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

typedef int tdata;

int i, s, max_depth = 0;

struct node;

typedef node *link;

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

struct node {
  tdata data;
  link left;
  link right;
} * tree;

void print_tree(link t) {
  static int l = 0;
  l++;
  if (t) {
    print_tree(t->right);
    for (i = 0; i < l; i++)
      printf("    ");
    printf("\\__%d\n", t->data);
    print_tree(t->left);
  }
  l--;
}

void insert_tree(link &t, tdata v)
{
  if (!t) {
    t = new node;
    t->data = v;
    t->left = 0;
    t->right = 0;
  } else {
    if (v < t->data)
      insert_tree(t->left, v);
    else if (v > t->data)
      insert_tree(t->right, v);
  }
}

link q;

void del(link &);

void delete_tree(link &tree, tdata v) {
  if (tree)
    if (v < tree->data)
      delete_tree(tree->left, v);
    else if (v > tree->data)
      delete_tree(tree->right, v);
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

void add_tree(link &t, int n) {
  for (i = 0; i < n; i++) {
    int v = rand() % 120 + 1;
    insert_tree(tree, v);
  }
}

void count(link t) {
  if (t) {
    count(t->right);
    s++;
    count(t->left);
  }
}

void depth_tree(link t) {
  static int l = 0;
  max_depth = max(l, max_depth);
  l++;
  if (t) {
    depth_tree(t->right);
    depth_tree(t->left);
  }
  l--;
}

int main() {
  time_t t;
  srand(time(&t));
  int k = 1, n;
  tree = 0;
  tdata v;
  while (k) {
    printf("\n    MENU\n 0 - exit\n 1 - add random tree"
           "\n 2 - print tree\n 3 - insert item"
           "\n 4 - delete item\n 5 - number of nodes"
           "\n 6 - depth(особое действие по варианту)"
           "\n 7 - clear tree"
           "\n 8 - exit\n ==>");
    scanf("%d", &k);
    if (!k)
      break;
    if (k == 1) {
      printf("\nInput number of items: ==>");
      scanf("%d", &n);
      add_tree(tree, n);
    }
    if (k == 2)
      if (tree)
        print_tree(tree);
      else
        printf("\nTree is empty.\n");
    if (k == 3) {
      printf("For insert Input v=");
      scanf("%d", &v);
      insert_tree(tree, v);
    }
    if (k == 4) {
      printf("For delete Input v=");
      scanf("%d", &v);
      delete_tree(tree, v);
    }
    if (k == 5) {
      s = 0;
      count(tree);
      printf("\nNumber of nodes =%d\n", s);
    }
    if (k == 7)
      tree = 0;
    if (k == 6) {
        max_depth = 0;
        depth_tree(tree);
        printf("\n Depth = %d\n", max_depth);
    }
    if (k == 8) {
        return 0;
    }
  }
  return 0;
}
