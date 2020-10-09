//
//  main.cpp
//  [2217] 로프
//
//  Created by YOO TAEWOOK on 2020/09/22.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int ropeNum;
void init();
void solve();

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

void solve(){
    int max = 0;
    // 가장 작은 것부터 시작하여
    for(int i = 0 ; i < ropeNum ; i++){
        // (가장 작은 가용 중량) * (선택 가능한 최대 로프수) 로 max값 갱신
        // 작은 것부터 하나씩 선택에서 제외해본다
        if(max < v[i] * (ropeNum - i))
            max = v[i] * (ropeNum - i);
    }
    cout<<max<<endl;
}

void init(){
    //freopen("input.txt", "r", stdin);
    cin>>ropeNum;
    v.assign(ropeNum, 0);
    for(int i = 0 ; i < ropeNum ; i++){
        cin>>v[i];
    }
    // 가장 작은 무게를 견딜 수 있는 로프부터 오름차순 정렬
    sort(v.begin(), v.end());
    
}
