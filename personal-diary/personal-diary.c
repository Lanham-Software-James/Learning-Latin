#include<stdio.h>

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

int main()
{
  int main_control = 1;
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
          /* code */
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
}