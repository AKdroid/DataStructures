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

//Heap functions

void buildheap(int *array,int length,int type){
    int i;
    for(i=(length+1)/2;i>0;i--){
        if(type==MAX_HEAP){
            maxheapify(array,length,i);
        }
        else if(type==MIN_HEAP){
            minheapify(array,length,i);
        }
    }
}

void maxheapify(int * array,int length,int i){
    int r,l,largest,temp;
    l=2*i;
    r=2*i+1;
    if(l-1<length && array[l-1]>array[i-1]){
        largest=l-1;
    }
    else
        largest=i-1;
    if(r-1<length && array[r-1]>array[largest]){
        largest=r-1;
    }
    if(i!=largest+1){
        temp=array[i-1];
        array[i-1]=array[largest];
        array[largest]=temp;
        maxheapify(array,length,largest+1);
    }
}
void minheapify(int * array,int length,int i){
    int r,l,smallest,temp;
    l=2*i;
    r=2*i+1;
    if(l-1<length && array[l-1]<array[i-1]){
        smallest=l-1;
    }
    else
        smallest=i-1;
    if(r-1<length && array[r-1]<array[smallest]){
        smallest=r-1;
    }
    if(i!=smallest+1){
        temp=array[i-1];
        array[i-1]=array[smallest];
        array[smallest]=temp;
        minheapify(array,length,smallest+1);
    }
}
void heapsort(int *array,int length,int order){
    while(length>0){
        if(order==ASCENDING){
            buildheap(array,length,MIN_HEAP);
            array=array+1;
            length--;
        }
        else if(order==DESCENDING){
            buildheap(array,length,MAX_HEAP);
            array=array+1;
            length--;
        }
    }
}

int extract_min(int *array,int length){
    buildheap(array,length,MIN_HEAP);
    return array[0];
}

int extract_max(int *array,int length){
    buildheap(array,length,MAX_HEAP);
    return array[0];
}
int binarysearch(int* array,int left,int right,int query,int direction){
    int mid,pos=-1;
    while(left<=right){
            mid=left+(right-left)/2;
            if(array[mid]==query){
                pos=mid;
                if(direction==0)break;
            }
            if(array[mid]<query+(direction>0?direction:0)){
                left=mid+1;
            }else{
                right=mid-1;
            }
                
                
    }
    return pos;
    
}
int findvalue(int *array,int size,int query){
    int p;
    int left=0;
    int right=size-1;
    p=binarysearch(array,left,right,query,-1);
    if(p>=0){
        return binarysearch(array,left,right,query,1)-p+1;
    }
    return 0;
}

