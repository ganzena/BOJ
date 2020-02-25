//
//  main.cpp
//  [14503] 로봇 청소기
//
//  Created by YOO TAEWOOK on 2018. 3. 20..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Robot{
    pair<int, int> loc;
    int dir;
    int cnt;
    int stack;
};

vector<pair<int, int> > dir;
vector<vector<int> > map;
vector<vector<bool> > visit;
queue<Robot> q;

int N, M, ans = 0;
Robot robot;

void init();
void solve();
int turnLeft(int);

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void solve(){
    while(!q.empty()){
        Robot now = q.front();
        q.pop();
        ans = now.cnt;
        while(now.stack++ < 4){ // 로봇은 총 네번 회전하고 빠꾸한다
            now.dir = turnLeft(now.dir);
            pair<int, int> nextLoc = make_pair(now.loc.first + dir.at(now.dir).first, now.loc.second + dir.at(now.dir).second);
            
            if(map[nextLoc.first][nextLoc.second] == 1 || visit[nextLoc.first][nextLoc.second])
                continue;
            Robot next = {nextLoc, now.dir, now.cnt + 1, 0};
            visit[nextLoc.first][nextLoc.second] = true;
            
            q.push(next);
            break;
        }
        if(q.empty()){ //청소할 곳이 없었을 경우 후진
            pair<int, int> backLoc = make_pair(now.loc.first - dir.at(now.dir).first, now.loc.second - dir.at(now.dir).second);
            if(map[backLoc.first][backLoc.second] == 1) //후진하려는데 벽이면 끝
                break;
            // 이미 청소한 곳이면 그대로 아니면 청소 갯수 증가
            Robot next = {backLoc, now.dir, (visit[backLoc.first][backLoc.second] ? now.cnt : now.cnt + 1), 0};
            visit[backLoc.first][backLoc.second] = true;
            
            q.push(next);
        }
    }
    
    cout<<ans<<endl;
}

int turnLeft(int dir){
    if(dir == 0)
        return 3;
    else if(dir == 1)
        return 0;
    else if(dir == 2)
        return 1;
    else if(dir == 3)
        return 2;
    return -1;
}

void init(){
    //freopen("input.txt", "r", stdin);
    cin>>N>>M;
    
    map.assign(N, vector<int>(M, 0));
    visit.assign(N, vector<bool>(M, false));
    robot = {make_pair(0, 0), 0, 0, 0};
    cin>>robot.loc.first>>robot.loc.second>>robot.dir;
    visit[robot.loc.first][robot.loc.second] = true; //청소상태로 표시
    robot.cnt += 1; //청소 갯수 증가
    q.push(robot);
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>map[i][j];
        }
    }
    
    dir.push_back(make_pair(-1, 0));
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(0, -1));
}



