/*
 * Problem 13.c
 * 
 * Copyright 2011 Samuel Johnson <esamueljohnson@gmail.com>
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

int main(int argc, char **argv)
{
	FILE *fp=fopen("/home/kavya/Programming/Timepass/fifty","r");
	unsigned long int sum = 0,number=0;
	char c;
	while ((c = fgetc(fp)) != EOF)
	{
		if(c=='\n')
		{
			sum+=number;
			number=0;
			continue;
		}
		number=number*10;
		number+=(c-48);
	}
	printf("%ld",sum);
	return 0;
}

