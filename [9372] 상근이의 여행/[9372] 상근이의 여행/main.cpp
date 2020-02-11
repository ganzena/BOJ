//
//  main.cpp
//  [9372] 상근이의 여행
//
//  Created by YOO TAEWOOK on 10/02/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool> > map;
vector<pair<int, bool> > visit;
int N, M;
void init();
void solve();
int ans = 0 ;


int main(int argc, const char * argv[]) {
    //freopen("input.txt", "r", stdin);
    int tc;
    cin>>tc;
    while(tc > 0){
        init();
        tc--;
    }
    return 0;
}



void init(){
    cin>>N>>M;
    map.assign(N + 1, vector<bool>(N + 1, false));
    for(int i = 0 ;i <= N ; i++){
        visit.push_back(make_pair(i, false));
    }
    for(int i = 0 ; i < M ; i++){
        int x, y;
        cin>>x>>y;
        map[x][y] = true;
        map[y][x] = true;
    }
    
    cout<<N - 1 <<endl;
}
