//
//  main.cpp
//  [2458] 키 순서
//
//  Created by YOO TAEWOOK on 2020/09/22.
//

#include <iostream>
#include <vector>

using namespace std;


int studentNum, compareNum;

vector<int> v [501];

void init();
void solve();

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

void init(){
    freopen("input.txt", "r", stdin);
    cin>>studentNum>>compareNum;
    for(int i = 0 ; i < compareNum; i++){
        int small, big;
        cin>>small>>big;
        v[small].push_back(big);
    }
}
