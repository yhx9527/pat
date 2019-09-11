//
//  main.cpp
//  PAT-A1065
//
//  Created by 雨含香 on 2019/9/10.
//  Copyright © 2019 雨含香. All rights reserved.
//

//#include <iostream>
//#include <cstdio>

//int main(int argc, const char * argv[]) {
//    int num;
//    scanf("%d", &num);
//    long long int a,b,c;
//    for(int i=1;i<=num;i++){
//        scanf("%lld%lld%lld", &a, &b, &c);
//        printf("Case #%d: ",i);
//        if(a>0&&b>0){
//            if(c<=0){
//                printf("true");
//            } else {
//                if(a>c-b) printf("true");
//                else printf("false");
//            }
//        } else if(a<0&&b<0){
//            if(c>=0){
//                printf("false");
//            } else {
//                if(a>c-b) printf("true");
//                else printf("false");
//            }
//        } else {
//            if(a+b>c) printf("true");
//            else printf("false");
//        }
//        printf("\n");
//    }
//    return 0;
//}

#include <iostream>
#include <cstdio>
//方法2,根据溢出之后数据正负改变来做
int main(int argc, const char * argv[]) {
    int num;
    scanf("%d", &num);
    long long a,b,c;
    
    for(int i=1;i<=num;i++){
        scanf("%lld%lld%lld", &a, &b, &c);
        long long res=a+b;
        printf("Case #%d: ",i);
        if(a>0&&b>0&&res<0) printf("true");
        else if(a<0&&b<0&&res>=0) printf("false");
        else if(res>c) printf("true");
        else printf("false");
        printf("\n");
    }
    return 0;
}

