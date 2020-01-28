//
//  main.cpp
//  [1969] DNA
//
//  Created by YOO TAEWOOK on 21/01/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>


using namespace std;

int row, col;
vector<string> strList;
map<char, int> strMap;
string result;
int dist = 0;

void init();
void print();
void getDistance();
void mapInit();
char findMax();

int main(){
    init();
    getDistance();
    return 0;
}


void init(){
    freopen("input.txt", "r", stdin);
    cin >> row >> col;
    for (int i = 0; i < row; i++){
        string tmp;
        cin >> tmp;
        strList.push_back(tmp);
    }
}

void getDistance(){
    
    for (int i = 0; i < col; i++){
        mapInit();
        for (int j = 0; j < row; j++){
            char temp = strList.at(j).at(i);
            strMap.find(temp)->second++;
        }
        char addChar = findMax();
        result.push_back(addChar);
        strMap.clear();
    }
    
    cout << result << endl;
    cout << dist << endl;
}

char findMax(){
    map<char, int>::iterator iter;
    map<char, int>::iterator maxIter;
    int max = 0;
    for (iter = strMap.begin(); iter != strMap.end(); iter++){
        if (iter->second > max){
            max = iter->second;
            maxIter = iter;
        }
    }
    
    
    dist += row - (maxIter->second);
    return maxIter->first;
}

void mapInit(){
    strMap.insert(make_pair('T', 0));
    strMap.insert(make_pair('G', 0));
    strMap.insert(make_pair('A', 0));
    strMap.insert(make_pair('C', 0));
}


