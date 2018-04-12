//
//  main.cpp
//  [14501] 퇴사
//
//  Created by YOO TAEWOOK on 2018. 4. 10..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef pair<int, int> pii;
vector<pii> schedule;
vector<pii> selected;
vector<int> DP;

void run();
int day, Time, Price, maximum = 0;
bool visit = false;
int main(int argc, const char * argv[]) {
    cin>>day;
    day++;
    schedule.assign(day, pii(0,0));
    DP.assign(day, 0);
    for(int i = 1 ; i < day ; i++){
        cin>>Time>>Price;
        schedule[i].first = Time;
        schedule[i].second = Price;
        //DP[i] = Price;
    }
    
    run();

    cout<<maximum<<endl;
    return 0;
}
void run(){
    for(int i = 1 ; i < day ; i++){

    }
    
    for(int i = 1 ; i < day ; i++){
       maximum = max(maximum, DP[i]);
    }
}


