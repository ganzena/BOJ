//
//  main.cpp
//  [14888] 연산자 끼워넣기
//
//  Created by YOO TAEWOOK on 2018. 3. 21..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<int> inputVector;
vector<int> copied;
vector<char> math;

int numberNum, add, subtract, multiply, divide;
int maximum = INT_MIN, minimum = INT_MAX;

int main(int argc, const char * argv[]) {
    
    cin>>numberNum;
    inputVector.assign(numberNum, 0);
    math.assign(numberNum - 1, NULL);
    
    for(int i = 0 ; i < inputVector.size() ; i++){
        cin>>inputVector[i];
    }
    cin>>add>>subtract>>multiply>>divide;
    int cnt = 0;
    while(multiply--){
        math[cnt++] = '*';
    }
    while(add--){
        math[cnt++] = '+';
    }
    while(subtract--){
        math[cnt++] = '-';
    }
    while(divide--){
        math[cnt++] = '/';
    }
    
    do{
        copied = inputVector;
        for(int i = 0 ; i < copied.size() - 1 ; i++){
            if(math.at(i) == '+'){
                copied[i + 1] = copied[i] + copied[i + 1];
            }else if(math.at(i) == '-'){
                copied[i + 1] = copied[i] - copied[i + 1];
            }else if(math.at(i) == '*'){
                copied[i + 1] = copied[i] * copied[i + 1];
            }else if(math.at(i) == '/'){
                bool negative = false;
                if(copied[i] < 0){
                    copied[i] *= -1;
                    negative = true;
                }
                copied[i + 1] = copied[i] / copied[i + 1];
                if(negative){
                    copied[i + 1] *= -1;
                }
            }
        }
        
        int result = copied[copied.size() - 1];
        maximum = max(maximum, result);
        minimum = min(minimum, result);
    }while(next_permutation(math.begin(), math.end()));
    
    cout<<maximum<<endl;
    cout<<minimum<<endl;
    return 0;
}
