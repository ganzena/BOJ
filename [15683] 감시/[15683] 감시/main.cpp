//
//  main.cpp
//  [15683] 감시
//
//  Created by YOO TAEWOOK on 2018. 4. 16..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct CCTV{
    int type;
    int x;
    int y;
};
int n, m, input;
int cctvNum = 0;
int counter = 100;
vector<vector<int>> map(8, vector<int>(8, 0)); // 맵

vector<int> cctvRotate = {4, 2, 4, 4, 1}; //타입별 cctv rotate 수
vector<CCTV> cctvVector;

void init(){
    cin>>n>>m;
    for(int i = 0 ; i < n ; i++){ //세로
        for(int j = 0 ; j < m ; j++){ //가로
            cin>>input;
            map[i][j] = input;
            
            if(input != 0 && input != 6){ //CCTV
                CCTV cctv;
                cctv.type = input - 1;
                cctv.x = j;
                cctv.y = i;
                cctvVector.push_back(cctv);
                cctvNum++;
            }
        }
    }
}

void update(int dir, CCTV cctv){
    dir = (dir % 4);
    
    if(dir == 0){ // 동
        for(int j = cctv.x + 1 ; j < m ; j++){
            if(map[cctv.y][j] == 6)
                break;
            else
                map[cctv.y][j] = -1;
        }
    }else if(dir == 1){ // 북
        for(int i = cctv.y - 1 ; i >= 0 ; i--){
            if(map[i][cctv.x] == 6)
                break;
            else
                map[i][cctv.x] = -1;
        }
    }else if(dir == 2){ // 서
        for(int j = cctv.x - 1; j >= 0 ; j--){
            if(map[cctv.y][j] == 6)
                break;
            else
                map[cctv.y][j] = -1;
        }
    }else if(dir == 3){ // 남
        for(int i = cctv.y + 1; i < n ; i++){
            if(map[i][cctv.x] == 6)
                break;
            else
                map[i][cctv.x] = -1;
        }
    }
}

void dfs(int index){
    if(index == cctvNum){
        int compare = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(map[j][i] == 0)
                    compare++;
            }
        }
        if(counter > compare)
            counter = compare;
        return;
    }
    
    int cctvType = cctvVector.at(index).type;
    vector<vector<int>> copyMap(8, vector<int>(8, 0)); // 백업 맵
    for(int dir = 0 ; dir < cctvRotate.at(cctvType) ; dir++){
        copyMap = map;
        if(cctvType == 0){
            update(dir, cctvVector.at(index));
        }else if(cctvType == 1){
            update(dir, cctvVector.at(index));
            update(dir + 2, cctvVector.at(index));
        }else if(cctvType == 2){
            update(dir, cctvVector.at(index));
            update(dir + 1, cctvVector.at(index));
        }else if(cctvType == 3){
            update(dir, cctvVector.at(index));
            update(dir + 1, cctvVector.at(index));
            update(dir + 2, cctvVector.at(index));
        }else if(cctvType == 4){
            update(dir, cctvVector.at(index));
            update(dir + 1, cctvVector.at(index));
            update(dir + 2, cctvVector.at(index));
            update(dir + 3, cctvVector.at(index));
        }
        dfs(index + 1);
        map = copyMap;
    }
}

int main(int argc, const char * argv[]) {
    init();
    dfs(0);
    cout<<counter<<endl;
    return 0;
}

