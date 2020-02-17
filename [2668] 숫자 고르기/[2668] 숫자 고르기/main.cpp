//
//  main.cpp
//  [2668] 숫자 고르기
//
//  Created by YOO TAEWOOK on 13/02/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int N, cnt = 0;

bool map [101][101] = {false, };
vector<vector<int> > visit;
vector<bool> ans;
void init();
void solve(int);
void print();

int main(){
    init();
    for(int i = 1 ; i <= N ; i++){
        visit.assign(N+1, vector<int>(N+1, 0));
        solve(i);
    }
    print();
}

void print(){
    cout<<cnt<<endl;
    for(int i = 0 ; i < ans.size() ; i++){
        if(ans.at(i))
            cout<<i<<endl;
    }
}

void solve(int x){
    visit[x][x]++;
    if(visit[x][x] >= 2){ // 해당 정점을 두 번 이상 방문했을때
        if(!ans.at(x)){ // 해당 정점이 싸이클 표시가 안 되어있으면
            ans.at(x) = true; //true로 바꾸고
            cnt++; //카운트 증가
        }
        return;
    }
    
    for(int i = 1 ; i <= N ; i++){
        if(map[x][i]){ //간선이 있다면
            solve(i); //들어간다
        }
    }
    return;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N;
    for(int i = 1 ; i <= N ; i++){
        int tmp;
        cin>>tmp;
        map[i][tmp] = true;
    }
    visit.assign(N+1, vector<int>(N+1, 0));
    ans.assign(N+1, false); // 해당 정점이 싸이클인지 표시
}
