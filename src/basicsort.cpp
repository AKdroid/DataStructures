/*
 * basicsort.cpp
 *
 *  Created on: Jun 22, 2012
 *      Author: akhil
 */

#include<basicsort.h>

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void rotate(int dest,int source,int * array){
	int j=0;
	int temp=array[source];
	for(j=source;j>dest;j--){
		array[j]=array[j-1];
	}
	array[dest]=temp;
}

void selectionsort(int *array,int arraylength,int flag){

	int i,j;

	for(i=0;i<arraylength-1;i++){
		for(j=i+1;j<arraylength;j++){

			if(flag==ASCENDING){

				if(array[i]>array[j]){
					swap(&array[i],&array[j]);
				}

			}
			else if(flag==DESCENDING){

				if(array[i]<array[j]){
					swap(&array[i],&array[j]);
				}

			}

		}
	}

}

void bubblesort(int *array,int arraylength,int flag){
	int i,j;
	for(i=arraylength-1;i>=0;i--){
		for(j=0;j<i-1;j++){
			if((array[j]>array[j+1]&&flag==ASCENDING) || (array[j]<array[j+1]&&flag==DESCENDING) ){
				swap(&array[i],&array[j]);
			}
		}
	}
}

void insertionsort(int *array,int arraylength,int flag){
	for(int i=0;i<arraylength-1;i++){
		for(int j=i+1;j<arraylength;j++){
			if((array[i]>array[j]&&flag==ASCENDING)||(array[i]<array[j]&&flag==DESCENDING)){
				rotate(i,j,array);
			}
		}
	}
}


