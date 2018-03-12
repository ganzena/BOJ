//
//  main.cpp
//  [3184] 양
//
//  Created by YOO TAEWOOK on 2018. 3. 7..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//
//글자 '.' (점)은 빈 필드를 의미하며, 글자 '#'는 펜스를, 글자 'o'는 양, 'v'는 늑대를 의미한다.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//vector< vector<char> > backYard(250, vector<char>(250));
vector<int> dirX = {0, 0, 1, -1}; //동서남북 체크용
vector<int> dirY = {1, -1, 0, 0}; //동서남북 체크용
const char EMPTY = '.', FENCE = '#', SHEEP = 'o', WOLF = 'v';
int row, col;

int BFS(vector< vector<char> > &, vector< vector<bool> > &, pair<int, int>);

int main(int argc, const char * argv[]) {
    cin>>row>>col;
    
    int sheepSurvived = 0, wolfSurvived = 0;
    
    vector< vector<char> > space(row, vector<char>(col));
    vector< vector<bool> > visited(row, vector<bool>(col, false));
    
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cin>>space[i][j];
        }
    }
    
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            if(space[i][j] != FENCE && !visited[i][j]){
                int whoSurvived = BFS(space, visited, pair<int, int>(i, j));
                if(whoSurvived < 0)
                    wolfSurvived += (whoSurvived * -1);
                else
                    sheepSurvived += whoSurvived;
            }
        }
    }
    
    cout<<sheepSurvived<<" "<<wolfSurvived<<endl;
}

int BFS(vector< vector<char> > &space, vector< vector<bool> > &visited, pair<int, int> location){
    queue< pair<int, int> > queue;
    queue.push(location);
    visited[location.first][location.second] = true;
    int wolfNum = 0, sheepNum = 0;
    while(!queue.empty()){
        int x = queue.front().first;
        int y = queue.front().second;
        queue.pop();
        char curLoc = space[x][y];
        if(curLoc == WOLF){
            wolfNum++;
        }else if(curLoc == SHEEP){
            sheepNum++;
        }
        visited[x][y] = true;
        for(int i = 0 ; i < 4 ; i++){ // 동서남북 체크
            int newX = x + dirX[i];
            int newY = y + dirY[i];
            if(newX >= 0 && newX < row && newY >= 0 && newY < col){ // 배열 안인지 체크
                if(visited[newX][newY] == false && space[newX][newY] != FENCE){
                    queue.push(pair<int, int>(newX, newY));
                    visited[newX][newY] = true;
                }
            }
        }
    }
    if(wolfNum >= sheepNum){
        return wolfNum * -1;
    }else{
        return sheepNum;
    }
}
