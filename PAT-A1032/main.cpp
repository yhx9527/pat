//
//  main.cpp
//  PAT-A1032
//
//  Created by 雨含香 on 2019/10/3.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1032 Sharing
#include <iostream>
#include <cstdio>

const int maxn=100010;
struct Node{
    char data;
    int next;
    bool flag;
}arr[maxn];
int main(int argc, const char * argv[]) {
    int s1, s2, num;
    scanf("%d%d%d",&s1, &s2, &num);
    while(num--){
        int address, next;
        char data;
        scanf("%d %c %d",&address, &data, &next);
        arr[address].data = data;
        arr[address].next = next;
    }
    int pos;
    for(pos=s1;pos!=-1;pos=arr[pos].next){
        arr[pos].flag=true;
    }
    for(pos=s2;pos!=-1;pos=arr[pos].next){
        if(arr[pos].flag) break;
    }
    if(pos==-1){
        printf("-1");
    } else {
        printf("%05d", pos);
    }
    
    return 0;
}
