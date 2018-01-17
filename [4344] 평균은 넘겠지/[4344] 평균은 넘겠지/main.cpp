//
//  main.cpp
//  [4344] 평균은 넘겠지
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int num_Test;
    int num_Student;
    double total;
    double avg = 0;
    int counter;
    double upper;
    cin>>num_Test;
    for(int i = 0 ; i < num_Test ; i++){
        cin>>num_Student;
        double* scoreArr = new double [num_Student];
        total = 0;
        counter = 0;
        for(int j = 0 ; j < num_Student ; j++){
            cin>>scoreArr[j];
            total+=scoreArr[j];
        }
        avg = total / num_Student;
        for(int j = 0 ; j < num_Student ; j++){
            if(scoreArr[j] > avg)
                counter++;
        }
        upper = (double)counter / (double)num_Student * 100;
        cout<<fixed;
        cout.precision(3);
        cout<< upper << "%" <<endl;
        
    }
    
    
    return 0;
}
