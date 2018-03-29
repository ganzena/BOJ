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
vector< vector< int > > map;
vector<pair<int, int>> direction = {pair<int, int>(-1, 0), pair<int, int>(0, 1), pair<int, int>(1, 0), pair<int, int>(0, -1)}; //북동남서

int row, col, curI, curJ, dir, counter = 0;
int rotateLeft(int);
void clean(int, int, int);
int main(int argc, const char * argv[]) {
    cin>>row>>col;
    cin>>curI>>curJ>>dir;
    
    map.assign(row, vector<int>(col));
    
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cin>>map[i][j];

        }
    }
    map[curI][curJ] = 2;
    counter++;
    clean(curI, curJ, dir);
    cout<<counter<<endl;
   
    return 0;
}

int rotateLeft(int dir){ //회전 북 동 남 서 순으로 되어있기 때문에
    if(dir == 0)
        return 3;
    else
        return --dir;
}

// 0은 빈칸, 1은 벽, 2는 청소함
void clean(int startI, int startJ, int curDir){
    for(int i = 0 ; i < 4 ; i++){
        // 현재 방향인 curDir을 회전함수에 집어넣어, 왼쪽방향을 구하고 어차피 무조건 도니까 현재 방향도 업데이트
        int leftDir = rotateLeft(curDir);
        curDir = leftDir;
        int leftI = startI + direction.at(leftDir).first;
        int leftJ = startJ + direction.at(leftDir).second;
        if(map[leftI][leftJ] == 1){ // 벽이면 돌아가서 회전
            continue;
        }
        if(map[leftI][leftJ] == 0){ // 청소 공간이면 청소를 시작한다.
            map[leftI][leftJ] = 2;
            counter++;
//            cout<<endl;
//            for(int j = 0 ; j < row ; j++){
//                for(int k = 0 ; k < col ; k++){
//                    cout<<map[j][k]<<" ";
//                }
//                cout<<endl;
//            }
            clean(leftI, leftJ, curDir);
            return;
        }
    }
    //회전을 다 했는데도 갈 곳을 못 찾았을 경우
    int backI = startI - direction.at(curDir).first;
    int backJ = startJ - direction.at(curDir).second;
    if(map[backI][backJ] == 1) // 후진했는데 벽이면 종료
        return;
    else
        clean(backI, backJ, curDir); // 벽이 아니면 청소 재개
}
