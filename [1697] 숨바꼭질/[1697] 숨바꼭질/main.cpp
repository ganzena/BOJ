//
//  main.cpp
//  [1697] 숨바꼭질
//
//  Created by YOO TAEWOOK on 2018. 3. 24..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;

vector<int> road(MAX, 0);
vector<bool> visited(MAX, false);
vector<int> command = {0, 1, 2}; //teleport foward back
int soobin, bro, minimum = 100000, simpleDist, counter = 0;

int Teleport(int);
int Foward(int);
int Back(int);
void chase(int);
int main(int argc, const char * argv[]) {
    cin>>soobin>>bro;
    simpleDist = bro - soobin;
    // minimum은 한 칸 이동만 했을 때의 최소값(텔레포트를 사용하여 이보다 적게 움직여야함)
    if(simpleDist == 0){
        cout<<0<<endl;
        return 0;
    } else if(simpleDist < 0){
        simpleDist *= -1;
    }
    
    chase(soobin);
    cout<<road[bro]<<endl;
    return 0;
}

void chase(int start){
    queue<int> soobinQueue;
    soobinQueue.push(start);
    road[start] = 0;
    visited[start] = true;
    while(!soobinQueue.empty()){
        int soobinCur = soobinQueue.front();
        soobinQueue.pop();
        int movedCur;
        for(int i = 0 ; i < command.size() ; i++){
            if(i == 0){
                movedCur = Teleport(soobinCur);
                if(movedCur >= 0 && movedCur < MAX && !visited[movedCur]){
                    visited[movedCur] = true;
                    road[movedCur] = road[soobinCur] + 1;
                    soobinQueue.push(movedCur);
                }
            }else if(i == 1){
                movedCur = Foward(soobinCur);
                if(movedCur >= 0 && movedCur < MAX && !visited[movedCur]){
                    visited[movedCur] = true;
                    road[movedCur] = road[soobinCur] + 1;
                    soobinQueue.push(movedCur);
                }
            }else if(i == 2){
                movedCur = Back(soobinCur);
                if(movedCur >= 0 && movedCur < MAX && !visited[movedCur]){
                    visited[movedCur] = true;
                    road[movedCur] = road[soobinCur] + 1;
                    soobinQueue.push(movedCur);
                }
            }
        }
    }
}

int Teleport(int start){
    return start*2;
}

int Foward(int start){
    return ++start;
}

int Back(int start){
    return --start;
}
