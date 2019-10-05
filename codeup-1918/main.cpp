//
//  main.cpp
//  codeup-1918
//
//  Created by 雨含香 on 2019/10/3.
//  Copyright © 2019 雨含香. All rights reserved.
//
//codeup1918 实现简单计算机

#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <cstdio>
#include <string>

using namespace std;
struct node {
    int num;
    char ch;
    bool flag;
};
string str;
map<char, int> op;
stack<node> st;
queue<node> q;

//将前缀转成后缀
void change(){
    node temp;
    for(string::iterator it=str.begin();it!=str.end();){
        if(*it>='0'&&*it<='9'){
            temp.flag=true;
            temp.num = *it-'0';
            it++;
            while(*it>='0'&&*it<='9'){
                temp.num=temp.num*10+(*it-'0');
                it++;
            }
            q.push(temp);
        } else {
            temp.flag=false;
            temp.ch=*it;
            printf("%c\n", *it);
            if(*it==')'){
                while(!st.empty()&&st.top().ch!='('){
                    q.push(st.top());
                    st.pop();
                }
                if(st.empty()) {
                    printf("表达式错误");
                    return;
                } else {
                    st.pop();
                }
            } else if(*it=='('){
            
                st.push(temp);
            }
            else{
                while(!st.empty()&&st.top().ch!='('&&op[*it]<=op[st.top().ch]){
                    q.push(st.top());
                    st.pop();
                }
                st.push(temp);
            }
            it++;
        }
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}

//计算后缀表达式
double compute(){
    stack<double> cal;
    while(!q.empty()){
        node temp=q.front();
        q.pop();
        if(temp.flag){
            cal.push(temp.num);
        } else {
            double num1=cal.top();
            cal.pop();
            double num2=cal.top();
            cal.pop();
            double res;
            switch(temp.ch){
                case '+': res=num2+num1;
                    break;
                case '-': res=num2-num1;
                    break;
                case '*': res=num2*num1;
                    break;
                case '/': res=num2/num1;
                    break;
            }
            cal.push(res);
        }
    }
    return cal.top();
}

int main(int argc, const char * argv[]) {
    op['+']=op['-']=1;
    op['*']=op['/']=2;
    while(getline(cin, str), str!="0"){
        for(string::iterator it=str.begin();it!=str.end();it++){
            if(*it==' ') str.erase(it);
        }
        cout<<str<<'\n';
        while(!st.empty()) st.pop();
        change();
        printf("%.2f\n", compute());
    }
    return 0;
}
