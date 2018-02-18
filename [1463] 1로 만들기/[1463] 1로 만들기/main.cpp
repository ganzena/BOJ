//
//  main.cpp
//  [1463] 1로 만들기
//
//  Created by YOO TAEWOOK on 2018. 2. 2..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int input;
    int counter = 0;
    cin>>input;
    
    while(input != 1){
        if(input % 3 == 0 || input % 2 == 0){
            if(input % 3 == 0){
                input /= 3;
            }else{
                input /= 2;
            }
        }else{
            input--;
        }
        counter++;
    }
    
    cout<<counter<<endl;
    return 0;
}
