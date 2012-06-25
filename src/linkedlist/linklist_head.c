#include<linkedlist/linklist_head.h>

linklist * createnode(){
    linklist*nw= (linklist *)malloc(sizeof(linklist)); 
    nw->next=NULL;
    nw->prev=NULL;
    return nw;
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

int insert( linklist **first,int position,linklist* node){
    int i;
    linklist *nw;
    if(position>count(first)){
        return -1;
    }
    else if(position == 0){
        //node=createnode();
        node->prev=NULL;
        node->next=*first;
        *first=node;
    }
    else{
        nw=*first;
        for(i=0;i<position-1;i++){
            nw=nw->next;
            
        } 
        node->next=nw->next;
        node->prev=nw;
        if(nw->next!=NULL)
        nw->next->prev=node;
        nw->next=node;
    }
    return 0;
}

int detachnode (linklist **first,int position){
    int i;
    linklist *now,*temp;
    if(position>=count(first))
        return -1;
    else if(position==0){
        now=*first;
        now->next->prev=NULL;
        first=&now->next;
    }
    else{
        now=*first;
        for(i=0;i<position-1;i++){
            now=now->next;
        }
       
        temp=now->next;
        now->next=temp->next;
        temp->next->prev=now;
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
    *first=temp;
}
