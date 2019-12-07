//
//  main.cpp
//  PAT-A1147
//
//  Created by 雨含香 on 2019/11/27.
//  Copyright © 2019 雨含香. All rights reserved.
// 1147 Heaps (30 分)
//堆的判断，后序遍历

#include <iostream>
#include <vector>
using namespace std;


vector<int> v;
void tellheap(){
    int ifmin=1,ifmax=1;
    for(int i=2;i<v.size();i++){
        if(v[i/2]>=v[i]) ifmin=0;
        else if(v[i/2] < v[i]) ifmax=0;
    }
    if(ifmin==1){
        printf("Min Heap");
    } else if(ifmax==1){
        printf("Max Heap");
    } else{
        printf("Not Heap");
    }
    printf("\n");
}
void postorder(int i){
    if(i<v.size()){
        postorder(2*i);
        postorder(2*i+1);
        printf("%d%s", v[i], i==1?"":" ");
    }
}


int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    v.resize(m+1);
    while(n--){
        for(int i=1;i<=m;i++){
            scanf("%d", &v[i]);
        }
        tellheap();
        postorder(1);
        printf("\n");
    }
    return 0;
}
