/*
 * Problem 12.c
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

int triangle(int i)
{
	return (i*(i+1))/2;
}

int *factors(int num)
{
	static int factor[500];
	int i,index=0;
	for(i=1;i<=num;i++)
	{
		if(num%i==0)
		{
			factor[index]=i;
			index++;
		}
	}
	return factor;
}

int main(int argc, char **argv)
{
	int i,num,*a,j,sum=0,largest=200;
	for(i=1;;i++)
	{
		num=triangle(i);
		a=factors(num);
		for(j=0;;j++)
		{
			sum+=1;
			if(*(a+j)==num)
			break;
		}
		printf("%d\n",i);
		if(sum>=largest)
		break;
		sum=0;
	}
	printf("\n\nThe largest number with %d factors is %d",largest,num);
	return 0;
}
