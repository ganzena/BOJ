//
//  main.cpp
//  [5397] 키로거
//
//  Created by YOO TAEWOOK on 29/01/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
// - : back space / < > : 왼 오 이동
// 입력되면 커서는 오른쪽으로 이동
using namespace std;

vector<string> inputs;
string input;
int N;

void init();
void solve();


int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void solve(){
    for(int i = 0 ; i < N ; i++){
        string temp = "";
        string::iterator iter = temp.begin();
        string input = inputs.at(i);
        for(int j = 0 ; j < input.size() ; j++){
            char c = input.at(j);
            if(c == '<'){
                if(iter != temp.begin()) // 커서의 위치가 맨 앞이 아니면
                    iter--; // 왼쪽으로 이동
            }else if(c == '>'){
                if(iter != temp.end()) // 커서의 위치가 맨 끝이 아니면
                    iter++; // 오른쪽으로 이동
            }else if(c == '-'){
                if(iter == temp.begin()){
                    //커서가 맨 앞이면 아무것도 하지않음
                }else{
                    // 아니면 반복자 왼쪽으로 옮겨서 지움
                    iter = temp.erase(--iter);
                    
                }
            }else {

                //temp.insert(iter++, c);
                
                
                iter = temp.insert(iter, c);
                iter++;
            }
        }
        cout<<temp<<endl;
    }
}
void init(){

    freopen("input.txt", "r", stdin);
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        string temp;
        cin>>temp;
        inputs.push_back(temp);
    }
}
