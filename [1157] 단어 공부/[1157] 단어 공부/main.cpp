//
//  main.cpp
//  [1157] 단어 공부
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    map<char, int>::iterator iter;
    map<char, int>::iterator maxIter;
    map<char, int> map;
    
    int counter = 0;
    string input;
    
    cin>>input;
    
    transform(input.begin(), input.end(), input.begin(), ::toupper); //소문자를 대문자로 바꾸는 작업 1.시작점 2.끝점 3.저장위치 4.변환형태
    
    for(int i = 0 ; i < input.length() ; i++){
        if(map.find(input.at(i)) == map.end()) //find 함수는 못 찾았을 시에 map.end()를 리턴
            map.insert(pair<char, int>(input.at(i), 1));
        else
            map.find(input.at(i))->second++;
    }
    maxIter = map.begin();
    for(iter = map.begin() ; iter != map.end() ; iter++){
        if(maxIter->second < iter->second)
            maxIter = iter;
    }
    
    for(iter = map.begin() ; iter != map.end() ; iter++){
        if(maxIter->second == iter->second){
            counter++;
            if(counter > 1){
                cout<<"?"<<endl;
                return 0;
            }
        }
    }
    
    cout<<maxIter->first<<endl;
    
    return 0;
}
