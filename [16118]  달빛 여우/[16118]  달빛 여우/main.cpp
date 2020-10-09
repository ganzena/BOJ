//
//  main.cpp
//  [16118]  달빛 여우
//
//  Created by YOO TAEWOOK on 2020/09/25.
//

#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#define endl "\n"

using namespace std;

class Edge{
public:
    int node;
    int dist;
    Edge(int node, int dist){
        this->node = node;
        this->dist = dist;
    }
    bool operator <(const Edge& edge) const{
        return this->dist > edge.dist;
    }
};

priority_queue<Edge> pq;
vector<Edge> edgeInfo[4001];
int foxDistArr [4001];
int wolfDistArr [4001];

int treeNum, roadNum;

void init();
void foxDijkstra();
void wolfDijkstra();
void print();

int main(int argc, const char * argv[]) {
    init();
    foxDijkstra();
    wolfDijkstra();
    print();
    // 최단경로 기록 초기화
    return 0;
}


void init(){
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>treeNum>>roadNum;
    
    // 최단경로 기록 초기화
    for(int i = 1 ; i <= 4000 ; i++){
        foxDistArr[i] = INT_MAX;
        wolfDistArr[i] = INT_MAX;
    }
    
    // 간성 정보 셋팅
    for(int i = 0 ; i < roadNum ; i++){
        int start, end, dist;
        cin>>start>>end>>dist;
        edgeInfo[start].push_back(Edge(end, dist));
    }
}

void print(){
    int count = 0;;
    for(int i = 1 ; i <= treeNum ; i++){
        if(foxDistArr[i] < wolfDistArr[i]){
            count++;
        }
    }
    cout<<count<<endl;
}

void foxDijkstra(){
    foxDistArr[1] = 0;
    pq.push(Edge(1, 0));
    while(!pq.empty()){
        Edge now = pq.top();
        pq.pop();
        if(now.dist < foxDistArr[now.node])
            continue;
        for(int i = 0 ; i < edgeInfo[now.node].size(); i++){
            int nextNode = edgeInfo[now.node][i].node;
            int nextDist = edgeInfo[now.node][i].dist * 2 + now.dist;
            if(foxDistArr[nextNode] > nextDist){
                foxDistArr[nextNode] = nextDist;
                pq.push(Edge(nextNode, nextDist));
            }
        }
    }
    
    while(!pq.empty()){
        pq.pop();
    }
}

void wolfDijkstra(){
    bool canBoost = true;
    wolfDistArr[1] = 0;
    pq.push(Edge(1, 0));
    while(!pq.empty()){
        Edge now = pq.top();
        pq.pop();
        if(now.dist < wolfDistArr[now.node])
            continue;
        for(int i = 0 ; i < edgeInfo[now.node].size(); i++){
            int nextNode = edgeInfo[now.node][i].node;
            int nextDist;
            if(canBoost){
                nextDist = edgeInfo[now.node][i].dist + now.dist;
                canBoost = false;
            }else{
                nextDist = edgeInfo[now.node][i].dist * 4 + now.dist;
                canBoost = true;
            }
             
            if(wolfDistArr[nextNode] > nextDist){
                wolfDistArr[nextNode] = nextDist;
                pq.push(Edge(nextNode, nextDist));
            }
        }
    }
}
