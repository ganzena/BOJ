//
//  main.cpp
//  [2738] 행렬 덧셈
//
//  Created by YOO TAEWOOK on 2018. 5. 9..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > matrix;

int row, col;
int main(int argc, const char * argv[]) {
    cin>>row>>col;
    matrix.assign(row, vector<int>(col));
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cin>>matrix[i][j];
        }
    }
    int temp;
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cin>>temp;
            matrix[i][j] += temp;
        }
    }
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
