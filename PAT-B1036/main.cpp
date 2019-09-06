//
//  main.cpp
//  PAT-B1036
//
//  Created by 雨含香 on 2019/9/5.
//  Copyright © 2019 雨含香. All rights reserved.
//

#include <iostream>
#include <cstdio>

int main(int argc, const char * argv[]) {
    int len,line;
    char c;
    scanf("%d %c", &len, &c);
    for(int i=0;i<len;i++){
        printf("%c", c);
    }
    if(len%2){
        line = len/2+1;
    }else{
        line = len/2;
    }
    for(int i=0;i<line-2;i++) {
        printf("\n");
        for(int j=0;j<len;j++){
            if(j==0)
                printf("%c", c);
            else if(j==len-1)
                printf("%c", c);
            else
                printf(" ");
        }
    }
    printf("\n");
    for(int i=0;i<len;i++){
        printf("%c", c);
    }
    return 0;
}
