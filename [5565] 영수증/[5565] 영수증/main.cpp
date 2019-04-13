//
//  main.cpp
//  [5565] 영수증
//
//  Created by YOO TAEWOOK on 25/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>

using namespace std;

int total;

void init();

int main(int argc, const char * argv[]) {
    init();
    return 0;
}

void init(){
    cin>>total;
    for(int i = 0 ; i < 9 ; i++){
        int price;
        cin>>price;
        total -= price;
    }
    cout<<total<<endl;
    
}
