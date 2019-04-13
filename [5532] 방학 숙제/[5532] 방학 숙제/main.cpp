//
//  main.cpp
//  [5532] 방학 숙제
//
//  Created by YOO TAEWOOK on 25/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>

using namespace std;

int L, A, B, C, D;
int playDay;

void init();
void calculate();

int main(int argc, const char * argv[]) {
    init();
    calculate();
    cout<<playDay<<endl;
    return 0;
}

void init(){
    cin>>L>>A>>B>>C>>D;
}

void calculate(){
    int koreanMax = A % C == 0 ? A / C : (A / C) + 1;
    int mathMax = B % D == 0 ? B / D : (B / D) + 1;
    int studyMax = koreanMax > mathMax ? koreanMax : mathMax;
    playDay = L - studyMax;
}
