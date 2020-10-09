//
//  main.cpp
//  [2606] 바이러스
//
//  Created by YOO TAEWOOK on 2020/09/18.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> network [101];
bool visited [101];

int computerNum;
int caseNum;

void init();
void solve();

int main(int argc, const char * argv[]) {
    init();
    solve();
    //print();
    return 0;
}

void solve(){
    int start = 1;
    int answer = 0;
    queue<int> q;
    q.push(start); // 시작점
    visited[1] = true;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0 ; i < network[now].size() ; i++){
            int next = network[now][i];
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
                answer++;
            }
        }
    }
    cout<<answer<<endl;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>computerNum;
    cin>>caseNum;
    for(int i = 0 ; i < caseNum ; i++){
        int com1, com2;
        cin>>com1>>com2;
        network[com1].push_back(com2);
        network[com2].push_back(com1);
    }
}
