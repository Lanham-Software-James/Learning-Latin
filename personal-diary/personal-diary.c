/*
**  This is another program to strengthen my understanding of C.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/*
 *  Function to display the main menu to the user. 
 *  Put this in a function just to clean up main. Doesn't really need to be seperate.
 */
void printMainMenu() 
{
  printf("\n*************************************\n");
  printf("* PASSWORD PROTECTED PERSONAL DIARY *\n");
  printf("*************************************\n\n");
  printf("                MAIN MENU:\n\n");
  printf("ADD RECORD:                       [1]\n");
  printf("VIEW RECORD:                      [2]\n");
  printf("EDIT RECORD:                      [3]\n");
  printf("DELETE RECORD:                    [4]\n");
  printf("EDIT PASSWORD:                    [5]\n");
  printf("EXIT:                             [6]\n\n");
  printf("ENTER YOUR CHOICE: ");
}

/*
 * Function for adding a record.
 */
void addRecord()
{
  time_t rawtime;
  struct tm * timeinfo;
  int scanf_success = -1;
  char *firstname = malloc( sizeof(char) * 50);
  char *lastname = malloc( sizeof(char) * 50);
  char *password = malloc( sizeof(char) * 50);
  char *diary_entry = malloc( sizeof(char) * 1000);
  FILE *entry;
  char tmp[5] = "";
  struct stat st = {0};
  char entry_name[130] = "./entries/";
  
  //Print header
  printf("\n*************************************\n");
  printf("*          ADD RECORD MENU          *\n");
  printf("*************************************\n\n");

  //Getting current time.
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );

  //Printing current time.
  printf("Current Date/Time is: %d/%d/%d %d:%d:%d\n", timeinfo->tm_mday,
            timeinfo->tm_mon + 1, timeinfo->tm_year + 1900,
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

  //Loop controling first name input
  printf("Enter your first name: ");
  while (scanf(" %49[^\n]", firstname) < 1)
  {
    printf("\nThere was a problem. Please enter your first name: ");
  }

  //Loop controling last name input
  printf("Enter your last name: ");
  while (scanf(" %49[^\n]", lastname) < 1)
  { 
    printf("\nThere was a problem. Please enter your last name: ");
  }

  //Loop controling entry password
  printf("Enter your entry password: ");
  while (scanf(" %49[^\n]", password) < 1)
  { 
    printf("\nThere was a problem. Please enter diary entry: ");
  }

  //Loop controling Diary Entry
  printf("Enter your diary entry: ");
  while (scanf(" %999[^\n]", diary_entry) < 1)
  { 
    printf("\nThere was a problem. Please enter diary entry: ");
  }

  //Building file name
  sprintf(tmp, "%d", timeinfo->tm_mday);        //Day
  strcat(entry_name, tmp);
  strcat(entry_name, "-");

  sprintf(tmp, "%d", timeinfo->tm_mon + 1);     //Month
  strcat(entry_name, tmp);
  strcat(entry_name, "-");

  sprintf(tmp, "%d", timeinfo->tm_year + 1900); //Year
  strcat(entry_name, tmp);

  if (stat(entry_name, &st) == -1) {    //Check if date directory exists
      mkdir(entry_name, 0700);          //If not create directory
  }
  
  strcat(entry_name, "/");
  strcat(entry_name, firstname);              //Firstname
  strcat(entry_name, "-");

  strcat(entry_name, lastname);               //Lastname
  strcat(entry_name, "_");

  sprintf(tmp, "%d", timeinfo->tm_hour);        //Hour
  strcat(entry_name, tmp);
  strcat(entry_name, "-");

  sprintf(tmp, "%d", timeinfo->tm_min);        //Minute
  strcat(entry_name, tmp);
  strcat(entry_name, "-");

  sprintf(tmp, "%d", timeinfo->tm_sec);        //Second
  strcat(entry_name, tmp);

  entry = fopen(entry_name, "w");
  if (entry == NULL)
  {
    printf("Error opening file!\n");
    exit(1);
  }

  fprintf(entry, "Entry date:  %d/%d/%d %d:%d:%d\nAuthor First Name: %s\nAuthor Last Name: %s\nPassword: %s\nEntry: %s\n", 
            timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900,
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec,
            firstname, lastname, password, diary_entry);
  
  fclose(entry);

  free(firstname);
  free(lastname);
  free(password);
  free(diary_entry);
}

/*
 * Function for viewing an existing record.
 * WIP
 */
void viewRecord()
{
  //Print menu
  printf("\n*************************************\n");
  printf("*          VIEW RECORD MENU         *\n");
  printf("*************************************\n\n");
}

/*
 *  Big boy main.
 */
int main()
{
  int main_control = 1;
  //Main control loop
  while (main_control == 1)
  {
    int scanf_success = -1;
    
    //Loop controling main menu input
    while (scanf_success <= 0)
    {
      int user_choice = -1;
      char c;
      printMainMenu();
      scanf_success = scanf("%d", &user_choice);

      switch (user_choice)
      {
        case 1: //Add Record
          addRecord();
          break;
        
        case 2: //View Record
          viewRecord();
          break;

        case 3: //Edit Record
          /* code */
          break;

        case 4: //Delete Record
          /* code */
          break;

        case 5: //Change Record Password
          /* code */
          break;

        case 6: //Exit
          main_control = 0;
          printf("Goodbye!\n");
          break;

        default:
          scanf("%c", &c); //Need this to prevent infinite loop due to scanf
          printf("Please enter a valid choice (1-6)!");
          break;
      }
    }
  }

  return(0);
}