//
//  main.cpp
//  [2941] 크로아티아 알파벳
//
//  Created by YOO TAEWOOK on 2018. 2. 16..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) { //=, -, j
    vector<string> croatia = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    int counter = 0;
    string input;
    cin>>input;
    
    for(int i = 0 ; i < input.length() ; i++){
        for(int j = 0 ; j < croatia.size() ; j++){
            if(!input.substr(i, croatia.at(j).length()).compare(croatia.at(j))){ //input.at(i)서부터 croatia.at(j)의 길이만큼 잘라서 croatia.at(j)와 비교
                i += croatia.at(j).length() - 1; //두 문자열이 서로 같으므로, 다음에 비교할 알파벳의 직전으로 i를 위치시킨다.
                break;
                }
            }
        counter++;
    }
    
    cout<<counter<<endl;
    return 0;
}
