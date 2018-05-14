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

int solution(vector<int> &A);
int main(int argc, const char * argv[]) {
    
    
    return 0;
}

int solution(vector<int> &A){
    int maxInVec;
    sort(A.begin(), A.end());
    maxInVec = A[A.size() - 1];
    
    if(maxInVec <= 0)
        return 1;
    int i;
    int check = 1;
    for(i = 0 ; i < A.size() ; i++){
        if(A[i] > 0){
            if(A[i] > check)
                break;
            else if(check == A[i])
                check++;
        }
    }
    return check;
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


