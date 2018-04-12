//
//  main.cpp
//  Test 1
//
//  Created by YOO TAEWOOK on 2018. 3. 30..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <algorithm>
#include <limits.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
vector<pii> dir = {pii(-1, 0), pii(0, -1), pii(1, 0), pii(0, 1)};

int inputNum;
string input;
vector<pci> inputVector;
vector<pci>::iterator findIter;
int main(int argc, const char * argv[]) {
    cin>>inputNum;
    while(inputNum--){
        cin>>input;
        char standard;
        for(int i = 0 ; i < input.length() ; i++){
            standard = input.at(i);
            int counter = 0;
            int j;
            for(j = i ; j < input.length() ; j++){
                if(input.at(j) == standard){
                    counter++;
                    if(j == input.length() - 1)
                        i = input.length();
                }else{

                    i = j - 1;
                    break;
                }
            }
            inputVector.push_back(pci(standard, counter));
            
        }
        for(findIter = inputVector.begin() ; findIter != inputVector.end() ; findIter++){
            cout<<findIter->second<<findIter->first;
        }
        cout<<endl;

        inputVector.clear();
        input.clear();
    }
    
    return 0;
}


