#include <stdio.h>
#include <string.h>

struct Student {
  char name[21];
  int score;
};

void writeEntry(struct Student * student, FILE *file){
  fprintf(file, "%s %d\n", student->name, student->score);
}

void collectEntries(struct Student * student, char * filename){
  char answer[1];
  FILE *pFile;

  pFile = fopen(filename, "a");
  while(strcmp(answer, "n")!=0){
    printf("Name: ");
    scanf("%s", student->name);
    printf("Score: ");
    scanf("%d", &student->score);
    writeEntry(student, pFile);
    printf("Would you like to add another student? [y/n]?");
    scanf("%s", answer);
  }
  fclose(pFile);
}

int main(int argc, char *argv[]){
  char *filename="data.txt";
  char name[21];
  int score;
  char answer[1];
  struct Student student;

  collectEntries(&student, filename);

  return 0;
}
