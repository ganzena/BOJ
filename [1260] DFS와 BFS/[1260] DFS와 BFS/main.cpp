//
//  main.cpp
//  [1260] DFS와 BFS
//
//  Created by YOO TAEWOOK on 2018. 1. 25..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void BFS(vector< vector<int> > &, vector<bool> &, int); // &을 붙여준 이유 : 메모리 초과가 나지 않기 위해 레퍼런스로 넘김
void DFS(vector< vector<int> > &, vector<bool> &, int);

int main(int argc, const char * argv[]) {
    int vertexNum; // vertex의 갯수
    int edgeNum; // edge의 갯수
    int vertexSrc; // 시작 vertex 번호
    
    vector<bool> visited;
    vector<int> element;
    vector< vector<int> > adj; // 인접 행렬
    
    cin>>vertexNum>>edgeNum>>vertexSrc;

    vertexNum++;
    
    visited.assign(vertexNum, false); // 방문 벡터 초기화

    for(int i = 0 ; i < vertexNum ; i++){ // 2차원 벡터
        element.resize(vertexNum);
        adj.push_back(element);
    }
    
    for(int i = 0 ; i < vertexNum ; i++){ // 인접행렬 0으로 초기화
        for(int j = 0 ; j < vertexNum ; j++){
            adj[i][j] = 0;
        }
    }
    
    while(edgeNum > 0){ // 인접한 vertex 설정
        int vertex1, vertex2;
        cin>>vertex1 >> vertex2;
        
        adj[vertex1][vertex2] = 1;
        adj[vertex2][vertex1] = 1;
        edgeNum--;
    }
    DFS(adj, visited, vertexSrc);
    cout<<endl;
    visited.clear();
    visited.assign(vertexNum, false); // 방문 벡터 초기화

    BFS(adj, visited, vertexSrc);
    cout<<endl;

    
    return 0;
}

void BFS(vector< vector<int> > &adj, ::vector<bool> &visited, int source){
    queue<int> queue;
    visited[source] = true;
    queue.push(source);
    while(!queue.empty()){
        int temp = queue.front();
        cout<< temp <<' ';
        queue.pop();
        for(int i = 0 ; i < adj[0].size() ; i++){
            if(!visited[i] && adj[temp][i] == 1){
                visited[i] = true;
                queue.push(i);
            }
        }

    }
}

void DFS(vector< vector<int> > &adj, ::vector<bool> &visited, int source){
    visited[source] = true;
    cout<<source<<" ";
    
    for(int i = 0 ; i < adj[0].size() ; i++)
        if(adj[source][i] == 1 && !visited[i])
            DFS(adj, visited, i);
    
}
