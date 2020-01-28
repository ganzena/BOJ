//
//  main.cpp
//  [1138] 한 줄로 서기
//
//  Created by YOO TAEWOOK on 22/01/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> line;
vector<int> leftTalls;

int n;

void init();
void print();
void perm(int, int);
bool check();

int main(int argc, const char * argv[]) {
    init();
    perm(0, 0);
    return 0;
}

bool check(){
    for(int i = 0 ; i < n ; i++){
        int target = line.at(i);
        int cnt = 0;
        for(int j = i - 1 ; j >= 0 ; j--){
            if(line.at(j) > target){
                cnt++;
            }
        }
        if(cnt != leftTalls.at(target - 1))
            return false;
    }
    return true;
}

void perm(int depth, int start){
    if(depth == n){
        if(check()){
            print();
        }
    }
    
    for(int i = start ; i < n ; i++){
        swap(line.at(i), line.at(start));
        perm(depth + 1, start + 1);
        swap(line.at(i), line.at(start));
    }
}

void print(){
    for(int i = 0 ; i < n ; i++){
        cout<< line.at(i) << " ";
    }cout<<endl;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>n;
    line.assign(n, 0);
    leftTalls.assign(n, 0);
    for(int i = 0 ; i < n ; i++){
        cin>>leftTalls.at(i);
        line.at(i) = i + 1;
    }
}
