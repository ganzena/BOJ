//
//  main.cpp
//  [1057] 토너먼트
//
//  Created by YOO TAEWOOK on 2018. 4. 9..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>

using namespace std;

int num, jimin, hansoo, counter = 1;

int main(int argc, const char * argv[]) {
    cin>>num>>jimin>>hansoo;
    while(num != 1){
        if((jimin + hansoo)%4 == 3 && (jimin - hansoo == 1 || jimin - hansoo == -1)){ //만나는 경우
            break;
        }
        if(jimin % 2 == 0)//짝수
            jimin = jimin / 2;
        else
            jimin = jimin / 2 + 1;
        if(hansoo % 2 == 0)
            hansoo = hansoo / 2;
        else
            hansoo = hansoo / 2 + 1;
        if(num % 2 == 0)
            num /= 2;
        else
            num = num / 2 + 1;
        counter++;
    }
    if(num == 1)
        cout<<-1<<endl;
    else
        cout<<counter<<endl;
    return 0;
}
