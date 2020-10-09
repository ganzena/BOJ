//
//  main.cpp
//  [10814] 나이순 정렬
//
//  Created by YOO TAEWOOK on 2020/09/19.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Member{
    int seq;
    int age;
    string name;
};

vector<Member> v;
vector<Member>::iterator iter;

void init();
void solve();

int num;

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

bool compare(const Member& a, const Member& b){
    if(a.age == b.age){
        return a.seq < b.seq;
    }
    return a.age < b.age;
}

void solve(){
    sort(v.begin(), v.end(), compare);
    for(iter = v.begin() ; iter != v.end() ; iter++){
        cout<<iter->age<<" "<<iter->name<<"\n";
    }
}

void init(){
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>num;
    for(int i = 0 ; i < num ; i++){
        Member member;
        member.seq = i;
        cin>>member.age>>member.name;
        v.push_back(member);
    }
}
