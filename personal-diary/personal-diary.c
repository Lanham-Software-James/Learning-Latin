/*
**  This is another program to strengthen my understanding of C.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
 * WIP
 */
void addRecord()
{
  time_t rawtime;
  struct tm * timeinfo;
  int scanf_success = -1;
  char c;
  int n;
  char *firstname = malloc( sizeof(char) * 50);
  char *lastname = malloc( sizeof(char) * 50);
  char *password = malloc( sizeof(char) * 50);
  char *diary_entry = malloc( sizeof(char) * 1000);

  printf("\n*************************************\n");
  printf("*          ADD RECORD MENU          *\n");
  printf("*************************************\n\n");

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf("Current Date/Time is: %d %d %d %d:%d:%d\n", timeinfo->tm_mday,
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

  free(firstname);
  free(lastname);
  free(password);
  free(diary_entry);
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
          /* code */
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