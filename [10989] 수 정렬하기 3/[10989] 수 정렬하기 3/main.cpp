//
//  main.cpp
//  [10989] 수 정렬하기 3
//
//  Created by YOO TAEWOOK on 2018. 5. 11..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int num;
void init();
void Print();
void CountingSort();
void BOJCountingSort();
void RadixSort();
int maxValue = 0;
int main(int argc, const char * argv[]) {
    
    //CountingSort();
    
    init();
    RadixSort();
    Print();
    
    return 0;
}

void init(){
    cin>>num;
    v.assign(num, 0);

    for(int i = 0 ; i < num ; i++){
        cin>>v[i];
        maxValue = max(maxValue, v[i]);
        
    }
}

void BOJCountingSort(){
    cin>>num;
    v.assign(10001, 0);
    int temp;
    for(int i = 0 ; i < num ; i++){
        cin>>temp;
        v[temp]++;
    }
    
    for(int i = 1 ; i <= 10000 ; i++){
        if(v[i] > 0){
            for(int j = 0 ; j < v[i] ; j++){
                printf("%d\n", i);
            }
        }
    }
}

void RadixSort(){
    int maxRadix = 1;
    while(maxRadix < maxValue){
        maxRadix *= 10;
    }
    vector<int> swapV;
    vector<int> tempV(num);
    
    for(int i = 1 ; i <= maxRadix ; i *= 10){ //1의 자리 10의 자리 순으로 계속 늘려나간다.
        vector<int> countV(10, 0); //매 자릿수마다 count를 새롭게 해야하기 때문에 for문안에 선언한다.
        //counting sort
        for(int j = 0 ; j < v.size() ; j++){ // 해당 자릿수에 있는 0 ~ 9까지의 숫자의 갯수기록
            countV[(v[j] / i) % 10]++;
        }
        
        for(int j = 1 ; j < 10 ; j++){ // 카운트 누적합
            countV[j] = countV[j] + countV[j - 1];
        }
        
        for(int j = (int)v.size() - 1 ; j >= 0 ; j--){
            // (v[j] / i) % 10 == 현재 자릿수에 있는 숫자, count[현재 자리숫에 있는 숫자] = 그 숫자가 위치해야할 index값
            // --를 한 이유 : 제대로 된 배치를 위해서 한 칸 앞에 배치해야함 그리고 해당 숫자를 한 번 썼으므로 count값을 줄여야함
            tempV[--countV[(v[j] / i) % 10]] = v[j];
        }
        v = tempV; //v를 현재 단계의 sorting이 완료된 tempV로 바꾼다.
        
    }
}

void CountingSort(){
    vector<int> countV(maxValue + 1, 0); //각 데이터가 몇 개 있는지 기록할 배열
    vector<int> sortedV(v.size()); //sorting한 데이터를 넣을 배열
    
    for(int i = 0 ; i < v.size() ; i++){ //각 요소가 몇 개 있나 기록
        countV[v[i]]++; //v[i]에 있는 값을 인덱스로하여 countV에서 counting함
    }
    
    for(int i = 1 ; i < countV.size() ; i++){
        countV[i] = countV[i] + countV[i - 1]; //count 벡터의 누적값 계산
    }
    
    for(int i = (int)v.size() - 1 ; i >= 0 ; i--){
        sortedV[--countV[v[i]]] = v[i];
    }
    
    v = sortedV;
}

void Print(){
    for(int i = 1 ; i < v.size() ; i++){
        cout<<v[i]<<endl;
    }
}
