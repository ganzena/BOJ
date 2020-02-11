//
//  main.cpp
//  [1065] 한수
//
//  Created by YOO TAEWOOK on 05/02/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>

using namespace std;

int N;
int cnt = 0;

int main(int argc, const char * argv[]) {
    //freopen("input.txt", "r", stdin);
    cin>>N;
    if(N < 100){
        cnt = N;
    }else{
        cnt += 99;
        int one = 0, ten = 0, hundread = 0;
        for(int i = 100 ; i <= N ; i++){
            int tempN = i;
            while(tempN >= 10){
                if(tempN >= 100){
                    one = tempN % 10;
                    tempN /= 10;
                }else{
                    ten = tempN % 10;
                    hundread = tempN / 10;
                    tempN /= 10;
                }
            }
            int cha1 = ten - one;
            int cha2 = hundread - ten;
            if(cha1 == cha2)
                cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
