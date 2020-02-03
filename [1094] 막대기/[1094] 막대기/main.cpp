//
//  main.cpp
//  [1094] 막대기
//
//  Created by YOO TAEWOOK on 29/01/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> stick;

int target;
bool check();
void cut();
void init();

int main(int argc, const char * argv[]) {
    init();
    cut();
    return 0;
}

void cut(){
    if(!check()){
        
        while(1){
            
            int min = stick.at(stick.size() - 1);
            int half = min/2;
            stick.pop_back();
            for(int i = 0 ; i < 2 ; i++){
                stick.push_back(half);
            }
            int sum = 0;
            for(int i = 0 ; i < stick.size() - 1 ; i++){
                sum += stick.at(i);
            }
            if(sum >= target)
                stick.pop_back();
            
            if(check())
                break;
        }
    }
    cout<<stick.size()<<endl;
}

bool check(){
    int sum = 0;
    for(int i = 0 ; i < stick.size() ; i++){
        sum += stick.at(i);
    }
    if(sum == target)
        return true;
    
    return false;
}

void init(){
    //freopen("input.txt", "r", stdin);
    cin>>target;
    stick.push_back(64);
}
