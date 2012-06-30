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

void swap(void *a,void *b);

void rotate(int dest,int source,int * array);

void selectionsort(int *array,int arraylength,int flag);

void bubblesort(int *array,int arraylength,int flag);

void insertionsort(int *array,int arraylength,int flag);

void merge(int*left,int*right,int length_left,int length_right);

void mergesort(int* array,int length);

void set_pivot(int *array,int length);

void quicksort(int *array,int length);

#endif /* BASICSORT_H_ */
