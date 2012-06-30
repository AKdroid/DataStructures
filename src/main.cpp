#include<iostream>
#include<stddef.h>
#include<basicsort.h>
#include<trees/BST.h>
/*
 * main.cpp
 *
 *  Created on: May 30, 2012
 *      Author: akhil
 */


using namespace std;
int main()
{
	int number[]={12,11,10,9,15,14,13,8,7,6,5,4,3,2,1,0};
        BST *root=NULL,*parent=NULL;
        root=construct(number,16,root);
        removeData(12,&root);
        display_reverseinorder(root);
        cout<<"print"<<endl;
        int numb[]={2,5,3,7,8,6,1,4};
        quicksort(numb,8);
        for(int j=0;j<8;j++)
            cout<<numb[j]<<endl;
        return 0;
		
}



