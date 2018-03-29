//
//  main.cpp
//  [2178] 미로 탐색
//
//  Created by YOO TAEWOOK on 2018. 3. 21..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > map;
vector< pair<int, int> > direction = {pair<int, int>(1, 0), pair<int, int>(0, 1), pair<int, int>(-1, 0), pair<int, int>(0, -1)};
int row, col;
int endI, endJ;
int counter = 1;
void BFS(int, int);
// 1은 이동가능 0은 이동 불가능 (2는 이동 완료)
int main(int argc, const char * argv[]) {
    cin>>row>>col;
    map.assign(row, vector<int>(col));
    endI = row - 1;
    endJ = col - 1;
    
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            scanf("%1d",&map[i][j]);
        }
    }

    
    BFS(0, 0);
    cout<<map[endI][endJ]<<endl;
    return 0;
}

void BFS(int startI, int startJ){
    queue<pair<int, int>> queue;
    queue.push(pair<int, int>(startI, startJ));
    
    while(!queue.empty()){
        startI = queue.front().first;
        startJ = queue.front().second;
        queue.pop();
        for(int i = 0 ; i < 4 ; i++){
            int neighborI = startI + direction.at(i).first;
            int neighborJ = startJ + direction.at(i).second;
            if(neighborI >= 0 && neighborI < row && neighborJ >= 0 && neighborJ < col){
                if(map[neighborI][neighborJ] == 1){
                    queue.push(pair<int, int>(neighborI, neighborJ));
                    map[neighborI][neighborJ] = map[startI][startJ] + 1; //몇 번의 너비 탐색으로 도달했는지를 기록한다
                }
            }
        }
    }
}
