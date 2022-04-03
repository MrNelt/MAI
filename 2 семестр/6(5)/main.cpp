#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {
  FILE *fi, *fo;
  if (argc != 2){
    printf("Вы должны задать 1 параметр: файл 'базы данных'");
    return 1;
  }
  if ((fi = fopen(argv[1], "rb")) == NULL){
        printf("Не получилось открыть: %s\n", argv[1]);
        return 1;
  }
  int l, r;
  printf("Введите через пробел 2 числа l и r -- границы баллов абитуриентов, которых Вы хотите найти\n");
  scanf("%d %d", &l, &r);
  struct S { //создание структуры  "базы данных"
    char lastname[20];
    char fio[20];
    char gender[20];
    int num_school;
    bool medal;
    int score1;
    int score2;
    int score3;
    bool essay;
  };
  S s; //создание переменной нашей структуры
  S s1;
  int len = sizeof(S); //длина структуры
  while (!feof(fi)) {
    s1 = s;
    fread(&s, len, 1, fi);
    if (strcmp(s.lastname, s1.lastname)) {
      int score = s.score1 + s.score2 + s.score3;
      char G[] = "Мужской";
      if (score >= l && score <= r && !strcmp(s.gender, G)) {
        printf("Фамилия=%s, ФИО=%s, Пол=%s, Номер школы=%d, Наличие медали=%d, Балл по 1 предмету=%d, Балл по 2 предмету=%d, Балл по 3 предмету=%d, Зачёт по сочинению=%d\n",s.lastname,
            s.fio, s.gender, s.num_school, s.medal, s.score1, s.score2, s.score3, s.essay);
      }
    }
  }
  fclose(fi);
  return 0;
}