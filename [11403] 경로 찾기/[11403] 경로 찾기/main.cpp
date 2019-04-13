//
//  main.cpp
//  [11403] 경로 찾기
//
//  Created by YOO TAEWOOK on 09/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> link;
vector<vector<bool>> visited;
int n;

void init();
void search();
void DFS(int, int, int);
void print();
int main(int argc, const char * argv[]) {
    init();
    search();
    print();
    return 0;
}

void init(){
    cin>>n;
    map.assign(n, vector<int>(n, 0));
    link.assign(n, vector<int>(n, 0));
    visited.assign(n, vector<bool>(n, false));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>map[i][j];
            
        }
    }
}

void search(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < n ; k++){
                if(map[j][i] == 1 && map[i][k] == 1){
                    map[j][k] = 1;
                }
            }
        }
    }
}



void print(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<map[i][j]<<" ";
        }cout<<endl;
    }
}


