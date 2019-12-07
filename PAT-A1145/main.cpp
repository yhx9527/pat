//
//  main.cpp
//  PAT-A1145
//
//  Created by 雨含香 on 2019/11/25.
//  Copyright © 2019 雨含香. All rights reserved.
// 1145 Hashing - Average Search Time (25 分)
//hash表，平方探测法解决冲突

#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int msize,n,m;
    cin >> msize >> n>>m;
    while(!isPrime(msize)) msize++;
    vector<int> mp(msize,0);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        int flag=1;
        for(int j=0;j<=msize;j++){
            int index=(x+j*j)%msize;
            if(mp[index]==0){
                mp[index]=x;
                flag=0;
                break;
            }
        }
        if(flag==1){
            printf("%d cannot be inserted.\n", x);
        }
    }
    int total=0;
    for(int i=0;i<m;i++){
        int x;
        scanf("%d", &x);
        for(int j=0;j<=msize;j++){
            int index=(x+j*j)%msize;
            total++;
            if(mp[index]==x || mp[index]==0){
                break;
            }
        }
    }
    printf("%.1f", total*1.0/m);
    
    return 0;
}
