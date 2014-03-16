/*
 * 48.c
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
 * Compile with gcc 48.c -o 48 -lgmp
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
 
int main(void)
{
 int i;
 mpz_t z;
 mpz_t sum;
 mpz_init(z);
 mpz_init(sum);
 mpz_set_str(sum, "0", 10);
 for(i=1;i<=1000;i++){
	mpz_ui_pow_ui(z,i,i);
	mpz_add(sum,sum,z);	
 }
 gmp_printf("The sum is %Zd\n",sum);
 mpz_clear(z);
 mpz_clear(sum);
 return EXIT_SUCCESS;
}
