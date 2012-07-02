 /* Program to find the smallest positive number that is evenly divisible by all of the numbers from 1 to 20.
 * Problem 5 of projecteuler.net
 * 
 * 
 * Samuel Johnson <esamueljohnson@gmail.com>
 */

#include<stdio.h>

int main () {
  unsigned int i=2, check,checked=0;
  while(i++) {
    for(check=20;check>=2;check--) {
      if(i%check)
	break;
      else
	checked++;
    }
    if(checked==19)
      break;
    checked=0;
  }
  printf("The smallest number is %d\n",i);
  return 0;
}
