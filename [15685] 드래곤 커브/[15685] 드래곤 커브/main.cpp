//
//  main.cpp
//  [15685] 드래곤 커브
//
//  Created by YOO TAEWOOK on 14/04/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//    1
//2       0
//    3
struct DragonCurve{
    pair<int, int> loc;
    int dir;
    int gen;
};

vector< vector<int> > map(101, vector<int>(101, 0));
vector<DragonCurve> dcV;
//vector< pair<int, int> > dir = {make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1), make_pair(1, 0)};
vector< pair<int, int> > dir;


int N;
int counter = 0;

void init();
void draw();
void count();

int main(int argc, const char * argv[]) {
    init();
    draw();
    count();
    cout<<counter<<endl;
    return 0;
}

void draw(){
    for(int i = 0 ; i < (int)dcV.size() ; i++){
        DragonCurve dc = dcV.at(i);
        vector<int> history;
        history.push_back(dc.dir);
        while(dc.gen > 0){
            for(int i = (int)history.size() - 1 ; i >= 0 ; i--)
                history.push_back((history.at(i) + 1) % 4);
            dc.gen--;
        }
        pair<int, int> now = dc.loc;
        map[now.first][now.second] = 1;
        for(int i = 0 ; i < (int)history.size() ; i++){
            now = make_pair(now.first + dir.at(history.at(i)).first, now.second + dir.at(history.at(i)).second);
            if(now.first < 0 || now.first >= 101 || now.second < 0 || now.second >= 101)
                continue;
            map[now.first][now.second] = 1;
        }
    }
}

void count(){
    for(int i = 0 ; i < 100 ; i++){
        for(int j = 0 ; j < 100 ; j++){
            if(map[i][j] == 1){
                if(map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1)
                    counter++;
            }
        }
    }
}

void init(){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        int x,y,d,g;
        cin>>y>>x>>d>>g;
        DragonCurve temp;
        temp.loc = make_pair(x, y);
        temp.dir = d;
        temp.gen = g;
        dcV.push_back(temp);
    }
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(-1, 0));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(1, 0));
}
