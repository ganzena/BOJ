//
//  main.cpp
//  [9085] 더하기
//
//  Created by YOO TAEWOOK on 19/01/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>

using namespace std;

int cnt;

void run();

int main(int argc, const char * argv[]) {
    //freopen("input.txt", "r", stdin);
    cin>>cnt;
    for(int i = 0 ; i < cnt ; i ++){
        run();
    }
    return 0;
}

void run(){
    int size, total = 0;
    
    cin>>size;
    for(int i = 0 ; i < size ; i++){
        int temp;
        cin>>temp;
        total += temp;
    }
    
    cout<<total<<endl;;
}

