//
//  main.cpp
//  [18808] 스티커 붙이기
//
//  Created by YOO TAEWOOK on 2020/03/25.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

struct Sticker{ //스티커 정보
    int r;
    int c;
    vector<vector<int> > sticker;
};

vector<vector<int> > map;
vector<vector<bool> > visited;
vector<Sticker> stickerV;
int N, M, K; //세로 가로 스티커 갯수

void init();
void solve();
bool check(int, int, int); // 붙일 수 있는 곳인지 확인
void rotate(int);
void cover();
void print();


int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

bool check(int x , int y, int no){ // 이 스티커를 붙일수 있는지 확인
    Sticker now = stickerV.at(no);
    for(int i = x ; i < x + now.r ; i++){
        for(int j = y ; j < y + now.c ; j++){
            if(i >= N || j >= M)
                return false;
            if(map[i][j] == 1 && now.sticker[i - x][j - y] == 1) // 둘다 1이면 안됨
                return false;
        }
    }
    return true;
}

void rotate(int no){ // 90도 회전
    Sticker target = stickerV.at(no);
    vector<vector<int> > now = stickerV.at(no).sticker;
    vector<vector<int> > next;
    next.assign(target.c, vector<int>(target.r, 0));
    for(int i = 0 ; i < target.r ; i++){
        for(int j = 0 ; j < target.c ; j++){
            next[j][target.r - i - 1] = now[i][j];
        }
    }
    stickerV.at(no).r = target.c;
    stickerV.at(no).c = target.r;
    stickerV.at(no).sticker = next;
}

void cover(int x, int y, int no){ // 스티커 붙이기
    Sticker now = stickerV.at(no);
    for(int i = x ; i < x + now.r ; i++){
        for(int j = y ; j < y + now.c ; j++){
            if(map[i][j] == 0)
                map[i][j] = now.sticker[i - x][j - y];
        }
    }
}

void solve(){
    bool isCovered = false;
    int rotateCnt = 0;
    for(int k = 0 ; k < stickerV.size() ; k++){
        isCovered = false;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(check(i, j, k)){
                    cover(i, j, k);
                    isCovered = true;
                    break;
                }
            }
            if(isCovered)
                break;
        }
        if(isCovered){ // 스티커 붙이기 성공했으면
            rotateCnt = 0; // 회전 수 초기화
        }else{
            rotateCnt++;
            if(rotateCnt == 4){
                rotateCnt = 0;
            }else{
                rotate(k);
                k--;
            }
        }
    }
    
    int count = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(map[i][j] == 1)
                count++;
        }
    }
    cout<<count<<endl;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N>>M>>K;
    map.assign(N, vector<int>(M, 0));
    for(int k = 0 ; k < K ; k++){
        Sticker init;
        cin>>init.r>>init.c;
        init.sticker.assign(init.r, vector<int>(init.c, 0));
        for(int i = 0 ; i < init.r ; i++){
            for(int j = 0 ; j < init.c ; j++){
                cin>>init.sticker[i][j];
            }
        }
        stickerV.push_back(init); // 스티커 정보 저장
    }
}

