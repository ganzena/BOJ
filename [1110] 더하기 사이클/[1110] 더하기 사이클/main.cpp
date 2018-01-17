//
//  main.cpp
//  [1110] 더하기 사이클
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int number;
    cin>>number;
    
    int counter = 0;
    int temp = number;
    
    int ten;
    int unit;
    int sum = 0;
    
    while(1){
        ten = number / 10;
        unit = number % 10;
        sum = ten + unit;
        sum = sum % 10;
        number = unit * 10 + sum;
        
        counter++;
        if(temp == number)
            break;
    }
    
    cout<<counter<<endl;
}

