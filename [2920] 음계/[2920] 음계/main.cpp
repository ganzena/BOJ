//
//  main.cpp
//  [2920] 음계
//
//  Created by YOO TAEWOOK on 2018. 1. 23..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int array [8];
    int temp;
    
    for(int i = 0 ; i < 8 ; i++){
        int input;
        cin>>input;
        array[i] = input;
    }
    
    temp = array[0] - array[1];
    
    for(int i = 0 ; i < 7 ; i++){
        if(temp != (array[i] - array[i + 1])){
            cout<<"mixed"<<endl;;
            return 0;
        }
    }
    if(temp < 0)
        cout<<"ascending"<<endl;
    else
        cout<<"descending"<<endl;
    
    return 0;
}
