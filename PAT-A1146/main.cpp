//
//  main.cpp
//  PAT-A1146
//
//  Created by 雨含香 on 2019/11/26.
//  Copyright © 2019 雨含香. All rights reserved.
// 1146 Topological Order (25 分)
// 拓扑排序

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,m;
    cin >>n>>m;
    int point[1010]={0};
    vector<int> graph[n+1];
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        point[y]++;
    }
    int num;
    cin>>num;
    bool space=false;
    for(int j=0;j<num;j++){
        vector<int>p1(point,point+n+1);
        bool flag=true;
        for(int i=0;i<n;i++){
            int temp;
            scanf("%d", &temp);
            if(p1[temp]!=0){
                flag=false;
            }
            for(int x:graph[temp]){
                p1[x]--;
            }
        }
        if(flag==false){
            printf("%s%d", space ? " ": "", j);
            space=true;
        }
        
    }
    
    return 0;
}
