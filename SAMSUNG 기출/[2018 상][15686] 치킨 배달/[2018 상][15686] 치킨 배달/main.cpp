//
//  main.cpp
//  [2018 상][15686] 치킨 배달
//
//  Created by YOO TAEWOOK on 2020/03/13.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<vector<int> > initMap;
vector<pair<int, int> > chickenV;
vector<pair<int, int> > tempV; // 치킨집 뽑아 놓을 벡터
vector<pair<int, int> > houseV;

int N, M; // N 맵 크기 1부터 시작, M 선택할 치킨집 수
int ans = INT_MAX;

void init();
void solve(int, int);
void check();

int main(int argc, const char * argv[]) {
    init();
    solve(0, 0);
    cout<<ans<<endl;
    return 0;
}

void check(){
    int sum = 0;
    for(int i = 0 ; i < (int)houseV.size() ; i++){
        int temp = INT_MAX;
        for(int j = 0 ; j < (int)tempV.size() ; j++){ //거리 측정
            temp = min(temp, abs(houseV.at(i).first - tempV.at(j).first) + abs(houseV.at(i).second - tempV.at(j).second));
        }
        sum += temp;
    }
    ans = min(ans, sum); //최솟값 업데이트
}

void solve(int depth, int index){
    if(depth == M){
        check();
        return;
    }
    
    for(int i = index ; i < (int)chickenV.size() ; i++){
        tempV.push_back(chickenV.at(i)); //치킨집 중 M개를 뽑아 저장
        solve(depth + 1, i + 1);
        tempV.pop_back();
    }
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N>>M;
    initMap.assign(N + 1, vector<int>(N + 1,0));
    for(int i = 1 ; i < N + 1 ; i++){
        for(int j = 1 ; j < N + 1 ; j++){
            cin>>initMap[i][j];
            if(initMap[i][j] == 2)
                chickenV.push_back(make_pair(i, j));
            else if(initMap[i][j] == 1)
                houseV.push_back(make_pair(i, j));
        }
    }
}
