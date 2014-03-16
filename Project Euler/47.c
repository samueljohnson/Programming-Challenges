/*
 * 47.c
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
 * Still a work in progress.
 */

// Program to print all prime factors
# include <stdio.h>
# include <math.h>

int first[100];
int second[100];
int idx=0;
int isecond=0;

// A function to print all prime factors of a given number n
void primeFactors(int n,int array[100])
{
	int i;
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        //printf("%d ", 2);
        array[idx++]=2;
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            //printf("%d ", i);
            array[idx++]=i;
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (n > 2){
        //printf ("%d ", n);
        array[idx++]=n;
	}
	array[idx]='\0';
	idx=0;
}

int main()
{
    int i,j,x,y,counter1=0,counter2=0,value;
    primeFactors(2334530,first);
    for(i=0;first[i]!='\0';i++)
		printf("%d ",first[i]);
	printf("\n\n");	
	primeFactors(58080*5*3*3,second);
    for(i=0;second[i]!='\0';i++)
		printf("%d ",second[i]);
	
	i=0,j=0;
	while(second[i]!='\0'){
		if(second[i]==second[i+1]){
			//printf("\nBoth are equal\n");
			second[j]=second[j]*second[i+1];
			i++;
			//continue;
		}
		else{
			second[++j]=second[++i];
		}
	}
	second[j]='\0';
	printf("\n\n");
	for(i=0;second[i]!='\0';i++)
		printf("%d ",second[i]);
		
    return 0;
    
    for(i=1;;i++){
		j=i+1;
		primeFactors(i,first);
		primeFactors(j,second);
		
	}
    
    return 0;
}
