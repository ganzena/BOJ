//
//  main.cpp
//  [모의 SW 역량테스트] 벌꿀채취
//
//  Created by YOO TAEWOOK on 2018. 4. 11..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
vector< vector<int> > house;
vector<piii> selectedHoney; //(i좌표, j좌표), 꿀
vector<piii> permuteHoney;
vector<piii> finalHoney;
int test, houseSize, selectNum, maxHoney, maxMoney = 0, firstMoney = 0;
void init();
void collect();
void print();
void doMath(int, int, int);
int main(int argc, const char * argv[]) {
    cin>>test;
    int cnt = 0;
    while(cnt < test){
        init();
        collect();
        //print();
        collect();
        //print();
        cnt++;
        printf("#%d %d\n", cnt, maxMoney);
    }
    return 0;
}
void collect(){
    //1번째 일꾼
    for(int i = 0 ; i < houseSize ; i++){
        for(int j = 0 ; j < houseSize - selectNum + 1 ; j++){
            for(int k = j ; k < selectNum + j ; k++){
                if(house[i][k] == 0)// 이미 꿀을 채취해간 경우
                    break;
                selectedHoney.push_back(piii(pii(i, k), house[i][k])); // 한 사람이 고를 수 있는 꿀 채취

            }
            if(selectedHoney.size() != selectNum){
                while(!selectedHoney.empty())
                    selectedHoney.pop_back();
                continue;
            }
            int cnt = 1;
            int temp = maxMoney;
            while(cnt <= selectNum){ //최대 수익을 내본다.
                doMath(0, 0, cnt);
                //permuteHoney.clear();
                cnt++;
            }
            if(temp != maxMoney){ //최대 수익이 바뀌었으면 선택된 꿀들로 업데이트해준다
                finalHoney = selectedHoney;
            }
            while(!selectedHoney.empty())
                selectedHoney.pop_back();
            
        }
    }
    
    while(!finalHoney.empty()){
        int i = finalHoney.back().first.first;
        int j = finalHoney.back().first.second;
        house[i][j] = 0;
        finalHoney.pop_back();
        
    }
    
    if(firstMoney == 0){
        firstMoney = maxMoney;
        maxMoney = 0;
    }else{
        maxMoney += firstMoney;
    }
    
}

void doMath(int start, int depth, int limit){
    if(depth == limit){
        int temp = 0;
        int sum = 0;
        for(int i = 0 ; i < limit ; i++){
            sum += permuteHoney[i].second;
        }
        if(sum > maxHoney)
            return;
        
        for(int i = 0 ; i < limit ; i++){
            temp += permuteHoney[i].second * permuteHoney[i].second;
        }
        maxMoney = max(temp, maxMoney);
        return;
    }
    for(int i = start ; i < selectNum ; i++){
        permuteHoney[depth] = selectedHoney[i];
        doMath(i + 1, depth + 1, limit);
    }
}
void init(){
    cin>>houseSize>>selectNum>>maxHoney; //벌통 전체 사이즈 / 한 사람당 고를 수 있는 벌통 갯수 / 최대 꿀 채취량
    house.assign(houseSize, vector<int>(houseSize));
    for(int i = 0 ; i < houseSize ; i++){
        for(int j = 0 ; j < houseSize ; j++){
            cin>>house[i][j];
        }
    }
    while(!selectedHoney.empty())
        selectedHoney.pop_back();
    permuteHoney.assign(selectNum, piii(pii(0, 0), 0));
    maxMoney = 0;
    firstMoney = 0;
}

void print(){
    cout<<endl;
    for(int i = 0 ; i < houseSize ; i++){
        for(int j = 0 ; j < houseSize ; j++){
            cout<<house[i][j]<<" ";
        }cout<<endl;
    }
}
