//
//  main.cpp
//  PAT-A1034-2
//
//  Created by 雨含香 on 2019/10/4.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1034 Head of a Gang 并查集解法，有bug

#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
const int maxn=2010;
map<string, int> str2int;
map<int, string> int2str;
map<string ,int> res;

int numPerson=-1;
int father[maxn];
int weight[maxn]={0}; //以每个节点为根节点的总权值
int point[maxn]={0}; //点权
int person[maxn]={0}; //以每个节点为根节点的集合的人数

void init(){
    for(int i=0;i<maxn;i++){
        father[i]=i;
        person[i]=1;
    }
}

int change(string str){
    if(str2int.find(str)!=str2int.end()){
        return str2int[str];
    } else {
        numPerson++;
        str2int[str]=numPerson;
        int2str[numPerson]=str;
        return numPerson;
    }
    
}
int findFather(int p){
    int a=p;
    while(p!=father[p]){
        p=father[p];
    }
    while(a!=father[a]){
        int z=father[a];
        father[a]=p;
        a=z;
    } //路径压缩
    return p;
}
void Union(int a, int b, int w){
    int i=findFather(a);
    int j=findFather(b);
    if(point[a]>point[i]){
        father[a]=a;
        father[i]=a;
        swap(person[a], person[i]);
        swap(weight[a], weight[i]);
        i=a;
    }
    if(point[b]>point[j]){
        father[b]=b;
        father[j]=b;
        swap(person[b], person[j]);
        swap(weight[b], weight[j]);
        j=b;
    }
    
    if(i!=j){
        weight[i]+=w;
        weight[j]+=w;
        if(point[i]>=point[j]){
            father[j]=i;
            person[i]+=person[j];
        } else {
            father[i]=j;
            person[j]+=person[i];
            
        }
    } else{
        weight[i]+=w;
    }
}

int main(int argc, const char * argv[]) {
    int num,K;
    scanf("%d %d", &num, &K);
    init();
    while(num--){
        string s1,s2;
        int w;
        cin>>s1>>s2>>w;
        int i=change(s1);
        int j=change(s2);
        point[i]+=w;
        point[j]+=w;
        Union(i,j, w);
    }
    int cluster=0;
    for(int i=0;i<maxn;i++){
        if(i==father[i]){
            if(person[i]>2&&weight[i]>K){
                cluster++;
                res[int2str[i]]=person[i];
            }
        }
    }
    printf("%d\n", cluster);
    for(map<string,int>::iterator it=res.begin();it!=res.end();it++){
        cout<<it->first<<" "<<it->second<<"\n";
    }
    return 0;
}
