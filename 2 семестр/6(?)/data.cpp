#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {
  FILE *fi, *fo;
  if (argc != 3){
    printf("Вы должны задать 2 параметра: текстовый файл и выходной файл!");
    return 1;
  }
  if ((fi = fopen(argv[1], "r")) == NULL) {
    printf("Не получилось открыть: %s\n", argv[1]);
    return 1;
  }
  if ((fo = fopen(argv[2], "wb")) == NULL) {
    printf("Не получилось открыть: %s\n", argv[2]);
    return 1;
  }
  struct S { //создание структуры "базы данных"
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
  int l = sizeof(S); //длина структуры
  while (!feof(fi)) {
    fscanf(fi, "%s %s %s %d %d %d %d %d %d", &s.lastname, &s.fio, &s.gender, &s.num_school, &s.medal, &s.score1, &s.score2, &s.score3, &s.essay);
    //printf("%s %s %c %d %d %d %d\n", s.lastname, s.fio, s.gender, s.num_school, s.medal, s.score, s.essay);
    fwrite(&s, l, 1, fo); /* write struct s to file */
  }
  fclose(fi);
  fclose(fo);
  //Вывод записанной информации
  fi = fopen(argv[2], "rb");
  while (!feof(fi)) {
    s1 = s;
    fread(&s, l, 1, fi);
    if (strcmp(s.lastname, s1.lastname)) {
      printf("Фамилия=%s, ФИО=%s, Пол=%s, Номер школы=%d, Наличие медали=%d, Балл по 1 предмету=%d, Балл по 2 предмету=%d, Балл по 3 предмету=%d, Зачёт по сочинению=%d\n",s.lastname,
            s.fio, s.gender, s.num_school, s.medal, s.score1, s.score2, s.score3, s.essay);
    }
  }
  fclose(fi);
  return 0;
}