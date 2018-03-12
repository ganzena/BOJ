//
//  main.cpp
//  [6603] 로또
//
//  Created by YOO TAEWOOK on 2018. 3. 9..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#define MAXSIZE 13

using namespace std;
vector<int> lotto(MAXSIZE);
vector<int> combi(MAXSIZE);

int num;
void Combination(int, int);

int main(int argc, const char * argv[]) {
    stack<int> deniedStack;
    while(cin>>num&&num){ // 0 입력 받을 때까지 계속하기
        for(int i = 0 ; i < num ; i++){
            cin>>lotto[i];
        }
        Combination(0, 0);
        cout<<endl;
    }
    return 0;
}

void Combination(int start, int depth){
    if(depth == 6) {
        for(int i = 0; i < 6; i++) {
            cout << combi[i] << ' ';
        }
        cout<<endl;
        return;
    }
    
    for(int i = start; i< num; i++) {
        combi[depth] = lotto[i];
        Combination(i + 1, depth + 1);
    }
}
