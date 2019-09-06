//
//  main.cpp
//  PAT-B1001
//
//  Created by 雨含香 on 2019/9/5.
//  Copyright © 2019 雨含香. All rights reserved.
//

#include <iostream>
#include <cstdio>

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    int count=0;
    while(n!=1){
        if(n%2){
            n = (3*n+1)/2;
        } else {
            n/=2;
            
        }
        count++;
    }
    printf("%d", count);
    return 0;
}
