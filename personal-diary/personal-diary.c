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
    printMainMenu();
    main_control = 0;
  }
  

}