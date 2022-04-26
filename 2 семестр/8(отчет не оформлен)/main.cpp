#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct ls;

typedef ls *link;
typedef int item;

struct ls {
    item body;
    link next;
}*tail, *head, *t;

void randomize() {
    long a = time(0);
    srand(a);
}

void add(item m) {
    if (!tail) { //если элементов в списке 0
        tail = new ls;
        tail->body = m;
        tail->next = 0;
        head = new ls;
        head->body = m;
        head->next = 0;
    }
    else {
        t = new ls;
        t->body = m;
        t->next = 0;
        if (tail->next == 0) {
            tail->next = t;
        }
        head->next = t;
        head = head->next; //голова передвигается
    }
}

void addFirst(item m) { //добавление элемента в начало
    if (!head) { //если элементов в списке 0
        head = new ls;
        head->body = m;
        head->next = 0;
        tail = new ls;
        tail->body = m;
        tail->next = 0;
    }
    else {
        t = new ls;
        t->body = m;
        t->next = tail;
        tail = t;
    }
}

void genList(int n) { //генерация списка с кол-вом случайных элементов n
    for (int i = 0; i < n; i++) {
        item m = rand() % 155;
        add(m);
    }
}

int sizeList() {
    t = tail;
    int n = 0;
    do {
        n++;
        t = t->next; 
    } while (t != 0);
    return n;
}

void printList() {
    if (!tail) { //список пустой
        printf("\nList is empty\n");
    }
    else {
        printf("\nList:\n[ ");
        t = tail;
        do {
            printf("%d ", t->body);
            t = t->next;
        } while (t != 0);
        //printf("%d ]\n", t->body);
        printf("]\n");
    }
}


void deleting(item m) { //удаление элемента из списка
    t = tail;
    int flag = 0;
    ls *f;
    if (t->body == m) { //случай если первый элемент нужно удалить
        if (t->next == 0) { //список станет пустым
            delete t;
            tail = 0;
            head = 0;
            return;
        }
        else { //удаляем текущий элемент и двигаем tail
            f = t;
            t = t->next;
            tail = t;
            delete f;
            return; 
        }
    }
    do {
        if (t->next != 0) {
            if (t->next->body == m) {
                flag = 1;
                f = t->next;
                if (f->next != 0){
                    t->next = f->next;
                }
                else {
                    t->next = 0; //конец списка изменяется!!!
                    head = t; 
                    break;
                }
                delete f;
            }
        }
        t = t->next;
    } while (t != 0);
    if (!flag) {
        printf("\nItem with this value not exists!\n");
    }
}

void erase() {
    t = tail;
    ls *f;
    if (t) {
        do {
            f = t;
            t = t->next;
            delete f;
        } while (t != 0);
    }
    tail = 0;
    head = 0;
}

void insert(item m1, item m2) {
    t = tail;
    int flag = 0;
    ls *f1;
    ls *f2;
    do {
        if (t->body == m2) {
            flag = 1;
            if (t->next == 0) { //нужно просто добавить в конец списка число
                add(m1);
                return;
            }
            else {
                f1 = new ls;
                f1->body = m1;
                f1->next = t->next;
                t->next = f1;
                return;
            }            
        }
        t = t->next;
    } while (t != 0);
    if (!flag) {
        printf("\nItem with this value not exists!\n");
    }
}


void action(item m) {
    if (!tail) {
        return;
    }
    int counter = 0; //кол-во элементов с таким значением в списке
    t = tail;
    do {
        if (t->body == m) {
            counter++;
        }
        t = t->next;
    } while (t != 0);
    if (counter == 0) {
        printf("\nItem with this value not exists!\n");
        return;
    }
    erase(); //очищаем список
    for (int i = 0; i < counter; i++) {
        add(m); //добавляем выбранный элемент
    }
}


int main() {
    int k = 10;
    randomize();
    for (;;) {
        if (k == 10) {
            printf("\nInput from 1 to 10 or 0 for actions:\n"
                 "0. Exit.\n"
                 "1. Generation list.\n"
                 "2. Print list.\n"
                 "3. Addition new item in begin of list.\n"
                 "4. Addition new item in end of list.\n"
                 "5. Erase list.\n"
                 "6. Deleting from list.\n"
                 "7. Lenght of list.\n"
                 "8. Inserting in list.\n"
                 "9. Main Action. \n"
                 "10. Menu.\n");
        }
        else if (!k) {
            break;
        }
        else if (k == 1) {
            int n;
            printf("\nInput number of new items of list: n=");
            scanf("%d", &n);
            genList(n);
        }
        else if (k == 2) {
            printList();
        }
        else if (k == 3) {
            item m;
            printf("\nInput value of adding item: m=");
            scanf("%d", &m);
            addFirst(m);
        }
        else if (k == 4) {
            item m;
            printf("\nInput value of adding item: m=");
            scanf("%d", &m);
            add(m);
        }
        else if (k == 5) {
            erase();
        }
        else if (k == 6) {
            if (!tail) {
                printf("\nList is empty!\n");
            }
            else {
                printf("\nInput value of deleting item: m=");
                item m;
                scanf("%d", &m);
                deleting(m);
            }
        }
        else if (k == 7) {
            int n = 0;
            if (head) {
                n = sizeList();
            }
            printf("\nLenght of list=%d\n", n);
        }
        else if (k == 8) {
            if (!tail) {
                printf("\nList is empty!\n");
            }
            else {
                int m1, m2;
                printf("\nInput value inserting item: m1=");
                scanf("%d", &m1);
                printf("\nInput value item after which to insert: m2=");
                scanf("%d", &m2);
                insert(m1, m2);
            }
        }
        else if (k == 9) {
            if (!tail) {
                printf("\nList is empty!\n");
            }
            else {
                item m;
                printf("\nSelect the item that will remain in the list: m=");
                scanf("%d", &m);
                action(m);
            }
        }
        else {
            printf("Have no such number of MENU\n");
        }
        printf("\nInput number of MENU: k=");
        scanf("%d", &k);
    }
    return 0;
}