 /* Program to find the largest palindrome made from the product of two 3-digit numbers.
 * Problem 4 of projecteuler.net
 * 
 * 
 * Samuel Johnson <esamueljohnson@gmail.com>
 */

#include<stdio.h>

int is_palindrome (int n) {
  int reverse=0,original=n;
  while(n>0)
  {
      reverse *= 10;
      reverse += n%10;
      n /= 10;
  }
  if(reverse==original)
    return 1;
  else
    return 0;
}

int main () {
  int palindrome, lpalindrome=1, i, j;
  for(i=100;i<1000;i++) {
    for(j=i;j<1000;j++) {
      if(is_palindrome(i*j)){
	palindrome=i*j;
	if(palindrome>lpalindrome)
	  lpalindrome=palindrome;
      }
    }
  }
  printf("Largest palindrome is %d \n",lpalindrome);
  return 0;
}