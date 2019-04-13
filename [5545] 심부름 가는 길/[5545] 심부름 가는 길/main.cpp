//
//  main.cpp
//  [5545] 심부름 가는 길
//
//  Created by YOO TAEWOOK on 25/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>

using namespace std;

void init();
void printTime();

int total = 0;
int main(int argc, const char * argv[]) {
    init();
    printTime();
    return 0;
}

void init(){
    for(int i = 0 ; i < 4 ; i++){
        int sec;
        cin>>sec;
        total += sec;
    }
}

void printTime(){
    int min = total/60;
    int sec = total%60;
    cout<<min<<endl;
    cout<<sec<<endl;
}
