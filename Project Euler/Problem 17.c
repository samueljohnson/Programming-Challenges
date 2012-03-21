/*
 * Problem 17.c
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
 
#include <stdio.h>
#include <string.h>
#include "NumToText.h"

int calcsum(int);
char* itoa(int,int);

int main(){
	char only_number[100];
    char outputString[2048];
    int sum=0,n;
    int i;
    for(i=1;i<=1000;i++){
		n=calcsum(i);
		sum+=n;
	}
    printf("\n%d\n",sum);
	return 0;
}

int calcsum(int n){
	int i,sum=0;
    char outputString[2048];
	char *only_number=itoa(n,10);
    NumberToText(only_number, outputString);
    for(i=0;outputString[i]!='\0';i++){
		if(outputString[i]==' ')
			continue;
		sum+=1;
	}
	if(n>99 && (only_number[strlen(only_number)-1]!='0' || only_number[strlen(only_number)-2]!='0'))
		sum+=3;
	printf("%s-> %d\n",outputString,sum);
    return(sum);
}

char* itoa(int val, int base){
	static char buf[32] = {0};
	int i = 30;
	for(; val && i ; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];
	return &buf[i+1];
}
