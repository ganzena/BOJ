//
//  main.cpp
//  [Codility] BinaryGap
//
//  Created by YOO TAEWOOK on 2018. 5. 14..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>

using namespace std;
int solution(int N);
int main(int argc, const char * argv[]) {
    cout<<solution(51712)<<endl;
    return 0;
    
    
}

int solution(int N) {
    int maxGap = 0;
    int tempGap = 0;
    bool flag = false;
    while(N != 0){
        if(flag == false){
            if(N % 2 == 1)
                flag = true;
        }else{
            if(N % 2 == 1){
                maxGap = max(maxGap, tempGap);
                tempGap = 0;
            }else{
                tempGap++;
            }
        }
        N /= 2;
    }
    return maxGap;
}
