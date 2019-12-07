//
//  main.cpp
//  PAT-A1132
//
//  Created by 雨含香 on 2019/12/3.
//  Copyright © 2019 雨含香. All rights reserved.
// 1132 Cut Integer (20 分)
//字符操作

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int a = stoi(s.substr(0, s.length()/2));
        int b = stoi(s.substr(s.length()/2, s.length()/2));
        if(a*b!=0&&stoi(s)%(a*b)==0){
            printf("Yes\n");
        }else {
            printf("No\n");
        }
    }
    return 0;
}
