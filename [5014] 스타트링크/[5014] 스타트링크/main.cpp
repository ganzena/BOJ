//
//  main.cpp
//  [5014] 스타트링크
//
//  Created by YOO TAEWOOK on 2020/03/31.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void init();
int solve();
vector<int> building;

int F, S, G, U, D; // 총 층(F) / 스타트링크 위치(G) / 현재위치(S) / 얼만큼 위로(U) / 얼만큼 아래로(D)

int main(int argc, const char * argv[]) {
    init();
    if(solve() == -1){
        cout<<"use the stairs"<<endl;
    } else{
        cout<<building.at(G)<<endl;
    }
    
    return 0;
}

int solve(){
    queue<pair<int, int> > loc;
    loc.push(make_pair(S, 0));
    
    while(!loc.empty()){
        pair<int, int> now = loc.front(); // first는 현재 위치 second는 버튼 누른 횟수
        loc.pop();
        if(now.first == G){
            building.at(now.first) = now.second;
            return now.second;
        }
        if(now.first > F || now.first < 1)
            continue;
        if(building.at(now.first) >= 0)
            continue;
        building.at(now.first) = now.second;
        
        int upNext = now.first + U;
        int downNext = now.first - D;
        loc.push(make_pair(upNext, now.second + 1));
        loc.push(make_pair(downNext, now.second + 1));
    }
    
    return -1;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>F>>S>>G>>U>>D;
    building.assign(F + 1, -1);
}
