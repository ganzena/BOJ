//
//  main.cpp
//  [12851] 숨바꼭질 2
//
//  Created by YOO TAEWOOK on 2018. 3. 24..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define MAX 100001

using namespace std;
typedef pair<int, int> pii;
int soobin, bro, counter = 0, ret = INT_MAX;

int main(int argc, const char * argv[]) {
    cin>>soobin>>bro;
    vector<int> track(MAX, 0);
    vector<int> visitCount(MAX, 0);
    vector<bool> visit(MAX, false);
    queue<pii> soobinQueue;
    soobinQueue.push(pii(soobin, 0));

    while(!soobinQueue.empty()){
        int soobinCur = soobinQueue.front().first;
        int cost = soobinQueue.front().second;
        soobinQueue.pop();
        visit[soobinCur] = true;
        if(soobinCur == bro){
            visitCount[cost]++;
            //cout<<cost<<" 번 째에 찾았다!"<<endl;
            ret = min(ret, cost);
        }
        if(soobinCur * 2 >= 0 && soobinCur * 2< MAX && visit[soobinCur * 2] == false){
            soobinQueue.push(pii(soobinCur * 2, cost + 1));
        }
        if(soobinCur + 1 >= 0 && soobinCur + 1 < MAX && visit[soobinCur + 1] == false){
            soobinQueue.push(pii(soobinCur + 1, cost + 1));
        }
        if(soobinCur - 1 >= 0 && soobinCur - 1< MAX && visit[soobinCur - 1] == false){
            soobinQueue.push(pii(soobinCur - 1, cost + 1));
        }
    }
    
    cout<<ret<<endl;
    cout<<visitCount[ret]<<endl;
    return 0;
}

