#include <stdio.h>
#include <string.h>

struct Student {
  char name[21];
  int score;
};

void writeEntry(struct Student * student, FILE *file){
  fprintf(file, "%s %d\n", student->name, student->score);
}

int main(int argc, char *argv[]){
  FILE *pFile;
  char name[21];
  int score;
  char answer[1];
  struct Student student;

  // Open the file 
  pFile = fopen("database.txt", "a");

  if (pFile != NULL){
    while(strcmp(answer, "n")!=0){
      printf("Name: ");
      scanf("%s", name);
      printf("Test score: ");
      scanf("%d", &score);
      strcpy(student.name, name);
      student.score = score;

      //Store this information in the database
      writeEntry(&student, pFile); 
      printf("Are there any more students [y/n]?");
      scanf("%s", answer);
    }
    fclose(pFile);
  } else {
    printf("Could not open the file.\n");
  }

  return 0;
}
