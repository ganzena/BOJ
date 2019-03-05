//
//  main.cpp
//  [2583] 영역 구하기
//
//  Created by YOO TAEWOOK on 04/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
vector<pair<int, int>> square;
vector<int> zone;
vector<pair<int, int>> dir = {pair<int, int>(1, 0), pair<int, int>(-1, 0), pair<int, int>(0, 1), pair<int, int>(0, -1)};
int m, n, k;

void init();
void draw();
void BFS();
void print();

int main(int argc, const char * argv[]) {
    init();
    draw();
    BFS();
    print();
    return 0;
}

void print(){
    cout<<zone.size()<<endl;
    sort(zone.begin(), zone.end());
    for(int i : zone){
        cout<<i<<" ";
    }
    cout<<endl;
}

void BFS(){
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(map[i][j] == 0){
                int zoneSize = 1;
                map[i][j] = 1;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                while(!q.empty()){
                    pair<int, int> now = q.front();
                    q.pop();
                    
                    for(int l = 0 ; l < 4 ; l++){
                        pair<int, int> next = make_pair(now.first + dir.at(l).first, now.second + dir.at(l).second);
                        
                        if(next.first < 0 || next.first >= m || next.second < 0 || next.second >= n)
                            continue;
                        
                        if(map[next.first][next.second] == 0){
                            map[next.first][next.second] = 1;
                            q.push(make_pair(next.first, next.second));
                            zoneSize++;
                        }
                    }
                }
                zone.push_back(zoneSize);
            }
        }
    }
}

void draw(){
    for(int i = 0 ; i < square.size() - 1 ; i += 2){
        pair<int, int> left = make_pair(m - square.at(i).second - 1, square.at(i).first);
        pair<int, int> right = make_pair(square.at(i + 1).first - 1, square.at(i + 1).second - 1);
        right = make_pair(m - right.second - 1, right.first);
        for(int j = left.first ; j >= right.first ; j--){
            for(int l = left.second ; l <= right.second ; l++){
                map[j][l] = 1;
            }
        }
    }
}

void init(){
    cin>>m>>n>>k;
    for(int i = 0 ; i < k ; i++){
        int first, second;
        cin>>first>>second;
        square.push_back(make_pair(first,second));
        cin>>first>>second;
        square.push_back(make_pair(first,second));
    }
    map.assign(m, vector<int>(n, 0));
}
