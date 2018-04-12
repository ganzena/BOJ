//
//  main.cpp
//  Test 3
//
//  Created by YOO TAEWOOK on 2018. 3. 30..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <algorithm>
#include <limits.h>
#define SIZE 100001
using namespace std;

typedef pair<int, int> pii;

vector<pii> dir = {pii(-1, 0), pii(0, -1), pii(1, 0), pii(0, 1)};

int inputNum, counter = 0;
vector< vector<int> > adj(SIZE);
vector< bool > visited(SIZE, true);
void DFS(int);
int main(int argc, const char * argv[]) {
    cin>>inputNum;
    while(inputNum--){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        visited[x] = false;
        visited[y] = false;
    }
    
    for(int i = 1 ; i < SIZE ; i++){
        if(visited[i] == false){
            DFS(i);
            counter++;
        }
    }
    
    cout<<counter<<endl;
    return 0;
}

void DFS(int start){
    visited[start] = true;
    
    for(int i = 0 ; i < adj[start].size() ; i++){
        int base = adj[start][i];
        if(!visited[adj[start][i]]){
            DFS(adj[start][i]);
        }
    }
}

