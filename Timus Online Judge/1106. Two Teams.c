/*
 * 1106. Two Teams.c
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

The group of people consists of N members. Every member has one or more friends in the group.
You are to write program that divides this group into two teams.
Every member of each team must have friends in another team.

Input

The first line of input contains the only number N (N ≤ 100).
Members are numbered from 1 to N. The second, the third,…and the (N+1)th line contain list of friends of the first, the second, …and the Nth member respectively.
This list is finished by zero. Remember that friendship is always mutual in this group.

Output

The first line of output should contain the number of people in the first team or zero if it is impossible to divide people into two teams.
If the solution exists you should write the list of the first group into the second line of output.
Numbers should be divided by single space. If there are more than one solution you may find any of them. 

Time Limit: 1.0 second
Memory Limit: 16 MB

 * 
 * 
 */

#include<stdio.h>

int search(int n,int a[]){
	int i,found=0;
	for(i=0;a[i]!=0;i++){
		if(n==a[i])
			found=1;
	}
	return found;
}
int array[100][100];
int main(){
	char c;
	FILE *in=fopen("/home/kavya/Programming/Timepass/Timus Online Judge/input","r");
	//FILE *out=fopen("/home/kavya/Programming/Timepass/Timus Online Judge/output","w");
	//int n=fgetc(in),i,j;
	int i,j,n;
	fscanf(in, "%d", &n);
	//n=n-48;
	//printf("%d\n\n",n);
	int ga[n],gb[n],a=0,b=0;
	for(i=0;i<n;i++)
		ga[i]=0,gb[i]=0;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			array[i][j]=0;
	i=1;
	fgetc(in);
	while((c=fgetc(in))!=EOF){
		j=0;
		while((c-48)!=0){
			array[i][j]=c-48;
			j++;
			fgetc(in);
			c=fgetc(in);
		}
		i++;
		fgetc(in);
	}
	int founda=0,foundb=0;
	j=1;
	for(i=1;i<=n;i++){
		founda=search(i,ga);
		foundb=search(i,gb);
		if(founda){
			continue;
		}
		else if(foundb){
			continue;
		}
		else{
			ga[a++]=i;
			for(j=0;array[i][j]!=0;j++){
				if(gb[b-1]!=array[i][j])
					gb[b++]=array[i][j];
			}
		}
		founda=0,foundb=0;
	}
	n=0;
	for(i=0;ga[i]!=0;i++)
		n++;
	printf("%d\n",n);
	if(n){
		for(i=0;ga[i]!=0;i++){
			printf("%d ",ga[i]);
		}
	}
	return 0;
}
