//
//  main.cpp
//  [3036] 링
//
//  Created by YOO TAEWOOK on 2018. 2. 16..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b){return b?GCD(b,a%b):a;}
int main(int argc, const char * argv[]) {
    int test;
    cin>>test;
    vector<int> vector;
    
    while(test != 0){
        int input;
        cin>>input;
        vector.push_back(input);
        test--;
    }
    
    for(int i = 1 ; i < vector.size() ; i++){
        int gcd = GCD(vector.at(0), vector.at(i));
        int boonMo = vector.at(i) / gcd;
        int boonJa = vector.at(0) / gcd;
        cout<<boonJa<<"/"<<boonMo<<endl;
    }
    
    return 0;
}
