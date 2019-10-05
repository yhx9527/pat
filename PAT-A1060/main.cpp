//
//  main.cpp
//  PAT-A1060
//
//  Created by 雨含香 on 2019/10/2.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1060 Are They Equal (25 分)

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int n;
//将字符串先进行格式化
string deal(string s, int& e){
    //去除前导0
    while(s.length()>0&&s[0]=='0'){
        s.erase(s.begin());
    }
    if(s[0]=='.'){
       s.erase(s.begin());
       while(s.length()>0&&s[0]=='0'){
            s.erase(s.begin());
            e--;
        }
    } else {
        int pos=s.find(".");
        if(pos==s.string::npos){
            e=s.size();
        } else {
            e=pos;
            s.erase(pos,1);
        }
    }
    int len = s.size();
    if(len==0) e=0;
    if(n<len){
        s.erase(n, len-n);
    } else {
        while(len++ < n){
           s+='0';
        }
    }
    
    return s;
}

int main(int argc, const char * argv[]) {
    string s1, s2, s3, s4;
    int e1=0,e2=0;
    cin>>n>>s1>>s2;
    s3=deal(s1, e1);
    s4=deal(s2, e2);
    
    if(s3==s4&&e1==e2){
        cout<<"YES "<<"0."<<s3<<"*10^"<<e1;
    } else {
        cout<<"NO "<<"0."<<s3<<"*10^"<<e1<<" "<<"0."<<s4<<"*10^"<<e2;
    }
    
    
    return 0;
}
