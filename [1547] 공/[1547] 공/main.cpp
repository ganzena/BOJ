//
//  main.cpp
//  [1547] 공
//
//  Created by YOO TAEWOOK on 25/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> ball;
int N;
void init();
int main(int argc, const char * argv[]) {
    init();
    return 0;
}

void init(){
    ball.assign(3, false);
    ball.at(0) = true;
    
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        int target1, target2;
        cin>>target1>>target2;
        target1--;
        target2--;
        swap(ball.at(target1), ball.at(target2));
    }
    
    for(int i = 0 ; i < 3 ; i++){
        if(ball.at(i) == true){
            cout<<i + 1<<endl;
            return;
        }
    }
}
