//
//  main.cpp
//  PAT-A1137(1)
//
//  Created by 雨含香 on 2019/11/30.
//  Copyright © 2019 雨含香. All rights reserved.
// 1137 Final Grading (25 分)另一种写法
//map,数据结构的构造

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
unordered_map<string, int> mp;

struct person{
    string id;
    int gp,gm,gf,g;
};

vector<person> v,ans;

int main(int argc, const char * argv[]) {
    int p,m,n;
    cin>>p>>m>>n;
    int idx=1;
    string id;
    int score;
    while(p--){
        cin>>id>>score;
        if(score>=200){
            v.push_back(person{id,score,-1,-1,0});
            mp[id]=idx++;
        }
    }
    while(m--){
        cin>>id>>score;
        if(mp[id]!=0){
            v[mp[id]-1].gm=score;
        }
    }
    while(n--){
        cin>>id>>score;
        if(mp[id]!=0){
            v[mp[id]-1].gf=v[mp[id]-1].g=score;
            if(v[mp[id]-1].gm>v[mp[id]-1].gf){
                v[mp[id]-1].g=(int)round(v[mp[id]-1].gm*0.4+score*0.6);
            }
        }
        
    }
    for(int i=0;i<v.size();i++){
        if(v[i].g>=60){
            ans.push_back(v[i]);
        }
    }
    sort(ans.begin(),ans.end(),[](person p1,person p2){
        return p1.g!=p2.g ? p1.g>p2.g : p1.id<p2.id;
    });
    for(int i=0;i<ans.size();i++){
        printf("%s %d %d %d %d\n",ans[i].id.c_str(),ans[i].gp,ans[i].gm,ans[i].gf,ans[i].g);
    }
    return 0;
}
