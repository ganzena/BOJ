//
//  main.cpp
//  [2019 하][17837] 새로운 게임 2
//
//  Created by YOO TAEWOOK on 2020/03/07.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Piece{ //체스 말
    int no; // 말 번호
    int x, y; //위치
    int d; //방향
};

vector<vector<int> > map; // 0 흰색 1 빨강 2 파랑
vector<Piece> pieceMap[13][13]; // 말들의 위치를 표현할 배열
vector<pair<int, int> > dir;
vector<Piece> pieceVector; //말들의 정보를 저장할 벡터

int N, K; // 체스판의 크기(1부터 시작), 갯수
Piece initPiece = {0, 0, 0, 0};  //말의 초기화 정보
int turn = 0;

void init();
void solve();
void blue(Piece&);
void white(Piece&, int, int);
void red(Piece&, int, int);
int reverseDir(int);
void redReverse(Piece&);
bool check(Piece);
void print();

int main(int argc, const char * argv[]) {
    init();
    solve();
    if(turn > 1000)
        cout<<-1<<endl;
    else
        cout<<turn<<endl;
    return 0;
}

int reverseDir(int dir){
    if(dir == 1){
        return 2;
    }else if(dir == 2){
        return 1;
    }else if(dir == 3){
        return 4;
    }else if(dir == 4){
        return 3;
    }
    return 0;
}

void white(Piece& piece, int xx, int yy){
    vector<Piece>::iterator iter;
    vector<Piece>::iterator tempIter;
    vector<Piece> tempV;
    
    for(iter = pieceMap[piece.x][piece.y].begin() ; iter != pieceMap[piece.x][piece.y].end() ; iter ++){
        if(iter->no == piece.no){ //현재 옮김의 대상인 말 발견
            tempIter = iter; //iter 값이 바뀌므로 tempIter에 초기 Iter 저장
            for(; iter != pieceMap[piece.x][piece.y].end() ; iter++){
                tempV.push_back(*iter); //tempV에 현재 대상인 말 위의 말들을 모두 삽입
            }
            break;
        }
        
    }
    iter = tempIter; //iter 값 복구 (현재 맵(벡터)에서 옮기는 대상을 가리키고 있음)
    pieceMap[piece.x][piece.y].erase(iter, pieceMap[piece.x][piece.y].end()); // 대상 이후부터 쭉 삭제
    
    piece.x = xx; //말 위치 변경
    piece.y = yy; //말 위치 변경
    for(int i = 0 ; i < tempV.size() ; i++){ //위에 있는 말들의 정보 업데이트
        tempV.at(i).x = xx;
        tempV.at(i).y = yy;
        pieceMap[xx][yy].push_back(tempV.at(i));
        pieceVector.at(tempV.at(i).no).x = xx; //pieceVector의 인덱스는 말의 번호와 일치한다
        pieceVector.at(tempV.at(i).no).y = yy;
    }
}

void red(Piece& piece, int xx, int yy){
    vector<Piece>::iterator iter;
    vector<Piece>::iterator tempIter;
    vector<Piece> tempV;
    
    for(iter = pieceMap[piece.x][piece.y].begin() ; iter != pieceMap[piece.x][piece.y].end() ; iter ++){
        if(iter->no == piece.no){
            tempIter = iter;
            for(; iter != pieceMap[piece.x][piece.y].end() ; iter++){
                tempV.push_back(*iter);
            }
            break;
        }
    }
    
    iter = tempIter;
    
    pieceMap[piece.x][piece.y].erase(iter, pieceMap[piece.x][piece.y].end());
    
    piece.x = xx;
    piece.y = yy;
    for(int i = (int)tempV.size() - 1 ; i >= 0; i--){ //흰색과 이 부분만 다르다. (거꾸로 넣는거)
        tempV.at(i).x = xx;
        tempV.at(i).y = yy;
        pieceMap[xx][yy].push_back(tempV.at(i));
        pieceVector.at(tempV.at(i).no).x = xx;
        pieceVector.at(tempV.at(i).no).y = yy;
    }
}

void blue(Piece& piece){
    // 방향 반대로 하고 한 칸 이동 이떄 그 뒤도 파란색이면 이동하지않고 방향만 바꿈
    piece.d = reverseDir(piece.d);
    int xx = piece.x + dir.at(piece.d).first; // 말이 움직일 다음 좌표
    int yy = piece.y + dir.at(piece.d).second;
    if(xx < 1 || yy < 1 || xx > N || yy > N || map[xx][yy] == 2){ //맵을 벗어나거나 파란색인 경우
        //방향만 바꾸고 끝
        for(int i = 0 ; i < pieceMap[piece.x][piece.y].size() ; i++){
            if(pieceMap[piece.x][piece.y].at(i).no == piece.no){
                pieceMap[piece.x][piece.y].at(i).d = piece.d;
                break;
            }
        }
        
        return;
    }else{ // 그게 아니면
        if(map[xx][yy] == 0){ // 하얀색으로 가거나
            white(piece, xx, yy);
        }else{ // 빨간색으로 가거나
            red(piece, xx, yy);
        }
    }
    return;
}

void solve(){
    while(++turn <= 1000){
        for(int i = 1 ; i < pieceVector.size() ; i++){
            Piece& now = pieceVector.at(i);
            int d = now.d; // 말의 방향
            int xx = now.x + dir.at(d).first; // 말이 움직일 다음 좌표
            int yy = now.y + dir.at(d).second;
            if(xx < 1 || yy < 1 || xx > N || yy > N || map[xx][yy] == 2){ //파란색인 경우
                blue(now);
            }else if(map[xx][yy] == 1){ //빨간색인 경우
                red(now, xx, yy);
            }else if(map[xx][yy] == 0){ //하얀색인 경우
                white(now, xx, yy);
            }

            if(pieceMap[now.x][now.y].size() >= 4) //새로 옮긴 좌표에 말이 4개 이상 있으면 종료
                return;
        }
    }
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N>>K;
    map.assign(N + 1, vector<int>(N + 1, 0));
    
    for(int i = 1 ; i < N + 1 ; i++){
        for(int j = 1 ; j < N + 1 ; j++){
            cin>>map[i][j];
        }
    }
    pieceVector.push_back(initPiece); //인덱스 보정 위한 쓰레기값 추가
    for(int i = 1 ; i < K+1 ; i++){
        Piece p ;
        p.no = i;
        cin>>p.x>>p.y>>p.d;
        pieceVector.push_back(p);
        pieceMap[p.x][p.y].push_back(p);
    }
    
    // 방향 설정
    dir.push_back(make_pair(0, 0)); //방향벡터 인덱스 보정 위한 쓰레기값 추가
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(-1, 0));
    dir.push_back(make_pair(1, 0));
}
