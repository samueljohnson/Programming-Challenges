/*
 * Problem 14.c
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
 
 
/* 
 * There is still room for improvement
*/

#include<stdio.h>
unsigned long ite=0;

void even(unsigned long);

void odd (unsigned long o){
	ite++;
	o=3*o+1;
	even(o);
}

void even (unsigned long e){
	ite++;
	e/=2;
	if(e==1)
		return;
	else if(!(e%2))
		even(e);
	else
		odd(e);
}

int main(){
	unsigned long i,store[1000000],longest=0,number;
	for(i=2;i<1000000;i++){
		if(!(i%2)){
			ite=1;
			even(i);
			store[i]=ite;
		}
		else{
			ite=1;
			odd(i);
			store[i]=ite;
		}
		if(store[i]>longest){
			longest=store[i];
			number=i;
		}
	}
	printf("The number that produces the longest chain is %ld\n",number);
	return 0;
}
