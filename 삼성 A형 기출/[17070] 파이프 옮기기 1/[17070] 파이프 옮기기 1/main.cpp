//
//  main.cpp
//  [17070] 파이프 옮기기 1
//
//  Created by YOO TAEWOOK on 2020/03/15.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

enum STATUS {GARO, SERO, DAEGAK};

struct Pipe{
    pair<int, int> head;
    pair<int, int> tail;
    STATUS status; // 1 가로 2 세로 3 대각선
};

vector<vector<int> > initMap;

void init();
void solve(Pipe);
Pipe garo(Pipe);
Pipe sero(Pipe);
Pipe daegak(Pipe);

int N;
long long int cnt = 0;
Pipe pipe;

int main(int argc, const char * argv[]) {
    init();
    solve(pipe);
    cout<<cnt<<endl;
    return 0;
}

void solve(Pipe pipe){
    // 헤드 만 맵 넘어갈 가능성이 있다
    if(pipe.head.first < 0 || pipe.head.second < 0 || pipe.head.first >= N + 1 || pipe.head.second >= N + 1)
        return;
    // 현재 파이프의 상태가 가로 혹은 세로일 때 해드의 위치에 벽이 있는지 체크
    if(pipe.status == GARO || pipe.status == SERO){
        if(initMap[pipe.head.first][pipe.head.second] == -1)
            return;
    // 현재 파이프의 상태가 대각선일 때 해드의 주변에 벽이 있는지 체크
    }else if(pipe.status == DAEGAK){
        if(initMap[pipe.head.first][pipe.head.second] == -1)
            return;
        if(initMap[pipe.head.first][pipe.head.second - 1] == -1 || initMap[pipe.head.first - 1][pipe.head.second] == -1 )
            return;
    }
    // 끝에 도달했다면 경우의 수 증가시키고 종료
    if(pipe.head.first == N && pipe.head.second == N){
        cnt++;
        return;
    }
    
    if(pipe.status == GARO){ //가로일때
        solve(garo(pipe));
        solve(daegak(pipe));
    }else if(pipe.status == SERO){ //세로일때
        solve(sero(pipe));
        solve(daegak(pipe));
    }else if(pipe.status == DAEGAK){ //대각선일때
        solve(garo(pipe));
        solve(sero(pipe));
        solve(daegak(pipe));
    }
}

Pipe garo(Pipe pipe){
    if(pipe.status == GARO){
        pipe.head.second++;
        pipe.tail.second++;
    }else if(pipe.status == DAEGAK){
        pipe.head.second++;
        pipe.tail.first++;
        pipe.tail.second++;
        pipe.status = GARO;
    }
    return pipe;
}

Pipe sero(Pipe pipe){
    if(pipe.status == SERO){
        pipe.head.first++;
        pipe.tail.first++;
    }else if(pipe.status == DAEGAK){
        pipe.head.first++;
        pipe.tail.first++;
        pipe.tail.second++;
        pipe.status = SERO;
    }
    return pipe;
}

Pipe daegak(Pipe pipe){
    if(pipe.status == SERO){
        pipe.head.first++;
        pipe.head.second++;
        pipe.tail.first++;
        pipe.status = DAEGAK;
    }else if(pipe.status == GARO){
        pipe.head.first++;
        pipe.head.second++;
        pipe.tail.second++;
        pipe.status = DAEGAK;
    }else if(pipe.status == DAEGAK){
        pipe.head.first++;
        pipe.head.second++;
        pipe.tail.first++;
        pipe.tail.second++;
    }
    return pipe;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N;
    initMap.assign(N + 1, vector<int>(N + 1, 0));
    for(int i = 1 ; i < N + 1 ; i++){
        for(int j = 1; j < N + 1 ; j++){
            cin>>initMap[i][j];
            if(initMap[i][j] == 1)
                initMap[i][j] = -1;
        }
    }
    pipe.tail = make_pair(1, 1);
    pipe.head = make_pair(1, 2);
    pipe.status = GARO;
}
