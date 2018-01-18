//
//  main.cpp
//  [10866] 덱
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <deque>

using namespace std;

int main(int argc, const char * argv[]) {
    deque<int>::iterator iter;
    deque<int> deque;
    string input;
    int counter = 0;
    int number;
    cin>>number;
    while(counter < number){
        cin>>input;
        if(input == "push_front"){
            int num;
            cin>>num;
            deque.push_front(num);
        }else if(input == "push_back"){
            int num;
            cin>>num;
            deque.push_back(num);
        }else if(input == "pop_front"){
            if(deque.empty()){
                cout<<-1<<endl;
            }else{
                cout<<deque.front()<<endl;
                deque.pop_front();
            }
        }else if(input == "pop_back"){
            if(deque.empty()){
                cout<<-1<<endl;
            }else{
                cout<<deque.back()<<endl;
                deque.pop_back();
            }
        }else if(input == "size"){
            cout<<deque.size()<<endl;
        }else if(input == "empty"){
            if(deque.empty())
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }else if(input == "front"){
            if(deque.empty()){
                cout<<-1<<endl;
            }else{
                cout<<deque.front()<<endl;
            }
        }else if(input == "back"){
            if(deque.empty()){
                cout<<-1<<endl;
            }else{
                cout<<deque.back()<<endl;
            }
        }
        
        counter++;
    }
    return 0;
}
