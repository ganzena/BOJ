//
//  main.cpp
//  [2839] 설탕 배달
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
    int sugar;
    int total = 0;
    cin>>sugar;
    
    while(1){
        if(sugar % 5 == 0){
            total = sugar/5 + total;
            cout<<total<<endl;
            break;
        }else if(sugar <= 0){
            cout<<-1<<endl;
            break;
        }
        sugar -= 3;
        total++;
    }
    
    return 0;
}
