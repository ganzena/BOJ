//
//  main.cpp
//  [2979] 트럭 주차
//
//  Created by YOO TAEWOOK on 30/01/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > times;
vector<int> fares;
vector<vector<bool> > timeTable;

int total = 0;
void init();
void solve();
void print();

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void print(){
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            if(timeTable[i][j])
            cout<<1<<"\t";
            else
            cout<<0<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

void solve(){
    for(int i = 0 ; i < 3 ; i++){
        int first = times.at(i).first;
        int second = times.at(i).second;
        for(int j = first - 1 ; j < second - 1 ; j++){
            timeTable[i][j] = true;
        }
    }
    
    for(int j = 0 ; j < 100 ; j++){
        int count = 0;
        for(int i = 0 ; i < 3 ; i++){
            if(timeTable[i][j])
            count++;
        }
        if(count != 0)
            total += fares.at(count - 1) * count;
    }
    
    cout<<total<<endl;
}

void init(){
    freopen("input.txt", "r", stdin);
    fares.assign(3, 0);
    for(int i = 0 ; i < 3 ; i++){
        cin>>fares.at(i);
    }
    for(int i = 0 ; i < 3 ; i++){
        int first, second;
        cin>>first>>second;
        times.push_back(make_pair(first, second));
    }
    timeTable.assign(3, vector<bool>(101, false));
}
