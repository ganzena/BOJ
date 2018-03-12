//
//  main.cpp
//  [1325] 효율적인 해킹
//
//  Created by YOO TAEWOOK on 2018. 3. 7..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

void DFS(vector< vector<int> > &, vector<bool> &, int);
int counter;

int main(int argc, const char * argv[]) {
    int num, test, node1, node2;
    cin>>num>>test;
    num++;
    vector<bool> visited;
    vector< vector<int> > adj(num); //2차원 배열
    vector<int> max(num);
    vector<int> answer;
    int maxCnt = 0;
    
    while (test--) {
        cin>>node1>>node2;
        adj[node2].push_back(node1);
    }
   
    for(int i = 1 ; i < num ; i++){
        counter = 0;
        visited = vector<bool>(num, false);
        DFS(adj, visited, i);
        //cout<<i<<"일 때 counter : "<<counter<<endl;
        max.at(i) = counter;
        if(maxCnt < counter)
            maxCnt = counter;
    }
    
    for(int i = 0 ; i < max.size() ; i++){
        if(max.at(i) == maxCnt)
            answer.push_back(i);
    }
    
    sort(answer.begin(), answer.end());
    for(int i = 0 ; i < answer.size() ; i++)
        cout<<answer.at(i)<<" ";
    
    cout<<endl;
    
    return 0;
}

void DFS(vector< vector<int> > & adj, vector<bool> & visited, int start){
    visited[start] = true;
    
    for(int i = 0 ; i < adj[start].size() ; i++){
        if(!visited[adj[start][i]]){
            counter++;
            DFS(adj, visited, adj[start][i]);
        }
    }
}


