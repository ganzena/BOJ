//
//  main.cpp
//  [5585] 거스름돈
//
//  Created by YOO TAEWOOK on 20/01/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> list;

int n;
int cnt = 0;
int main(){
    //freopen("input.txt", "r", stdin);
    cin >> n;
    n = 1000 - n;
    int array[] = { 500, 100, 50, 10, 5, 1 };
    for (int i = 0; i < 6; i++){
        cnt += n / array[i];
        n %= array[i];
    }
    
    
    cout << cnt << endl;
    return 0;
}
