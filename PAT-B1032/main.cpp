//
//  main.cpp
//  PAT-B1032
//
//  Created by 雨含香 on 2019/9/5.
//  Copyright © 2019 雨含香. All rights reserved.
//

#include <iostream>
#include <cstdio>

int main(int argc, const char * argv[]) {
    int num;
    scanf("%d", &num);
    int arr[100010]={0};
    for(int i=0;i<num;i++){
        int index;
        int score;
        scanf("%d %d", &index, &score);
        arr[index]+=score;
    }
    int max=arr[1];
    int index=1;
    for(int j=2;j<num+1;j++){
        if(arr[j]>max){
            max=arr[j];
            index=j;
        }
    }
    printf("%d %d", index, arr[index]);
    return 0;
}
