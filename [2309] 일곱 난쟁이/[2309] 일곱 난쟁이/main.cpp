//
//  main.cpp
//  [2309] 일곱 난쟁이
//
//  Created by YOO TAEWOOK on 03/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dwarfList;
vector<int> selected;
vector<int> answer;
void init();
void DFS(int, int);
void print();

int main(int argc, const char * argv[]) {
    init();
    DFS(0,0);
    print();
    return 0;
}

void print(){
    for(int i = 0 ; i < answer.size() ; i++){
        cout<<answer.at(i)<<endl;
    }
}

void DFS(int depth, int index){
    if(depth == 7){
        int sum = 0;
        for(int i = 0 ; i < selected.size() ; i++){
            sum += selected.at(i);
        }

        if(sum == 100){
            answer = selected;
            sort(answer.begin(), answer.end());
        }
        return;
    }
    
    for(int i = index ; i < dwarfList.size(); i++){
        selected.push_back(dwarfList.at(i));
        DFS(depth + 1, i + 1);
        selected.pop_back();
    }
    
}

void init(){
    for(int i = 0 ; i < 9 ; i++){
        int num;
        cin>>num;
        dwarfList.push_back(num);
    }
}
