#include<iostream>
#include<stddef.h>
#include<basicsort.h>
#include<linkedlist/linklist_head.h>
#include<linkedlist/linklist_sample.h>
/*
 * main.cpp
 *
 *  Created on: May 30, 2012
 *      Author: akhil
 */


using namespace std;
int main()
{
	int number[]={15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
        mergesort(number,16);
        for(int i=0;i<16;i++){
            cout<<number[i]<<endl;
        }
        return 0;
		
}



