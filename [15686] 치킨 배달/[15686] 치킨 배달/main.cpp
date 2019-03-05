//
//  main.cpp
//  [15686] 치킨 배달
//
//  Created by YOO TAEWOOK on 19/02/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
vector<pair<int, int>> houseVector;
vector<pair<int, int>> chickenVector;
vector<pair<int, int>> tempVector;
vector<int> houseTemp;
int n, m; // n 맵 크기 m 최대 치킨집 수
int minLen = 99999;

void init();
void dfs(int, int);
int main(int argc, const char * argv[]) {
    init();
    dfs(0, 0);
    cout<<minLen<<endl;
    return 0;
}

void init(){
    cin>>n>>m;
    map.assign(n, vector<int>(n, 0));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>map[i][j];
            if(map[i][j] == 1){
                houseVector.push_back(make_pair(i, j));
            }else if(map[i][j] == 2){
                chickenVector.push_back(make_pair(i, j));
            }
        }
    }
}

void dfs(int depth, int index){
    if(depth == m){
        int sum = 0;
        for(pair<int, int> h : houseVector){
            int len = 999999;
            for(pair<int, int> c : tempVector){
                int comp = abs(h.first - c.first) + abs(h.second - c.second);
                len = min(len, comp);
            }
            sum += len;
        }
        minLen = min(minLen, sum);
        
        return;
    }
    
    for(int i = index ; i < chickenVector.size() ; i++){
        tempVector.push_back(chickenVector.at(i));
        dfs(depth + 1, i + 1);
        tempVector.pop_back();
    }
}
