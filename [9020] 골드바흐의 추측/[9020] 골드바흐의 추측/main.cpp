//
//  main.cpp
//  [9020] 골드바흐의 추측
//
//  Created by YOO TAEWOOK on 2018. 2. 20..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    int num, test;
    vector<bool> vector;
    
    cin>>test;
    
    vector.assign(10001, true);
    vector.at(0) = false;
    vector.at(1) = false;
    
    for(int i = 2 ; i < sqrt(vector.size()) ; i++){
        if(vector.at(i)){
            for(int j = i*i ; j < vector.size() ; j += i){ //에라토스체네스의 체는 만나는 수의 배수값들을 모두 지우는 것
                vector.at(j) = false;
            }
        }
    }
    
    while(test){
        cin>>num;
        
        int i,j;
        for(i = j = num/2; j < num; i--, j++){
            if(vector.at(i) == true && vector.at(j) == true){
                cout<<i<<" "<<j<<endl;
                break;
            }
        }
        
        test--;
    }
    return 0;
}
