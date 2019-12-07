//
//  main.cpp
//  PAT-A1153
//
//  Created by 雨含香 on 2019/11/13.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1153 Decode Registration Card of PAT
//字符串信息的获取，处理

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct node{
    int v;
    string key;
};


int main(int argc, const char * argv[]) {
    int k,l;
    cin>>k>>l;
    vector<node> list(k);
    for(int i=0;i<k;i++){
        cin >> list[i].key >> list[i].v;
    }
    for(int i=1;i<=l;i++){
        int num;
        string s;
        cin>>num>>s;
        printf("Case %d: %d %s\n", i, num, s.c_str());
        vector<node> ans;
        int count=0, sum=0;
        if(num==1){
            for(int i=0;i<k;i++){
                if(s[0]==list[i].key[0]) ans.push_back(list[i]);
            }
        } else if(num==2){
            for(int i=0;i<k;i++){
                if(s==list[i].key.substr(1,3)) {
                    count++;
                    sum+=list[i].v;
                }
            }
            if(count!=0)
                printf("%d %d\n", count, sum);
        } else if(num==3){
            unordered_map<string, int> mp;
            for(int i=0;i<k;i++){
                if(s==list[i].key.substr(4,6)){
                    mp[list[i].key.substr(1,3)]++;
                }
            }
            for(auto it:mp){
                ans.push_back({it.second, it.first});
            }
        }
        sort(ans.begin(), ans.end(), [](const node &a, const node &b){
            return a.v != b.v ? a.v>b.v : a.key < b.key;
        });
        for(auto it:ans){
            printf("%s %d\n", it.key.c_str(), it.v);
//            cout << it.key <<" " <<it.v <<endl;
        }
        if(((num==1 || num==3)&&ans.empty()) || (num==2&&count==0)) printf("NA\n");
    }
    return 0;
}
