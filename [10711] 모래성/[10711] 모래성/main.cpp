//
//  main.cpp
//  [10711] 모래성
//
//  Created by YOO TAEWOOK on 2020/09/23.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'

using namespace std;

vector<vector<int> > beach;
//vector<pair<int, int> > dir;
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0, -1, 1, 0, 1, -1};
queue<pair<int, int> > sandQ;
queue<pair<int, int> > delQ;

void init();
void solve();

int W, H;
int day = 0;

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void solve(){
    while(1){
        int qSize = (int)sandQ.size();
        int queueCnt = qSize;
        // 횟수 카운트 하기위해서 큐사이즈만큼만 실행
        while(queueCnt--){
            int cnt = 0;
            pair<int, int> now = sandQ.front();
            sandQ.pop();
            for(int i = 0 ; i < 8 ; i++){
                pair<int, int> next = pair<int, int>(now.first + dx[i], now.second + dy[i]);
                // 주변 탐색
                if(next.first >= H || next.first < 0 || next.second >= W || next.second < 0)
                    continue;
                // 파도가 있다면 카운트
                if(beach[next.first][next.second] == 0)
                    cnt++;
            }
            //무너질 모래는 delQ에 넣는다
            if(cnt >= beach[now.first][now.second])
                delQ.push(now);
            else
                sandQ.push(now);
        }
        // delQ에 있는 좌표를 모두 0으로 변환
        while(!delQ.empty()){
            beach[delQ.front().first][delQ.front().second] = 0;
            delQ.pop();
        }
        // 파도 친 횟수 카운트
        day++;
        // 탈출 조건
        if(qSize == (int)sandQ.size() || sandQ.empty())
            break;
    }
    cout<<day<<endl;
}

void init(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>H>>W;
    beach.assign(H, vector<int>(W, 0));
    for(int i = 0 ; i < H ; i++){
        string input;
        cin>>input;
        for(int j = 0 ; j < W ; j++){
            //파도는 0으로 변환
            if(input.at(j) == '.')
                beach[i][j] = 0;
            else{
                beach[i][j] = input.at(j) - '0';
                // 절대 무너지지 않을 모래성은 큐에 포함하지 않음
                if(beach[i][j] == 9)
                    continue;
                sandQ.push(pair<int, int>(i, j));
            }
        }
    }
    
//    dir.push_back(pair<int, int>(0, 1));
//    dir.push_back(pair<int, int>(0, -1));
//    dir.push_back(pair<int, int>(1, 1));
//    dir.push_back(pair<int, int>(1, -1));
//    dir.push_back(pair<int, int>(-1, -1));
//    dir.push_back(pair<int, int>(-1, 1));
//    dir.push_back(pair<int, int>(-1, 0));
//    dir.push_back(pair<int, int>(1, 0));
}
