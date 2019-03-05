//
//  main.cpp
//  [2747] 피보나치 수
//
//  Created by YOO TAEWOOK on 2018. 2. 18..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

typedef long long int type;


void DP();
int Recursion(int);
type num;
int main(int argc, const char * argv[]) {
    
   
    cin>>num;
    DP();
    //cout<<Recursion(num)<<endl;
    
    

    return 0;
}

int Recursion(int input){
    if(input == 0)
        return 0;
    if(input == 1)
        return 1;
    
    return Recursion(input - 1) + Recursion(input - 2);
}

void DP(){
    int* fibo = new int[num + 1];
    fibo[0] = 0;
    fibo[1] = 1;
    
    for(int i = 2 ; i <= num ; i++){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    cout<<fibo[num]<<endl;
}
