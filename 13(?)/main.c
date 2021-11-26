#include <stdio.h>
#include "Set.h"

int main(){
    char Vowels[] = "AEIOUYaeiouy";
    char Sv[N * 2];
    char Svo[N * 2]; //множество гласных для старого слова
    char Svn[N * 2]; //множество гласных для текущего слова
    for (int i = 0; i < 2 * N; i++){
        Svo[i] = 0;
        Svn[i] = 0;
    }
    char oldWord[20]; //старое слово
    char nowWord[20]; //текущее слово
    int i = 0;
    char c;
    CreateSet(Vowels, Sv);
    while (i != EOF){
        int counter = 0;
        for (int i = 0; i < 20; i++) nowWord[i] = 0;
        for (int i = 0; i < 2 * N; i++) Svn[i] = 0;
        i = getchar();
        c = i;
        if (Letter(c)){ //начало слова
            nowWord[counter++] = c;
            if (FindinSet(c, Sv)){
                InSet(c, Svn);
            }
            while(i != EOF && Letter(c)){ //до тех пор, пока текущий символ - это буква(до конца слова)
                i = getchar();
                c = i;
                if (Letter(c)){ 
                    nowWord[counter++] = c;
                    if (FindinSet(c, Sv)){
                        //printf("%c \n", c);
                        InSet(c, Svn);
                    }
                }
            }
        }
        if (Letter(nowWord[0]) && Letter(oldWord[0])){ //проверка, что 2 соседних слова существуют
            char S_inter[N * 2];
            IntersSet(Svn, Svo, S_inter); //S_inter - пересечение множества гласных букв текущего слова и старого слова
            if (EmptySet(S_inter)){ //если оно пустое выписываем эти два слова
                for (int i = 0; i < 20; i++){
                    if (Letter(oldWord[i])){
                        printf("%c", oldWord[i]);
                    }
                    else {
                        break;
                    }
                }
                printf(" ");
                for (int i = 0; i < 20; i++){
                    if (Letter(nowWord[i])){
                        printf("%c", nowWord[i]);
                    }
                    else {
                        break;
                    }
                }
                printf("\n"); 
            }
        }
        for (int i = 0; i < 2 * N; i++){ //текущее множество гласных букв становится старым
            Svo[i] = Svn[i];
        }
        for (int i = 0; i < 20; i++){ //текущее слово становится старым
            oldWord[i] = nowWord[i];
        }
    }
    return 0;
}