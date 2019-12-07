//
//  main.cpp
//  PAT-A1139
//
//  Created by 雨含香 on 2019/11/30.
//  Copyright © 2019 雨含香. All rights reserved.
// 1139 First Contact (30 分)
// map，数据结构的使用，图，格式化

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
unordered_map<string, vector<string>> mp;
unordered_map<string, bool> tell;

struct friends{
    int f1,f2;
};

int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    while(m--){
        string a,b;
        cin>>a>>b;
        if(a.length()==b.length()){
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        tell[a+b]=tell[b+a]=true;
    }
    int num;
    cin>>num;
    while(num--){
        string love1,love2;
        cin>>love1>>love2;
        vector<friends> list;
        for(auto it1:mp[love1]){
            if(it1!=love2){
                for(auto it2:mp[love2]){
                    if(it2!=love1){
                        if(tell[it1+it2]==true){
                            list.push_back(friends{abs(stoi(it1)), abs(stoi(it2))});
                        }
                    }
                }
            }
        }
        sort(list.begin(),list.end(), [](friends a, friends b){
            if(a.f1!=b.f1){
                return a.f1<b.f1;
            } else {
                return a.f2<b.f2;
            }
        });
        printf("%d\n", list.size());
        for(int i=0;i<list.size();i++){
            printf("%04d %04d\n", list[i].f1,list[i].f2);
        }
    }
    return 0;
}
