#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[])
{
  int lower_range;
  int upper_range;
  int guesses=0;
  int winning_number;
  char input[10];
  int guess;

  do
  {
    printf("Lower range: ");
    fgets(input, 10, stdin);
    lower_range = strtol(input,NULL,10);
  }while(lower_range==0);

  do
  {
    printf("Upper range: ");
    fgets(input, 10, stdin);
    upper_range = strtol(input,NULL,10);
  }while(upper_range==0);
  
  winning_number = rand() % upper_range + lower_range;

  while(1)
  {
    do
    {
      printf("Your guess pls: ");
      fgets(input, 10, stdin);
      guess = strtol(input,NULL,10);
    }while(guess==0);

    guesses++;
    if(guess == winning_number)
    {
      printf("You got it and it took only %d guesses!\n", guesses);
      break;
    }
    else if(guess > winning_number)
      printf("Lower..\n");
    else
      printf("Higher..\n");
  }


  return 0;
}
