//
//  main.cpp
//  [1316] 그룹 단어 체커
//
//  Created by YOO TAEWOOK on 2018. 1. 20..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    int test;
    cin>>test;
    int counter = 0;
    int groupCounter = 0;
    while(counter < test){
        string input;
        cin>>input;
        map<char, bool>::iterator iter;
        map<char, bool> map;
        int i;
        for(i = 0 ; i < input.length() ; i++){
            if(map.find(input.at(i)) == map.end()){ // 해당 알파벳이 없을 때
                if(i > 0)
                    if(input.at(i) != input.at(i - 1))
                        map.find(input.at(i - 1))->second = false;
                
                map.insert(pair<char, bool>(input.at(i), true));
                
            }else{ // 해당 알파벳을 찾았을 때
                if(map.find(input.at(i))->second == true){ // 아직 반복 중인 경우
                    continue;
                } else{ //반복이 이미 끝난 경우(group 단어가 아님)
                    i = 0;
                    break;
                }
            }
        }
        if(i != 0)
            groupCounter++;
        counter++;
    }
    
    cout<<groupCounter<<endl;
    return 0;
}
