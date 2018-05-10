//
//  main.cpp
//  [10845] 큐
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#define MAX_SIZE 10000
using namespace std;

class Queue{
public:
    void Push(int);
    void Pop();
    void Size();
    void Empty();
    void Front();
    void Back();
    
    Queue(){
        queue = new int[10001];
        head = 0;
        tail = 0;
        num = 0;
    }
private:
    int* queue;
    int head;
    int tail;
    int num;
};

void Queue::Push(int data){
    if(num == MAX_SIZE){
        
    }else{
        tail = (tail + 1) % MAX_SIZE;
        queue[tail] = data;
    }
}

void Queue::Pop(){
    if(num == 0){
        cout<<-1<<endl;
    }else{
        cout<<queue[head]<<endl;
        head = (head + 1) & MAX_SIZE;
    }
    
}

void Queue::Empty(){
    if(num == 0){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }
}

void Queue::Size(){
    cout<<num<<endl;
}

void Queue::Front(){
    if(num == 0)
        cout<<-1<<endl;
    else
        cout<<queue[head]<<endl;
}

void Queue::Back(){
    if(num == 0)
        cout<<-1<<endl;
    else
        cout<<queue[tail]<<endl;
}

int main()
{
    int count;
    string command;
    cin>>count;
    
    Queue queue;
    
    for(int i = 0 ; i < count ; i++){
        cin>>command;
        if(command == "push"){
            int num;
            cin>>num;
            queue.Push(num);
        }else if(command == "pop"){
            queue.Pop();
        } else if(command == "front"){
            queue.Front();
        } else if(command == "back"){
            queue.Back();
        }else if(command == "empty"){
            queue.Empty();
        }else if(command == "size"){
            queue.Size();
        }
    }
}

