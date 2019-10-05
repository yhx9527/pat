//
//  main.cpp
//  PAT-B1040
//
//  Created by 雨含香 on 2019/9/25.
//  Copyright © 2019 雨含香. All rights reserved.
//有几个PAT

#include <iostream>
#include <cstdio>
#include <cstring>

const int MAX_N=100010;
const int MOD = 1000000007;
char str[MAX_N];
int left_num[MAX_N]={0};

int main(int argc, const char * argv[]) {
    fgets(str, MAX_N, stdin); //*
    int len=strlen(str)-1;
    
    int right_num=0;
    int count=0;
    if(str[0]=='P') left_num[0]=1;
    for(int i=1;i<len;i++){
        if(str[i]=='P'){
            left_num[i]=left_num[i-1]+1;
        } else {
            left_num[i]=left_num[i-1];
        }
    }
    for(int i=len-1;i>=0;i--){
        if(str[i]=='T'){
            right_num++;
        }else if(str[i]=='A'){
            count=(count + left_num[i]*right_num)%MOD; //*
        }
    }
    printf("%d", count);
    return 0;
}
