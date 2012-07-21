#include<iostream>
#include<stddef.h>
#include<basicsort.h>
#include<trees/BST.h>
/*
 * main.cpp
 *
 *  Created on: May 30, 2012
 *      Author: akhil
 */


using namespace std;
int main()
{
    int order=0;
	int numbers[10000];
        int sorted[10000];
        int length=0;
        long long sum=0;
        BST *root=NULL,*parent=NULL;
        FILE *fp=fopen("//home//akhil//python//Median.txt","r");
        cout<<fp;
        if(fp != NULL){
        fscanf(fp,"%d",&numbers[length]);
           length++;
        root=construct(numbers,1,root);
        sum=numbers[0];
        int median;
        for(int n=1;n<10000;n++){
           fscanf(fp,"%d",&numbers[length]);
           insertData(numbers[length],root);
           if(length%2==0){
               order=length/2;
           }else{
               order=(length-1)/2;
           }
           resetcount();
           display_order_statistic(root,order,&median);
           sum=sum+median;
           length++;
        }
        fclose(fp);
        }
        for(int i=0;i<5;i++)
            cout<<numbers[i]<<endl;
        printf("\nsum=%d",sum);
        return 0;
		
}



