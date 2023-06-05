#include <stdio.h>

void printBoard(char *board[])
{
  for (int i = 0; i < 3; i++)
  {
    printf("%s\n", *(board+i));
  }
  
}

int main()
{
  char row[] = {'-', '-', '-'};
  char *board[] = {row, row, row};

  printf("Welcome to Tic-Tac-Toe!\n");

  printBoard(board);

  return(0);
}