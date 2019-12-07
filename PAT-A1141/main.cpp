//
//  main.cpp
//  PAT-A1141
//
//  Created by 雨含香 on 2019/11/29.
//  Copyright © 2019 雨含香. All rights reserved.
// 1141 PAT Ranking of Institutions (25 分)
//map使用，条件筛选排序，字符串操作

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

struct test{
    string school;
    int tws,ns;
};
unordered_map<string, double> tws;
unordered_map<string, int> ns;
vector<test> pe;
bool cmp(test t1, test t2){
    if(t1.tws!=t2.tws){
        return t1.tws>t2.tws;
    } else if(t1.ns!=t2.ns){
        return t1.ns<t2.ns;
    } else {
        return t1.school<t2.school;
    }
};
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    while(n--){
        string id, school;
        double price;
        cin>>id;
        scanf("%lf", &price);
        cin>>school;
        for(int i=0;i<school.size();i++){
            school[i]=tolower(school[i]);
        }
        if(id[0]=='B'){
            price=price/1.5;
        } else if(id[0]=='T'){
            price=price*1.5;
        }
        tws[school]+=price;
        ns[school]+=1;
    }
    for(auto it:tws){
        pe.push_back(test{it.first,(int)it.second, ns[it.first]});
    }
    sort(pe.begin(),pe.end(),cmp);
    cout << pe.size()<<endl;
    int rank=0,pre=-1;
    for(int i=0;i<pe.size();i++){
        if(pe[i].tws!=pre) rank=i+1;
        pre=pe[i].tws;
        printf("%d %s %d %d\n", rank, pe[i].school.c_str(), pe[i].tws, pe[i].ns);
    }
    return 0;
}
