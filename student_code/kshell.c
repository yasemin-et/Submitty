#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<time.h>

void getTime(int *year, int *month, int *day, int *hour, int *minute, int *second) {
  // get current time
  time_t current_time;
  time(&current_time);

  // break down current time into components
  struct tm* local_time = localtime(&current_time);

  // extract components into separate variables
  *year = local_time->tm_year + 1900; // Years since 1900
  *month = local_time->tm_mon + 1;    // Month (0 - 11)
  *day = local_time->tm_mday;         // Day of the month (1 - 31)
  *hour = local_time->tm_hour;        // Hour (0 - 23)
  *minute = local_time->tm_min;       // Minute (0 - 59) 
  *second = local_time->tm_sec;       // Second (0 - 59)
}

bool execute(char* command, char* history) {
  if (strcmp(command, "exit") == 0) 
  {
    return false; // quits program
  }
  else if (strcmp(command, "time") == 0) 
  {
    int year, month, day, hour, minute, second;
    getTime(&year, &month, &day, &hour, &minute, &second);
    printf("Current Time: %02d:%02d:%02d\n", hour, minute, second);
  }
  else if (strcmp(command, "date") == 0) 
  {
    int year, month, day, hour, minute, second;
    getTime(&year, &month, &day, &hour, &minute, &second); 
    printf("Current Date: %02d/%02d/%d\n", month, day, year);
  }
  else if (strcmp(command, "echo") == 0)
  {
    printf("%s\n", command); 
  }
  else if (strcmp(command, "history") == 0)
  {
    printf("%s\n", history); 
  }
  return true; 
}

int main()
{
  bool will_continue = true;
  char* history = (char*)malloc(1); // initial allocation for an empty string 
  history[0] = '\0'; 
  size_t history_length; 

  char command[100]; // accepts max 99 chars

  printf("Welcome to my simple_shell.");
  while (will_continue) {
    printf("Commands: time, date, echo, history, exit.\n");
    scanf("%99s", command);

    // add command to our list
    history_length = strlen(history);
    history = (char*)realloc(history, history_length + strlen(command) + 2); // +2 for command and space 
    strcat(history, command); 
    strcat(history, " "); 
     
    // execute command
    will_continue = execute(command, history);
  }

  // free dynamically allocated memory
  free(history); 

  return 0; 
}
