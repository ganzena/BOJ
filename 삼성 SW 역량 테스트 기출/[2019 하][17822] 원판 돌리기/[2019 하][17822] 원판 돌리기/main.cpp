//
//  main.cpp
//  [2019 하][17822] 원판 돌리기
//
//  Created by YOO TAEWOOK on 2020/03/10.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

struct Command{
    int no;
    int dir;
    int cnt;
};

vector<vector<int> > circles; //원판들
vector<pair<int, int> > direction; //방향
vector<Command> commands; //명령 벡터

void init();
void solve();
void rotate(Command); // 시계 방향
void erase();

int N, M, T; // N : 원판 갯수 -> 벡터 선언시 N+1로 선언/ M : 정수 갯수 / T : 회전수

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void solve(){
    for(int i = 0 ; i < (int)commands.size() ; i++){
        Command cmd = commands.at(i);
        rotate(cmd); // 회전
        erase(); // 인접수들 지우기
    }
    int sum = 0;
    for(int i = 1; i < N + 1 ; i++){
        for(int j = 0; j < M ; j++){
            sum += circles[i][j];
        }
    }
    cout<<sum<<endl;
}

void erase(){
    bool isDeleted = false; // 지워진 인접수가 있느냐
    vector<vector<bool> > visit; //BFS 를 위한 방문 벡터
    visit.assign(N + 1, vector<bool>(M, false));

    for(int i = 1 ; i < N + 1; i++){
        for(int j = 0;  j < M ; j++){
            int target = circles[i][j];
            if(target == 0 || visit[i][j]) //이미 지워진 숫자 continue
                continue;
            queue<pair<int, int> > q;
            queue<pair<int, int> > dQ; // 지워질 수를 담는 큐
            dQ.push(make_pair(i, j));
            q.push(make_pair(i, j));
            while(!q.empty()){
                pair<int, int> now = q.front();
                q.pop();
                visit[i][j] = true;
                for(int k = 0 ; k < 4 ; k++){
                    pair<int, int> next = make_pair(now.first + direction.at(k).first, now.second + direction.at(k).second);
                    if(next.second < 0) // 양 끝에 대한 보정
                        next.second = M - 1;
                    else if(next.second >= M) // 양 끝에 대한 보정
                        next.second = 0;
                    if(next.first < 1 || next.first >= N + 1 || visit[next.first][next.second] || circles[next.first][next.second] != target )
                        continue;
                    visit[next.first][next.second] = true;
                    q.push(next);
                    dQ.push(next); //인접수가 있으므로 지울 큐에 푸시
                }
            }
            if(dQ.size() > 1){ //인접수가 있는것
                while(!dQ.empty()){
                    pair<int, int> del = dQ.front();
                    dQ.pop();
                    circles[del.first][del.second] = 0; //인접수 0으로 제거
                }
                isDeleted = true;
            }
        }
    }
    if(!isDeleted){ // 지워진 수가 없었다면 평균 구해야함
        double sum = 0;
        int cnt = 0;
        for(int i = 1 ; i < N + 1 ; i++){
            for(int j = 0 ; j < M ; j++){
                if(circles[i][j] != 0){
                    sum += circles[i][j];
                    cnt++;
                }
            }
        }
        if(cnt == 0)
            return;
        double avg = sum / cnt;
        for(int i = 1 ; i < N + 1 ; i++){
            for(int j = 0 ; j < M ; j++){
                if(circles[i][j] == 0)
                    continue;
                if(circles[i][j] > avg) // 평균보다 크면 -1
                    circles[i][j]--;
                else if(circles[i][j] < avg) // 평균보다 작으면 +1
                    circles[i][j]++;
            }
        }
    }
}

void rotate(Command cmd){
    int i = cmd.no;
    int plus = i; // 배수를 찾아 더해질 수
    int cnt = cmd.cnt;
    if(cnt == 0)
        return;
    
    while(i < N + 1){
        deque<int> tempDq (circles.at(i).begin(), circles.at(i).end());
        if(cmd.dir == 1){ // 반시계 방향
            for(int j = 0 ; j < cnt ; j++){
                int tempInt = tempDq.front();
                tempDq.pop_front();
                tempDq.push_back(tempInt);
            }
        }else{ // 시계 방향
            for(int j = 0 ; j < cnt ; j++){
                int tempInt = tempDq.back();
                tempDq.pop_back();
                tempDq.push_front(tempInt);
            }
        }
        
        for(int j = 0 ; j < M; j++){
            circles[i][j] = tempDq.front();
            tempDq.pop_front();
        }
        if(i != 1){ // 배수에 해당하는 원판들도 다 회전시킨다
            i += plus;
        }else{
            break;
        }
    }
}

void init(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M>>T;
    circles.assign(N + 1, vector<int>(M, 0));
    for(int i = 1 ; i < N + 1; i++){
        for(int j = 0; j < M; j++){
            cin>>circles[i][j];
        }
    }
    while(T-- > 0){
        Command temp;
        cin>>temp.no>>temp.dir>>temp.cnt;
        commands.push_back(temp);
    }
    
    direction.push_back(make_pair(0, 1));
    direction.push_back(make_pair(0, -1));
    direction.push_back(make_pair(1, 0));
    direction.push_back(make_pair(-1, 0));
}
