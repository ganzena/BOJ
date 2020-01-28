//
//  main.cpp
//  [17144] 미세먼지 안녕!
//
//  Created by YOO TAEWOOK on 27/01/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[50][50][2] = {0};
vector<pair<int, int> > dir;
queue<pair<int, int> > miseQ;

int R, C, T;
int upX, downX;

void init();
void run();
void mise();
void puri();

int main(int argc, const char * argv[]) {
    init();
    run();
    
    return 0;
}

void mise(){
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            if(map[i][j][0] != -1 && map[i][j][0] != 0){
                int cnt = 0;
                for(int k = 0 ; k < 4 ; k++){
                    int xx = i + dir.at(k).first;
                    int yy = j + dir.at(k).second;
                    if(xx < 0 || yy < 0 || xx >= R || yy >= C || map[xx][yy][0] == -1)
                        continue;
                    cnt++;
                    map[xx][yy][1] += map[i][j][0]/5;
                }
                map[i][j][0] = map[i][j][0] - (map[i][j][0]/5) * cnt;
            }
        }
    }
    
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            map[i][j][0] += map[i][j][1];
            map[i][j][1]= 0;
        }
    }
}

void puri(){
    
    // 아래에서 위로
    for(int i = upX-1 ; i > 0 ; i--){
        map[i][0][0] = map[i - 1][0][0];
    }
    
    //왼쪽에서 오른쪽으로
    for(int j = 0 ; j < C-1 ; j++){
        map[0][j][0] = map[0][j+1][0];
    }
    
    for(int i = 0 ; i < upX ; i++){
        map[i][C-1][0] = map[i + 1][C-1][0];
    }
    
    for(int j = C-1 ; j > 1 ; j--){
        map[upX][j][0] = map[upX][j-1][0];
    }
    
    map[upX][1][0] = 0;
    
    // 아래에서 위로
    for(int i = downX + 1; i < R-1 ; i++){
        map[i][0][0] = map[i + 1][0][0];
    }
    
    for(int j = 0 ; j < C-1 ; j++){
        map[R-1][j][0] = map[R-1][j+1][0];
    }
    
    for(int i = R - 2 ; i >= downX ; i--){
        map[i+1][C-1][0] = map[i][C-1][0];
    }
    
    for(int j = C-1 ; j > 0 ; j--){
        map[downX][j][0] = map[downX][j-1][0];
    }
    
    map[downX][1][0] = 0;
}
void run(){
    while(T-- != 0){
        mise();
        puri();
    }
    int sum = 2;
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            sum += map[i][j][0];
        }
    }
    cout<<sum<<endl;
}

void init(){
    //freopen("input.txt", "r", stdin);
    cin>>R>>C>>T;
    bool flag = true;
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            cin>>map[i][j][0];
            if(map[i][j][0] == -1){
                if(flag){
                    flag = false;
                    upX = i;
                }else{
                    downX = i;
                }
            }else if(map[i][j][0] != 0){
                miseQ.push(make_pair(i, j));
            }
        }
    }
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
}
