//
//  main.cpp
//  [1927] 최소 힙
//
//  Created by YOO TAEWOOK on 2020/09/25.
//

#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"

using namespace std;

class Compare{
public:
    bool operator()(const int& a, const int& b) const{
        return a > b;
    }
};

bool compare(int& a, int& b){
    return a > b;
}
priority_queue<int, vector<int>, Compare> pq;

int tcNum, printNum;

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>tcNum;
    for(int i = 0 ; i < tcNum ; i++){
        int temp;
        cin>>temp;
        if(temp == 0){
            if(pq.empty()){
                cout<<0<<endl;
            }else{
                cout<<pq.top()<<endl;
                pq.pop();
            }
        }else{
            pq.push(temp);
        }
    }
    return 0;
}
