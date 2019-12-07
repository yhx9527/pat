//
//  main.cpp
//  PAT-A1152
//
//  Created by 雨含香 on 2019/11/12.
//  Copyright © 2019 雨含香. All rights reserved.
// 字符中数字提取，素数判断

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if(n<=1) return false;
    int sqr = (int)sqrt(1.0*n);
    for(int i=2;i<=sqr;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int l,k;
    string s;
    cin >> l>>k>>s;
    for(int i=0;i<=l-k;i++){
        string t = s.substr(i,k);
        int m = stoi(t);
        if(isPrime(m)){
            cout << m;
            return 0;
        }
    }
    cout << 404;
    return 0;
}
