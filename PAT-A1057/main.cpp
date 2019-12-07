//
//  main.cpp
//  PAT-A1057
//
//  Created by 雨含香 on 2019/10/14.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1057 Stack
#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

const int maxn = 100010;
int number[maxn]={0};
stack<int> mystack;
int block[maxn]={0};

int main(int argc, const char * argv[]) {
    int num, key;
    scanf("%d", &num);
    int size = floor(sqrt(1.0*num));
    int amount = ceil(sqrt(1.0*num));
//    string str;
    char str[20];
    while(num--){
//        cin>>str;
        scanf("%s", str);
        if(strcmp(str,"Push")==0){
            scanf("%d", &key);
            mystack.push(key);
            number[key]++;
            block[key/amount]++;
        }else if(strcmp(str,"Pop")==0){
            if(!mystack.empty()){
                int key = mystack.top();
                printf("%d\n", key);
                mystack.pop();
                number[key]--;
                block[key/amount]--;
            }else {
                printf("Invalid\n");
            }
         }else if(strcmp(str,"PeekMedian")==0){
            if(mystack.empty()){
                printf("Invalid\n");
            } else {
                int total = mystack.size(), N;
                if(total&1){
                    N = (total+1)/2;
                } else {
                    N = total/2;
                }
                int index=0;
                for(int i=0;i<size;i++){
                    if(N>block[i]){
                        N-=block[i];
                        index+=amount;
                    }else{
                        break;
                    }
                }
                int value;
                for(int j=index;j<maxn;j++){
                    if(N>0){
                        N-=number[j];
                    } else {
                        value = j;
                        break;
                    }
                }
                printf("%d\n", value-1);
            }
        }
    }
    return 0;
}
