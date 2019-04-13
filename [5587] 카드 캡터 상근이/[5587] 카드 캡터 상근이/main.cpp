//
//  main.cpp
//  [5587] 카드 캡터 상근이
//
//  Created by YOO TAEWOOK on 25/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> sg;
vector<int> gs;
int lastNum = -1;

void init();
void playGame();
bool gsGame();
bool sgGame();

int main(int argc, const char * argv[]) {
    init();
    playGame();
    cout<<gs.size()<<endl;
    cout<<sg.size()<<endl;
    return 0;
}

bool sgGame(){
    vector<int>::iterator iter = sg.begin();
    for(iter = sg.begin() ; iter != sg.end() ; iter++){
        if(*iter > lastNum){
            lastNum = *iter;
            sg.erase(iter);
            return false;
        }
    }
    lastNum = -1;
    return false;
}

bool gsGame(){
    vector<int>::iterator iter = gs.begin();
    for(iter = gs.begin() ; iter != gs.end() ; iter++){
        if(*iter > lastNum){
            lastNum = *iter;
            gs.erase(iter);
            return true;
        }
    }
    lastNum = -1;
    return true;
}

void playGame(){
    bool flag = true; //true == sangGuen
    while(!gs.empty() && !sg.empty()){
        if(flag){
            flag = sgGame();
        }else{
            flag = gsGame();
        }
    }
}

void init(){
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        int num;
        cin>>num;
        sg.push_back(num);
    }
    sort(sg.begin(), sg.end());
    for(int i = 1 ; i <= n*2 ; i++){
        bool flag = true;
        for(int j = 0 ; j < n ; j++){
            if(i == sg.at(j))
                flag = false;
        }
        if(flag)
            gs.push_back(i);
    }
   sort(gs.begin(), gs.end());
}
