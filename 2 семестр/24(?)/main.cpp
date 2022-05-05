#include <stdio.h>
#include <stdlib.h>

typedef char tdata;

int i;
char ch;

struct node;

typedef node *link;

struct node {
  tdata data;
  link left, right;
} * tree;

void printtree(link t) {
  static int l = 0;
  l++;
  if (t) {
    printtree(t->right);
    for (i = 0; i < l; i++)
      printf("    ");
    printf("\\__%c\n", t->data);
    printtree(t->left);
  }
  l--;
} // printtree----------------------------------

int isAN() { return (ch >= 'a') && (ch <= 'z') || (ch >= '0') && (ch <= '9'); }

int isN(char c) { return (c >= '0') && (c <= '9'); }

link mknode(char c, link l, link r) {
  link t = new node;
  t->data = c;
  t->left = l;
  t->right = r;
  return t;
}

link expr();

link fact() {
  link t;
  scanf("%c", &ch);
  if (ch == '(') {
    t = expr();
    if (ch != ')')
      printf("ERROR: not )\n");
  } else if (isAN())
    t = mknode(ch, 0, 0);
  else
    printf("ERROR: not AN\n");
  return t;
}

link term() {
  link tm;
  int done;
  char ch1;
  tm = fact();
  done = 0;
  while ((ch != '\n') && (!done)) {
    scanf("%c", &ch);
    if ((ch == '^') || (ch == '*') || (ch == '/')) {
      ch1 = ch;
      tm = mknode(ch1, tm, fact());
    } else
      done = 1;
  }
  return tm;
}

link expr() {
  link ex;
  int done;
  char ch1;
  ex = term();
  done = 0;
  while ((ch != '\n') && (!done)) {
    if ((ch == '+') || (ch == '-')) {
      ch1 = ch;
      ex = mknode(ch1, ex, term());
    } else
      done = 1;
  }
  return ex;
}

void tree2expr(link tree) {
  if (tree) {
    if ((tree->data == '+') || (tree->data == '-'))
      printf("(");
    tree2expr(tree->left);
    printf("%c", tree->data);
    tree2expr(tree->right);
    if ((tree->data == '+') || (tree->data == '-'))
      printf(")");
  }
}

void trans_tree(link tree) { //
  if (tree) {
    if (tree->data == '*')
      if (tree->left->data == '^' && tree->right->data == '^') { //будем упрощать только простые случаи
        link l = tree->left; //переходим к узлу со значением ^
        link r = tree->right;
        link base1 = l->left; //переход к узлу с основанием степени
        link base2 = r->left;
        if (base1->data == base2->data && !base1->left && !base1->right && !base2->left && !base2->right) { //проверка на то основание одинаковое и узлы с онованием терминальные
          tree->data = '^';
          tree->left = base1;
          link plus = new node; //создаем новый узел для сложения показателей степени
          plus->data = '+';
          plus->left = l->right;
          plus->right = r->right;
          tree->right = plus;
          i = 1;
        }
      }
    trans_tree(tree->left);
    trans_tree(tree->right);
  }
}

int main() {
  int k = 0;
  printf("Menu:\n"
  "1) Enter the expression\n"
  "2) Output the expression tree\n"
  "3) Output an expression from the expression tree\n"
  "4) Main action\n"
  "5) Menu\n"
  "6) Exit \n" 
  );
  tree = 0;
  for(;;) {
    printf("Input the number of menu: ");
    scanf("%d", &k);
    char c = 0;//съесть символ перехода
    c = getchar();
    if (k == 1) {
      printf("Input expression:\n");
      tree = 0;
      tree = expr();
    }
    else if (k == 2) {
      if (tree) {
        printtree(tree);
        printf("\n");
      }
      else {
        printf("The tree is empty\n");
      }
    }
    else if (k == 3) {
      if (tree) {
        tree2expr(tree);
        printf("\n");
      }
      else {
        printf("The tree is empty\n");
      }
    }
    else if (k == 4) {
      if (tree) {
        i = 1;
        while (i) {
          i = 0;
          trans_tree(tree);
        }
      }
      else {
        printf("The tree is empty\n");
      }
    }
    else if (k == 5) {
      printf("Menu:\n"
      "1) Enter the expression\n"
      "2) Output the expression tree\n"
      "3) Output an expression from the expression tree\n"
      "4) Main action\n"
      "5) Menu\n"
      "6) Exit\n" 
      );
    }
    else if (k == 6) {
      break;
    }
    else {
      printf("There is no such menu item.\n");
    }
  }
  return 0;
}