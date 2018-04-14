//
//  main.cpp
//  [14890] 경사로
//
//  Created by YOO TAEWOOK on 2018. 3. 23..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > map;
vector< vector<bool> > slope;
vector< vector<bool> > vSlope;
vector< vector<bool> > hSlope;
int size, length, counter = 0;
void Horizontal();
void Vertical();
int main(int argc, const char * argv[]) {
    
    cin>>size>>length;
    map.assign(size, vector<int>(size, 0));
    slope.assign(size, vector<bool>(size, false));
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            cin>>map[i][j];
        }
    }
    //경사로 중복 체크 해줘야함
    Horizontal();
    Vertical();
    
    cout<<counter<<endl;
    return 0;
    
}
void Vertical(){ //세로 검증
    vSlope = slope;
    for(int j = 0 ; j < size ; j++){
        bool pass = true;
        for(int i = 0 ; i < size - 1 ; i++){
            if(map[i][j] == map[i + 1][j]){
                continue;
            }else if(map[i][j] - map[i + 1][j] == 1){ //위쪽이 더 높음 아래쪽에 경사로를 놔야함 기준 i
                if(i + length < size){
                    for(int k = i + 1 ; k < i + length ; k++){
                        if(map[k][j] != map[k + 1][j]){ //경사로를 지을 땅들의 높낮이가 다르면 경사로 지을 수 없다
                            pass = false;
                            break;
                        }
                    }
                    if(pass){
                        for(int k = i + 1 ; k < i + length + 1; k++){
                            if(vSlope[k][j] == true){ //경사로 지을 수 없다
                                pass = false;
                                break;
                            }
                        }
                        if(pass){ // 경사로를 지을 수 있을 때 경사로를 짓는 곳을 true로 바꾼다.
                            for(int k = i + 1 ; k < i + length + 1; k++){
                                vSlope[k][j] = true;
                            }
                        }
                    }
                }else{ //경사로를 놓을 곳이 범위를 넘어버렸다
                    pass = false;
                    break;
                }
            }else if(map[i][j] - map[i + 1][j] == -1){ //아래쪽이 더 높음 위쪽에 경사로를 놔야함 기준 i + 1
                if(i + 1 - length >= 0){
                    for(int k = i ; k > i - length + 1; k--){
                        if(map[k][j] != map[k - 1][j]){
                            pass = false;
                            break;
                        }
                    }
                    if(pass){
                        for(int k = i ; k > i - length ; k--){
                            if(vSlope[k][j] == true){ //이미 경사로가 지어져있어 경사로 지을 수 없다
                                pass = false;
                                break;
                            }
                        }
                        if(pass){ // 경사로를 지을 수 있다면
                            for(int k = i ; k > i - length ; k--){
                                vSlope[k][j] = true; //경사로를 짓는다.
                            }
                        }
                    }
                }else{
                    pass = false;
                    break;
                }
            }else{
                pass = false;
                break;
            }
        }
        if(pass)
            counter++;
    }
}
void Horizontal(){
    hSlope = slope;
    for(int i = 0 ; i < size ; i++){
        bool pass = true;
        for(int j = 0 ; j < size - 1 ; j++){
            if(map[i][j] == map[i][j + 1]){
                continue;
            }else if(map[i][j] - map[i][j + 1] == 1){ //왼쪽이 더 높음 오른쪽에 경사로를 놔야함. 기준 j
                if(j + length < size){
                    for(int k = j + 1 ; k < j + length ; k++){
                        if(map[i][k] != map[i][k + 1]){ // 경사로를 놓을 곳의 높이가 다르면 통과 못한다
                            pass = false;
                            break;
                        }
                    }
                    
                    if(pass){ // 경사로를 놓을 곳의 높이가 같을 때
                        for(int k = j + 1 ; k < j + length + 1; k++){
                            if(hSlope[i][k] == true){ // 이미 경사로가 있다면 경사로를 놓을 수 없다.
                                pass = false;
                                break;
                            }
                        }
                        
                        if(pass){ // 경사로를 놓을수 있으면
                            for(int k = j + 1 ; k < j + length + 1; k++){ //경사로를 놓는다
                                    hSlope[i][k] = true;
                            }
                        }
                    }
                }else{
                    pass = false;
                    break;
                }
            }else if(map[i][j] - map[i][j + 1] == -1){ //오른쪽이 더 높음 왼쪽에 경사로를 놔야함 기준. j + 1
                if(j + 1 - length >= 0){
                    for(int k = j ; k > j - length + 1 ; k--){ //경사로를 놓을 곳의 높이가 다르면 경사로를 못 놓는다.
                        if(map[i][k] != map[i][k - 1]){
                            pass = false;
                            break;
                        }
                    }
                    
                    if(pass){ //
                        for(int k = j ; k > j - length; k--){
                            if(hSlope[i][k] == true){
                                pass = false;
                                break;
                            }
                        }
                        
                        if(pass){
                            for(int k = j ; k > j - length; k--)
                                hSlope[i][k] = true;
                        }
                    }
                }else{
                    pass = false;
                    break;
                }
            }else{
                pass = false;
                break;
            }
        }
        if(pass)
            counter++;
        
    }
}
