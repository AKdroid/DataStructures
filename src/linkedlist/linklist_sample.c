#include<linkedlist/linklist_sample.h>


IntegerList* createIntegerNode(){
    return (IntegerList *)malloc(sizeof(IntegerList)); 
}

IntegerList* integerList(int number){
    IntegerList * integer;
    integer=createIntegerNode();
    integer->num=number;
    integer->node=*createnode();
    return integer;
}

IntegerList * getIntegerList(linklist *node_){
    if(node_==NULL)
        return NULL;
    int offset=offsetof(IntegerList,node);
    char *temp=(char *)node_;
    return (IntegerList *)(temp-offset);
}

IntegerList * insert_Integer(int number,int position,linklist **first){
    IntegerList* integer=integerList(number);
    int result=insert(first,position,&integer->node);
    if(result == 0){
        return integer;
    }
    else return NULL;
}

void remove_Integer(int position,linklist **first){
    linklist*temp=get(first,position);
    IntegerList* tempI;
    if(temp!=NULL){
        tempI=getIntegerList(temp);
        int result=removenode(first,position);
        if(result==0)
        free(tempI);
    }
}

IntegerList* get_Integer(linklist ** first,int position){
    linklist* temp=get(first,position);
    if(temp!=NULL)
        return getIntegerList(temp);
    else 
        return NULL;
}

IntegerList* getnextentry(IntegerList* curr){
    return getIntegerList(curr->node.next);
}
IntegerList* getpreventry(IntegerList* curr){
    return getIntegerList(curr->node.prev);
}

void sort_list(IntegerList * list_first){
    
}

int search_list(int number,linklist ** first){
    int pos=-1,cnt=-1;
    IntegerList * entry =getIntegerList(*first);
    while(entry!= NULL){
        pos++;
        if(entry->num==number){
            cnt=pos;
            break;
        }
        entry=getnextentry(entry);
    }
    return cnt;
}

void display(IntegerList *list_entry){
    printf("%d \n ",list_entry->num);
}
void displayall(linklist** first){
    int i;
    IntegerList*nw=getIntegerList(*first);
    for(i=0;i<count(first);i++){
        printf("%d\n",nw->num);
        nw=getnextentry(nw);
    }
}