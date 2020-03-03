//
//  main.cpp
//  [9663] N-Queen
//
//  Created by YOO TAEWOOK on 29/02/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > map;
vector<pair<int, int> > dir;

void init();
void solve(int, int);
bool check(int, int);

int N;
int ans = 0;

int main(int argc, const char * argv[]) {
    init();
    solve(0,0);
    cout<<ans<<endl;
    return 0;
}

bool check(int i, int j){ //적절한 위치에 놓였는지 체크
    for(int d = 0 ; d < dir.size() ; d++){
        int ii = i;
        int jj = j;
        while(1){
            ii += dir.at(d).first;
            jj += dir.at(d).second;
            if(ii < 0 || jj < 0 || ii >= N || jj >= N) //맵 밖을 벗어나면 break
                break;
            if(map[ii][jj] == 1) // 해당 방향에 이미 퀸이 있는 경우 false 리턴
                return false;
        }
    }
    
    return true;
}

void solve(int depth, int i){
    if(depth == N){
        ans++;
        return;
    }
    for(int j = 0 ; j < N ; j++ ){
        map[i][j] = 1; // 해당 위치에 퀸을 놓는다.
        if(check(i, j)) //
            solve(depth + 1, i + 1);
        map[i][j] = 0; // 해당 위치 초기화
    }
}

void init(){
    //freopen("input.txt", "r", stdin);
    cin>>N;
    map.assign(N, vector<int>(N, 0));
    dir.push_back(make_pair(-1, 0)); //북
    dir.push_back(make_pair(-1, 1)); //북서
    dir.push_back(make_pair(-1, -1)); //북동
    // 퀸을 배치할 때 같은 행에 배치 하지 않으므로 동 서 체크 안함
    // 북쪽부터 채우므로 남동 남 남서 체크 안함
    
}
