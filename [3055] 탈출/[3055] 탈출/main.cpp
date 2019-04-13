//
//  main.cpp
//  [3055] 탈출
//
//  Created by YOO TAEWOOK on 13/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> map;

int R, C, counter = 0;
pair<int, int> beaver;
pair<int, int> hedgehog;
queue<pair<int, int>> waterQ;
queue<pair<int, int>> hedgehogQ;
vector<pair<int, int>> dir = {make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0)};
vector<vector<bool>> visited;

void init();
void BFS();
void print();

void debug();
int main(int argc, const char * argv[]) {
    init();
    BFS();
    print();
    return 0;
}

void print(){
    if(map[beaver.first][beaver.second] < 0)
        cout<<"KAKTUS"<<endl;
    else
        cout<<map[beaver.first][beaver.second]<<endl;
}

void BFS(){
    while(1){
        if(!waterQ.empty()){
            pair<int, int> waterLast = waterQ.back();
            while(!waterQ.empty()){
                pair<int, int> waterNow = waterQ.front();
                waterQ.pop();
                for(int i = 0 ; i < 4 ; i++){
                    pair<int, int> waterNext = make_pair(waterNow.first + dir.at(i).first, waterNow.second + dir.at(i).second);
                    
                    if(waterNext.first < 0 || waterNext.first >= R || waterNext.second < 0 || waterNext.second >= C)
                        continue;
                    
                    if(map[waterNext.first][waterNext.second] != -2 && map[waterNext.first][waterNext.second] != -3 && visited[waterNext.first][waterNext.second] == false){
                        waterQ.push(waterNext);
                        //map[waterNext.first][waterNext.second] = -1;
                        visited[waterNext.first][waterNext.second] = true;
                    }
                }
                
                if(waterNow == waterLast){ // 한 바퀴 돌았다는 뜻
                    waterLast = waterQ.back();
                    break;
                }
            }
        }
        pair<int, int> hedgehogLast = hedgehogQ.back();
        while(!hedgehogQ.empty()){
            pair<int, int> hedgehogNow = hedgehogQ.front();
            
            hedgehogQ.pop();
            
            for(int i = 0 ; i < 4 ; i++){
                pair<int, int> hedgehogNext = make_pair(hedgehogNow.first + dir.at(i).first, hedgehogNow.second + dir.at(i).second);
                
                if(hedgehogNext.first < 0 || hedgehogNext.first >= R || hedgehogNext.second < 0 || hedgehogNext.second >= C)
                    continue;
                
                if(map[hedgehogNext.first][hedgehogNext.second] != -1 && map[hedgehogNext.first][hedgehogNext.second] != -3 && visited[hedgehogNext.first][hedgehogNext.second] == false){
                    
                    map[hedgehogNext.first][hedgehogNext.second] = map[hedgehogNow.first][hedgehogNow.second] + 1;
                    visited[hedgehogNext.first][hedgehogNext.second] = true;
                    if(hedgehogNext == beaver)
                        return;
                    
                    hedgehogQ.push(hedgehogNext);
                }
            }
            
            if(hedgehogNow == hedgehogLast){
                hedgehogLast = hedgehogQ.back();
                break;
            }
        }
        
        if(hedgehogQ.empty())
            return;
    }
}

void init(){
    cin>>R>>C;
    map.assign(R, vector<int>(C, 0));
    visited.assign(R, vector<bool>(C, false));
    char input;
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            cin>>input;
            if(input == 'D'){ // beaver
                beaver = make_pair(i, j);
                map[i][j] = -2; //
            }else if(input == 'S'){ // hedgehog
                hedgehog = make_pair(i, j);
                hedgehogQ.push(make_pair(i, j));
            }else if(input == '*'){ // water
                waterQ.push(make_pair(i, j));
                map[i][j] = -1;
            }else if(input == 'X'){ // stone
                map[i][j] = -3;
            }
        }
    }
}
