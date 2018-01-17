//
//  main.cpp
//  [2490] 윷놀이
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int input;
    int back = 0; //등(1)
    
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            cin>>input;
            if(input){
                back++;
            }
        }
        
        switch(back){
            case 0:
                cout<<"D"<<endl;
                break;
            case 1:
                cout<<"C"<<endl;
                break;
            case 2:
                cout<<"B"<<endl;
                break;
            case 3:
                cout<<"A"<<endl;
                break;
            case 4:
                cout<<"E"<<endl;
                break;
        }
        back = 0;
    }
}

