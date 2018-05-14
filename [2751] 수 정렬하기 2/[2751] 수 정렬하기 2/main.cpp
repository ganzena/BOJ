//
//  main.cpp
//  [2751] 수 정렬하기 2
//
//  Created by YOO TAEWOOK on 2018. 5. 14..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void HeapSort();
void HeapInit();
void BuildHeap();
void MaxHeapify(int, int);
void HeapPrint();
void Swap(vector<int>&, int, int);

void MergeSort();
vector<int> v;
int test;

int main(int argc, const char * argv[]) {
    HeapInit();
    HeapSort();
    HeapPrint();
    return 0;
}

void HeapPrint(){
    for(int i = 1 ; i < v.size() ; i++)
        //cout<<v[i]<<endl;
        printf("%d\n", v[i]);
    //cout<<endl;
}

void HeapInit(){
    cin>>test;
    v.assign(test + 1, 0);
    for(int i = 1 ; i < v.size() ; i++){ //인덱스로 부모와 자식을 찾기 위해서 1부터 값을 저장한다.
        cin>>v[i];
    }
}
void HeapSort(){
    BuildHeap();
    
    for(int i = (int)v.size() - 1 ; i > 0 ; i--){
        Swap(v, 1, i);
        MaxHeapify(1, i);
    }
}

void BuildHeap(){ // 자식이 있는 가장 밑의 노드부터 차례대로 Heapify한다
    for(int i = ((int)v.size() - 1)/2 ; i > 0 ; i--){
        MaxHeapify(i, (int)v.size());
    }
}

void MaxHeapify(int root, int size){ //root > left child, right child 로 만드는 함수
    int Lchild = root * 2;
    int Rchild = root * 2 + 1;
    int largest = root; // root left right 셋 중 가장 큰 것 저장
    
    if(Lchild < size && v[Lchild] > v[largest]){
        largest = Lchild;
    }
    if(Rchild < size && v[Rchild] > v[largest]){
        largest = Rchild;
    }
    if(largest != root){ //root가 제일 큰 값이 아닐 경우 바꿔야함
        Swap(v, largest, root);
        MaxHeapify(largest, size); //largest에는 원래 root와 바뀐 자식의 index가 들어간다.
    }
}

void Swap(vector<int> &v, int a, int b){
    int temp;
    temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}
