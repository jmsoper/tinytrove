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

int readEntry(struct Student * student, FILE *file){
  if(fscanf(file, "%s %d\n", student->name, &student->score)==EOF){
    return 0;
  } else {
    return 1;
  } 
}

void readAllEntries(struct Student * student, char * filename){
  FILE *pFile;
  pFile = fopen(filename, "r");  

  while (readEntry(student, pFile)){
    printf("%s %d\n", student->name, student->score);
  }
}

int main(int argc, char *argv[]){
  char *filename="data.txt";
  struct Student student;
  char command[10];
  char * help="To add a student or students, type in 'add.' To read entries, type in 'read'. To end the program, type in 'exit'.\n";

  printf("%s", help);
  do {
    scanf("%s", command);
    if (strcmp(command, "read")==0){
      readAllEntries(&student, filename);
    } else if (strcmp(command, "add")==0){
      collectEntries(&student, filename);
    } else if (strcmp(command, "exit")==0){
      printf("Exiting program.\n");
    } else if (strcmp(command, "help")==0){ 
      printf("%s", help);
    }else {
      printf("'%s' is not an available command. Type in 'help' to view available commands.\n", command);
    }
  } while(strcmp(command,"exit")!=0);

  return 0;
}
