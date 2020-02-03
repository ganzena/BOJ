//
//  main.cpp
//  [2161] 카드1
//
//  Created by YOO TAEWOOK on 30/01/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int N;
deque<int> deq;
vector<int> vec;

void init();
void solve();
void print();

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void solve(){
    while(1){
        if(deq.size() == 1)
            break;
        cout<<deq.back()<<" ";
        deq.pop_back();
        int tmp = deq.back();
        deq.pop_back();
        deq.push_front(tmp);
    }
    cout<<deq.front()<<endl;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N;
    for(int i = N ; i > 0 ; i--){
        deq.push_back(i);
    }
}
