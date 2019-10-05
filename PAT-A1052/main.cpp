//
//  main.cpp
//  PAT-A1052
//
//  Created by 雨含香 on 2019/10/3.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1052 Linked List Sorting

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=100010;
struct node {
    int address;
    int next;
    int key;
    bool flag;
} arr[maxn];
bool cmp(node a, node b){
    if(a.flag&&b.flag){
        return a.key<b.key;
    } else {
        return a.flag>b.flag;  //有效的放前面，无效放后面
    }
    
}
int main(int argc, const char * argv[]) {
    int num, ad, count=0;
    scanf("%d %d", &num, &ad);
    for(int i=0;i<num;i++){
        int address, key, next;
        scanf("%d %d %d", &address, &key, &next);
        arr[address].address=address;
        arr[address].key=key;
        arr[address].next=next;
    }
    for(int p=ad;p!=-1;p=arr[p].next){
        arr[p].flag = true;
        count++;
    }
    if(count==0){
        printf("0 -1"); //特判
    }else {
        sort(arr, arr+maxn, cmp);
        printf("%d %05d\n", count, arr[0].address); //地址格式化需注意
        for(int i=0;i<count;i++){
            if(i<count-1)
                printf("%05d %d %05d\n", arr[i].address, arr[i].key, arr[i+1].address);
            else
                printf("%05d %d -1", arr[count-1].address, arr[count-1].key);
        }
    }
    
    
    return 0;
}
