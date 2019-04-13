//
//  main.cpp
//  [3190] 뱀
//
//  Created by YOO TAEWOOK on 2018. 3. 26..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> map;
vector<pair<int, int>> dir = {make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0) };
queue<pair<int, char>> command;
pair<int, int> head;
pair<int, int> tail;
pair<int, int> headChangLoc;

int N, K, L;
int playTime = 1;
int headDir = 0;

void init();
void run();
void print(int);
int main(int argc, const char * argv[]) {
    init();
    run();
    cout<<playTime<<endl;
    return 0;
}

void run(){
    while(1){
        pair<int, int> nextHead = make_pair(head.first + dir.at(headDir).first, head.second + dir.at(headDir).second);
        if(nextHead.first < 0 || nextHead.first >= N || nextHead.second < 0 || nextHead.second >= N || map[nextHead.first][nextHead.second].first == 1)
            break;

        if(map[nextHead.first][nextHead.second].first == 2){
            map[nextHead.first][nextHead.second].first = 1;
            map[nextHead.first][nextHead.second].second = headDir;
            head = nextHead;
        }else{
            map[nextHead.first][nextHead.second].first = 1;
            map[nextHead.first][nextHead.second].second = headDir;
            head = nextHead;
            pair<int, int> nowTailDir = dir.at(map[tail.first][tail.second].second);
            map[tail.first][tail.second] = make_pair(0, -1);
            tail = make_pair(tail.first + nowTailDir.first, tail.second + nowTailDir.second);
            map[tail.first][tail.second].first = 1;
        }
        
        if(playTime == command.front().first){
            char cmd = command.front().second;
            command.pop();
            int nextDir;
            if(cmd == 'L'){
                nextDir = (headDir + 3)%4;
            }else{
                nextDir = (headDir + 1)%4;
            }
            headDir = nextDir;
            map[head.first][head.second].second = nextDir;
        }
        playTime++;
    }
}

void init(){
    cin>>N>>K;
    map.assign(N, vector<pair<int, int>>(N, make_pair(0, -1)));
    for(int i = 0 ; i < K ; i++){
        int r,c;
        cin>>r>>c;
        map[--r][--c].first = 2; //2 == apple
    }
    cin>>L;
    for(int i = 0 ; i < L ; i++){
        pair<int, char> cmd;
        cin>>cmd.first>>cmd.second;
        command.push(cmd);
    }
    head = tail = make_pair(0, 0);
    map[0][0] = make_pair(1, 0);
}
