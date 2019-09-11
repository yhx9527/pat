//
//  main.cpp
//  PAT-B1010
//
//  Created by 雨含香 on 2019/9/11.
//  Copyright © 2019 雨含香. All rights reserved.
//
//一元多项式求导
//数组元素下标作为指数，元素值作为系数

#include <iostream>
#include <cstdio>

int main(int argc, const char * argv[]) {
    int arr[1010]={0};
    int k,v;
    while(scanf("%d %d",&k, &v)!=EOF){
        arr[v]=k;
    }
    int count=0;
    for(int i=1;i<=1000;i++){
        arr[i-1]=arr[i]*i;
        arr[i]=0;
        if(arr[i-1]!=0) count++;
    }
    if(count==0) printf("0 0");
    for(int i=1000;i>=0;i--){
        if(arr[i]!=0){
            printf("%d %d",arr[i],i);
            count--;
            if(count!=0){
                printf(" ");
            }
        }
    }
    return 0;
}
