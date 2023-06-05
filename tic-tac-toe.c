#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void readUserName( char* user_name, int user_number ) 
{
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

void printBoard(int rows, int columns, char board[rows][columns])
{
  printf("\n   1   2   3 \n");

  for (int i = 0; i < rows; i++)
  {
    printf("%d ", i+1);
    for (int j = 0; j < columns; j++)
    {
      if(j == (columns - 1)){
        printf(" %c ", board[i][j]);
      }
      else
      {
        printf(" %c |", board[i][j]);
      }
      
      
    }
    if(i == (rows - 1))
    {
      printf("\n\n");
    }
    else
    {
      printf("\n  ---|---|---\n");
    }
  }
}

void playTurn( int rows, int columns, char board[rows][columns], int user1_turn, char* username )
{
  int x_coord = -1;
  int y_coord = -1;
  int scanf_success = -1;
  int turn_success = -1;

  while (turn_success < 0)
  {
    while (scanf_success <= 0)
    {
      printf("%s, please enter your x-coordinate: ", username);
      scanf_success = scanf("%d", &x_coord);

      if (scanf_success <= 0)
      {
        printf("There was a problem reading your x-coordinate. Please try again.\n");
      }
      else if (x_coord < 0 || x_coord > columns)
      {
        printf("Please enter a number between 1 and %d.\n", columns);
        scanf_success = -1;
      }
    }

    scanf_success = -1;

    while (scanf_success <= 0)
    {
      printf("%s, please enter your y-coordinate: ", username);
      scanf_success = scanf("%d", &y_coord);

      if (scanf_success <= 0)
      {
        printf("There was a problem reading your y-coordinate. Please try again\n");
      }
      else if (y_coord < 0 || y_coord > rows)
      {
        printf("Please enter a number between 1 and %d.\n", rows);
        scanf_success = -1;
      }
    }

    if (board[y_coord - 1][x_coord - 1] != '-')
    {
      printf("This space has been played. Please try again.\n");
    }
    else if(user1_turn == 1)
    {
      board[y_coord - 1][x_coord - 1] = 'X';
      turn_success = 1;
    }
    else
    {
      board[y_coord - 1][x_coord - 1] = 'O';
      turn_success = 1;
    }
  }
}

void checkWin( int rows, int columns, char board[rows][columns], int* user1_turn, char* username )
{
  // *user1_turn = -1;
}

int main()
{
  const int ROWS = 3;
  const int COLUMNS = 3;

  char *user_name_1 = malloc( sizeof( char ) * 50 );
  char *user_name_2 = malloc( sizeof( char ) * 50 );

  char board[ROWS][COLUMNS];

  int user1_turn = -1;

  generateBoard(ROWS, COLUMNS, board);

  printf("Welcome to Tic-Tac-Toe!\n");
  
  readUserName(user_name_1, 1);
  readUserName(user_name_2, 2);

  srand(time(0));
  user1_turn = (rand() % 2);

  if (user1_turn == 1)
  {
    printf("Player 1 (%s) gets to go first!\n", user_name_1);
  }
  else{
    printf("Player 2 (%s) gets to go first!\n", user_name_2);
  }

  while(user1_turn >= 0)
  {

    printBoard(ROWS, COLUMNS, board);

    if(user1_turn == 1) {
      playTurn( ROWS, COLUMNS, board, user1_turn, user_name_1);
      checkWin( ROWS, COLUMNS, board, &user1_turn, user_name_1);
      user1_turn = 0;
    }
    else {
      playTurn( ROWS, COLUMNS, board, user1_turn, user_name_2);
      checkWin( ROWS, COLUMNS, board, &user1_turn, user_name_2); 
      user1_turn = 1;
    }
  }
  

  

  free(user_name_1);
  free(user_name_2);
  return(0);
}