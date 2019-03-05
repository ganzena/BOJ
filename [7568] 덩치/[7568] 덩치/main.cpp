//
//  main.cpp
//  [7568] 덩치
//
//  Created by YOO TAEWOOK on 03/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Dungchi{
    pair<int, int> hw;
    int rank;
};

int n;
vector<Dungchi> dungchiList;

void init();
void ranking();
void print();

int main(int argc, const char * argv[]) {
    init();
    ranking();
    print();
    return 0;
}

void print(){
    for(int i = 0 ; i < dungchiList.size() ; i++){
        cout<<dungchiList.at(i).rank<<" ";
    }
    cout<<endl;
}

void ranking(){
    for(int i = 0 ; i < dungchiList.size() ; i++){
        for(int j = 0 ; j < dungchiList.size() ; j++){
            if(dungchiList.at(i).hw.first < dungchiList.at(j).hw.first){
                if(dungchiList.at(i).hw.second < dungchiList.at(j).hw.second){
                    dungchiList.at(i).rank++;
                }
            }
        }
    }
}

void init(){
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        int first;
        int second;
        cin>>first>>second;
        Dungchi dungchi = {make_pair(first, second), 1};
        dungchiList.push_back(dungchi);
    }
}
