/*
 * Problem 15.c
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
 
// This is a brute force approach that won't work for n=20
// Actual solution is the answer of 40C20
// i.e. 137846528820
 
#include <stdio.h>
#include <unistd.h>

void ltree(int,int,int);
void rtree(int,int,int);
unsigned long long l=0;

int main(){
	int n=10,pid;
	//pid=fork();
	//if(!pid)
		//ltree(0,0,n);
	//else
		rtree(0,0,n);
	printf("The total number of possibilities for a %d x %d square is %lld\n",n,n,2*l);
	return 0;
}

void ltree(int x, int y, int n){
	if((x==n)&&(y==n)){
		l++;
		return;
	}
	if(x<n){
		x++;
		ltree(x,y,n);
		if(y<n)
			rtree(x,y,n);
	}
	else{
		return;
	}
}

void rtree(int x, int y, int n){
	if((x==n)&&(y==n)){
		l++;
		return;
	}
	if(y<n){
		y++;
		if(x<n)
			ltree(x,y,n);
		rtree(x,y,n);
	}
	else{
		return;
	}

}
