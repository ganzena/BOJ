//
//  main.cpp
//  [2018 하][16234] 인구 이동
//
//  Created by YOO TAEWOOK on 2020/03/07.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int> > visit; // 연합 기록
vector<vector<int> > map;
vector<pair<int, int> > dir;

int N, L, R; // N : 땅 크기, 두 나라의 인구 차이가 L이상 R이하면 국경선 연다
void init();
void solve();
void print();

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void solve(){
    int cnt = 0; // 인구 이동 횟수
    int unionNo = 1; // 연합 번호
    while(1){
        // 연합 기록 시작
        visit.assign(N, vector<int>(N, 0));
        bool stop = true; // 연합이 생성 안 될 경우 종료
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(visit[i][j] != 0) //이미 연합에 들어가있는 칸이면 continue
                    continue;
                vector<pair<int, int> > unionV; //연합국 벡터
                queue<pair<int, int> > q; // BFS 큐
                q.push(make_pair(i, j));
                unionV.push_back(make_pair(i, j));
                int totalPeopleNum = map[i][j];
                while(!q.empty()){
                    pair<int, int> now = q.front();
                    q.pop();
                    visit[i][j] = unionNo;
                    for(int k = 0 ; k < 4 ; k++){
                        int ii = now.first + dir.at(k).first;
                        int jj = now.second + dir.at(k).second;
                        if(ii < 0 || jj < 0 || ii >= N || jj >= N || visit[ii][jj] != 0)
                            continue;
                        int gap = abs(map[now.first][now.second] - map[ii][jj]);
                        if(gap > R || gap < L)
                            continue;
                        visit[ii][jj] = unionNo;
                        
                        q.push(make_pair(ii, jj));
                        unionV.push_back(make_pair(ii, jj)); //연합국 벡터에 삽입
                        totalPeopleNum += map[ii][jj]; //연합 인구합
                        stop = false;
                    }
                }
                if(unionV.size() == 1){ // 연합에 참여한 나라가 없음
                    visit[i][j] = 0; // 연합 제외
                    continue;
                }else{
                    int countryNum = (int)unionV.size();
                    int moveNum = totalPeopleNum / countryNum;
                    for(int i = 0 ; i < unionV.size() ; i++){
                        int x = unionV.at(i).first;
                        int y = unionV.at(i).second;
                        map[x][y] = moveNum;
                    }
                }
                unionNo++;
            }
        }
        if(stop)
            break;
        cnt++;
    }
    cout<<cnt<<endl;
}

void init(){
    //freopen("input.txt", "r", stdin);
    cin>>N>>L>>R;
    // 맵 설정
    map.assign(N, vector<int>(N, 0));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>map[i][j];
        }
    }
    
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
}
