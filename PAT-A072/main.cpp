//
//  main.cpp
//  PAT-A072
//
//  Created by 雨含香 on 2019/10/8.
//  Copyright © 2019 雨含香. All rights reserved.
//
//1072 Gas Station

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

const int maxn = 1020;
const int INF = 1000000000;

int roads[maxn][maxn];
int houses, gas, dist;
int len;
int dis[maxn];
bool flag[maxn];
double avarage=INF, minNum=-1;
int gasindex;
bool pass=false;

void dijkstra(int k){
    fill(dis, dis+maxn, INF);
    fill(flag, flag+maxn, false);
    dis[k]=0;
    for(int i=1;i<=len;i++){
        int u=-1, MIN=INF;
        for(int j=1;j<=len;j++){
            if(!flag[j]&&dis[j]<MIN){
                u=j;
                MIN=dis[j];
            }
        }
        if(u==-1) break;
        flag[u]=true;
        for(int x=1;x<=len;x++){
            if(!flag[x]&&roads[u][x]!=INF){
                if(dis[u]+roads[u][x]<dis[x]){
                    dis[x]=dis[u]+roads[u][x];
                }
            }
        }
    }
}
int getID(string s){
    int i=0;
    int id=0;
    while(i<s.size()){
        if(s[i]!='G') {
            id=id*10+s[i]-'0';
        }
        i++;
    }
    if(s[0]=='G') id=id+houses;
    return id;
}
int main(int argc, const char * argv[]) {
    int num;
    scanf("%d %d %d %d", &houses, &gas, &num, &dist);
    fill(roads[0], roads[0]+maxn*maxn, INF);
    while(num--){
        string a,b;
        int dis;
        cin>>a>>b>>dis;
        int x,y;
        x=getID(a);
        y=getID(b);
        roads[y][x] =roads[x][y] = dis;
    }
    len = houses+gas;
    for(int k=1+houses;k<=len;k++){
        dijkstra(k);
        
        double sum=0, minTemp=INF;
        bool passTemp=true;
        for(int y=1;y<=houses;y++){
            if(dis[y]>dist){
                passTemp=false;
                break;
            }
            if(dis[y]<minTemp){
                minTemp=dis[y];
            }
            sum+=1.0*dis[y]/houses;
            passTemp=true;
        }
        if(passTemp){
            double temp = sum;
            if(minTemp>minNum){
                avarage = temp;
                minNum = minTemp;
                gasindex=k-houses;
            } else if(minTemp==minNum){
                if(temp<avarage){
                    avarage = temp;
                    gasindex=k-houses;
                    }
//                } else if(temp==avarage&&k-houses<gasindex){
//                    gasindex=k-houses;
//                }
            }
            pass=true;
        }
    }
    
    if(pass){
        printf("G%d\n", gasindex);
        printf("%.1f %.1f", minNum, avarage);
    } else {
        printf("No Solution");
    }
    
    return 0;
}
