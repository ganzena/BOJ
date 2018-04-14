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

#define MAX 21
using namespace std;

typedef pair<int, int> pii;
vector<pii> schedule;
vector<pii> selected;
vector<int> DP(MAX, 0);

void run();
int day, Time, Price, maximum = 0;
bool visit = false;
int main(int argc, const char * argv[]) {
    cin>>day;
    day++;
    schedule.assign(day, pii(0,0));
    
    for(int i = 1 ; i < day ; i++){
        cin>>Time>>Price;
        schedule[i].first = Time;
        schedule[i].second = Price;
    }
    run();
    cout<<maximum<<endl;
    return 0;
}
void run(){
    for(int i = 1 ; i < day ; i++){
        if(DP[i] == 0)
            DP[i] = DP[i - 1];
        int complete = i + schedule[i].first - 1;
        DP[complete] = max(DP[i - 1] + schedule[i].second, DP[complete]);
    }
    
    for(int i = 1 ; i < day ; i++){
       maximum = max(maximum, DP[i]);
    }
}


