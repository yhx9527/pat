//
//  main.cpp
//  PAT-A1157
//
//  Created by 雨含香 on 2019/11/6.
//  Copyright © 2019 雨含香. All rights reserved.
//1157 Anniversary

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,m;
    string id, oldest="999999999999999999";
    int count=0;
    unordered_set<string> alumnus;
    cin >> n;
    while(n--){
        cin>>id;
        alumnus.insert(id);
    }
    cin>>m;
    while(m--){
        cin >> id;
        if(alumnus.count(id)){
            count++;
            if(stoi(id.substr(6,8))<stoi(oldest.substr(6,8))){
                oldest=id;
            }
        }else {
            if(count==0&&stoi(id.substr(6,8))<stoi(oldest.substr(6,8))){
                oldest=id;
            }
        }
    }
    cout << count <<endl <<oldest;
    return 0;
}
