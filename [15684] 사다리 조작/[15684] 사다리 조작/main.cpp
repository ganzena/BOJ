//
//  main.cpp
//  [15684] 사다리 조작
//
//  Created by YOO TAEWOOK on 31/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
/**
 1. N 개의 세로선, M 개의 가로선
 2. 각각의 세로선에 놓을 수 있는 가로선의 갯수 H
 3. 새로 놓는 가로선은, 두 가로선이 연속되거나 접하면 안됨
 
 */

using namespace std;
struct Ladder{
    bool leftLink;
    bool rightLink;
};

int N, M, H, answer = 4;
bool result = false;
vector<vector<int>> map;
vector<vector<Ladder>> copied;
vector<pair<int, int>> dir = {make_pair(0, -1), make_pair(0, 1), make_pair(-1, 0)};
void init();
void DFS(int, int, int);
void print();
bool test();


int main(int argc, const char * argv[]) {
    init();
    if(M == 0){
        cout<<0<<endl;
        return 0;
    }
    if(test()){
        cout<<0<<endl;
        return 0;
    }
    DFS(0, 1, 0);
    
    if(answer == 4)
        cout<<-1<<endl;
    else
        cout<<answer<<endl;
    
    return 0;
}

void print(int n){
    if(n == 2){
        cout<<"[ "<< n<<" ] 번 째"<<endl;
        for(int i = 1 ; i <= H ; i++){
            for(int j = 0 ; j < N ; j++){
                cout<<map[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

void DFS(int depth, int startI, int startJ){
    //print(depth);
    if(depth >= answer){
        return;
    }
    if(depth < 3){
        if(test()){
            print(depth);
            answer = min(answer, depth);
            return;
        }
    }
    
    if(depth == 3){
        if(test()){
            print(depth);
            answer = min(answer, depth);
        }
        return;
    }
    
    for(int i = startI ; i <= H ; i++){
        for(int j = startJ ; j < N-1 ; j++){
            if(map[i][j] == 0 || map[i][j + 1] == 0){
                map[i][j] = 1;
                map[i][j + 1] = 1;
                DFS(depth + 1, i, 0);
                map[i][j] = 0;
                map[i][j + 1] = 0;
            }
        }
    }
}

bool test(){
    for(int j = 0 ; j < N ; j++){
        pair<int, int> now = make_pair(0, j);
        vector<vector<bool>> visited;
        visited.assign(H + 2, vector<bool>(N, false));
        visited[now.first][now.second] = true;
        bool flag = false;
        while(now.first < H + 1){
            bool leftFlag = false;
            bool rightFlag = false;
            pair<int, int> left = make_pair(now.first, now.second - 1);
            pair<int, int> right = make_pair(now.first, now.second + 1);
            if(flag == true && left.second >= 0 && left.second < N && map[left.first][left.second] == 1 && !visited[left.first][left.second]){
                leftFlag = true;
            }
            if(flag == true && right.second >= 0 && right.second < N && map[right.first][right.second] == 1 && !visited[right.first][right.second]){
                rightFlag = true;
            }
            if(!leftFlag && !rightFlag){
                if(!visited[now.first + 1][now.second]){
                    now = make_pair(now.first + 1, now.second);
                    visited[now.first][now.second] = true;
                    flag = true;
                    if(now.first == H + 1){
                        if(now.second != j)
                            return false;
                        else
                            break;
                    }
                    
                }
            }else if(leftFlag){
                now = left;
                visited[now.first][now.second] = true;
                flag = false;
            }else{
                now = right;
                visited[now.first][now.second] = true;
                flag = false;
            }
        }
    }
    return true;
}


void init(){
    cin>>N>>M>>H;
    map.assign(H + 2, vector<int>(N, 0));
    for(int i = 0 ; i < M ; i++){
        int first, second;
        cin>>first>>second;
        second--;
        map[first][second] = 1;
        map[first][second + 1] = 1;
    }
}
