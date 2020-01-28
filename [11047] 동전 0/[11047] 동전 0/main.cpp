//
//  main.cpp
//  [11047] 동전 0
//
//  Created by YOO TAEWOOK on 22/01/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, target, cnt = 0;
vector< int > coins;

void init ();
void solve ();
int main(){
    init ();
    solve ();
    
    return 0;
}

void solve (){
    for (int i = n - 1; i >= 0; i--){
        cnt += target / coins.at (i);
        target %= coins.at (i);
    }
    
    cout << cnt << endl;
}
void init (){
    //freopen ("input.txt", "r", stdin);
    cin >> n >> target;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        coins.push_back (tmp);
    }
}

