//
//  main.cpp
//  PAT-A1144
//
//  Created by 雨含香 on 2019/11/24.
//  Copyright © 2019 雨含香. All rights reserved.
// 1144 The Missing Number (20 分)
//map映射

#include <iostream>
#include <map>
using namespace std;
map<int,int> mp;

int main(int argc, const char * argv[]) {
    int n,num=0;
    cin >> n;
    while(n--){
        int a;
        scanf("%d", &a);
        mp[a]++;
    }
    while(++num){
        if(mp[num]==0) break;
    }
    cout<<num;
    return 0;
}
