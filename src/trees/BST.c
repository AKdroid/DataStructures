#include<trees/BST.h>

BST * createNode(){
    BST * node= (BST *)malloc(sizeof(BST));
    node->data=0;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void deleteNode(BST * node){
    free(node);
}



BST* insertData(int data_,BST * root){
    BST *node;
    
    if(root==NULL){
       node=createNode();
       node->data=data_;
       return node;
    }
    else{
        if(data_ <= root->data){
            root->left=insertData(data_,(root->left));
        }
        else{
            root->right=insertData(data_,(root->right));
        }
        return root;
    }
}

int removeData(int data_,BST **root){
    BST* parent=NULL,*succ=NULL;
    BST *node=search(data_,*root,&parent);
    if(node==NULL)
        return 0;
    else
    {
        if(node->left!=NULL&&node->right!=NULL){
            
            parent=node;
            succ=node->right;
            while(succ->left!=NULL){
                parent=succ;
                succ=succ->left;
            }
            printf("In double children\n");
            node->data=succ->data;
            node=succ;
        }
        
        if(node->left==NULL&&node->right==NULL){
            if(parent->left==node )
                parent->left=NULL;
            else 
                parent->right=NULL;
        }
        else if(node->left==NULL){
            if(parent->left==node )
                parent->left=node->right;
            else 
                parent->right=node->right;
        }
        else if(node->right==NULL){
            if(parent->left==node )
                parent->left=node->left;
            else 
                parent->right=node->left;
        }
       
        deleteNode(node);
        return 1;
    }
}

BST *search(int data_,BST *root,BST **parent){
    BST* node=NULL;
    *parent=NULL;
    if(root!=NULL){
        if(data_<root->data){
           node= search(data_,root->left,parent);
          
           if(root->left==node){
               *parent=root;
           }
        }
        else if(data_>root->data){
            node=search(data_,root->right,parent);
            if(root->right==node){
               *parent=root;
           }
        }
        else{
            return root;
        }
    }
    return node;
}

void display_inorder(BST *root){ //sort in ascending number
    if(root==NULL)
        return;

     display_inorder(root->left);
     
     printf("%d\n",root->data);      
     
     display_inorder(root->right);
    
}
void resetcount(){
    bst_cnt=0;
}
void display_order_statistic(BST *root,int order,int *value){ //sort in ascending number
    if(root==NULL)
        return;
     display_order_statistic(root->left,order,value);
     if(bst_cnt==order){
         *value=root->data;
         printf("\nmedian=%d , %d",bst_cnt,root->data); 
     }
     bst_cnt++;    
     display_order_statistic(root->right,order,value);
    
}
void display_preorder(BST *root){ 
    if(root==NULL)
        return;
     printf("%d\n",root->data);       
     
     display_preorder(root->left);
   
     display_preorder(root->right);
    
}

void display_postorder(BST *root){ 
    if(root==NULL)
        return;  
    display_postorder(root->left);
    display_postorder(root->right);
    
    printf("%d\n",root->data);  
    
    
}

void display_reverseinorder(BST *root){// sort in descending order
    if(root==NULL)
        return;  
   
    display_reverseinorder(root->right);
    
    printf("%d\n",root->data); 
    
    display_reverseinorder(root->left);
}
BST* construct(int * array,int length,BST * root){
    BST* rootnode;
    int i;
    if(length<=0)
        return NULL;
    rootnode=insertData(array[0],root);
    for(i=1;i<length;i++){
        insertData(array[i],rootnode);
    }
    return rootnode;
}