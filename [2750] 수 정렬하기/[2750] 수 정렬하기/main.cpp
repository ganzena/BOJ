//
//  main.cpp
//  [2750] 수 정렬하기
//
//  Created by YOO TAEWOOK on 2018. 1. 20..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int test;

void BubbleSort();
void SelectionSort();
void InsertionSort();

void MergeSort(vector<int> &, int, int);
void QuickSort(vector<int> &, int, int);
void HeapSort();

void RadixSort();

void Print();
int main(int argc, const char * argv[]) {

    cin>>test;
    
    for(int i = 0 ; i < test ; i++){
        int input;
        cin>>input;
        v.push_back(input);
    }
    
    //BubbleSort();
    //SelectionSort();
    //InsertionSort();
    QuickSort(v, 0, test - 1);
    for(int i = 0 ; i < test ; i++){
        cout<<v[i]<<endl;
    }
    
    return 0;
}

void QuickSort(vector<int>& v, int left, int right){
    int i = left, j = right;
    int pivot = v[(left + right) / 2]; //pivot은 중간값 (value < pivot) pivot (value > pivot) 
    int temp;
    while(i < j){
        while(v[i] < pivot) //v[i]가 pivot보다 작지 않을 때까지 반복
            i++;
        while(v[j] > pivot) //v[j]가 pivot보다 크지 않을 때까지 반복
            j--;
  
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        
    }
    
    if(left < j)
        QuickSort(v, left, j - 1);
    if(i < right)
        QuickSort(v, i + 1, right);
}

void InsertionSort(){
    for(int i = 1; i < test ; i++){ //i 이하의 인덱스들은 정렬이 되어있다는 것으로 가정한다.
        int temp = v[i]; // 정렬할 값을 따로 빼놓고
        int j; //j를 밖에 선언
        for(j = i - 1 ; j >= 0 && v[j] > temp ; j--){ //j가 배열의 범위 안에 그리고 v[j]가 temp보다 큰 동안
            v[j + 1] = v[j]; //한칸씩 뒤로 땡긴다.
        }
        v[j + 1] = temp; //for문을 나온 것은 v[j] < temp이므로 v[j+1] 에 temp가 들어가야한다.
        //Print();
    }
}

void BubbleSort(){
    int temp;
    for(int i = 0 ; i < test ; i++){
        for(int j = 0 ; j < test - (i + 1) ; j++){
            if(v[j + 1] < v[j]){
                temp = v[j + 1];
                v[j + 1] = v[j];
                v[j] = temp;
            }
        }
        //Print();
    }
}

void SelectionSort(){
    int indexMin, temp;
    for(int i = 0 ; i < test - 1 ; i++){ // 0번째 인덱스부터 순차적으로 정렬
        indexMin = i; // 최솟값의 인덱스를 저장할 변수
        for(int j = i + 1; j < test ; j++){
            if(v[j] < v[indexMin]){
                indexMin = j; //최솟값이 위치한 인덱스로 업데이트함
            }
        }
        //바꿈
        temp = v[i];
        v[i] = v[indexMin];
        v[indexMin] = temp;
        //Print();
    }
}

void Print(){
    for(int i = 0 ; i < test ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
