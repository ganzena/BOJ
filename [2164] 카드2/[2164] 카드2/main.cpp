//
//  main.cpp
//  [2164] 카드2
//
//  Created by YOO TAEWOOK on 30/01/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <deque>

using namespace std;

deque<int> deq;

int N;

void init();
void solve();

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void solve(){
    while(1){
        //1. 맨위 버리고
        //2. 그다음 맨위 맨 밑으로 깔고
        if(deq.size() == 1)
            break;
        deq.pop_back();
        if(deq.size() == 1)
            break;
        int tmp = deq.back();
        deq.pop_back();
        deq.push_front(tmp);
        
    }
    cout<<deq.front()<<endl;
}

void init(){
    //freopen("input.txt", "r", stdin);
    cin>>N;
    for(int i = N ; i > 0 ; i--){
        deq.push_back(i);
        
    }
}
