//
//  main.cpp
//  [11650] 좌표 정렬하기
//
//  Created by YOO TAEWOOK on 2020/09/19.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int num;
vector< pair<int, int> > v;

void init();
void solve();

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

bool compare(pair<int, int>& a, pair<int, int>& b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
void solve(){
    sort(v.begin(), v.end(), compare);
    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
}

void init(){
    //freopen("input.txt", "r", stdin);
    cin>>num;
    for(int i = 0 ; i < num ; i++){
        pair<int, int> input;
        cin>>input.first>>input.second;
        v.push_back(input);
    }
}
