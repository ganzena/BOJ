//
//  main.cpp
//  [2455] 지능형 기차
//
//  Created by YOO TAEWOOK on 29/01/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > station;

int maximum = 0, cur = 0;

void init();
void solve();
int main(int argc, const char * argv[]) {
    
    init();
    solve();
    return 0;
}

void solve(){
    for(int i = 0 ; i < 4 ; i++){
        int out = station.at(i).first;
        int in = station.at(i).second;
        
        cur -= out;
        cur += in;
        maximum = max(cur, maximum);
    }
    cout<<maximum<<endl;
}

void init(){
    //freopen("input.txt", "r", stdin);
    for(int i = 0 ; i < 4 ; i++){
        int a, b;
        cin>>a>>b;
        station.push_back(make_pair(a, b));
    }
}
