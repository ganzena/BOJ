//
//  main.cpp
//  [1546] 평균
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    double score;
    int num;
    double total = 0;
    double max = 0;
    
    cin>>num;
    double* scoreArr = new double[num];
    
    for(int i = 0 ; i < num ; i++){
        cin>>score;
        scoreArr[i] = score;
        if(max == 0){
            max = scoreArr[i];
        }else{
            if(max < scoreArr[i])
                max = scoreArr[i];
        }
    }
    
    for(int i = 0 ; i < num ; i++){
        scoreArr[i] = scoreArr[i] / max * 100;
        total += scoreArr[i];
    }
    cout<<fixed;
    cout.precision(2);
    cout<<(total/num)<<endl;
    
    return 0;
}
