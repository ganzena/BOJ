//
//  main.cpp
//  [1929] 소수 구하기
//
//  Created by YOO TAEWOOK on 2018. 2. 18..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

// 에라토스테네스의 체
// 주어진 자연수 N이 소수이기 위한 필요 충분조건은 N이 N의 제곱근보다 크지 않은 어떤 소수로도 나눠지지 않는다.
// 수가 수를 나누면 몫이 발생하게 되는데 몫과 나누는 수, 둘 중 하나는 반드시 제곱근N 이하이기 때문이다.


#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int start, end;
    vector<bool> vector;
    cin>>start>>end;
    
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
    
    for(int i = start ; i < vector.size() ; i++)
        if(vector.at(i) == true)
            printf("%d\n", i); // endl은 강제로 flush하는 연산으로써 시간초과가 날 경우 printf로 바꿔주는 것이 좋다.
    return 0;
}
