//
//  main.cpp
//  코팅테스트 모의고사 2
//
//  Created by YOO TAEWOOK on 2020/03/21.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

enum STATUS {LAKE, CAN_WATER, NO_WATER};
enum WATER {EMPTY, GREEN, RED, FLOWER};

struct Water{
    int x;
    int y;
    int t;
    WATER color;
};

void init();
void solve(int, int);
void check();
void spread();
void print();

vector<pair<int, int> > dir;
vector<vector<STATUS> > map;
vector<vector<Water> > waterMap;
vector<pair<int, int> > canWaterV;
vector<Water> tempV;


int N, M, G, R; // G = 초록색 배양액 R = 빨간색 배양액
int ans = 0;

int main(int argc, const char * argv[]) {
    init();
    solve(0, 0);
    cout<<ans<<endl;
    return 0;
}

void spread(){
    Water waterTemp;
    waterTemp.color = EMPTY;
    waterTemp.t = 0;
    waterMap.assign(N, vector<Water>(M, waterTemp));
    //print();
    int temp = 0;
    int time = 0;
    queue<Water> redQ;
    queue<Water> greenQ;
    
    for(int i = 0 ; i < tempV.size() ; i++){
        Water init = tempV.at(i);
         waterMap[init.x][init.y] = init; //이거 안해서 틀린듯?
        if(tempV.at(i).color == RED){
            redQ.push(tempV.at(i));
        }else{
            greenQ.push(tempV.at(i));
        }
    }
    while(!redQ.empty() && !greenQ.empty()){
        while(!redQ.empty()){
            Water now = redQ.front();
            if(now.t > time)
                break;
            redQ.pop();
            if(waterMap[now.x][now.y].color == FLOWER)
                continue;
            waterMap[now.x][now.y] = now;
            for(int i = 0 ; i < 4 ; i++){
                int xx = now.x + dir.at(i).first;
                int yy = now.y + dir.at(i).second;
                if(xx < 0 || yy < 0 || xx >= N || yy >= M || waterMap[xx][yy].color != EMPTY || map[xx][yy] == LAKE ){
                    continue;
                }
                
                Water next;
                next.x = xx;
                next.y = yy;
                next.t = now.t + 1;
                next.color = RED;
                waterMap[xx][yy] = next;
                redQ.push(next);
            }
            
        }
        //print();
        while(!greenQ.empty()){
            Water now = greenQ.front();
            if(now.t > time)
                break;
            greenQ.pop();

            waterMap[now.x][now.y] = now;
            for(int i = 0 ; i < 4 ; i++){
                int xx = now.x + dir.at(i).first;
                int yy = now.y + dir.at(i).second;
                if(xx < 0 || yy < 0 || xx >= N || yy >= M || waterMap[xx][yy].color == GREEN || map[xx][yy] == LAKE || waterMap[xx][yy].color == FLOWER){
                    continue;
                }
                
                if(waterMap[xx][yy].color == RED){
                    if(waterMap[xx][yy].t != now.t + 1)
                        continue;
                }
                
                //RED랑 EMPTY만 나옴
                Water next;
                next.x = xx;
                next.y = yy;
                next.t = now.t + 1;
                next.color = GREEN;
                if(waterMap[xx][yy].color == RED){
                    temp++;
                    waterMap[xx][yy] = next;
                    waterMap[xx][yy].color = FLOWER;
                }else{
                    
                    waterMap[xx][yy] = next;
                    greenQ.push(next);
                }
                
            }
        }
        //cout<<time<<"일 때"<<endl;
        //print();
        time++;
        
    }
    
    ans = max(temp, ans);
    
}

void solve(int depth, int start){
    
    if((R <= 0 && G <= 0)){
        //cout<<"-----------------------------"<<endl;
         spread();
        //print();

        return;
    }
    
    for(int i = start ; i < (int)canWaterV.size() ; i++){
        
        Water temp;
        temp.x = canWaterV.at(i).first;
        temp.y = canWaterV.at(i).second;
        temp.t = 0;
        if(R > 0){
            temp.color = RED;
            tempV.push_back(temp);
            R--;
            solve(depth + 1, i + 1);
            R++;
            tempV.pop_back();
        }
        
        if(G > 0){
            temp.color = GREEN;
            tempV.push_back(temp);
            G--;
            solve(depth + 1, i + 1);
            G++;
            tempV.pop_back();
        }
    }
    
    return;
    
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N>>M>>G>>R;
    map.assign(N, vector<STATUS>(M, LAKE));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            int num;
            cin>>num;
            if(num == 0){
                map[i][j] = LAKE;
            }else if(num == 1){
                map[i][j] = NO_WATER;
            }else{
                map[i][j] = CAN_WATER;
                canWaterV.push_back(make_pair(i, j));
            }
        }
    }
    
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
    
}
