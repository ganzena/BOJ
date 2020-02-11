//
//  main.cpp
//  [2573] 빙산
//
//  Created by YOO TAEWOOK on 09/02/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct BingSan{
    int year; // 시간의 경과
    int height; //빙산의 높이
    int x, y; //좌표
};

vector<vector<int> > map;
vector<pair<int, int> > dir;
vector<vector<bool> > visit;
queue<BingSan> q;


int N, M, year = 0;
void init();
void melt();
bool check();
void print();


int main(int argc, const char * argv[]) {
    init();
    melt();
    return 0;
}

void print(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cout<<map[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}

bool check(){
    queue<BingSan> copyQ;
    copyQ.push(q.front()); // 카피큐에 빙산 1개를 집어넣는다.
    while(!copyQ.empty()){ //카피큐에 연결되어 있는 모든 빙산들에 방문 처리를 한다
        BingSan cur = copyQ.front();
        copyQ.pop();
        visit[cur.x][cur.y] = true;
        for(int i = 0 ; i < 4 ; i++){
            int xx = cur.x + dir.at(i).first;
            int yy = cur.y + dir.at(i).second;
            
            if(xx >= N || yy >= M || xx < 0 || yy < 0 || map[xx][yy] == 0 || visit[xx][yy]){
                continue;
            }
            BingSan next = {cur.year, cur.height, xx, yy};
            visit[xx][yy] = true;
            copyQ.push(next);
        }
    }
    
    copyQ = q; // 다시 현재의 큐를 대입한다.
    while(!copyQ.empty()){ //카피큐를 pop 하면서 해당 빙산에 방문 여부를 확인한다.
        BingSan cur = copyQ.front();
        copyQ.pop();
        if(!visit[cur.x][cur.y]){ //방문이 안 되어있다는것은 연결되지 않았다는 것 즉 2등분 이상이란 소리다
            return true;
        }
    }
    
    return false; //아니라면 연결되어 있는 것임
}

void melt(){
    queue<pair<int, int> > iceQ;
    while(!q.empty()){
        BingSan cur = q.front();
        int past = year;
        year = cur.year;
        if(past != year){ //해가 바뀐것
            while(!iceQ.empty()){ //해가 바뀌었으므로 0이 된 빙산들을 업데이트 해준다
                map[iceQ.front().first][iceQ.front().second] = 0;
                iceQ.pop();
            }
            if(check()){ // 등분 되었는지 체크한다
                cout<<year<<endl;
                return;
            }else{ //아직 한 덩어리면 방문벡터 초기화
                visit.assign(N, vector<bool>(M, false));
            }
        }
    
        q.pop();
        int cnt = 0;
        for(int i = 0 ; i < 4 ; i++){
            int xx = cur.x + dir.at(i).first;
            int yy = cur.y + dir.at(i).second;
            if(xx >= N || yy >= M || xx < 0 || yy < 0 || map[xx][yy] > 0){
                continue;
            }
            cnt++;
        }
        if(cur.height - cnt > 0){
            BingSan next = {cur.year + 1, cur.height - cnt, cur.x, cur.y};
            map[cur.x][cur.y] = cur.height - cnt;
            q.push(next);
        }else{
            map[cur.x][cur.y] = 11; // 바로 0으로 처리해버리면 다른 빙산에서 해당 값까지 카운트하므로 일단 다른 값으로 세팅하고 추후 0으로 업데이트
            iceQ.push(make_pair(cur.x, cur.y)); //0으로 만들어야하는 빙산들의 좌표 저장
        }
    }
    
    cout<<0<<endl; //다 녹을때까지 분리되지 않았다면 0 출력
    return;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N>>M;
    map.assign(N, vector<int>(M, 0));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>map[i][j];
            if(map[i][j] > 0){
                q.push({0, map[i][j], i, j});
            }
        }
    }
    visit.assign(N, vector<bool>(M, false));
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
    
}
