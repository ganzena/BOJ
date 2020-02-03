//
//  main.cpp
//  [1062] 가르침
//
//  Created by YOO TAEWOOK on 03/02/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, maximum = 0;
int basic = 0;
vector<char> fullSet;
vector<bool> visited;
vector<char> perm;
vector<vector<char> > inputs;

void init();
void select(int, int);
void checkWord();

int main(int argc, const char * argv[]) {
    init();
    if(K > 5)
        select(0, 0);
    cout<<maximum + basic<<endl;
    return 0;
}

void checkWord(){
    int cnt = 0;
    for(int i = 0 ; i < N ; i++){
        vector<char> input = inputs.at(i);
        int j;
        for(j = 0 ; j < input.size() ; j++){
            char target = input.at(j);
            if(!visited[target - 'a']) //해당 위치의 값이 false 면 못 읽는 단어인것
                break;
            
        }
        if(j == input.size())
            cnt++;
    }
    maximum = max(maximum, cnt);
    
}

void select(int depth, int index){
    if(depth == K - 5){
        checkWord();
        //print();
        return ;
    }
    
    for(int i = index ; i < visited.size() ; i++){
        if(!visited[i]){
            visited[i] = true;
            select(depth + 1, i + 1);
            visited[i] = false;
        }
    }
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>N>>K;
    // a n t i c
    if(K < 5) // 기본 문자 5개를 모르면 아예 못 읽으므로
        return;
    visited.assign(26, false); //알파벳 갯수만큼의 visited 배열 선언
    visited['a' - 'a'] = true;
    visited['n' - 'a'] = true;
    visited['t' - 'a'] = true;
    visited['i' - 'a'] = true;
    visited['c' - 'a'] = true; //기본값들 true로 설정
    
    for(int i = 0 ; i < N ; i++){
        vector<char> input;
        string str;
        cin>>str;
        for(int j = 0 ; j < str.size() ; j++){
            input.push_back(str.at(j));
        }
        
        for(int j = 0 ; j < input.size() ; j++){
            char temp = input.at(j);
            if(temp == 'a' || temp == 'n' || temp == 't' || temp == 'i' || temp == 'c')
                continue;
            bool isNo = true;
            for(int k = 0 ; k < fullSet.size() ; k++){
                if(fullSet.at(k) == temp){
                    isNo = false;
                    break;
                }
            }
            if(isNo){
                fullSet.push_back(temp);
            }
        }
        input.erase(input.begin(), input.begin() + 4); // 접두사 제거
        input.erase(input.end() - 4, input.end()); // 접미사 제거
        
        vector<char>::iterator iter;
        for(vector<char>::iterator iter = input.begin() ; iter != input.end() ; iter++){ // 기본 값들 있으면 다 제거
            if(*iter == 'a' || *iter  == 'n' || *iter  == 't' || *iter  == 'i' || *iter  == 'c')
                input.erase(iter--);
        }
        if(input.empty()){ //빈 값이라면 리스트에 넣지 않는다.
            basic++;
        } else{
            inputs.push_back(input);
        }
    }
    N -= basic; //빈 값이라 안 들어간 숫자만큼 N에서 빼준다
}
