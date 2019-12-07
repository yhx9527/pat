//
//  main.cpp
//  PAT-A1154
//
//  Created by 雨含香 on 2019/11/14.
//  Copyright © 2019 雨含香. All rights reserved.
// 集合，图的边与顶点

#include <iostream>
#include <set>
#include <vector>
using namespace std;
struct node{
    int t1,t2;
};

int main(int argc, const char * argv[]) {
    int d,e;
    cin >> d>>e;
    vector<node> edge(e);
    for(int i=0;i<e;i++){
        scanf("%d %d",&edge[i].t1, &edge[i].t2);
    }
    int k;
    cin>>k;
    while(k--){
        int a[10010];
        set<int> myset;
        bool flag=true;
        for(int i=0;i<d;i++){
            
            scanf("%d", &a[i]);
            myset.insert(a[i]);
        };
        for(int i=0;i<e;i++){
            if(a[edge[i].t1]==a[edge[i].t2]){
                flag=false;
                break;
            }
        }
        if(flag){
            printf("%d-coloring\n", myset.size());
        }else{
            printf("No\n");
        }
    }
    return 0;
}
