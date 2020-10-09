//
//  main.cpp
//  [1916] 최소비용 구하기
//
//  Created by YOO TAEWOOK on 2020/09/25.
//

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define endl "\n"
using namespace std;

class Edge{
public:
    int node;
    int dist;
    
    Edge(int a, int b){
        this->node = a;
        this->dist = b;
    }
    
    bool operator <(const Edge& a) const{
        return this->dist > a.dist;
    }
};

vector<Edge> edgeInfo [1001];
int dist[1001];

void init();
void solve();

int N, M;
int startPoint, endPoint;

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void solve(){
    // 자기 자신의 거리는 0으로 셋팅(출발지)
    dist[startPoint] = 0;
    priority_queue<Edge> pq;
    pq.push(Edge(startPoint, 0));
    while(!pq.empty()){
        // 현재 위치한 node
        Edge now = pq.top();
        pq.pop();
        // 출발지로부터의 비용과 
        if(dist[now.node] < now.dist)
            continue;
        for(int i = 0; i < edgeInfo[now.node].size() ; i++){
            int nextNode = edgeInfo[now.node][i].node;
            int nextDist = edgeInfo[now.node][i].dist + now.dist;
            if(nextDist < dist[nextNode]){
                dist[nextNode] = nextDist;
                pq.push(Edge(nextNode, nextDist));
            }
        }
    }
    
    cout<< dist[endPoint] <<endl;
}

void init(){
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    cin>>M;
    // 간선 정보 저장
    for(int i = 0 ; i < M ; i++){
        int start, end, dist;
        cin>>start>>end>>dist;
        edgeInfo[start].push_back(Edge(end, dist));
    }
    cin>>startPoint>>endPoint;
    
    // DP 전 모든 dist 최대로 초기화
    for(int i = 1 ; i <= N ; i++){
        dist[i] = INT_MAX;
    }
}
