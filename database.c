#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  FILE *pFile;
  char name[21];
  int score;
  char answer[1];

  // Open the file 
  pFile = fopen("database.txt", "a");

  if (pFile != NULL)
  {
    while(strcmp(answer, "n")!=0)
    {
      printf("Name: ");
      scanf("%s", name);
      printf("Test score: ");
      scanf("%d", &score);

      //Store this information in the database
      fprintf(pFile, "%s %d\n", name, score);
      printf("Are there any more students [y/n]?");
      scanf("%s", answer);
    }

    fclose(pFile);
  }
  else 
  {
    printf("Could not open the file.\n");
  }

  return 0;
}
