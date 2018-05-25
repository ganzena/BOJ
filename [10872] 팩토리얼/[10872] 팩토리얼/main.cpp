//
//  main.cpp
//  [10872] 팩토리얼
//
//  Created by YOO TAEWOOK on 2018. 4. 26..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

typedef unsigned long long int type;
using namespace std;

vector<type> factorial;
type num;
void DP();
type Recursion(type);

int main(int argc, const char * argv[]) {
    cin>>num;
    //DP();
    cout<<Recursion(num)<<endl;
    return 0;
}

void DP(){
    factorial.assign(num + 1, 0);
    factorial[0] = 1;
    for(int i = 1 ; i < factorial.size() ; i++){
        factorial[i] = factorial[i - 1] * i;
    }
    cout<<factorial[num]<<endl;
}

type Recursion(type num){
    if(num == 0)
        return 1;
    
    return Recursion(num - 1) * num;
}


