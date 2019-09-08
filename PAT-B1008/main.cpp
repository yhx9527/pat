//
//  main.cpp
//  PAT-B1008
//
//  Created by 雨含香 on 2019/9/7.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1008 数组元素循环右移问题 (20 分)
#include <iostream>
#include <cstdio>
int main(int argc, const char * argv[]) {
    int arr[110];
    int n,m;
    scanf("%d%d", &n, &m);
    int count=0;
    m = m%n; //修正m，放置m>n的情况
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    for(int i=n-m;i<n;i++){
        printf("%d", arr[i]);
        count++;
        if(count < n){
            printf(" ");
        }
    }
    for(int i=0; i<n-m;i++){
        printf("%d", arr[i]);
        count++;
        if(count < n){
            printf(" ");
        }
    }
    
    return 0;
}


