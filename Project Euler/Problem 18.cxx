/*
 * Problem 18.cxx
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
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define digits 14
char *binary (unsigned int v) {
static char binstr[17] ;
int i;

binstr[digits] = '\0' ;
for (i=0; i<digits; i++) {
binstr[digits-1-i] = v & 1 ? '1' : '0' ;
v = v / 2 ;
}

return binstr;
}

int main(int argc, char **argv)
{
	int i,j,cl=0,ite=0,nextnumber,n;
	char num[3],line[100];
	unsigned long int sum=0,greatest=0;
	FILE *in=fopen("./Problem 18.txt","r");
	fgets(line,10,in);
	sum=atoi(line);
	for(i=0;i<pow(2,digits);i++){
		strcpy(num,binary(i));
		for(j=0;j<digits;j++){
			n=num[j];
			n-=48;
			if(n==0){
				fgets(line,100,in);
				nextnumber=line[cl+0]-48;
				nextnumber*=10;
				nextnumber+=line[cl+1]-48;
				sum+=nextnumber;
			}
			else{
				fgets(line,100,in);
				cl+=3;
				nextnumber=line[cl+0]-48;
				nextnumber*=10;
				nextnumber+=line[cl+1]-48;	
				sum+=nextnumber;
			}
		}
		if(sum>greatest)
			greatest=sum;
		printf("Sum is %ld\n",sum);
		ite++;
		sum=75;
		rewind(in);
		cl=0;
		fgets(line,10,in);
		nextnumber=0;
		printf("\n");
	}
	printf("\nGreatest sum is %ld",greatest);
	return 0;
}
