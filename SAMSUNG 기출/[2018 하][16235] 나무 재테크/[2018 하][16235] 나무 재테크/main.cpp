//
//  main.cpp
//  [2018 하][16235] 나무 재테크
//
//  Created by YOO TAEWOOK on 2020/03/07.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Tree{ //나무의 구조체
    int x, y;
    int age;
};

int foodMap [11][11] ; //양분이 들어있는 map;
int plusMap [11][11]; //겨울에 추가될 양분의 양;
vector<Tree> map[11][11]; // 나무가 심어져있는 map;
queue<Tree> deadQ; // 죽은 나무 목록
vector<pair<int, int> > dir;

void init();
void solve();
void spring();
void summer();
void fall();
void winter();
void count();
bool compare(Tree, Tree);

int N, M, K; // 배열의 길이, 나무 갯수, K년이 지난 후 살아남은 나무 수
int ans = 0;

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void solve(){
    while(K-- > 0){
        spring();
        summer();
        fall();
        winter();
    }
    count();
}

void count(){
    for(int i = 1; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            ans += map[i][j].size();
        }
    }
    cout<<ans<<endl;
}

void spring(){
    // 1. 나무가 자신의 "나이만큼" 양분을 먹고 나이가 1 증가
    // 2. 여러 나무가 있다면 어린 나무부터 양분을 먹음(정렬 필요)
    // 3. 자기 나이만큼 먹을 양분이 없으면 죽는다.
    for(int i = 1; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            sort(map[i][j].begin(), map[i][j].end(), compare);
            vector<Tree>::iterator iter;
            for(iter = map[i][j].begin() ; iter != map[i][j].end() ; iter++){
                if(foodMap[i][j] >= iter->age){ // 먹을 양분이 있으면
                    foodMap[i][j] -= iter->age;
                    iter->age++;
                }else{ //먹을 양분이 없으면 그 뒤로 다 죽음
                    vector<Tree>::iterator tempIter;
                    tempIter = iter;
                    for(; iter != map[i][j].end() ; iter++){
                        deadQ.push(*iter);
                    }
                    map[i][j].erase(tempIter, map[i][j].end());
                    break;
                }
            }
        }
    }
}

void summer(){
    // 0. 죽은 나무 큐 사이즈 만큼 ans에서 빼줌(X)
    // 1. 봄에 죽은 나무가 양분으로 변함
    // 2. 죽은 나무의 나이 / 2 가 나무가 있던 칸에 양분으로 됨
    while(!deadQ.empty()){
        Tree dead = deadQ.front();
        deadQ.pop();
        foodMap[dead.x][dead.y] += dead.age/2;
    }
}

void fall(){
    // 1. 번식 대상은 나이가 5의 배수인 나무
    // 2. 인접 8칸으로 나이가 1인 나무가 번식하게됨
    for(int i = 1; i <= N ; i++){
        for(int j = 1 ; j<= N ; j++){
            vector<Tree>::iterator iter;
            for(iter = map[i][j].begin() ; iter != map[i][j].end() ; iter++){
                if(iter->age % 5 != 0)
                    continue;
                for(int k = 0 ; k < 8 ; k++){
                    int xx = iter->x + dir.at(k).first;
                    int yy = iter->y + dir.at(k).second;
                    if(xx < 1 || yy < 1 || xx > N || yy > N)
                        continue;
                    Tree baby = {xx, yy, 1};
                    map[xx][yy].push_back(baby);
                }
            }
        }
    }
}

void winter(){
    // 1. 초기 입력값만큼 양분이 추가됨
    for(int i = 1; i <= N ; i++){
        for(int j = 1 ; j<= N ; j++){
            foodMap[i][j] += plusMap[i][j];
        }
    }
}

bool compare(Tree a, Tree b){ // 나이가 어린 순으로 나무 정렬
    return a.age < b.age;
}

void init(){
    //freopen("input.txt", "r", stdin);
    cin>>N>>M>>K;
    for(int i = 1; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            cin>>plusMap[i][j];
        }
    }

    while(M-- > 0){
        Tree init;
        cin>>init.x>>init.y>>init.age;
        map[init.x][init.y].push_back(init);
    }
    
    for(int i = 1; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            foodMap[i][j] = 5; //영양분 맵 5로 초기화
        }
    }
    
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(-1, 0));
    dir.push_back(make_pair(1, 1));
    dir.push_back(make_pair(-1, 1));
    dir.push_back(make_pair(-1, -1));
    dir.push_back(make_pair(1, -1));
}
