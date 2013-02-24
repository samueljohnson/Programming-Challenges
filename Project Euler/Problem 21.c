/*
 * Problem 21.c
 * 
 * Copyright 2013 Samuel Johnson <esamueljohnson@gmail.com>
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

int sopd(int num){
	int sum=1,i;
	for(i=2;i<=num/2;i++)
		if(!(num%i))
			sum+=i;
	return sum;
}

int main(){
	int i,sum=0;
	for(i=2;i<10000;i++)
		if(i==sopd(sopd(i))&&sopd(sopd(i))>sopd(i))
			sum+=sopd(sopd(i))+sopd(i);
	printf("The Sum of all amicable numbers less than 10000 is %d\n",sum);
	return 0;
}


