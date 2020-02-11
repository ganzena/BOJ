//
//  main.cpp
//  [7562] 나이트의 이동
//
//  Created by YOO TAEWOOK on 10/02/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> now, fin;
vector<vector<int> > map;
int size;

void init();
void solve();
void print();
pair<int, int> move(pair<int, int>, int);

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>>tc;
    while(tc > 0){
        init();
        solve();
        tc--;
    }
    
    return 0;
}

void print(){
    for(int i = 0 ;i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            cout<<map[i][j]<<"\t";
        }cout<<endl;
    }cout<<endl;
}

pair<int, int> move(pair<int, int> loc, int dir){
    //나이트가 움직일 수 있는 경우의 수 8가지를 dir에 따라 움직인다.
    if(dir == 0){
        loc.first -= 2;
        loc.second++;
    }else if(dir == 1){
        loc.first--;
        loc.second+=2;
    }else if(dir == 2){
        loc.first++;
        loc.second += 2;
    }else if(dir == 3){
        loc.first += 2;
        loc.second++;
    }else if(dir == 4){
        loc.first+=2;
        loc.second--;
    }else if(dir == 5){
        loc.first++;
        loc.second -= 2;
    }else if(dir == 6){
        loc.first--;
        loc.second -= 2;
    }else if(dir == 7){
        loc.first -= 2;
        loc.second--;
    }
    
    
    return loc;
}

void solve(){
    if(now == fin){ //만약 초기에 현재 위치와 목표 위치가 같다면 안 움직인다
        cout<<0<<endl;
        return;
    }
    queue<pair<int, int> > q;
    q.push(now);
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        int curWeight = map[now.first][now.second];
        for(int i = 0 ; i < 8 ; i++){ //8가지의 움직임을 다 해본다
            pair<int, int> next = move(now, i);
            if(next.first >= size || next.second >= size || next.first < 0 || next.second < 0 ){
                continue;
            }
            
            int nextWeight = map[next.first][next.second];
            
            if(curWeight == 0 || nextWeight == 0){ // 만약 현재 0번 움직였거나, 다음에 움직일 곳이 방문하지 않았을 경우
                map[next.first][next.second] = curWeight + 1;
                q.push(next);
            }
            else if(nextWeight > curWeight + 1){ // 그게 아니라면 현재 weight + 1이 다음 움직일 곳의 weight보다 작으면 업데이트를 해주고 큐에 넣는다
                map[next.first][next.second] = curWeight + 1;
                q.push(next);
            }
        }
    }
    
    //print();
    
    cout<<map[fin.first][fin.second]<<endl;
}

void init(){
    cin>>size;
    map.assign(size, vector<int>(size, 0));
    int nowFirst, nowSecond, finFirst, finSecond;
    cin>>nowFirst>>nowSecond;
    now = make_pair(nowFirst, nowSecond); //현재 나이트의 위치
    cin>>finFirst>>finSecond;
    fin = make_pair(finFirst, finSecond); //목표 나이트의 위치
}
