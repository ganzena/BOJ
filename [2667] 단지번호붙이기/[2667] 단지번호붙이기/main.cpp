//
//  main.cpp
//  [2667] 단지번호붙이기
//
//  Created by YOO TAEWOOK on 02/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visited;
vector<pair<int, int>> dir = {pair<int, int>(0, 1), pair<int, int>(0, -1), pair<int, int>(1, 0), pair<int, int>(-1, 0)};
vector<int> danji;
int n;

void init();
void print();
void BFS(int, int);

int main(int argc, const char * argv[]) {
    init();
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(map[i][j] == 1 && visited[i][j] == false)
                BFS(i, j);
        }
    }
    print();
    return 0;
}

void print(){
    sort(danji.begin(), danji.end());
    cout<<danji.size()<<endl;
    for(int i = 0 ; i < danji.size() ; i++){
        cout<<danji.at(i)<<endl;
    }
}

void BFS(int first, int second){
    queue<pair<int, int>> q;
    q.push(pair<int, int>(first, second));
    visited[first][second] = true;
    int count = 1;
    while(!q.empty()){
        pair<int, int> curLoc = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            pair<int, int> nextLoc = make_pair(curLoc.first + dir[i].first, curLoc.second + dir[i].second);
            
            if(nextLoc.first < 0 || nextLoc.first >= n || nextLoc.second < 0 || nextLoc.second >= n)
                continue;
            
            if(visited[nextLoc.first][nextLoc.second] == false && map[nextLoc.first][nextLoc.second] == 1){
                visited[nextLoc.first][nextLoc.second] = true;
                count++;
                q.push(nextLoc);
            }
        }
    }
    danji.push_back(count);
}

void init(){
    cin>>n;
    map.assign(n, vector<int>(n, 0));
    visited.assign(n, vector<bool>(n, false));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            //cin>>map[i][j];
            scanf("%1d", &map[i][j]);
        }
    }
}
