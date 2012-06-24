#include<linkedlist/linklist_head.h>

linklist *createnode(){
    return (linklist *)malloc(sizeof(linklist)); 
}
void deletenode(linklist *node){
    free(node);
}


linklist * gotonext( linklist * current){
    return current->next;
}

linklist * gotoprevious(linklist * current){
    return current->prev;
}

int insert( linklist **first,int position){
    int i;
    linklist *node,*nw;
    if(position>count(first)){
        return -1;
    }
    else if(position == 0){
        node=createnode();
        node->prev=NULL;
        node->next=*first;
        first=&node;
    }
    else{
        nw=*first;
        for(i=0;i<position;i++){
            nw=nw->next;
        }
        nw=gotoprevious(nw);
        node=createnode();
        node->next=nw->next;
        node->prev=nw;
        nw->next->prev=node;
        nw->next=node;
    }
    return 0;
}

int removenode (linklist **first,int position){
    int i;
    linklist *now,*temp;
    if(position>=count(first))
        return -1;
    else if(position==0){
        now=*first;
        now->next->prev=NULL;
        first=&now->next;
        deletenode(now);
    }
    else{
        now=*first;
        for(i=0;i<position;i++){
            now=now->next;
        }
        now=gotoprevious(now);
        temp=now->next;
        now->next=temp->next;
        temp->next->prev=now;
        free(temp);
    } 
    return 0;    
}

linklist* get(linklist**first,int position){
    linklist *now=*first;
    int i;
    if(position>=count(first))
        return NULL;
    else
        for(i=0;i<position;i++)
            now=now->next;
    return now;
}

int count(linklist **first){
    int count=0;
    linklist *now=*first;
    while(now != NULL){
        count++;
        now=now->next;
    }
    return count;
}

void reverse(linklist ** first){
    linklist * now=*first,*temp;
    while(now!=NULL){
        temp=now;
        now=now->next;
        temp->next=temp->prev;
        temp->prev=now;
    }
    first=&temp;
}
void swap(linklist* one,linklist*two){
    linklist *temp_n,*temp_p;
    temp_n=one->next;
    temp_p=one->prev;
    
    one->next=two->next;
    one->prev=two->prev;
    
    two->next=temp_n;
    two->prev=temp_p;
} 