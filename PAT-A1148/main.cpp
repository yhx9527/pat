//
//  main.cpp
//  PAT-A1148
//
//  Created by 雨含香 on 2019/11/19.
//  Copyright © 2019 雨含香. All rights reserved.
// 1148 Werewolf - Simple Version
// 暴力枚举法

#include <iostream>
#include <vector>
#include<cmath>
using namespace std;


int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<int> speaker(n+1);
    
    for(int i=1;i<=n;i++){
        scanf("%d",&speaker[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            vector<int> human(n+1,1);
            vector<int> liar;
            human[i]=human[j]=-1;
            for(int x=1;x<=n;x++){
                if(speaker[x]*human[abs(speaker[x])]<0){
                    liar.push_back(x);
                }
            }
            if(liar.size()==2&&(human[liar[0]]+human[liar[1]]==0)){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    cout<<"No Solution";
    
    return 0;
}
