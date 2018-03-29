//
//  main.cpp
//  [14923] 미로 탈출
//
//  Created by YOO TAEWOOK on 2018. 3. 21..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< pair<int, int> > dir = {make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0), make_pair(0, 1)};
vector< vector<int> > maze;
vector< vector<int> > copiedMaze;
queue<pair<int, int>> wallQueue;
int row, col;
int startI, startJ, endI, endJ, counter = 99999;
void BFS(int, int);
int main(int argc, const char * argv[]) {
    cin>>row>>col;
    maze.assign(row, vector<int>(col));
    cin>>startI>>startJ;
    cin>>endI>>endJ;
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cin>>maze[i][j];
            if(maze[i][j] == 1){
                wallQueue.push(make_pair(i, j));
            }
        }
    }
    startI--;
    startJ--;
    endI--;
    endJ--;
    
    
    while(!wallQueue.empty()){
        copiedMaze = maze;
        int destroyI = wallQueue.front().first;
        int destroyJ = wallQueue.front().second;
        wallQueue.pop();
        copiedMaze[destroyI][destroyJ] = 0;
        BFS(startI, startJ);
        counter = min(counter, copiedMaze[endI][endJ] / 2);
    }
    if(copiedMaze[endI][endJ] == 0)
        cout<<-1<<endl;
    else
        cout<<counter<<endl;
    
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
            int newI = startI + dir.at(i).first;
            int newJ = startJ + dir.at(i).second;
            if(newI >= 0 && newI < row && newJ >= 0 && newJ < col){
                if(copiedMaze[newI][newJ] == 0){
                    copiedMaze[newI][newJ] = copiedMaze[startI][startJ] + 2;
                    queue.push(make_pair(newI, newJ));
                }
            }
        }
    }
}
