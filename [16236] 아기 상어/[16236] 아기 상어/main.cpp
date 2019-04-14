//
//  main.cpp
//  [16236] 아기 상어
//
//  Created by YOO TAEWOOK on 25/02/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Shark{
    pair<int, int> loc;
    int size;
    int exp;
    int time;
};

typedef pair<int, int> pii;
vector< vector<int> > map;
vector< vector<bool> > visited;
//vector< pii > dir = {pii(0, 1), pii(-1, 0), pii(0, -1), pii(1, 0)};
vector< pii > dir;

Shark shark;
int n;
int sec = 0;

void init();
void BFS();
void print();

int main(int argc, const char * argv[]) {
    init();
    BFS();
    cout<<shark.time<<endl;
    return 0;
}

void init(){
    cin>>n;
    map.assign(n, vector<int>(n, 0));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>map[i][j];
            if(map[i][j] == 9){
//                shark.loc = make_pair(i, j);
//                shark.size = 2;
//                shark.exp = 2;
//                shark.time = 0;
                shark = {make_pair(i, j), 2, 2, 0};
                map[i][j] = 0;
            }
        }
    }
    //dir = {pii(0, 1), pii(-1, 0), pii(0, -1), pii(1, 0)};

    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(-1, 0));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
}

void BFS(){
    while(1){
        visited.assign(n, vector<bool>(n, false));
        queue<Shark> q;
        queue<Shark> fishQ;
        q.push(shark);
        visited[shark.loc.first][shark.loc.second] = true;
        
        int minTime = -1;
        while(!q.empty()){
            Shark nowShark = q.front();
            if(nowShark.time == minTime)
                break;
            q.pop();
            pair<int, int> nowLoc = nowShark.loc;
            for(int i = 0 ; i < 4 ; i++){
                pair<int, int> nextLoc = make_pair(nowLoc.first + dir.at(i).first, nowLoc.second + dir.at(i).second);
                
                if(nextLoc.first < 0 || nextLoc.first >= n || nextLoc.second < 0 || nextLoc.second >= n)
                    continue;
                
                if(visited[nextLoc.first][nextLoc.second] == false && map[nextLoc.first][nextLoc.second] <= nowShark.size){
                    visited[nextLoc.first][nextLoc.second] = true;
                    Shark tempShark = nowShark;
                    tempShark.time++;
                    tempShark.loc = nextLoc;
                    if(map[nextLoc.first][nextLoc.second] < tempShark.size && map[nextLoc.first][nextLoc.second] != 0){
                        minTime = tempShark.time;
                        fishQ.push(tempShark);
                    }
                    q.push(tempShark);
                }
            }
        }
        if(minTime < 0)
            break;
        
        Shark nextShark = fishQ.front();
        while(!fishQ.empty()){
            Shark tempShark = fishQ.front();
            fishQ.pop();
            if(tempShark.loc.first < nextShark.loc.first){
                nextShark = tempShark;
            }else if(tempShark.loc.first == nextShark.loc.first){
                if(tempShark.loc.second < nextShark.loc.second){
                    nextShark = tempShark;
                }
            }
        }
        
        map[nextShark.loc.first][nextShark.loc.second] = 0;
        nextShark.exp--;
        if(nextShark.exp == 0){
            nextShark.size++;
            nextShark.exp = nextShark.size;
        }
        shark = nextShark;
    }
}


