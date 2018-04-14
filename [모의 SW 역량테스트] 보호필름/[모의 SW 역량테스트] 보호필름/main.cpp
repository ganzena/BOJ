//
//  main.cpp
//  [모의 SW 역량테스트] 보호필름
//
//  Created by YOO TAEWOOK on 2018. 4. 12..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define MAX_HEIGHT 13
#define MAX_WIDTH 20

using namespace std;

vector< vector<int> > film(MAX_HEIGHT, vector<int>(MAX_WIDTH));
vector< vector<int> > copyFilm(MAX_HEIGHT, vector<int>(MAX_WIDTH));
vector<int> permVector(MAX_HEIGHT, 0); // 몇 번째 행에 주사를 놓을 것인가?
vector<int> originVec(MAX_HEIGHT, 0); // 행 전체
vector<int> binaryPerm(MAX_HEIGHT, 0);

void init();
bool perm(int, int);
bool check();
void print();

int height, width, pass, minimum, limit = 2, minInject = 2;
int canOut = false;
int main(int argc, const char * argv[]) {
    int test, cnt = 1;
    cin>>test;
    while(cnt <= test){
        init();
        
        if(check()){
            printf("#%d %d\n", cnt, 0);
        }else{
            while(!perm(0, 0) && limit < minimum)
                limit++;
            printf("#%d %d\n", cnt, minimum);
            
        }
        cnt++;
    }
    return 0;
}

bool perm(int start, int depth){
    if(depth > limit)
        return false;
    
    if(depth == limit){ //permutation에서 몇 번째 행에 주사를 놓을지 정해짐
        for(int i = 1 ; i <= (int)pow(2, depth) ; i++){
            for(int j = 0 ; j < depth ; j++){ //각 행에 0을 넣을지 1을 넣을지 정하는 상황
                if(i % (int)pow(2, j) == 0){ // 이 때 바뀌어야한다
                    if(binaryPerm[j] == 0)
                        binaryPerm[j] = 1;
                    else
                        binaryPerm[j] = 0;
                }
            }
            
            for(int j = 0 ; j < depth ; j++){ //각 행마다 약품 주입.
                int drug = binaryPerm[j];
                int target = permVector[j];
                for(int k = 0 ; k < width ; k++){
                    film[target][k] = drug;
                }
                //cout<<target<<" ";
            }
            //            cout<<" = "<<limit<<endl;
            //            print();
            //            cout<<endl;
            
            if(check()){
                //print();
                minimum = min(minimum, limit);
                canOut = true;
                break;
            }else{
                film = copyFilm;
            }
        }
        
        binaryPerm.assign(MAX_HEIGHT, 0);
        //permVector.assign(MAX_HEIGHT, 0);
        
    }
    
    if(canOut)
        return true;
    
    for(int i = start ; i < height ; i++){
        permVector[depth] = originVec[i];
        perm(i + 1, depth + 1);
        if(canOut)
            return true;
    }
    
    return canOut;
}

bool check(){
    bool canPass = false;
    for(int j = 0 ; j < width ; j++){ //각 열을 이동하면서
        canPass = false;
        for(int i = 0 ; i < height - pass + 1; i++){ //
            int standard = film[i][j];
            for(int k = i ; k < pass + i ; k++){
                if(standard == film[k][j]){
                    canPass = true;
                }else{
                    canPass = false;
                    break;
                }
            }
            if(canPass == true)
                break;
        }
        if(canPass == false)
            break;
    }
    return canPass;
}

void init(){
    cin>>height>>width>>pass; // 두께, 너비, 합격 기준
    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){
            cin>>film[i][j];
        }
    }
    for(int i = 0 ; i < height ; i++){
        originVec[i] = i;
    }
    minimum = height + 1;
    copyFilm = film;
    limit = 2;
    canOut = false;
}

void print(){
    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){
            cout<<film[i][j]<<" ";
        }cout<<endl;
    }
}
