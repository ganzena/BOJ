//
//  main.cpp
//  [Codility] MissingInteger
//
//  Created by YOO TAEWOOK on 2018. 5. 13..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int PlusSolution(vector<int> &);
int MinusSolution(vector<int> &);
void QuickSort(vector<int> &, int, int);

int main(int argc, const char * argv[]) {
    vector<int> A = {-1, -2, -3, 0, 3, 5, -4, 9};
    cout<<"배열에 없는 가장 작은 양의 정수 : "<<PlusSolution(A)<<endl;
    cout<<"배열에 없는 가장 큰 음의 정수 : "<<MinusSolution(A)<<endl;

    return 0;
}

int PlusSolution(vector<int> &A){
    QuickSort(A, 0, (int)A.size() - 1);
    if(A[A.size() - 1] <= 0)
        return 1;
    int check = 1;
    for(int i = 0 ; i < A.size() ; i++){
        if(A[i] > 0){
            if(A[i] > check)
                break;
            else if(A[i] == check)
                check++;
        }
    }
    return check;
}

int MinusSolution(vector<int> &A){
    QuickSort(A, 0, (int)A.size() - 1);
    if(A[0] >= 0) // 배열의 가장 작은 수가 양수면 가장 큰 음수는 -1
        return -1;
    int check = -1; // 가장 큰 음수부터 시작
    for(int i = (int)A.size() - 1 ; i >= 0 ; i--){
        if(A[i] < 0){ //음수일 때만 실행
            if(A[i] < check)
                break;
            else if(A[i] == check)
                check--;
        }
    }
    return check;
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

//int solution(vector<int> &A){
//    int maxInVec = A[0];
//    //    sort(A.begin(), A.end());
//    //    maxInVec = A[A.size() - 1];
//
//    for(int i = 0 ; i < A.size() ; i++){
//        maxInVec = max(A[i], maxInVec);
//    }
//
//    if(maxInVec <= 0)
//        return 1;
//
//    vector<bool> checkVec(maxInVec + 1);
//
//    for(int i = 0 ; i < A.size() ; i++){
//        if(A[i] > 0)
//            checkVec[A[i]] = true;
//    }
//
//    int i;
//    for(i = 1 ; i < checkVec.size() ; i++){
//        if(checkVec[i] == false)
//            break;
//    }
//
//    return i;
//}


