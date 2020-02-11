//
//  main.cpp
//  [1107] 리모컨
//
//  Created by YOO TAEWOOK on 05/02/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int N, M, mini = 5000000;
int minChannel = 5000000;
vector<bool> numbers;
vector<int> decade; //거꾸로 큰수
deque<pair<int, int> > push;
vector<pair<int, int> > memory;
void init();
void set();
void howLong();

int main(int argc, const char * argv[]) {
    init();
    set();
    cout<<mini<<endl;
    return 0;
}
void howLong(){
    
}
void set(){
    int tempN = N;
    int cnt = 0;
    while(tempN != 0){
        tempN /= 10;
        cnt++;
    }
    int bigTarget = N, smallTarget = N, digit = 1;
    while(1){
        bool allPass = true;
        int tempBig = bigTarget / digit;
        while(tempBig != 0){
            if(!numbers.at(tempBig % 10)){
                allPass = false;
                
                break;
            }else{
                tempBig /= 10;
                digit *= 10;
            }
        }
        
        if(!allPass){
            bigTarget += digit;
            //digit = 1;
        }else{
            break;
        }
    }
    digit = 1;
    while(1){
        bool allPass = true;
        int tempSmall = smallTarget / digit;
        while(tempSmall != 0){
            if(!numbers.at(tempSmall % 10)){
                allPass = false;
                break;
            }else{
                tempSmall /= 10;
                digit *= 10;
            }
        }
        if(!allPass){
            smallTarget -= digit;
        }else{
            break;
        }
    }
    //    cout<<"N : "<<N<<endl;
    //    cout<<"N보다 큰 수 : "<<bigTarget<<endl;
    //    cout<<"N보다 작은 수 : "<<smallTarget<<endl;
    int bigCnt = (bigTarget - N + cnt);
    int smallCnt = (N - smallTarget + cnt);
    mini = min(bigCnt, smallCnt);
    mini = min(mini, N - 100);
}



void init(){
    //freopen("input.txt", "r", stdin);
    cin>>N>>M;
    numbers.assign(10, true);
    for(int i = 0 ; i < M ; i++){
        int wrong;
        cin>>wrong;
        numbers.at(wrong) = false;
    }
}
