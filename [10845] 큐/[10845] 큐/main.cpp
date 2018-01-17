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

using namespace std;


int main()
{
    int count;
    string command;
    cin>>count;
    
    queue<int> queue;
    
    for(int i = 0 ; i < count ; i++){
        cin>>command;
        if(command == "push"){
            int num;
            cin>>num;
            queue.push(num);
        }else if(command == "pop"){
            if(queue.empty())
                cout<< -1 <<endl;
            else{
                cout<<queue.front()<<endl;
                queue.pop();
            }
        } else if(command == "front"){
            if(queue.empty())
                cout<< -1 <<endl;
            else
                cout<<queue.front()<<endl;;
        } else if(command == "back"){
            if(queue.empty())
                cout<< -1 <<endl;
            else
                cout<< queue.back() <<endl;
        }else if(command == "empty"){
            if(queue.empty())
                cout<< 1 <<endl;
            else
                cout<< 0 <<endl;
        }else if(command == "size"){
            cout<< queue.size() <<endl;
        }
    }
}

