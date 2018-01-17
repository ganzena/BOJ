//
//  main.cpp
//  [1934] 최소공배수
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}

int main()
{
    int number;
    cin>>number;
    
    for(int i = 0 ; i < number ; i++){
        int a, b;
        cin>>a>>b;
        cout<<lcm(a,b)<<endl;
    }
}
