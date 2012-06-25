/* 
 * File:   linklist_sample.h
 * Author: akhil
 * This file demonstrates the use of a doubly link list using linklist_head
 * and provides a basic integer type linklist 
 * Created on June 24, 2012, 10:45 PM
 */

#include<stdio.h>
#include<stddef.h>
#include<linkedlist/linklist_head.h>



#ifndef LINKLIST_SAMPLE_H
#define	LINKLIST_SAMPLE_H



#ifdef	__cplusplus
extern "C" {
#endif

struct IntegerList{
    int num;
    linklist node;
};

typedef struct IntegerList IntegerList;

IntegerList* createIntegerNode();

IntegerList * integerList( int number);

IntegerList * getIntegerList(linklist *);

IntegerList * insert_Integer(int number,int position,linklist **first);

void remove_Integer(int position,linklist **first);

IntegerList* get_Integer(linklist **first,int position);

IntegerList* getnextentry(IntegerList* curr);

IntegerList* getpreventry(IntegerList* curr);

void sort_list(IntegerList *);

int search_list(int number,linklist** first);    

void display(IntegerList *);

void displayall(linklist **first);
    
#ifdef	__cplusplus
}
#endif

#endif	/* LINKLIST_SAMPLE_H */

