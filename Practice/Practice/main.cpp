//
//  main.cpp
//  Practice
//
//  Created by YOO TAEWOOK on 2018. 4. 26..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

//정수 배열이 주어지면 1부터 시작하여 배열에 없는 가장 작은
//양수를 찾으시오. 시간복잡도 제한: O(n)
//
//예)
//input: [1, 2, 3, 4]
//output: 5
//
//input: [1, 2, 4, 5]
//output: 3
//
//input: [-4, 4, 6, 3, 1]
//output: 2
//
//input: [2, 1, 0, 3]
//output: 4

#include <iostream>
#include <vector>

using namespace std;



void quickSort(int, int, int*);
void solve(int*);
int main(int argc, const char * argv[]) {
    
    int test[4] = {1, 2, 3, 4};
//    int test[4] = {1, 2, 4, 5};
//    int test[5] = {-4, 4, 6, 3, 1};
//    int test[5] = {-4, 1, 3, 4, 6};
//    int test[4] = {2, 1, 0, 3};

    return 0;
}

void quickSort(int left, int right, int* test){
    
}

void solve(int* test){
    int min = 99999999;
    int max = 0;
    int len = sizeof(*test) / sizeof(int);

    for(int i = 0 ; i < len ; i++){
        if(min >= test[i]){
            if(test[i] > 0)
                min = test[i] + 1;
        }
        
        if(max <= test[i])
            max = test[i] + 1;
    }
    printf("최솟값 : %d, 최댓값 : %d\n", min, max);
}




