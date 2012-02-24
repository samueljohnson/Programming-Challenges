/* There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 * 
 * Problem 9 of projecteuler.net
 * 
 * add '-lm' option to gcc
 * 
 * Samuel Johnson <esamueljohnson@gmail.com>
 */

#include<stdio.h>
#include<math.h>

int is_perfect_sq(int n) {
  float sq = sqrt(n);
  if(sq == (int) sq)
    return 1;
  else
    return 0;  
}

int main () {
  int a, b, c;
  for(a=1;a<999;a++) {
    for(b=a;b<999;b++) {
      if(is_perfect_sq(a*a + b*b)) {
	c=sqrt(a*a + b*b);
	if(a+b+c == 1000)
	  printf("abc is %d\n",a*b*c);
      }
    }
  }
  return 0;
}