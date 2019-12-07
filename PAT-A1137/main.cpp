//
//  main.cpp
//  PAT-A1137
//
//  Created by 雨含香 on 2019/11/30.
//  Copyright © 2019 雨含香. All rights reserved.
// 1137 Final Grading (25 分)


#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

unordered_map<string, int> gp;
unordered_map<string, int> gm;
unordered_map<string, int> gf;
struct person{
    string name;
    int gp,gm,gf,g;
};
vector<person> list;
int main(int argc, const char * argv[]) {
    int p,m,n;
    cin>>p>>m>>n;
    while(p--){
        string name;int grade;
        cin>>name>>grade;
        gp[name]=grade;
    }
    while(m--){
        string name;int grade;
        cin>>name>>grade;
        gm[name]=grade;
    }
    while(n--){
        string name;int grade;
        cin>>name>>grade;
        gf[name]=grade;
    }
    
    for(auto it:gp){
        double g=0;
        int p=it.second;
        int m=gm[it.first]>0?gm[it.first]:-1;
        int f=gf[it.first]>0?gf[it.first]:-1;
        if(m>f){
            g=((m==-1?0:m)*0.4+(f==-1?0:f)*0.6);
        }else if(f!=-1){
            g=f;
        }
        if(p>=200&&p<=900&&g>=60&&g<=100){
            list.push_back(person{it.first, p, m, f, (int)round(g)});
        }
    }
    sort(list.begin(), list.end(), [](person a1, person a2){
        if(a1.g!=a2.g){
            return a1.g>a2.g;
        } else {
            return a1.name<a2.name;
        }
    });
    for(int i=0;i<list.size();i++){
        printf("%s %d %d %d %d\n",list[i].name.c_str(), list[i].gp, list[i].gm,list[i].gf,list[i].g);
    }
    return 0;
}
