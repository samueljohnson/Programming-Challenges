/*
 * Random_Selection.cxx
 * 
 * The following program selects x entries from a list of y entries
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

using namespace std;

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime> 
#include <algorithm>

int main(int argc, char **argv)
{
	int total, select, collision;
	cout << "Enter the total number of elements: ";
	cin >> total;
	vector<int> numbers (total);
	cout << "Enter the number of items to be selected: ";
	cin >> select;
	vector<int> selection (select);
	if(select>total){
		cout << "Wrong selection";
		return -1;
	}
	for(unsigned int i=0;i<numbers.size();i++){
		numbers[i]=i+1;
	}
	cout << endl << "The selection list is " << endl << endl;
	srand (time(NULL));
	for(int i=0;i<select;i++){
		int temp=rand()%total+1;
		if(find(selection.begin(), selection.end(), temp) != selection.end()){
			i--, collision++;
			continue;
		}
		else
			selection[i]=temp;
	}
	sort(selection.begin(),selection.end());
	for(unsigned int i=0;i<selection.size();i++)
		cout << selection[i] << endl;
	cout << endl << "Collided " << collision << " times" << endl;
	return 0;
}
