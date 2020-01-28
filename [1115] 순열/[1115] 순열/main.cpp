//
//  main.cpp
//  [1115] 순열
//
//  Created by YOO TAEWOOK on 22/01/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> numbers;
vector<int> standard;

map<int, bool> existMap;
map<int, bool>::iterator iter;


int num;
int minimum = 9999999;

void init();
void perm(int, int);
void compare();
bool makeSon();

int main(int argc, const char * argv[]) {
    init();
    perm(0, 0);
    cout<<minimum<<endl;
    return 0;
}

bool makeSon(){
    vector<int> tmpVec;
    tmpVec.assign(num ,0);
    bool isPerm = true;
    for(int i = 0 ; i < num ; i++){
        if(i == 0){
            tmpVec.at(i) = 0;
            existMap.find(0)->second = true;
        }else{
            
            int target = numbers.at(tmpVec.at(i - 1));
            if((existMap.find(target) == existMap.end()) || existMap.find(target)->second == true){
                isPerm = false;
                break;
            }else{
                existMap.find(target)->second = true;
                tmpVec.at(i) = numbers.at(tmpVec.at(i - 1));
            }
        }
    }
    
    for(iter = existMap.begin() ; iter != existMap.end() ; iter++ ){
        iter->second = false;
    }
    
    return isPerm;
}


void compare(){
    int tmpMin = 0;
    for(int i = 0 ; i < num ; i++){
        if(numbers.at(i) != standard.at(i)){
            tmpMin++;
        }
    }
    minimum = min(tmpMin, minimum);
}

void perm(int depth, int start){
    if(depth == num){
        if(makeSon()){
            compare();
        }
        return;
    }
    for(int i = start ; i < num ; i++){
        swap(numbers.at(start), numbers.at(i));
        perm(depth + 1, start + 1);
        swap(numbers.at(start), numbers.at(i));
    }
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>num;
    standard.assign(num, 0);
    for(int i = 0 ; i < num ; i++){
        cin>>standard.at(i);
        numbers.push_back(i);
        existMap.insert(make_pair(i, false));
    }
    
}
