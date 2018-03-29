//
//  main.cpp
//  [1920] 수 찾기
//
//  Created by YOO TAEWOOK on 2018. 3. 29..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> input;
queue<int> testQueue;

bool binarySearch(int);

int inputSize, testSize;

int main(int argc, const char * argv[]) {
    cin>>inputSize;
    input.assign(inputSize, 0);
    for(int i = 0 ; i < inputSize ; i++){
        cin>>input[i];
    }
    sort(input.begin(), input.end());
    
    cin>>testSize;
    for(int i = 0 ; i < testSize ; i++){
        int temp;
        cin>>temp;
        testQueue.push(temp);
    }
    
    while(!testQueue.empty()){
        int target = testQueue.front();
        testQueue.pop();
        if(binarySearch(target))
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}

bool binarySearch(int target){
    int max = inputSize - 1;
    int min = 0;
   
    while(min <= max){
        int mid = (max + min) / 2;
        if(input.at(mid) > target){
            max = mid - 1;
        }else if(input.at(mid) < target){
            min = mid + 1;
        }else{
            return true;
        }
    }
    return false;
}
