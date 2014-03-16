/*
 * 46.c
 * 
 * Copyright 2014 Samuel Johnson <esamueljohnson@gmail.com>
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


#include <stdio.h>
#include <math.h>

int is_prime(int p) {
  int i;
  for(i=2;i<p;i++) {
    if(!(p%i)) {
      break;
    }
  }
  if(i==p)
    return 1;
  else
    return 0;
}

int main(int argc, char **argv)
{
	unsigned int i,j,k,temp,success=0;	
	for(i=9;;i=i+2){
		if(!is_prime(i)){
			for(j=3;j<i;j=j+2){
				if(is_prime(j)){
					k=(i-j)/2;
					temp=sqrt(k);
					if(temp*temp==k){
						success=1;
						//printf("%u follows GOC as %u = %u + 2x%u^2\n",i,i,j,temp);
						break;
					}
				}
			}
			if(!success){
				printf("%d breaks GOC\n",i);
				//return 0;
			}
			else{
				//printf("%d follows Goldbach's other conjecture\n",i);
			}
			success=0;
		}
		else
			continue;
	}
}

