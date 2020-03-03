//
//  main.cpp
//  [17779] 게리맨더링 2
//
//  Created by YOO TAEWOOK on 29/02/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<vector<int> > map;
vector<vector<int> > sector;
vector<int> sum;

void init();
void solve();
void mark(int, int);
void five(int ,int, int , int);
void numbering(int ,int, int , int);
void print(int, int, int, int);

int N;
int ans = INT_MAX;

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N;
    map.assign(N+1, vector<int>(N+1,0));
    sum.assign(6, 0);
    for(int i = 1 ; i < N+1 ;i++){
        for(int j = 1 ; j < N+1 ; j++){
            cin>>map[i][j];
        }
    }
}

void solve(){
    for(int i = 1 ; i < N+1 ;i++){
        for(int j = 1 ; j < N+1 ; j++){
            mark(i, j);
        }
    }
    cout<<ans<<endl;
}

void mark(int x, int y){ //기준점
    vector<vector<int> > initSector;
    initSector.assign(N + 1, vector<int>(N + 1, 0));
    int d1limit = y - 1;
    int d2limit = N - y;
    int d1d2limit = N - x;
    //5번 선거구
    for(int d1 = 1 ; d1 <= d1limit; d1++){
        for(int d2 = 1 ; d2 <= d2limit ; d2++){
            if(d1+d2 > d1d2limit)
                break;
            sector = initSector;
            five(x, y, d1, d2);
            numbering(x, y, d1, d2);
            int maximum = INT_MIN;
            int minimum = INT_MAX;
            for(int i = 1 ; i < sum.size() ; i++){
                maximum = max(maximum, sum.at(i));
                minimum = min(minimum, sum.at(i));
                sum.at(i) = 0;
            }
            ans = min(ans, maximum-minimum);
        }
    }
}

void five(int x, int y, int d1, int d2){
    sector[x][y] = 5;
    sum.at(5) += map[x][y];
    queue<pair<int, int> > q;
    int xx = x;
    int yy = y;
    while(1){ //위->왼
        xx++;
        yy--;
        if(xx > x + d1 || yy < y - d1)
            break;
        sector[xx][yy] = 5;
        sum.at(5) += map[xx][yy];
    }
    
    xx = x;
    yy = y;
    while(1){ //위->오
        xx++;
        yy++;
        if(xx > x + d2 || yy > y + d2)
            break;
        sector[xx][yy] = 5;
        sum.at(5) += map[xx][yy];
        q.push(make_pair(xx, yy)); // 오른쪽에서 왼쪽으로 채울 좌표 추가
    }
    
    xx = x + d1;
    yy = y - d1;
    while(1){ //왼->아
        xx++;
        yy++;
        if(xx > x + d1 + d2 || yy > y - d1 + d2)
            break;
        sector[xx][yy] = 5;
        sum.at(5) += map[xx][yy];
    }
    
    xx = x + d2;
    yy = y + d2;
    while(1){ //오->아
        xx++;
        yy--;
        if(xx >= x + d1 + d2 || yy <= y + d2 - d1)
            break;
        sector[xx][yy] = 5;
        sum.at(5) += map[xx][yy];
        q.push(make_pair(xx, yy)); // 오른쪽에서 왼쪽으로 채울 좌표 추가
    }
    
    
    while(!q.empty()){ // 오른쪽 선 기준으로 5 채우기
        pair<int,int> s = q.front();
        q.pop();
        int xx = s.first;
        int yy = s.second;
        
        int j = yy;
        while(1){
            if(sector[xx][--j] == 5)
                break;
            sector[xx][j] = 5;
            sum.at(5) += map[xx][j];
        }
    }
}

void numbering(int x, int y, int d1, int d2){
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            if(sector[i][j] == 5)
                continue;
            if(i < x + d1 && j <= y){
                sector[i][j] = 1;
                sum.at(1) += map[i][j];
            }else if(i <= x + d2 && j <= N && y < j){
                sector[i][j] = 2;
                sum.at(2) += map[i][j];
            }else if(x + d1 <= i && i <= N && j < y - d1 + d2){
                sector[i][j] = 3;
                sum.at(3) += map[i][j];
            }else if(x + d2 < i && i <= N && j <= N && y-d1+d2 <= j){
                sector[i][j] = 4;
                sum.at(4) += map[i][j];
            }
        }
    }
}

void print(int x, int y, int d1, int d2){
    cout<<x<<" "<<y<<" "<<d1<<" "<<d2<<endl;
    for(int i = 1 ; i < N+1 ;i++){
        for(int j = 1 ; j < N+1 ; j++){
            cout<<sector[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    
    for(int i = 1; i < 6 ; i++){
        cout<<i<<"/"<<sum.at(i)<<" ";
    }cout<<endl;
    cout<<endl;
}
