//
//  main.cpp
//  [2675] 문자열 반복
//
//  Created by YOO TAEWOOK on 2018. 1. 18..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {

    int test;
    cin>>test;
    int counter = 0;
    while(counter < test){
        int number;
        string input;
        cin>>number>>input;
        string changed;
        for(int i = 0 ; i < input.size() ; i++){
            for(int j = 0 ; j < number ; j++){
                changed.push_back(input.at(i));
            }
        }
        cout<<changed<<endl;
        counter++;
    }
    
    return 0;
}
