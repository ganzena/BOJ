//
//  main.cpp
//  [13549] 숨바꼭질 3
//
//  Created by YOO TAEWOOK on 2018. 3. 25..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define MAX 100000

using namespace std;

typedef pair<int, int> pii;
int soobin, bro, ret = INT_MAX, cnt = 0;
vector <int> road(MAX, 0);
vector <bool> visit(MAX, false);
queue <pii> q; // first = 도달비용, second = 위치

int main(int argc, const char * argv[]) {
    cin>>soobin>>bro;
    
    q.push(pii(0, soobin));
    
    if(soobin == bro){
        cout<<0<<endl;
        
    }else{
        while(!q.empty()){
            int cnt = q.front().first;
            int soobinCur = q.front().second;
            
            q.pop();
            visit[soobinCur] = true;
            
            if(soobinCur == bro){
                ret = min(ret, cnt);
            }
            
            if (soobinCur * 2 <= MAX && soobinCur * 2 >= 0 && visit[soobinCur * 2] == false)
                q.push(pii(cnt + 1, soobinCur * 2));
            
            if (soobinCur - 1 >= 0 && soobinCur - 1 <= MAX && visit[soobinCur - 1] == false)
                q.push(pii(cnt + 1, soobinCur - 1));
            
            if (soobinCur + 1 <= MAX && soobinCur + 1 >= 0 && visit[soobinCur + 1] == false)
                q.push(pii(cnt + 1, soobinCur + 1));
            
        }
        cout<<ret<<endl;
    }
    
    return 0;
    
}

