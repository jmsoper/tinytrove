#include <stdio.h>
#include <string.h>

struct Task {
  char name[21];
  int score;
};

void writeEntry(struct Task * task, FILE *file){
  fprintf(file, "%s %d\n", task->name, task->score);
}

void collectEntries(struct Task * task, char * filename){
  char answer[1];
  FILE *pFile;

  pFile = fopen(filename, "a");
  while(strcmp(answer, "n")!=0){
    printf("Name: ");
    scanf("%s", task->name);
    printf("Score: ");
    scanf("%d", &task->score);
    writeEntry(task, pFile);
    printf("Would you like to add another task? [y/n]?");
    scanf("%s", answer);
  }
  fclose(pFile);
}

int readEntry(struct Task * task, FILE *file){
  if(fscanf(file, "%s %d\n", task->name, &task->score)==EOF){
    return 0;
  } else {
    return 1;
  } 
}

int findEntryByName(struct Task * task, FILE *file, char * name){
  // first open the file
  // read through the file checking entries and comparing them.
  // either you go all the way through and reach EOF
  // or you will find the entry!
  // if you don't find it, signify so.
  // if you *do* find it, signify so you can...break the loop?
  // we need a "check entry" function to simplify this. maybe.
  // if you *do* find an entry, *leave it* so that we have the attributes of the found item. print it out.
}

/*
  we also need a function that writes all the items in memory into storage.
  we also need a function that reads everything in storage into memory...I think
  that way we can just manipulate what we have in memory
  ANY TIME that we modify memory, we modify storage and vice versa. KEEP IT UP TO DATE.
  this should allow us to: delete, edit, add. 
*/

/*
  of course we also need to print!
  we'll get there.
*/

void readAllEntries(struct Task * task, char * filename){
  FILE *pFile;
  pFile = fopen(filename, "r");  

  while (readEntry(task, pFile)){
    printf("%s %d\n", task->name, task->score);
    // Can we pass a reference to a function to call here?
  }
}

struct Task * readToMemory(char * filename, struct Task * allTasks){
  /*
  read through the entire database and copy it to memory.
  can we pass a reference to a function in C?
  */
  struct Task task; 
  FILE *pFile;
  pFile = fopen(filename, "r");
  int i = 0;
  while (readEntry(&task, pFile)){
    allTasks[i] = task;
    i++;
    //So we increment i for as long as we have more tasks getting added.
    //Who knows, there might be a better way (like "push" or something.)
  }  
  fclose(pFile);
  return allTasks;
}

void readAllFromMemory(struct Task * allTasks){
  //how do we know when we reach the end of an array? 
  //read until you reach the end of the array.
}

void updateStorage(){
  //read from memory into storage.
}

void updateMemory(){
  //read from storage to memory.
}

void editEntry(){
 /*
  take an appropriate identifier for an entry
  go through memory utnil you find the matching entry (what if it's multiple?)
  edit the entry in memory? 
  write this to storage. 
  alternately...write to a file, reading line by line, *until* you run over the current one and then put in the new version.
  */
}

void deleteEntry(){
  //same as above, but just omit it. --> memory will be a lil more nuanced (w indices)
}

// all of this will be accomplished with text commands, which is a pain in the ass.
// we can do better -- with ncurses!!

int main(int argc, char *argv[]){
  char *filename="data.txt";
  struct Task task;
  char command[10];
  char * help="To add a task or tasks, type in 'add.' To read entries, type in 'read'. To end the program, type in 'exit'.\n";
  struct Task allTasks[100]; //Max number of tasks = 100. Maybe non-sequential storage?

  //first, we read the data into memory.
  readToMemory(filename, allTasks);   
  readAllFromMemory(all);
  printf("%s", help);
  do {
    scanf("%s", command);
    if (strcmp(command, "read")==0){
      readAllEntries(&task, filename);
    } else if (strcmp(command, "add")==0){
      collectEntries(&task, filename);
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
