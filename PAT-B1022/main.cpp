//
//  main.cpp
//  PAT-B1022
//
//  Created by 雨含香 on 2019/9/6.
//  Copyright © 2019 雨含香. All rights reserved.
//
//输入两个非负 10 进制整数 A 和 B (≤2^30−1)，输出 A+B 的 D (1<D≤10)进制数。
//
//输入格式：
//
//输入在一行中依次给出 3 个整数 A、B 和 D。
//
//输出格式：
//
//输出 A+B 的 D 进制数。
//
//输入样例：
//
//123 456 8
//输出样例：
//
//1103

#include <iostream>
#include <cstdio>

int main(int argc, const char * argv[]) {
    int a,b,scale;
    scanf("%d%d%d",&a,&b,&scale);
    int sum = a+b;
    int bit[40]={0};
    int num=0;
    do {
        bit[num] = sum%scale;
        num++;
        sum/=scale;
    }while(sum!=0);
    for(int i=num-1;i>=0;i--) {
        printf("%d", bit[i]);
    }
    return 0;
}
