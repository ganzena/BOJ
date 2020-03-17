//
//  main.cpp
//  [17136] 색종이 붙이기
//
//  Created by YOO TAEWOOK on 2020/03/15.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > map;;
vector<vector<int> > initVisit;
vector<int> paperV;

void init();
void solve(int, int);
bool coverCheck(int, int, int);
void makeCover(int, int, int);
void update();
void print(vector<vector<int> >);
bool allCover(vector<vector<int> >);

int ans = 25;
int cnt = 0;

int main(int argc, const char * argv[]) {
    init();
    solve(0, 0);
    if(ans == 25)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    return 0;
}

// num 사이즈의 정사각형으로 덮이는지 판단
bool coverCheck(int x, int y, int num){
    for(int i = x ; i < x + num ; i++){
        for(int j = y ; j < y + num ; j++){
            if(map[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}
// 색종이 덮기
void makeCover(int x, int y, int num){
    for(int i = x ; i < x + num ; i++){
        for(int j = y ; j < y + num ; j++){
            map[i][j] = 0;
        }
    }
}
// 덮었던 거 다시 열기
void initCover(int x, int y, int num){
    for(int i = x ; i < x + num ; i++){
        for(int j = y ; j < y + num ; j++){
            map[i][j] = 1;
        }
    }
}
// 작업이 끝난 후 사용한 색종이 최솟값 갱신
void updateMin(){
    int temp = 25;
    for(int i = 1; i < 6 ; i++){
        temp -= paperV.at(i);
    }
    ans = min(ans, temp);
}

// 재귀 안에서 쓰는 것들은 되도록이면 전역변수를 쓸 것
// 벡터 같은거 선언 및 할당하면 시간 많이 걸림
void solve(int i, int j){
    if(j == 10){ // 마지막 열에 도달하면 다음 행으로
        solve(i + 1, 0);
        return;
    }
    if(i == 10){ // 마지막 행을 넘으면 모든 작업이 끝난 것
        ans = min(ans, cnt); // 최솟값 업데이트
        return;
    }
    if(map[i][j] == 0){
        solve(i, j + 1);
        return;
    }
    for(int k = 5 ; k > 0 ; k--){ // 크기 별 색종이가 덮일 수 있는지 판단
        if(paperV.at(k) == 0 || i + k > 10 || j + k > 10)
            continue;
        bool canCover = coverCheck(i, j, k);
        if(canCover){
            cnt++;
            paperV.at(k)--;
            makeCover(i, j, k); // 색종이 덮어두고 (0)
            solve(i, j);
            //재귀 호출 이후 원상복구
            paperV.at(k)++;
            cnt--;
            initCover(i, j, k);
        }
    }
    return;
}

void print(vector<vector<int> > visit){
    for(int i = 0 ; i < 10 ; i ++){
        for(int j = 0 ; j < 10 ; j++){
            cout<<visit[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    map.assign(10, vector<int>(10, 0));
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            cin>>map[i][j];
        }
    }
    paperV.assign(6, 5);
}
