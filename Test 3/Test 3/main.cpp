//
//  main.cpp
//  Test 3
//
//  Created by YOO TAEWOOK on 2018. 3. 30..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <algorithm>
#include <limits.h>
#define SIZE 100001
using namespace std;


int main(int argc, const char * argv[]) {
    vector<char> test = {'*', '-', '+', '-', '/'};
    sort(test.begin(), test.end());
    for(int i = 0 ; i < test.size() ; i++){
        cout<<test[i]<<" ";
    }cout<<endl;
}

