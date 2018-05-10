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
typedef pair<int, int> pii;

class CCTV{
public:
    int initI; //좌표값
    int initJ;
    int number; //번호
    bool isSafe; //감시 받고 있는지 여부
    
    CCTV(){}
    CCTV(int a, int b, int c, bool d){
        this->initI = a;
        this->initJ = b;
        this->number = c;
        this->isSafe = d;
    }
};

vector<pii> dir = {pii(-1, 0), pii(0, -1), pii(1, 0), pii(0, 1)}; //북서남동
vector< vector<CCTV> > map;
vector<CCTV> cctvVec;

void print(int);
void count();
void init();
void run();
void select(int, int, int);
int countSafe(int, int, int, int);
void realSafe(int, int, int);
bool compare(CCTV, CCTV);

int height, width, sagak, wallCnt = 0;

int main(int argc, const char * argv[]) {
    init();
    run();
    count();
    cout<<sagak - wallCnt<<endl;
    return 0;
}
void run(){
    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){
            if(map[i][j].number > 0 && map[i][j].number < 6){
                cctvVec.push_back(map[i][j]);
            }
        }
    }
    
    sort(cctvVec.begin(), cctvVec.end(), compare);
    
    for(int i = 0 ; i < cctvVec.size() ; i++){
        CCTV c = cctvVec[i];
        select(c.initI, c.initJ, c.number);
    }
    
    while(!cctvVec.empty())
        cctvVec.pop_back();
}

void count(){
    for(int i = 0 ; i <height ; i++){
        for(int j = 0 ; j < width ; j++){
            if(map[i][j].isSafe == false){
                sagak++;
            }
        }
    }
}

void select(int startI, int startJ, int number){
    if(number == 1){
        int tempDir = 0;
        int maximum = 0;
        for(int i = 0 ; i < 4 ; i++){
            int temp = maximum;
            maximum = max(maximum, countSafe(startI, startJ, i, 1));
            if(temp != maximum)
                tempDir = i;
        }
        realSafe(startI, startJ, tempDir);
    }else if(number == 2){ //북서남동
        int vertiCnt = 0, horizonCnt = 0;
        horizonCnt += countSafe(startI, startJ, 1, 1);
        horizonCnt += countSafe(startI, startJ, 3, 1);
        vertiCnt += countSafe(startI, startJ, 0, 1);
        vertiCnt += countSafe(startI, startJ, 2, 1);
        if(horizonCnt > vertiCnt){
            realSafe(startI, startJ, 1);
            realSafe(startI, startJ, 3);
        }else{
            realSafe(startI, startJ, 0);
            realSafe(startI, startJ, 2);
        }
    }else if(number == 3){
        int realDir1 = 0, realDir2 = 0;
        int maximum = 0;
        for(int i = 0 ; i < 4 ; i++){
            int dir1, dir2;
            if(i == 3){
                dir1 = 3;
                dir2 = 0;
            }else{
                dir1 = i;
                dir2 = i + 1;
            }
            int temp = maximum;
            int sum = 0;
            sum += countSafe(startI, startJ, dir1, 1);
            sum += countSafe(startI, startJ, dir2, 1);
            
            maximum = max(maximum, sum);
            if(maximum != temp){
                realDir1 = dir1;
                realDir2 = dir2;
            }
        }
        
        realSafe(startI, startJ, realDir1);
        realSafe(startI, startJ, realDir2);
    }else if(number == 4){
        int realDir1 = 0, realDir2 = 0, realDir3 = 0;
        int maximum = 0;
        for(int i = 0 ; i < 4 ; i++){
            int dir1 = 0, dir2 = 0, dir3 = 0;
            if(i == 0){
                dir1 = 0;
                dir2 = 1;
                dir3 = 2;
            }else if(i == 1){
                dir1 = 1;
                dir2 = 2;
                dir3 = 3;
            }else if(i == 2){
                dir1 = 2;
                dir2 = 3;
                dir3 = 0;
            }else if(i == 3){
                dir1 = 3;
                dir2 = 0;
                dir3 = 1;
            }
            int temp = maximum;
            int sum = 0;
            sum += countSafe(startI, startJ, dir1, 1);
            sum += countSafe(startI, startJ, dir2, 1);
            sum += countSafe(startI, startJ, dir3, 1);
            //cout<<sum<<endl;
            maximum = max(maximum, sum);
            if(maximum != temp){
                realDir1 = dir1;
                realDir2 = dir2;
                realDir3 = dir3;
            }
            
        }
    
        realSafe(startI, startJ, realDir1);
        realSafe(startI, startJ, realDir2);
        realSafe(startI, startJ, realDir3);
        
    }else if(number == 5){
        for(int i = 0 ; i < 4 ; i++){
            realSafe(startI, startJ, i);
        }
    }
    //print(number);
}

void realSafe(int startI, int startJ, int curDir){
    map[startI][startJ].isSafe = true;
    int newI = startI + dir.at(curDir).first;
    int newJ = startJ + dir.at(curDir).second;
    if(newI >= 0 && newJ >= 0 && newI < height && newJ < width){
        if(map[newI][newJ].number == 6)
            return;
        
        realSafe(newI, newJ, curDir);
    }else{
        return;
    }
}

int countSafe(int startI, int startJ, int curDir, int counter){
    
    while(1){
        startI = startI + dir.at(curDir).first;
        startJ = startJ + dir.at(curDir).second;

        if(startI >= 0 && startJ >= 0 && startI < height && startJ < width){
            if(map[startI][startJ].number == 6)
                break;
            if(map[startI][startJ].isSafe == false)
                counter++;
        }else{
            break;
        }


    }
    return counter;

}

bool compare(const CCTV x, const CCTV y){
    return x.number > y.number;
}

void init(){
    cin>>height>>width;
    map.assign(height, vector<CCTV>(width));
    wallCnt = 0;
    sagak = 0;
    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){
            int temp;
            cin>>temp;
            map[i][j] = CCTV(i, j, temp, false);
            if(temp == 6){
                wallCnt++;
            }
        }
    }
}

void print(int number){
    cout<<number<<endl;
    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){
            cout<<map[i][j].isSafe<<" ";
        }cout<<endl;
    }
}
