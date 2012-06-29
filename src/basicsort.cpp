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

void merge(int *arrayleft,int*arrayright,int length1,int length2){
    int i=0,j=0,array[length1+length2],k,m;
    
    //Main merge algorithm
    
    for(k=0;i<length1&&j<length2;k++){
        if(arrayleft[i]<=arrayright[j])
        {
            array[k]=arrayleft[i++];
        }
        else{
            array[k]=arrayright[j++];
        }
    }
    for(;i<length1;i++,k++){
        array[k]=arrayleft[i];
        
    }
    for(;j<length2;j++,k++){
        array[k]=arrayright[j];      
    }
   
    //Copy the merged array into the original one
    k=0;
    for(i=0;i<length1;i++,k++){
        arrayleft[i]=array[k];
    }
    for(j=0;j<length2;j++,k++){
        arrayright[j]=array[k];
    }
   
}
void mergesort(int *array,int length){
   
    if(length==2){
        if(array[0]>array[1])
        {
            int temp=array[0];
            array[0]=array[1];
            array[1]=temp;
        }
        return;
    }
    else if(length<2)
        return;
    else
    {
        mergesort(array,length/2);
        mergesort(array+length/2,length-length/2);
        merge(array,array+length/2,length/2,length-length/2);
    }
}