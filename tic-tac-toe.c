#include <stdio.h>
#include <stdlib.h>

void generateBoard(int rows, int columns, char board[rows][columns])
{
  for (int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      board[i][j] = '-';
    }
  }
}

void readUserName( char* user_name, int user_number ) {
  int scanf_success = -1;

  while (scanf_success <= 0)
  {
    printf("Please enter player %i's username (max 50 char): ", user_number);
    scanf_success = scanf("%s", user_name);

    if (scanf_success <= 0)
    {
      printf("There was a problem reading your username. Please try again\n");
    }
    else 
    {
      printf("Your username is: %s\n", user_name);
    }
  }
} 

void printBoard( char *board, int rows, int columns )
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      printf(" %c ", *(board+i+j));
    }
    printf("\n");
  }
}

int main()
{
  const int ROWS = 3;
  const int COLUMNS = 3;

  char *user_name_1 = malloc( sizeof( char ) * 50 );
  char *user_name_2 = malloc( sizeof( char ) * 50 );

  char (*board)[ROWS] = malloc( sizeof( char[ROWS][COLUMNS] ));

  generateBoard(ROWS, COLUMNS, board);

  printf("Welcome to Tic-Tac-Toe!\n");
  
  readUserName(user_name_1, 1);
  readUserName(user_name_2, 2);

  
  

  printBoard(*board, ROWS, COLUMNS);
  return(0);
}