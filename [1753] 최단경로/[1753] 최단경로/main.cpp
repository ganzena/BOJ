//
//  main.cpp
//  [1753] 최단경로
//
//  Created by YOO TAEWOOK on 2020/09/18.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define endl "\n"

using namespace std;

class Edge{
public:
    int next;
    int weight;
    
    Edge(int next, int weight){
        this->next = next;
        this->weight = weight;
    }
    
    bool operator <(const Edge& b) const{
        return this->weight > b.weight;
    }
    
    bool operator >(const Edge& b) const{
        return this->weight > b.weight;
    }
};

//priority_queue less 옵션 : 내림차순(큰 값이 top) greater 옵션 : 오름차순(작은 값이 top)

vector<Edge> edgeInfo [20001];
priority_queue<Edge> pq; // 이렇게만 써주려면 priority_queue의 기본 옵션이 less이므로 클래스 내에 less(<)에 대한 정의가 필요
//priority_queue<Edge, vector<Edge>, greater<vector<Edge>::value_type> > pq; // greater를 쓰고싶으면 less를 재정의하거나 greater(>)를 재정의 한뒤 씀
//priority_queue<Edge, vector<Edge>, Compare> pq;
//priority_queue<Edge, vector<Edge>, Compare> pq;
int dist[20001];
int V, E;
int start;

void init();
void dijkstra();
void print();
void printQ();

int main(int argc, const char * argv[]) {
    init();
    dijkstra();
    print();
    return 0;
}

void print(){
    for(int i = 1 ; i <= V ; i++){
        if(dist[i] == INT_MAX)
            cout<<"INF"<<endl;
        else
            cout<<dist[i]<<endl;
    }
}

void dijkstra(){
    dist[start] = 0;
    Edge edge = Edge(start, 0);
    pq.push(edge);
    while(!pq.empty()){
        //printQ();
        Edge now = pq.top();
        pq.pop();
        //기록된 거리가 현재 측정된 거리보다 짧으면 업데이트 안 함
        if(dist[now.next] < now.weight){
            continue;
        }
        for(int j = 0 ; j < edgeInfo[now.next].size() ; j++){
            // 연결된 노드들의 거리 기록
            int nextNode = edgeInfo[now.next][j].next;
            int nextDist = edgeInfo[now.next][j].weight + now.weight;
            // 연결된 다음 노드까지의 거리와 현재 위치에서 간 거리를 비교
            if(nextDist <= dist[nextNode]){
                dist[nextNode] = nextDist;
                pq.push(Edge(nextNode, nextDist));
            }
        }
    }
}

void init(){
    //freopen("input.txt", "read", stdin);
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>V>>E;
    cin>>start;
    
    //거리 초기화
    for(int i = 1 ; i < V + 1 ; i++){
        dist[i] = INT_MAX;
    }

    // 간선 정보 저장
    for(int i = 0 ; i < E ; i++){
        int start, end, weight;
        cin>>start>>end>>weight;
        Edge edge = Edge(end, weight);
        edgeInfo[start].push_back(edge);
    }
}

void printQ(){
    cout<<pq.top().next<<", weight = "<<pq.top().weight<<endl;
}
