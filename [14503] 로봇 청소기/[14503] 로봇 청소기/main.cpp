//
//  main.cpp
//  [14503] 로봇 청소기
//
//  Created by YOO TAEWOOK on 2018. 3. 20..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// Direction = 0 : 북쪽 / 1 : 동쪽 / 2 : 남쪽 / 3 : 서쪽
// Map = 0 : 빈칸 / 1 : 벽 / 2 : 청소됨
struct Vaccum{
    int r; //세로 위치
    int c; //가로 위치
    int d; //dir
};
int n, m; // 세로 가로

vector< vector<int> > map(50, vector<int>(50, 0));
vector<pair<int, int>> dir = {pair<int, int>(-1, 0), pair<int, int>(0, 1), pair<int, int>(1, 0), pair<int, int>(0, -1)};
Vaccum vaccum;
int totalClean = 0;

void init(){
    cin>>n>>m; // y x
    cin>>vaccum.r>>vaccum.c>>vaccum.d; //로봇 위치 및 방향 초기화
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin>>map[i][j];
        }
    }
}

void clean(){
    int counter = 0;
    while(1){
        map[vaccum.r][vaccum.c] = 2;
        vaccum.d = (vaccum.d + 1)%4;
        int nextR = vaccum.r + dir.at(vaccum.d).first;
        int nextC = vaccum.c + dir.at(vaccum.d).second;
        if(counter != 4){ // 아직 회전할 수 있을 때
            if(map[nextR][nextC] != 0){
                counter++;
            }else{
                vaccum.r = nextR;
                vaccum.c = nextC;
                counter = 0;
            }
        }else{ // 더 이상 회전 못할 때
            int backDir = (vaccum.d + 2)%4;
            int backR = vaccum.r + dir.at(backDir).first;
            int backC = vaccum.c + dir.at(backDir).second;
            if(map[backR][backC] == 1){ //후진을 했는데도 벽임
                break;
            }else{
                vaccum.r = backR;
                vaccum.c = backC;
                counter = 0;
            }
        }
    }
}

void count(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(map[i][j] == 2)
                totalClean++;
        }
    }
}

int main(int argc, const char * argv[]) {
    init();
    clean();
    count();
    cout<<totalClean<<endl;
}



