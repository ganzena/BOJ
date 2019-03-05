//
//  main.cpp
//  [10026] 적록색약
//
//  Created by YOO TAEWOOK on 03/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> map;
vector<vector<bool>> visited;
vector<pair<int, int>> dir = {pair<int, int>(1, 0), pair<int, int>(-1, 0), pair<int, int>(0, 1), pair<int, int>(0, -1)};
int n;
int yes, no = 0;

void init();
void BFS(bool);
void print();
int main(int argc, const char * argv[]) {
    init();
    BFS(true);
    BFS(false);
    print();
    return 0;
}

void print(){
    cout<<yes<<" "<<no<<endl;
}

void BFS(bool canSee){
    visited.assign(n, vector<bool>(n, false));
    if(canSee == true){
        queue<pair<int, int>> q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(visited[i][j] == false){
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                    while(!q.empty()){
                        pair<int, int> now = q.front();
                        q.pop();
                        for(int k = 0 ; k < 4 ; k++){
                            pair<int, int> next = make_pair(now.first + dir.at(k).first, now.second + dir.at(k).second);
                            
                            if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= n)
                                continue;
                            
                            if(visited[next.first][next.second] == false && map[next.first][next.second] == map[now.first][now.second]){
                                
                                visited[next.first][next.second] = true;
                                q.push(next);
                            }
                        }
                    }
                    yes++;
                }
            }
        }
    }else{
        queue<pair<int, int>> q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(visited[i][j] == false){
                    char base = map[i][j];
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                    while(!q.empty()){
                        pair<int, int> now = q.front();
                        q.pop();
                        for(int k = 0 ; k < 4 ; k++){
                            pair<int, int> next = make_pair(now.first + dir.at(k).first, now.second + dir.at(k).second);
                            
                            if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= n)
                                continue;
                            
                            if(visited[next.first][next.second] == false){
                                if(base == 'R' || base == 'G'){
                                    if(map[next.first][next.second] == 'R' || map[next.first][next.second] == 'G'){
                                        visited[next.first][next.second] = true;
                                        q.push(next);
                                    }
                                }else{
                                    if(map[next.first][next.second] == base){
                                        visited[next.first][next.second] = true;
                                        q.push(next);
                                    }
                                }
                            }
                        }
                    }
                    no++;
                }
            }
        }
    }
}

void init(){
    cin>>n;
    map.assign(n, vector<char>(n,' '));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>map[i][j];
        }
    }
}
