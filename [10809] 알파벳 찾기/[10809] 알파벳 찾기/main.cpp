//
//  main.cpp
//  [10809] 알파벳 찾기
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

int main()
{
    string input;
    cin>>input;
    map<char, int>::iterator iter;
    map<char, int> alphabet = {{'a', -1} , {'b', -1} , {'c', -1} , {'d', -1} , {'e', -1} , {'f', -1} , {'g', -1} , {'h', -1}, {'i', -1} , {'j', -1} , {'k', -1} , {'l', -1} , {'m', -1} , {'n', -1} , {'o', -1} , {'p', -1} , {'q', -1} , {'r', -1} , {'s', -1} , {'t', -1} , {'u', -1} , {'v', -1} , {'w', -1} , {'x', -1} , {'y', -1} , {'z', -1}};
    
    for(int i = 0 ; i < input.size() ; i++)
        if(alphabet.find(input.at(i))->second == -1)
            alphabet.find(input.at(i))->second = i;
    
    
    for(iter = alphabet.begin() ; iter != alphabet.end() ; iter++)
        cout<<iter->second<<' ';
    
    cout<<endl;
}



