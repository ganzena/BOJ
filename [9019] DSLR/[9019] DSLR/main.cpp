//
//  main.cpp
//  [9019] DSLR
//
//  Created by YOO TAEWOOK on 2020/04/03.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;


int T, A, B;

int getL(int);
int getR(int);
void solve();

int getL(int num){
    int temp = num;
    deque<int> dq;
    while(!temp % 10 == 0){
        dq.push_front(temp % 10);
        temp /= 10;
    }
    int lnum = 0;
    lnum += dq.front();
    dq.pop_front();
    int digit = 10;
    while(!dq.empty()){
        lnum += digit * dq.back();
        dq.pop_back();
        digit *= 10;
    }
    return lnum;
}

int getR(int num){
    int temp = num;
    deque<int> dq;
    while(!temp % 10 == 0){
        dq.push_front(temp % 10);
        temp /= 10;
    }
    int rnum = 0;
    int last = dq.back();
    dq.pop_back();
    int digit = 10;
    while(!dq.empty()){
        rnum += digit * dq.back();
        dq.pop_back();
        digit *= 10;
    }
    rnum += last * digit * 10;
    return rnum;
}
void solve(){
    queue<pair<int, string> > q;
    q.push(make_pair(A, ""));
    while(!q.empty()){
        pair<int, string> now = q.front();
        //cout<<now.first<<", "<<now.second<<endl;
        q.pop();
        if(now.first == B){
            cout<<now.second<<endl;
            return;
        }
        // D
        q.push(make_pair(now.first * 2 > 9999 ? (now.first * 2) / 10000 : now.first * 2, now.second.append("D")));
        now.second.erase(now.second.end()-1, now.second.end());
        // S
        q.push(make_pair(now.first - 1  == 0 ? 9999 : now.first - 1, now.second.append("S")));
        now.second.erase(now.second.end()-1, now.second.end());
        // L
        q.push(make_pair(getL(now.first), now.second.append("L")));
        now.second.erase(now.second.end()-1, now.second.end());
        // R
        q.push(make_pair(getR(now.first), now.second.append("R")));
        now.second.erase(now.second.end()-1, now.second.end());
    }
}

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    cin>>T;
    for(int i = 0 ; i < T ; i++){
        cin>>A>>B;
        solve();
    }
    return 0;
}

