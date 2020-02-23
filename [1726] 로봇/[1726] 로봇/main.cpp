//
//  main.cpp
//  [1726] 로봇
//
//  Created by YOO TAEWOOK on 2018. 3. 26..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Robot{
    pair<int, int> loc;
    int dir;
    int weight;
};

int M, N;
Robot start, fin = {make_pair(0, 0), 0,0};

int map[100][100][5]; //동서남북의 weight 값을 기록하기 위해 3차원으로 설정
vector<pair<int, int> > dir; //1 동 2 서 3 남 4 북
queue<Robot> q;

void init();
void solve();
int turnLeft(int);
int turnRight(int);
pair<int, int> move (pair<int, int>, int, int);
void print();

int main(){
    init();
    solve();
    return 0;
}

void solve(){
    //시작점과 끝점이 같을 경우
    if(start.loc.first == fin.loc.first && start.loc.second == fin.loc.second && start.dir == fin.dir ){
        cout<<0<<endl;
        return;
    }
    
    while(!q.empty()){
        Robot now = q.front();
        q.pop();
        //현재 보고 있는 방향이 뚫려있는 경우
        int limit = 3; //한번에 움직일 수 있는 최대 횟수
        Robot copyNow = now;
        
        while(limit-- > 0){ // 현재의 방향으로 직진(최대 3번까지 맵에 모두 기록)
            pair<int, int> nextLoc = make_pair(copyNow.loc.first + dir.at(copyNow.dir).first, copyNow.loc.second + dir.at(copyNow.dir).second);
            if(nextLoc.first < 0 || nextLoc.second < 0 || nextLoc.first >= M || nextLoc.second >= N || map[nextLoc.first][nextLoc.second][copyNow.dir] == -1){
                break;
            }
            if(map[nextLoc.first][nextLoc.second][copyNow.dir] != 0 && map[nextLoc.first][nextLoc.second][copyNow.dir] < now.weight + 1)
                break;
            Robot next = {nextLoc, copyNow.dir, now.weight + 1};
            map[next.loc.first][next.loc.second][next.dir] = next.weight;
            q.push(next);
            copyNow = next;
        }
        
        Robot next = {now.loc, turnLeft(now.dir), now.weight + 1};
        // 방문한 적이 없거나 (0), 해당 위치의 weight가 방문하려는 weight 보다 클 경우 (업데이트 필요)
        if(map[next.loc.first][next.loc.second][next.dir] == 0 || map[next.loc.first][next.loc.second][next.dir] > next.weight){
            map[next.loc.first][next.loc.second][next.dir] = next.weight;
            q.push(next);
        }
        
        next = {now.loc, turnRight(now.dir), now.weight + 1};
        // 방문한 적이 없거나 (0), 해당 위치의 weight가 방문하려는 weight 보다 클 경우 (업데이트 필요)
        if(map[next.loc.first][next.loc.second][next.dir] == 0 || map[next.loc.first][next.loc.second][next.dir] > next.weight){
            map[next.loc.first][next.loc.second][next.dir] = next.weight;
            q.push(next);
        }
    }
    // 끝점의 위치 출력
    cout<<map[fin.loc.first][fin.loc.second][fin.dir]<<endl;
}

int turnLeft(int dir){
    if(dir == 1){ //동
        return 4; //북
    }else if(dir == 2){ //서
        return 3; //남
    }else if(dir == 3){ //남
        return 1;
    }else if(dir == 4){//북
        return 2;
    }
    return -1;
}

int turnRight(int dir){
    if(dir == 1){ //동
        return 3; //남
    }else if(dir == 2){ //서
        return 4;//북
    }else if(dir == 3){//남
        return 2;
    }else if(dir == 4){
        return 1;
    }
    return -1;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>M>>N;
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            int num;
            cin>>num;
            if(num == 1)
                num = -1;
            for(int k = 1 ; k < 5 ; k++){
                map[i][j][k] = num;
            }
        }
    }
    cin>>start.loc.first>>start.loc.second>>start.dir;
    cin>>fin.loc.first>>fin.loc.second>>fin.dir;
    // 위치 보정
    start.loc.first--;
    start.loc.second--;
    fin.loc.first--;
    fin.loc.second--;
    
    q.push(start);
    
    dir.push_back(make_pair(0, 0));
    dir.push_back(make_pair(0, 1)); //동
    dir.push_back(make_pair(0, -1)); //서
    dir.push_back(make_pair(1, 0)); //남
    dir.push_back(make_pair(-1, 0)); //북
}

void print(){
    for(int k = 1 ; k < 5 ; k++){
        if(k==1){
            cout<<"오른쪽"<<endl;
        }else if(k==2){
            cout<<"왼쪽"<<endl;
        }else if(k==3){
            cout<<"아래쪽"<<endl;
        }else if(k==4){
            cout<<"위쪽"<<endl;
        }
        
        for(int i = 0 ; i < M ; i++){
            for(int j = 0 ; j < N ; j++){
                cout<<map[i][j][k]<<"\t"<<"\t";
            }cout<<endl;
        }cout<<endl;
    }
    
}
