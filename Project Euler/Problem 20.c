/*
 * Problem 20.c
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
 * Compile with -lgmp
 */

#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>

int main()
{
	mpz_t x;
	size_t size;
	unsigned int sum=0, i, num;
	printf("The the number to find the factorial digit sum of : ");
	scanf("%u",&num);
	mpz_init(x);
	mpz_fac_ui(x,num);
	gmp_printf("\nThe factorial of %u is %Zd\n",num,x);
	size=mpz_sizeinbase(x,10);
	char string[size];
	mpz_get_str(string,10,x);
	mpz_clear (x);
	for(i=0;string[i]!='\0';i++)
		sum=sum+string[i]-48;
	printf("\nThe sum of all digits in 100! is %u\n",sum);
	return 0;
}
