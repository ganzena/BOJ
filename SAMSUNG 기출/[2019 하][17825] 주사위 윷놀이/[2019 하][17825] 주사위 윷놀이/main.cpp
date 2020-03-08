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
        visit[now->x][now->y] = false;
        if(map[now->x][now->y + 1] == -1)
            continue;
        // 이동이 불가능할 경우 첫 위치로 재설정해야함
        int initX = now->x;
        int initY = now->y;
        // 이동 성공 플래그
        bool success = true;
        while(cmd-- > 0){
            int yy = now->y + 1;
            int nextScore = map[now->x][yy];
            if(now->x == 0){
                if(nextScore == 10){ //현재 위치는 파란색 직전
                    if(cmd == 0){ //이동은 파란색 칸에서 끝나므로 파란 화살표로 이동해야함
                        now->x = 1;
                        now->y = 0;
                        if(visit[now->x][now->y]){
                            success = false;
                            break;
                        }
                        now->score += map[now->x][now->y];
                    }else{ //red
                        now->x = 2;
                        now->y = 0;
                    }
                }else{
                    if(cmd == 0){ // 같은 행 내 이동
                        now->y++;
                        if(visit[now->x][now->y]){
                            success = false;
                            break;
                        }
                        now->score += map[now->x][now->y];
                    }else{
                        now->y++;
                    }
                }
            }else if(now->x == 1){ // 10 ~ 25
                if(nextScore == 25){ //현재 위치는 파란색 직전
                    if(cmd == 0){ //이동은 파란색 칸에서 끝나므로 파란 화살표로 이동해야함
                        now->x = 7; //25 ~ 40
                        now->y = 0;
                        if(visit[now->x][now->y]){
                            success = false;
                            break;
                        }
                        now->score += map[now->x][now->y];
                    }else{ //red
                        now->x = 7; //20~30
                        now->y = 0;
                    }
                }else{
                    if(cmd == 0){ // 같은 행 내 이동
                        now->y++;
                        if(visit[now->x][now->y]){
                            success = false;
                            break;
                        }
                        now->score += map[now->x][now->y];
                    }else{
                        now->y++;
                    }
                }
                
            }else if(now->x == 2){ // 10 ~ 20
                if(nextScore == 20){ //현재 위치는 파란색 직전
                    if(cmd == 0){ //이동은 파란색 칸에서 끝나므로 파란 화살표로 이동해야함
                        now->x = 3; //20~25
                        now->y = 0;
                        if(visit[now->x][now->y] ){
                            success = false;
                            break;
                        }
                        now->score += map[now->x][now->y];
                    }else{ //red
                        now->x = 4; //20~30
                        now->y = 0;
                    }
                }else{
                    if(cmd == 0){ // 같은 행 내 이동
                        now->y++;
                        if(visit[now->x][now->y]){
                            success = false;
                            break;
                        }
                        now->score += map[now->x][now->y];
                    }else{
                        now->y++;
                    }
                }
                
            }else if(now->x == 3){ //20~25
                if(nextScore == 25){ //현재 위치는 파란색 직전
                    if(cmd == 0){ //이동은 파란색 칸에서 끝나므로 파란 화살표로 이동해야함
                        now->x = 7; //25~40
                        now->y = 0;
                        if(visit[now->x][now->y]){
                            success = false;
                            break;
                        }
                        now->score += map[now->x][now->y];
                    }else{ //red
                        now->x = 7; //25~40
                        now->y = 0;
                    }
                }else{
                    if(cmd == 0){ // 같은 행 내 이동
                        now->y++;
                        if(visit[now->x][now->y]){
                            success = false;
                            break;
                        }
                        now->score += map[now->x][now->y];
                    }else{
                        now->y++;
                    }
                }
                
            }else if(now->x == 4){ //20~30
                if(nextScore == 30){ //현재 위치는 파란색 직전
                    if(cmd == 0){ //이동은 파란색 칸에서 끝나므로 파란 화살표로 이동해야함
                        now->x = 5; //20~25
                        now->y = 0;
                        if(visit[now->x][now->y]){
                            success = false;
                            break;
                        }
                        now->score += map[now->x][now->y];
                    }else{ //red
                        now->x = 6; //20~30
                        now->y = 0;
                    }
                }else{
                    if(cmd == 0){ // 같은 행 내 이동
                        now->y++;
                        if(visit[now->x][now->y]){
                            success = false;
                            break;
                        }
                        now->score += map[now->x][now->y];
                    }else{
                        now->y++;
                    }
                }
            }else if(now->x == 5){ //30~25
                if(nextScore == 25){ //현재 위치는 파란색 직전
                    if(cmd == 0){ //이동은 파란색 칸에서 끝나므로 파란 화살표로 이동해야함
                        now->x = 7; //25~40
                        now->y = 0;
                        if(visit[now->x][now->y]){
                            success = false;
                            break;
                        }
                        now->score += map[now->x][now->y];
                    }else{ //red
                        now->x = 7; //25~40
                        now->y = 0;
                    }
                }else{
                    if(cmd == 0){ // 같은 행 내 이동
                        now->y++;
                        if(visit[now->x][now->y]){
                            success = false;
                            break;
                        }
                        now->score += map[now->x][now->y];
                    }else{
                        now->y++;
                    }
                }
            }else if(now->x == 6){ //30~40
                if(nextScore == 40){ //현재 위치는 도착
                    if(cmd == 0){ //이동은 파란색 칸에서 끝나므로 파란 화살표로 이동해야함
                        now->x = 8; //25~40
                        now->y = 0;
                        if(visit[now->x][now->y]){
                            success = false;
                            break;
                        }
                        now->score += map[now->x][now->y];
                    }else{ //red
                        now->x = 8; //25~40
                        now->y = 0;
                    }
                }else{
                    if(cmd == 0){ // 같은 행 내 이동
                        now->y++;
                        if(visit[now->x][now->y]){
                            success = false;
                            break;
                        }
                        if(map[now->x][now->y] == 40 && visit[7][3]){
                            success = false;
                            break;
                        }
                        now->score += map[now->x][now->y];
                    }else{
                        now->y++;
                    }
                }
            }else if(now->x == 7){ //25~40
                if(nextScore == 40){ //현재 위치는 도착
                    if(cmd == 0){ //이동은 파란색 칸에서 끝나므로 파란 화살표로 이동해야함
                        now->x = 8; //25~40
                        now->y = 0;
                        if(visit[now->x][now->y]){
                            success = false;
                            break;
                        }
                        now->score += map[now->x][now->y];
                    }else{ //red
                        now->x = 8; //25~40
                        now->y = 0;
                    }
                }else{// 같은 행 내 이동
                    if(cmd == 0){ // 같은 행 내 이동
                        now->y++;
                        if(visit[now->x][now->y]){
                            success = false;
                            break;
                        }
                        now->score += map[now->x][now->y];
                    }else{
                        now->y++;
                    }
                }
            }else if(now->x == 8){ //40 도착
                if(nextScore == -1){ //현재 위치는 도착
                    break;
                }else{// 같은 행 내 이동
                    if(cmd == 0){ // 같은 행 내 이동
                        now->y++;
                        if(visit[now->x][now->y]){
                            success = false;
                            break;
                        }
                        now->score += map[now->x][now->y];
                    }else{
                        now->y++;
                    }
                }
            }
        }
        if(!success){
            now->x = initX;
            now->y = initY;
        }
        visit[now->x][now->y] = true;
//        cout<<tempV.at(i)<<"가 "<<command.at(i)<<" 번 이동 : ("<<map[initX][initY]<<") -> "<<map[now->x][now->y]<<endl;
    }
//    cout<<"--------------------------------------"<<endl;
    int sum = 0;
    for(int i = 0 ; i < 4 ; i++){
        sum += pieceV.at(i).score;
    }
    ans = max(ans, sum);
}

void solve(int depth){
    if(depth == 10){
        // 만들어진 tempV로 말 이동
        move();
        return;
    }
    
    for(int i = 0 ; i < 4 ; i++){
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
