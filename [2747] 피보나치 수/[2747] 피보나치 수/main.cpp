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

int main(int argc, const char * argv[]) {
    type input;
    cin>>input;
    vector<type> vector = {0,1,1};

    for(int i = 3 ; i <= input ; i++){
        vector.push_back(vector.at(i - 1) + vector.at(i - 2));
    }
    
    cout<<vector.at(input)<<endl;
    return 0;
}
