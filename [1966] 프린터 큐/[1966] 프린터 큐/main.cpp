//
//  main.cpp
//  [1966] 프린터 큐
//
//  Created by YOO TAEWOOK on 30/01/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <deque>

using namespace std;

deque<pair<int, int> > printer;

int test, N, M, P;

void init();
void solve();

int main(int argc, const char * argv[]) {
    //freopen("input.txt", "r", stdin);
    cin>>test;
    while(test-->0){
        init();
        solve();
    }
    return 0;
}
void solve(){
    int cnt = 0;
    deque<pair<int, int> >::iterator iter;
    while(1){
        int prio = printer.front().second;
        bool flag = true;
        for(iter = printer.begin() ; iter != printer.end() ; iter++){
            if(prio < iter->second){
                flag = false;
                break;
            }
        }
        if(flag){
            if(printer.front().first == M){
                cnt++;
                break;
            }else{
                printer.pop_front();
                cnt++;
            }
        }else{
            pair<int, int> temp = printer.front();
            printer.pop_front();
            printer.push_back(temp);
        }
        
        
    }
    cout<<cnt<<endl;
    
}
void init(){
    cin>>N>>M;
    printer.clear();
    for(int i = 0 ; i < N ; i++){
        int temp;
        cin>>temp;
        printer.push_back(make_pair(i, temp));
        
    }
}
