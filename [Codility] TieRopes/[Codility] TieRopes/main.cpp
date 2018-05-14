//
//  main.cpp
//  [Codility] TieRopes
//
//  Created by YOO TAEWOOK on 2018. 5. 13..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>

using namespace std;

int solution(int K, int A[], int N);
int main(int argc, const char * argv[]) {
    int arr[7] = {1, 2, 3, 4, 1, 1, 3};
    cout<<solution(4, arr, 7)<<endl;
    
    return 0;
}

int solution(int K, int A[], int N){
    int tiedLen = 0;
    int ropeCnt = 0;
    
    for(int i = 0 ; i < N ; i++){
        tiedLen += A[i];
        if(tiedLen >= K){
            tiedLen = 0;
            ropeCnt++;
        }
    }
    
    return ropeCnt;
}
