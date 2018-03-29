//
//  main.cpp
//  [10816] 숫자 카드 2
//
//  Created by YOO TAEWOOK on 2018. 3. 29..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

typedef pair<int, int> pii;
map<int, int> inputMap;


int inputSize, testSize;

int main(int argc, const char * argv[]) {
    scanf("%d", &inputSize);
    //input.assign(inputSize, 0);
    
    for(int i = 0 ; i < inputSize ; i++){
        int temp;
        scanf("%d", &temp);
        inputMap[temp]++;
    }
    
    scanf("%d", &testSize);
    for(int i = 0 ; i < testSize ; i++){
        int temp;
        scanf("%d", &temp);
        if(inputMap.find(temp) != inputMap.end())
            printf("%d ", inputMap.find(temp)->second);
        else
            printf("0 ");
    }
    printf("\n");
    return 0;
}

