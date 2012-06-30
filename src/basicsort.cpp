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
void set_pivot(int *array,int length){
    /*
     * set pivot as the an element between the most smallest and most largest 
     * to avoid the worst case. Somewhat random in nature.
     */
    int great,less,median,med;
    median=(length-1)/2;
    
    if(array[0]<array[length-1]){
        great=length-1;
        less=0;
    }
    else
    {
        great=0;
        less=length-1;
    }
    if(array[great]<array[median]){
        med=great;
    }else if(array[less]>array[median]){
        med=less;
    }else med=median;
    
    swap(array,array+med);
    
}
void quicksort(int *array,int length){
    int i,j;
    // i = boundary marking less than pivot and greater than pivot
    // j = boundary marking partitioned and unpartitioned space
    
    if(length<=1)
        return;
    
    i=1;
    
    set_pivot(array,length);  //sets the pivot to improve the performance
    
    for(j=1;j<length;j++){              // Partition the array so that array contains three parts
        if(array[0]>array[j]){          // the pivot,the partition less than pivot
            swap(array+i,array+j);      // partition more than pivot
            i++;
        }
    }
    swap(array,array+i-1);              //put the pivot value in its proper sorted place.
    
    quicksort(array,i-1); //quicksort the values less than pivot
    
    quicksort(array+i,length-i); //quicksort the values greater than pivot
}