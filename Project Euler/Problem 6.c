 /* Program to find the 10001st prime number.
 * Problem 6 of projecteuler.net
 * 
 * 
 * 
 * Samuel Johnson <esamueljohnson@gmail.com>
 */

#include<stdio.h>

int is_prime(int p) {
  int i;
  for(i=2;i<=p;i++) {
    if(!(p%i)) {
      break;
    }
  }
  if(i==p)
    return 1;
  else
    return 0;
}

int main () {
  int i=1,counter=0;
  while(i++) {
    if(is_prime(i)) {
      counter++;
    }
    if(counter==10001)
      break;
  }
  printf("The required prime is %d\n",i);
  return 0;
}
