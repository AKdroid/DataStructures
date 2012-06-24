#include<iostream>
#include<Sorter/basicsort.h>
/*
 * main.cpp
 *
 *  Created on: May 30, 2012
 *      Author: akhil
 */
using namespace std;
int main(){
		int numbers[]={1,2,3,4,5};
		insertionsort(numbers,5,DESCENDING);
		for(int i=0;i<5;i++)
		cout << numbers[i]<<endl;
}



