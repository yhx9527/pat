//
//  main.cpp
//  PAT-B1019
//
//  Created by 雨含香 on 2019/9/30.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1019 数字黑洞

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a>b;
}
void num_to_arr(int n, int nums[]){
    for(int i=0;i<4;i++){
        nums[i]=n%10;
        n/=10;
    }
}
int arr_to_num(int nums[]){
    int temp=0;
    for(int i=0;i<4;i++){
        temp=nums[i]+temp*10;
    }
    return temp;
}

int main(int argc, const char * argv[]) {
    int nums[4]={0};
    int num,min,max;
    scanf("%d", &num);
    
    while(true){
        num_to_arr(num, nums);
        sort(nums,nums+4);
        min=arr_to_num(nums);
        sort(nums, nums+4, cmp);
        max=arr_to_num(nums);
        
        num=max-min;
        printf("%04d - %04d = %04d\n", max, min, num);
        if(num==0 || num==6174) break;
    }
    
    
    
    return 0;
}
