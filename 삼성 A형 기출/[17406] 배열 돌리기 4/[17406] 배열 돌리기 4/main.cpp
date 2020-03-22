//
//  main.cpp
//  [17406] 배열 돌리기 4
//
//  Created by YOO TAEWOOK on 2020/03/22.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

struct Command{
    int r;
    int c;
    int s;
};

vector<vector<int> > map;
vector<pair<Command, bool> > cmdV;
vector<Command> tempV;

void init();
void solve(int, int);
void rotate();
void print();

int N, M, K;
int ans = INT_MAX;
int main(int argc, const char * argv[]) {
    init();
    //solve();
    solve(0, 0);
    cout<<ans<<endl;
    return 0;
}

void print(){
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            cout<<map[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}
void rotate(){
    vector<vector<int> > initMap = map;
    for(int k = 0 ; k < tempV.size() ; k++){
        Command cmd = tempV.at(k);
        int r = cmd.r;
        int c = cmd.c;
        int s = cmd.s;
        while(s > 0){
            int head = map[r-s][c+s];
            int tail;
            for(int j = c + s ; j > c - s ;j--){
                map[r-s][j] = map[r-s][j - 1];
            }
            
            tail = map[r + s][c + s];
            for(int i = r + s ; i > r - s + 1 ; i--){
                map[i][c + s] = map[i - 1][c + s];
            }
            map[r - s + 1][c + s] = head;
            head = tail;
            
            tail = map[r + s][c - s];
            for(int j = c - s ; j < c + s ; j++){
                map[r + s][j] = map[r+s][j + 1];
            }
            map[r + s][c + s - 1] = head;
            head = tail;
            
            for(int i = r-s ; i < r + s ; i++){
                map[i][c - s] = map[i + 1][c - s];
            }
            map[r + s - 1][c - s] = head;

            s--;
        }
    }
    
    for(int i = 1 ; i <= N ; i++){
        int sum = 0;
        for(int j = 1 ; j <= M ; j++){
            sum += map[i][j];
        }
        ans = min(sum, ans);
    }

    map = initMap;
}

void solve(int depth, int start){
    if(depth == K){
        rotate();
        return;
    }
    
    for(int i = 0 ; i < cmdV.size() ; i++){
        if(cmdV.at(i).second == false){ //중복을 허용하지 않는 순열
            tempV.push_back(cmdV.at(i).first);
            cmdV.at(i).second = true;
            solve(depth + 1, i);
            tempV.pop_back();
            cmdV.at(i).second = false;
        }
    }
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N>>M>>K;
    map.assign(N + 1, vector<int>(M + 1, 0));
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            cin>>map[i][j];
        }
    }
    for(int i = 0 ; i < K ; i++){
        Command cmd;
        cin>>cmd.r>>cmd.c>>cmd.s;
        cmdV.push_back(make_pair(cmd, false));
    }
}
