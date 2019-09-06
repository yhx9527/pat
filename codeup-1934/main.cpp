//
//  main.cpp
//  codeup-1934
//
//  Created by 雨含香 on 2019/9/5.
//  Copyright © 2019 雨含香. All rights reserved.
//

#include <iostream>
#include <cstdio>
const int max = 205;
int a[max]={};
int main(int argc, const char * argv[]) {
    int len, target;
    while(scanf("%d", &len) != EOF){
        for(int i=0;i<len;i++){
            scanf("%d", &a[i]);
        }
        int index=-1;
        scanf("%d", &target);
        for(int j=0;j<len;j++) {
            if(a[j]==target){
                index=j;
                break;
            }
        }
        printf("%d\n", index);
    }
    return 0;
}
