//
//  main.cpp
//  ReverseString
//
//  Created by YOO TAEWOOK on 2018. 5. 14..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>

void ReversePrint(char*);

using namespace std;

int main(int argc, const char * argv[]) {
    char* test = "Reverse";
    ReversePrint(test);
    cout<<endl;
    return 0;
}

void ReversePrint(char* str){
    if(*str == '\0')
        return;
    ReversePrint(str + 1);
    cout<<*str;
}
