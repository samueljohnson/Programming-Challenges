/* In a country, couples continues to have children until they have a boy.
 * If they have a girl, they have another child. If they have a boy, they stop.
 * What is the proportion of boys to girls in that country?
 * 
 * Illustrates the use of Random Number Generation, Call by Reference and Recursion
 * 
 * Samuel Johnson <esamueljohnson@gmail.com>
 * 
*/ 


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void reproduce(int *boys, int *girls);

int main() {
  int couples,i,boys=0,girls=0;
  printf("Enter the number of couples : ");
  scanf("%d",&couples);
  time_t seconds;
  time(&seconds);
  srand((unsigned int) seconds);
  for(i=0;i<couples;i++)
    reproduce(&boys, &girls);
  printf("\nBoys are %d and Girls are %d (including couples)\n",boys+couples,girls+couples);
  exit(0);
}

void reproduce(int *b, int *g) {
  if(rand()%2)
    (*b)++;
  else {
    (*g)++;
    reproduce(b, g);
  }
}
