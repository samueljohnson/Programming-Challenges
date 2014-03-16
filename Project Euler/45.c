/*
 * 45.c
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
#include <gmp.h>
#include <time.h>

void triangle(mpz_t, mpz_t);
void pentagonal(mpz_t, mpz_t);
void hexagonal(mpz_t, mpz_t);
	
int main(int argc, char **argv)
{
	mpz_t i,j,k,n,num1,num2,num3,result;
	int count=0;
	mpz_init(i);
	mpz_init(j);
	mpz_init(k);
	mpz_init(num1);
	mpz_init(num2);
	mpz_init(num3);
	mpz_init(i);
	mpz_init(j);
	mpz_init(k);
	mpz_init(result);
	mpz_init(n);
	
	clock_t t;
	t = clock();
	for(mpz_set_ui(i,2);;mpz_add_ui(i,i,1)){
		mpz_set(n, i);
		hexagonal(num1,n);
		gmp_printf("Hexagonal of %Zd is %Zd\n",n,num1);
		for(mpz_set(j,i);mpz_cmp(num1,num2)>0;mpz_add_ui(j,j,1)){
			mpz_set(n,j);
			pentagonal(num2,n);
			//gmp_printf("Pentagonal of %Zd is %Zd\n",n,num2);
			if(!mpz_cmp(num1,num2)){
				//gmp_printf("T%Zd = P%Zd = %Zd\n",i,j,num1);
				for(mpz_set(k,i);mpz_cmp(num1,num3);mpz_add_ui(k,k,1)){
					mpz_set(n,k);
					triangle(num3,n);
					//gmp_printf("Triangle of %Zd is %Zd\n",n,num3);
					if(!mpz_cmp(num2,num3)){
						count++;
						//gmp_printf("T%Zd = P%Zd = H%Zd = %Zd\n",i,j,k,num3);
						if(count==2){
							t = clock() - t;
							double time_taken = ((double)t)/CLOCKS_PER_SEC;
							gmp_printf("\n T(%Zd) = P(%Zd) = H(%Zd) = %Zd\n",i,j,k,num3);
							printf("\nThe program took %f seconds to execute", time_taken);
							mpz_clear(i);
							mpz_clear(j);
							mpz_clear(k);
							mpz_clear(num1);
							mpz_clear(num2);
							mpz_clear(num3);
							mpz_clear(result);
							return 0;
						}
					}
				}
			}
		}
	}
}

void triangle(mpz_t result, mpz_t n){
	mpz_t add,mul,div;
	mpz_init(add);
	mpz_init(mul);
	mpz_init(div);
	mpz_add_ui(add,n,1);
	mpz_mul(mul,n,add);
	mpz_div_ui(div,mul,2);
	mpz_set(result, div);
	mpz_clear(add);
	mpz_clear(mul);
	mpz_clear(div);
}

void pentagonal(mpz_t result, mpz_t n){
	mpz_t sub,mul1,mul2,div;
	mpz_init(sub);
	mpz_init(mul1);
	mpz_init(mul2);
	mpz_init(div);
	mpz_mul_ui(mul1,n,3);
	mpz_sub_ui(sub,mul1,1);
	mpz_mul(mul2,n,sub);
	mpz_div_ui(div,mul2,2);
	mpz_set(result, div);
	mpz_clear(sub);
	mpz_clear(mul1);
	mpz_clear(mul2);
	mpz_clear(div);
}

void hexagonal(mpz_t result, mpz_t n){
	mpz_t sub,mul1,mul2;
	
	mpz_init(sub);
	mpz_init(mul1);
	mpz_init(mul2);
	
	mpz_mul_ui(mul1,n,2);
	mpz_sub_ui(sub,mul1,1);
	mpz_mul(mul2,n,sub);
	mpz_set(result, mul2);
	mpz_clear(sub);
	mpz_clear(mul1);
	mpz_clear(mul2);
}
