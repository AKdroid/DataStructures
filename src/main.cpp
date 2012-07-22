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
  int numbers[]={3,5,2,7,9,1,6,0},length=8;
  printf("\nascending\n");
  heapsort(numbers,length,ASCENDING);
  for(int i=0;i<length;i++){
      printf("%d\t",numbers[i]);
  }
  printf("\ndescending\n");
  heapsort(numbers,length,DESCENDING);
  for(int i=0;i<length;i++){
      printf("%d\t",numbers[i]);
  }
  
 return 0;		
}



