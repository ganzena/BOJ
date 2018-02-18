//
//  main.cpp
//  [1158] 조세퍼스 문제
//
//  Created by YOO TAEWOOK on 2018. 2. 16..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int max; //최대 명수
    int next; //몇 번째를 제거할 것인가
    string result = "<";
    cin>>max>>next;
    
    queue<int> queue;
    
    for(int i = 1 ; i <= max ; i++){
        queue.push(i);
    }
    
    while(!queue.empty()){
        for(int i = 1; i < next ; i++){
            queue.push(queue.front());
            queue.pop();
        }
        result += to_string(queue.front());
        queue.pop();
        if(!queue.empty())
            result += ", ";
        else
            result += ">";
    }
    
    cout<<result<<endl;

    return 0;
}
