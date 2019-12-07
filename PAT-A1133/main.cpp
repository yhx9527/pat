//
//  main.cpp
//  PAT-A1133
//
//  Created by 雨含香 on 2019/12/4.
//  Copyright © 2019 雨含香. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct node{
  int start, data,next;
};
node list[100010];
vector<node> v,ans;

int main(int argc, const char * argv[]) {
    int a,n,k;
    cin>>a>>n>>k;
    for(int i=0;i<n;i++){
        int s,b,e;
        scanf("%d%d%d", &s, &b, &e);
        list[s]={s,b,e};
    }
    for(int it=a;it!=-1;it=list[it].next){
        v.push_back(list[it]);
    }
    for(int i=0;i<v.size();i++){
        if(v[i].data<0) ans.push_back(v[i]);
    }
    for(int i=0;i<v.size();i++){
        if(v[i].data>=0&&v[i].data<=k) ans.push_back(v[i]);
    }
    for(int i=0;i<v.size();i++){
        if(v[i].data>k) ans.push_back(v[i]);
    }
    for(int i=0;i<ans.size()-1;i++){
        printf("%05d %d %05d\n", ans[i].start, ans[i].data, ans[i+1].start);
    }
    printf("%05d %d -1\n", ans[ans.size()-1].start, ans[ans.size()-1].data);
    return 0;
}
