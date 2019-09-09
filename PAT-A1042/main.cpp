//
//  main.cpp
//  PAT-A1042
//
//  Created by 雨含香 on 2019/9/8.
//  Copyright © 2019 雨含香. All rights reserved.
//
//Shuffling Machine
//使用两个数组来操作
#include <iostream>
#include <cstdio>

const int CARDNUM=54;
int main(int argc, const char * argv[]) {
    int num;
    scanf("%d", &num);
    getchar();
    int indexs[CARDNUM]={};
    int end[CARDNUM]={};
    for(int i=0;i<CARDNUM;i++){
        scanf("%d", &indexs[i]);
    }
    char map[5]={'S','H','C','D','J'};
    int start[CARDNUM]={0};
    for(int i=0;i<CARDNUM;i++){
        start[i]=i;
    }
    while(num--){
        for(int i=0;i<CARDNUM;i++){
            end[indexs[i]-1]=start[i];
        }
        for(int i=0;i<CARDNUM;i++){
            start[i]=end[i];
        }
    }
    for(int i=0;i<CARDNUM;i++){
        printf("%c%d", map[start[i]/13], start[i]%13+1);
        if(i<CARDNUM-1){
            printf(" ");
        }
    }
    return 0;
}
