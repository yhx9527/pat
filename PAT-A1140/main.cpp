//
//  main.cpp
//  PAT-A1140
//
//  Created by 雨含香 on 2019/11/28.
//  Copyright © 2019 雨含香. All rights reserved.
// 1140 Look-and-say Sequence (20 分)
//循环，规则

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    int n, j;
    cin >> s>>n;
    while(--n){
        string t;
        for(int i=0;i<s.size();i=j){
            for(j=i;j<s.size()&&s[j]==s[i];j++);
            t+=s[i]+to_string(j-i);
        }
        s=t;
    }
    cout<<s;
    return 0;
}
