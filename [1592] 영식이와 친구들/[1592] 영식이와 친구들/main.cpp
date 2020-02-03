//
//  main.cpp
//  [1592] 영식이와 친구들
//
//  Created by YOO TAEWOOK on 03/02/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void throws();
void init();

vector<int> lines;
int N, M, L; // N : 사람수   M : 한 사람이 M 번 받으면 끝   L : 몇번째 사람에게 줄건지
int main(int argc, const char * argv[]) {
    init();
    throws();
    return 0;
}
void throws(){
    int i = 0;
    int size = N;
    int cnt = 0;
    while(1){
        //cout<<i + 1<<" ";
        if(++lines.at(i) == M){
            break;
        }
        
        if(lines.at(i)%2 == 0){ //반시계 L만큼
            if(i - L < 0){
                int tempL = L - i;
                i = size - tempL;
            }else{
                i -= L;
            }
        }else{ //시계 L만큼
            if(i + L >= N){
                int tempL = L - (size - i);
                i = tempL;
            }else{
                i += L;
            }
        }
        cnt++;
    }
    cout<<cnt<<endl;
}
void init(){
    freopen("input.txt", "r", stdin);
    cin>>N>>M>>L;
    lines.assign(N, 0);
}
