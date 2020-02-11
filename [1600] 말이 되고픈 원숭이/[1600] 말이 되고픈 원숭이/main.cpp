//
//  main.cpp
//  [1600] 말이 되고픈 원숭이
//
//  Created by YOO TAEWOOK on 11/02/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct Monkey{
    int limit;
    pair<int, int> loc;
};


int map[200][200][31] = {0, }; //3차원 맵 말 이동횟수에 따라 각기 다른 층의 배열에 기록한다
bool visit[200][200][31] = {false, }; //이에 따른 방문벡터 또한 3차원으로
vector<pair<int,int> > dir;

int K, W, H;
pair<int, int> s, e;
void init();
void solve();
pair<int, int> horseMove(pair<int, int>, int);

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

pair<int, int> horseMove(pair<int, int> loc, int dir){
    //원숭이가 움직일 수 있는 경우의 수 8가지를 dir에 따라 움직인다.
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
    if(s == e)
        cout<<0<<endl;
    queue<Monkey> q;
    q.push({0,s}); //원숭이의 초기 위치 셋팅
    while(!q.empty()){
        Monkey cur = q.front();
        q.pop();
        int curWeight = map[cur.loc.first][cur.loc.second][cur.limit];
        visit[cur.loc.first][cur.loc.second][cur.limit] = true;
        if(cur.limit < K - 1){ // 말의 움직임을 할 횟수가 남아있으면 말 움직임을 진행한다.
            for(int i = 0 ; i < 8 ; i++){
                pair<int, int> next = horseMove(cur.loc, i);
                if(next.first < 0 || next.second < 0 || next.first >= H || next.second >= W || map[next.first][next.second][cur.limit + 1] < 0 || visit[next.first][next.second][cur.limit + 1])
                    continue;
                
                map[next.first][next.second][cur.limit + 1] = curWeight + 1;
                visit[next.first][next.second][cur.limit + 1] = true;
                q.push({cur.limit + 1, next});
            }
        }
        for(int i = 0 ; i < 4 ; i++){ // 말 움직임 횟수와 관계없이 원숭이 움직임을 진행한다
            pair<int, int> next = make_pair(cur.loc.first + dir.at(i).first, cur.loc.second + dir.at(i).second);
            
            if(next.first < 0 || next.second < 0 || next.first >= H || next.second >= W || map[next.first][next.second][cur.limit] < 0 || visit[next.first][next.second][cur.limit] )
                continue;
            
            map[next.first][next.second][cur.limit] = curWeight + 1;
            visit[next.first][next.second][cur.limit] = true;
            q.push({cur.limit, next});
        }
    }
    int min = 999999;
    for(int i = 0 ; i < K ; i++){ //각 층에 기록된 값 중 가장 작은 값을 찾는다
        int tmp = map[e.first][e.second][i];
        if(tmp == 0)
            continue;
        min = (min > tmp ? tmp : min);
    }
    if(min == 999999) //min이 안 변했으면 도달하지 못한 것
        cout<<-1<<endl;
    else
        cout<<min<<endl;
}

void init(){
    //freopen("input.txt", "r", stdin);
    cin>>K;
    cin>>W>>H;
    K++; //3차원 배열 공간확보를 위해 K++

    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            int tmp;
            cin>>tmp;
            if(tmp == 1)
                tmp = -1;
            for(int k = 0 ; k < K ; k++){
                map[i][j][k] = tmp;
            }
        }
    }
    s = make_pair(0, 0); //초기 위치 셋팅
    e = make_pair(H - 1, W - 1); //도달 위치 셋팅
    
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
    
}
