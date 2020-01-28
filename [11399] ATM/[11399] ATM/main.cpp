//
//  main.cpp
//  [11399] ATM
//
//  Created by YOO TAEWOOK on 20/01/2020.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> list;

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
    sort(list.begin(), list.end());
    int total = 0;
    for (int i = 0; i < list.size(); i++){
        for (int j = 0; j <= i; j++){
            total += list.at(j);
        }
    }
    cout << total << endl;
    return 0;
}
