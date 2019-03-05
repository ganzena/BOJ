//
//  main.cpp
//  [6593] 상범 빌딩
//
//  Created by YOO TAEWOOK on 05/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

#define MAX_INT 987654321

using namespace std;

struct Location{
    pair<int, int> point;
    int floor;
};

vector<vector<char>> floor;
vector< vector<vector<char>> > building;

vector<vector<int>> timeFloor;
vector<vector<vector<int>>> timeBuilding;

vector<pair<int, int>> dir = {pair<int, int>(0, 1), pair<int, int>(0, -1), pair<int, int>(1, 0), pair<int, int>(-1, 0)};

int L, R, C; // L : 층 수, R : 한 층의 행, C : 한 층의 열

Location start, out;

void init();
void BFS();
void print();
void clear();

int main(int argc, const char * argv[]) {
    while(1){
        cin>>L>>R>>C;
        if(L == 0 && R == 0 && C == 0)
            break;
        init();
        BFS();
        print();
        clear();
    }
    return 0;
}

void clear(){
    timeBuilding.clear();
    building.clear();
}

void print(){
    int cost = timeBuilding.at(out.floor)[out.point.first][out.point.second];
    if(cost == MAX_INT)
        cout<<"Trapped!"<<endl;
    else
        cout<<"Escaped in "<<cost<<" minute(s)."<<endl;
}

void BFS(){
    queue<Location> q;
    q.push(start);
    timeBuilding.at(start.floor)[start.point.first][start.point.second] = 0;
    while(!q.empty()){
        Location now = q.front();
        q.pop();
        int nextTime = timeBuilding.at(now.floor)[now.point.first][now.point.second] + 1;
        for(int i = 0 ; i < 4 ; i++){
            Location next = {make_pair(now.point.first + dir.at(i).first, now.point.second + dir.at(i).second), now.floor};
            if(next.point.first < 0 || next.point.first >= R || next.point.second < 0 || next.point.second >= C){
                continue;
            }
            
            if(timeBuilding.at(next.floor)[next.point.first][next.point.second] > nextTime && building.at(next.floor)[next.point.first][next.point.second] == '.'){
                timeBuilding.at(next.floor)[next.point.first][next.point.second] = nextTime;
                q.push(next);
            }
        }
        Location down = {now.point, now.floor - 1};
        Location up = {now.point, now.floor + 1};
        
        if(down.floor >= 0){
            if(timeBuilding.at(down.floor)[down.point.first][down.point.second] > nextTime && building.at(down.floor)[down.point.first][down.point.second] == '.'){
                timeBuilding.at(down.floor)[down.point.first][down.point.second] = nextTime;
                q.push(down);
            }
        }
        
        if(up.floor < L){
            if(timeBuilding.at(up.floor)[up.point.first][up.point.second] > nextTime && building.at(up.floor)[up.point.first][up.point.second] == '.'){
                timeBuilding.at(up.floor)[up.point.first][up.point.second] = nextTime;
                q.push(up);
            }
        }
    }
}

void init(){
    int top = L;
    while(top > 0){
        timeFloor.assign(R, vector<int>(C, MAX_INT));
        floor.assign(R, vector<char>(C, ' '));
        for(int i = 0 ; i < R ; i++){
            for(int j = 0 ; j < C ; j++){
                cin>>floor[i][j];
                if(floor[i][j] == 'S'){
                    start = {make_pair(i, j), L - top};
                }
                if(floor[i][j] == 'E'){
                    out = {make_pair(i, j), L - top};
                    floor[i][j] = '.';
                }
            }
        }
        top--;
        building.push_back(floor);
        timeBuilding.push_back(timeFloor);
    }
}
