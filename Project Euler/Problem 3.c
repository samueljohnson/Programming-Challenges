/*
 * Problem 3.c
 * 
 * Copyright 2012 Samuel Johnson <esamueljohnson@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


/* Program to find the largest prime factor of a number.
 * Problem 3 of projecteuler.net
 * 
 */

#include<stdio.h>

int main () {
  int i, lfactor=1;
  long n;
  printf("Enter a number to find its largest prime factor : ");
  scanf("%ld",&n);
  for(i=2;i<=n;i++) {
    if(!(n%i)) {
      lfactor=i;
      n=n/i;
      i--;
    }
  }
  printf("Largest prime factor is %d \n",lfactor);
  return 0;
}
