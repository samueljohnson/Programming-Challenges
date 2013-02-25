/*
 * Problem 19m.c
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
int main(){
	int year=1901,day=2,sum=0;
	while(year<2001){
		day?:sum++,day=(day+31)%7;
		day?:sum++;
		if(year%4)
			day=(day+28)%7;
		else if(!(year%400))
			day=(day+28)%7;
		else
			day=((day+29)%7);
		day?:sum++,day=(day+31)%7;
		day?:sum++,day=(day+30)%7;
		day?:sum++,day=(day+31)%7;
		day?:sum++,day=(day+30)%7;
		day?:sum++,day=(day+31)%7;
		day?:sum++,day=(day+31)%7;
		day?:sum++,day=(day+30)%7;
		day?:sum++,day=(day+31)%7;
		day?:sum++,day=(day+30)%7;
		day?:sum++,day=(day+31)%7;
		year++;
	}
	printf("Sum is %d",sum);
	return 0;
}
