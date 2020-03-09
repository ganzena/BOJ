//
//  main.cpp
//  [2019 하][17825] 주사위 윷놀이
//
//  Created by YOO TAEWOOK on 2020/03/08.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Piece{
    int x = 0;
    int y = 0;
    int score = 0;
};

vector<Piece> pieceV;
vector<int> tempV;
vector<int> command;
vector<vector<bool> > visit;
int map[9][8] = {
    {0, 2, 4, 6, 8, 10, -1, -1},    //  0 : 0->10
    {10, 13, 16, 19, 25, -1, -1, -1},// 1 : 10~25(0~10's blue)
    {10, 12, 14, 16, 18, 20, -1, -1},// 2 : 10~20(0~10's red)
    {20, 22, 24, 25, -1, -1, -1, -1},// 3 : 20~25(10~20's blue)
    {20, 22, 24, 26, 28, 30, -1, -1},// 4 : 20~30(10~20's red)
    {30, 28, 27, 26, 25, -1, -1, -1},// 5 : 30~25(20~30's blue)
    {30, 32, 34, 36, 38, 40, -1, -1},// 6 : 30~40(20~30's red)
    {25, 30, 35, 40, -1, -1, -1, -1}, // 7 : 25~40
    {40, 0, -1, -1, -1, -1, -1, -1} // 8 : 도착
};

void init();
void solve(int);
void move();

int ans = 0;

int main(int argc, const char * argv[]) {
    init();
    solve(0);
    cout<<ans<<endl;
    return 0;
}

void move(){
    //말 리스트
    Piece piece;
    pieceV.assign(4, piece);
    visit.assign(9, vector<bool>(8, false));
    for(int i = 0 ; i < 10 ; i++){
        Piece* now = &pieceV.at(tempV.at(i)); // 움직일 말(tmpV의 번호는 pieceV의 index)
        int cmd = command.at(i); // 움직일 횟수
        visit[now->x][now->y] = false; // 움직이기 전 현 위치 미방문 처리 && 도착에 있는 말들은 미방문으로 처리
        if(now->x == 8 && now->y == 1) //현재 위치가 도착이면 진행 안 함
            continue;
        while(cmd-- > 0){
            int yy = now->y + 1;
            int nextScore = map[now->x][yy];
            if(now->x == 0 && nextScore == 10){
                if(cmd == 0){ //이동은 파란색 칸에서 끝나므로 파란 화살표로 이동해야함
                    now->x = 1; // 10 ~ 25
                }else{ //red
                    now->x = 2; // 10 ~ 20
                }
                now->y = 0;
            } else if(now->x == 1 && nextScore == 25){
                now->x = 7; // 25 ~ 40
                now->y = 0;
            } else if(now->x == 2 && nextScore == 20){ //현재 위치는 파란색 직전
                if(cmd == 0){ //이동은 파란색 칸에서 끝나므로 파란 화살표로 이동해야함
                    now->x = 3; //20~25
                }else{ //red
                    now->x = 4; //20~30
                }
                now->y = 0;
            } else if(now->x == 3 && nextScore == 25){ //20~25
                now->x = 7; // 25 ~ 40
                now->y = 0;
            } else if(now->x == 4 && nextScore == 30){ //20~30
                if(cmd == 0){ //이동은 파란색 칸에서 끝나므로 파란 화살표로 이동해야함
                    now->x = 5; //20~25
                }else{ //red
                    now->x = 6; //20~30
                }
                now->y = 0;
            } else if(now->x == 5 && nextScore == 25){ //30~25
                now->x = 7; //25~40
                now->y = 0;
                
            } else if(now->x == 6 && nextScore == 40){ //30~40
                now->x = 8; //40 ~ 종료
                now->y = 0;
            } else if(now->x == 7 && nextScore == 40){ //25~40
                now->x = 8; ///40 ~ 종료
                now->y = 0;
            } else if(now->x == 8 && nextScore == -1){ //도착에 도달
                break;
            } else{
                now->y++;
            }
        }
        // 이동이 끝난 자리가 이미 말이 있다면 테스트케이스에서 제외
        // 도착에 도달했던 말은
        if(visit[now->x][now->y])
            return;
        now->score += map[now->x][now->y]; //현재 위치의 점수를 더한다
        if(now->x != 8 || now->y != 1) //도착은 방문 처리 안함
            visit[now->x][now->y] = true; //방문 표시를 한다.
    }
    int sum = 0;
    for(int i = 0 ; i < 4 ; i++){
        sum += pieceV.at(i).score;
    }
    ans = max(ans, sum);
}

void solve(int depth){
    if(depth == 10){
        move();
        return;
    }
    
    for(int i = 0 ; i < 4 ; i++){ // 명령을 수행할 말들의 조합
        tempV.push_back(i);
        solve(depth + 1);
        tempV.pop_back();
    }
}

void init(){
    freopen("input.txt", "r", stdin);
    for(int i = 0 ; i < 10 ; i++){
        int temp;
        cin>>temp;
        command.push_back(temp);
    }
}
