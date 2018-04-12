//
//  main.cpp
//  [1021] 회전하는 큐
//
//  Created by YOO TAEWOOK on 2018. 4. 9..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <deque>
#include <queue>

using namespace std;


int qSize, num, totalCnt = 0;
int main(int argc, const char * argv[]) {
    deque<int> deq;
    queue<int> cmd;
    cin>>qSize>>num;
    for(int i = 1 ; i <=qSize ; i++){
        deq.push_back(i);
    }
    for(int i = 0 ; i < num ; i++){
        int temp;
        cin>>temp;
        cmd.push(temp);
    }
    while(!cmd.empty()){
        int value = cmd.front();
        cmd.pop();
        if(value == deq.front()){
            deq.pop_front();
        }else{
            int leftCnt = 0;
            int rightCnt;
            while(value != deq.front()){
                int temp = deq.front();
                deq.pop_front();
                deq.push_back(temp);
                leftCnt++;
            }
            deq.pop_front();
            rightCnt = (int)deq.size() + 1 - leftCnt;
            totalCnt += (leftCnt < rightCnt ? leftCnt : rightCnt);
        }
    }
    cout<<totalCnt<<endl;
    return 0;
}
