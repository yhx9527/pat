//
//  main.cpp
//  PAT-A1136
//
//  Created by 雨含香 on 2019/11/30.
//  Copyright © 2019 雨含香. All rights reserved.
// 1136 A Delayed Palindrome
// 大数加法操作实现

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool ispal(string s){
    string t=s;
    reverse(t.begin(), t.end());
    return s==t;
};

int main(int argc, const char * argv[]) {
    string str,res,temp;
    cin>>str;
    res=str;
    int num=10;
    while(!ispal(str)&&num--){
        string temp=str;
        res.clear();
        reverse(temp.begin(), temp.end());
        int ad=0;
        for(int i=0;i<str.size();i++){
            int x=stoi(str.substr(i,1))+stoi(temp.substr(i,1))+ad;
            res+=to_string(x%10);
            ad=x/10;
        }
        if(ad>0){
            res+=to_string(ad);
        }
        reverse(res.begin(), res.end());
        cout<<str<<" + "<<temp<<" = "<<res<<endl;
        str=res;

    }
    if(num>=0&&ispal(str)){
        cout<<res<<" is a palindromic number.";
    } else {
        cout<<"Not found in 10 iterations.";
    }
    return 0;
}
