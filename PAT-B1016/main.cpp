//
//  main.cpp
//  PAT-B1016
//
//  Created by 雨含香 on 2019/9/6.
//  Copyright © 2019 雨含香. All rights reserved.
////
//1016 部分A+B

#include <iostream>
#include <cstdio>
#include <cmath>


int main(int argc, const char * argv[]) {
    int a,da,b,db, pa=0, pb=0;
    scanf("%d %d %d %d", &a, &da, &b, &db);
    while(a) {
        if(a%10==da){
            pa = pa*10+da;
        }
        a/=10;
    }
    while(b) {
        if(b%10==db){
            pb = pb*10+db;
        }
        b/=10;
    }
    printf("%d", pa+pb);
    return 0;
}
