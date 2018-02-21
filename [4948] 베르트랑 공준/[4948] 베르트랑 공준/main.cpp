//
//  main.cpp
//  [4948] 베르트랑 공준
//
//  Created by YOO TAEWOOK on 2018. 2. 18..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int start, end, counter;
    vector<bool> vector;
    
    while(1){
        counter = 0;
        cin>>start;
        if(start == 0)
            break;
        end = start * 2;
        
        for(int i = 0 ; i <= end ; i++){
            if(i == 0 || i == 1) // input이 1이나 0이 들어올 것을 대비하여 이는 미리 false로 설정한다.
                vector.push_back(false);
            else
                vector.push_back(true);
        }
        
        for(int i = 2 ; i < vector.size() ; i++){
            if(vector.at(i)){
                for(int j = 2*i ; j < vector.size() ; j += i){ //에라토스체네스의 체는 만나는 수의 배수값들을 모두 지우는 것
                    vector.at(j) = false;
                }
            }
        }
        
        for(int i = start+1 ; i < vector.size() ; i++)
            if(vector.at(i) == true)
                counter++;
        
        cout<<counter<<endl;
        vector.erase(vector.begin(), vector.end());
    }
    return 0;
}
