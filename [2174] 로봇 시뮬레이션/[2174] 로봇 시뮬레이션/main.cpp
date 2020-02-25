//
//  main.cpp
//  [2174] 로봇 시뮬레이션
//
//  Created by YOO TAEWOOK on 2018. 3. 9..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Robot{
    int x;
    int y;
    int dir;
    int no; //로봇 번호
};

struct Command{
    int no;
    char type;
    int cnt;
};

vector<vector<Robot> > map;
queue<Command> commandQ;
vector<Robot> robotV;
vector<pair<int, int> > dir;

int A, B, N, M; //열 / 행 / 로봇 수 / 커맨드


void init();
void solve();
int dirToInt(char);
int left(int);
int right(int);

int main(){
    init();
    solve();
    return 0;
    
}

void solve(){
    while(!commandQ.empty()){
        Command cmd = commandQ.front();
        commandQ.pop();
        Robot* robot = &robotV.at(cmd.no); //로봇벡터에 있는 로봇을 업데이트 해주기 위해 포인터로
        
        if(cmd.type == 'F'){
            int pastX = robot->x;
            int pastY = robot->y;
            while(cmd.cnt-- > 0){
                int xx = robot->x + dir.at(robot->dir).first;
                int yy = robot->y + dir.at(robot->dir).second;
                if(xx < 0 || yy < 0 || xx >= B || yy >= A){ //벽이랑 충돌
                    cout<<"Robot "<<robot->no<<" crashes into the wall"<<endl;
                    return;
                }
                if(map[xx][yy].no != 0){ //로봇이랑 충돌
                    cout<<"Robot "<<robot->no<<" crashes into robot "<<map[xx][yy].no <<endl;
                    return;
                }
                //충돌 안했으면
                robot->x = xx;
                robot->y = yy;
            }
            map[robot->x][robot->y] = *robot;
            map[pastX][pastY] = {0,0,0,0};
            
        }else if(cmd.type == 'R'){
            cmd.cnt = cmd.cnt % 4;
            
            while(cmd.cnt-- > 0){
                robot->dir = right(robot->dir);
            }
            map[robot->x][robot->y] = *robot;
        }else if(cmd.type == 'L'){
            cmd.cnt = cmd.cnt % 4;
            while(cmd.cnt-- > 0){
                robot->dir = left(robot->dir);
            }
            map[robot->x][robot->y] = *robot;
        }
    }
    cout<<"OK"<<endl;
}

void init(){
    //freopen("input.txt", "r", stdin);
    cin>>A>>B; //열 행 5 4
    Robot init = {0,0,0,0};
    map.assign(B, vector<Robot>(A, init));
    cin>>N>>M; //로봇수 / 커맨드
    robotV.assign(N + 1, {0,0,0,0});
    for(int i =  1 ; i <= N ; i++){ //로봇 입력
        int c, r;
        char d;
        cin>>c>>r>>d;
        r = B - r;
        c--;
        Robot robot = {r, c, dirToInt(d), i};
        map[r][c] = robot;
        robotV[i] = robot;
    }
    
    for(int i = 0 ; i < M ; i++){ // 명령 입력
        Command cmd;
        cin>>cmd.no>>cmd.type>>cmd.cnt;
        commandQ.push(cmd);
    }
    
    dir.push_back(make_pair(-1, 0)); //북
    dir.push_back(make_pair(0, 1)); //동
    dir.push_back(make_pair(1, 0)); //남
    dir.push_back(make_pair(0, -1)); //서
}

int left(int dir){
    if(dir == 0)
        return 3;
    return --dir;
}

int right(int dir){
    if(dir == 3)
        return 0;
    return ++dir;
}

int dirToInt(char dir){
    if(dir == 'N'){
        return 0;
    }else if(dir == 'W'){
        return 3;
    }else if(dir == 'E'){
        return 1;
    }else if(dir == 'S'){
        return 2;
    }
    return -1;
}
