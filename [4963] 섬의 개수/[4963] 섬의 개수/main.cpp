//
//  main.cpp
//  [4963] 섬의 개수
//
//  Created by YOO TAEWOOK on 2020/09/18.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > map;
vector<vector<bool> > visited;
vector<pair<int, int> > dir;

int h, w;
void solve();

void solve(){
    queue<pair<int, int> > q;
    int count = 0;
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            if(map[i][j] == 1 && visited[i][j] == false){
                q.push(pair<int, int>(i, j));
                while(!q.empty()){
                    pair<int, int> now = q.front();
                    q.pop();
                    for(int d = 0 ; d < dir.size() ; d++){
                        pair<int, int> next = pair<int, int>(now.first + dir.at(d).first, now.second + dir.at(d).second);
                        if(next.first >= h || next.first < 0 || next.second >= w || next.second < 0)
                            continue;
                        if(visited[next.first][next.second] == true || map[next.first][next.second] == 0)
                            continue;
                        q.push(next);
                        visited[next.first][next.second] = true;
                    }
                }
                count++;
            }
        }
    }
    cout<<count<<endl;
}

int main(int argc, const char * argv[]) {
    freopen("input.txt", "read", stdin);
    dir.push_back(pair<int, int>(1, 0));
    dir.push_back(pair<int, int>(-1, 0));
    dir.push_back(pair<int, int>(1, 1));
    dir.push_back(pair<int, int>(1, -1));
    dir.push_back(pair<int, int>(-1, 1));
    dir.push_back(pair<int, int>(-1, -1));
    dir.push_back(pair<int, int>(0, 1));
    dir.push_back(pair<int, int>(0, -1));
    
    while(1){
        cin>>w>>h;
        if(w == 0 && h == 0)
            break;
        map.assign(h, vector<int>(w, 0));
        visited.assign(h, vector<bool>(w, false));
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                cin>>map[i][j];
            }
        }
        solve();
    }
    return 0;
}
