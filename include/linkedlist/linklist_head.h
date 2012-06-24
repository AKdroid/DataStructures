/* 
 * File:   linklist_head.h
 * Author: akhil
 * This file implements a basic doubly linked list and its allied functions 
 * Created on June 24, 2012, 7:03 PM
 */
#include<stdio.h>
#include<stdlib.h>


#ifndef LINKLIST_HEAD_H
#define	LINKLIST_HEAD_H

struct linklist_head{
    struct linklist_head *next;
    struct linklist_head *prev;
};

typedef struct linklist_head linklist;

//Memory Allocation-Deallocation
linklist * createnode();
void deletenode(linklist *);


//Traversing the list
linklist * gotonext( linklist * current);
linklist * gotoprevious( linklist * current);

//Basic functions

int  insert( linklist ** first,int position);
int  removenode( linklist ** first,int position);
linklist *get(linklist ** first,int position);

//Misc

int count( linklist ** first);
void reverse(linklist **first);         //reverse the whole list 
void swap(linklist* one,linklist* two); //can be used for sorting

/*
 * Application Note
 * 
 * Since a linked list is always used as a structure,the elements are offset statically
 * The structure that will contain linklist_head i.e. linklist as an element.
 * This offset can be retrieved using a macro defined in <stddef.h> :
 *   mystruct_pointer=  (struct mystruct *)(linklist_pointer -
 *                    offsetof(struct mystruct,mylinklist )); 
 *   
 */














#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LINKLIST_HEAD_H */

