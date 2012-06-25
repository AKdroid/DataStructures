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
	int number[]={1,2,3,4,5};
        linklist *first=NULL;
        IntegerList *list_first,*second;
        
        for(int m=0;m<5;m++){
        insert_Integer(number[m],m,&first);
        }
        list_first=getIntegerList(first);
        
        displayall(&first);
        
        displayall(&first);
        
        cout<<search_list(6,&first)<<endl;
        
        return 0;
		
}



