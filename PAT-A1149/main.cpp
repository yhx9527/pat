//
//  main.cpp
//  PAT-A1149
//
//  Created by 雨含香 on 2019/11/21.
//  Copyright © 2019 雨含香. All rights reserved.
//1149 Dangerous Goods Packaging (25 分)
//哈希表，map

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int num,k;
    cin >> num >>k;
    map<int, vector<int>> mp;
    while(num--){
        int a,b;
        scanf("%d %d",&a, &b);
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    while(k--){
        int count;
        int a[100000]={0};
        
        scanf("%d", &count);
        vector<int> v(count);
        while(count--){
            int adr;
            scanf("%d", &adr);
            a[adr]=1;
            v.push_back(adr);
        }
        bool flag=false;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<mp[v[i]].size();j++){
                if(a[mp[v[i]][j]]==1) flag=true;
            }
        }
        printf("%s\n", flag ? "No": "Yes");
    }
    return 0;
}
