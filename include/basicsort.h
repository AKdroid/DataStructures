/*
 * basicsort.h
 *
 *  Created on: Jun 22, 2012
 *      Author: akhil
 */

#include<stdio.h>
#include<iostream>



#ifndef BASICSORT_H_
#define BASICSORT_H_

#define ASCENDING 0
#define DESCENDING 1
#define MAX_HEAP 0
#define MIN_HEAP 1
void swap(void *a,void *b);

void rotate(int dest,int source,int * array);

void selectionsort(int *array,int arraylength,int flag);

void bubblesort(int *array,int arraylength,int flag);

void insertionsort(int *array,int arraylength,int flag);

void merge(int*left,int*right,int length_left,int length_right);

void mergesort(int* array,int length);

void set_pivot(int *array,int length);

void quicksort(int *array,int length);

void buildheap(int *array,int length,int type);

void maxheapify(int *array,int length,int i);

void minheapify(int *array,int length,int i);

void heapsort(int *array,int length,int order);

int extract_min(int *array,int length);

int extract_max(int *array,int length);

int binary_search(int *array,int left,int right,int query,int direction);

int findvalue(int *array,int size,int query);


#endif /* BASICSORT_H_ */
