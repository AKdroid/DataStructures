/* 
 * File:   BST.h
 * Author: akhil
 * BST stands for Binary Search Tree.
 * Searches in O(log n) and sorts in O(n log n)
 * Created on June 29, 2012, 1:21 PM
 */
#include<stdio.h>
#include<stdlib.h>


#ifndef BST_H
#define	BST_H

struct BST{
    int data;
    struct BST *left;
    struct BST *right;
};

typedef struct BST BST; 

#ifdef	__cplusplus
extern "C" {
#endif
static int bst_cnt;
BST * createNode();
void deleteNode(BST *);

BST* insertData(int data_,BST * root);
int  removeData(int data_,BST ** root);

BST* search(int data_,BST * root,BST **parent);

void display_inorder(BST* root);
void resetcount();
void display_order_statistic(BST*root,int order,int *value);
void display_preorder(BST* root);
void display_postorder(BST* root);
void display_reverseinorder(BST *root);

BST* construct(int * array,int length,BST *root);

#ifdef	__cplusplus
}
#endif

#endif	/* BST_H */

