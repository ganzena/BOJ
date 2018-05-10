//
//  main.cpp
//  [2740] 행렬 곱셈
//
//  Created by YOO TAEWOOK on 2018. 5. 9..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > matrix;
vector< vector<int> > matrix1;
vector< vector<int> > result;
int row, col, row1, col1;
int main(int argc, const char * argv[]) {
    cin>>row>>col;
    matrix.assign(row, vector<int>(col));
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cin>>matrix[i][j];
        }
    }
    
    cin>>row1>>col1;
    matrix1.assign(row1, vector<int>(col1));
    for(int i = 0 ; i < row1 ; i++){
        for(int j = 0 ; j < col1 ; j++){
            cin>>matrix1[i][j];
        }
    }
    result.assign(row, vector<int>(col1));
    for(int i = 0 ; i < row ; i++){
       
        for(int j = 0 ; j < col1 ; j++){
            int temp = 0;
            for(int k = 0 ; k < col ; k++){
                temp += matrix[i][k] * matrix1[k][j];
            }
            result[i][j] = temp;
        }
        
    }
    
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col1 ; j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
