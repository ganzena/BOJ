//
//  main.cpp
//  [4179] 불!
//
//  Created by YOO TAEWOOK on 16/02/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Info{
    pair<int, int> loc;
    int time;
};

char map[1000][1000];
int visit[1000][1000] = {0, }; //지훈이가 갔으면 1 불이 갔으면 2
queue<Info> jQ;
queue<Info> fQ;
vector<pair<int, int> > dir;

int R, C;

void init();
void solve();
bool jihoon(int);
void fire(int);


int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void print(){
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            cout<<visit[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}

bool jihoon(int time){
    while(!jQ.empty()){
        Info nowJ = jQ.front();
        
        if(nowJ.time != time) //현재 시간이랑 다르면 진행안함
            break;
        if(visit[nowJ.loc.first][nowJ.loc.second] == 2){ //현재 visit이 2로 된건 불이 닿았다는것
            jQ.pop(); //해당위치는 쓸모없게되었으므로 제거
            if(jQ.empty()){ //이 위치 빼곤 없었을 경우 탈출 실패
                cout<<"IMPOSSIBLE"<<endl;
                return false;
            }
            continue;
        }
        
        jQ.pop();
        visit[nowJ.loc.first][nowJ.loc.second] = 1;
        for(int i = 0 ; i < 4 ; i++){
            int xx = nowJ.loc.first + dir.at(i).first;
            int yy = nowJ.loc.second + dir.at(i).second;
            if( visit[xx][yy] != 0 || map[xx][yy] == '#'){
                continue;
            }
            
            if(xx < 0 || xx >= R || yy < 0 || yy >= C){ //만약에 탈출에 성공했다면
                cout<<nowJ.time + 1<<endl; //현재 시간에 +1
                return true;
            }
            
            visit[xx][yy] = 1; //방문한 곳에 1표시
            jQ.push({make_pair(xx, yy), nowJ.time + 1}); //다음 위치 표시
        }
//        cout<<"JIHOON TURN"<<endl;
//        print();
    }
    return false;
}

void fire(int time){
    while(!fQ.empty()){
        Info nowF = fQ.front();
        if(nowF.time != time){ //현재 시간이랑 다르면 진행 안함
            break;
        }
        fQ.pop();
        visit[nowF.loc.first][nowF.loc.second] = 2;
        for(int i = 0 ; i < 4 ; i++){
            int xx = nowF.loc.first + dir.at(i).first;
            int yy = nowF.loc.second + dir.at(i).second;
            if(xx < 0 || xx >= R || yy < 0 || yy >= C || visit[xx][yy] == 2 || map[xx][yy] == '#'){
                continue;
            }
            
            visit[xx][yy] = 2;
            //cout<<nowF.time<<endl;
            fQ.push({make_pair(xx, yy), nowF.time + 1});
        }
    }
//    cout<<"FIRE TURN"<<endl;
//    print();
}

void solve(){
    int time = 0;
    while(1){
//        cout<<time<<"번째"<<endl;
        if(jihoon(time))
            break;
        fire(time);
        time++;
    }
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>R>>C;
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            cin>>map[i][j];
            if(map[i][j] == 'J'){
                jQ.push({make_pair(i, j), 0});
                visit[i][j] = 1;
            }else if(map[i][j] == 'F'){
                fQ.push({make_pair(i, j), 0});
                visit[i][j] = 2;
            }
        }
    }
    
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
}
