//
//  main.cpp
//  [5373] 큐빙
//
//  Created by YOO TAEWOOK on 31/03/2019.
//  Copyright © 2019 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct Command {
    char dir;
    char clock;
};

vector<vector<char>> u; //위
vector<vector<char>> d; //아래
vector<vector<char>> f; //앞
vector<vector<char>> b; //뒤
vector<vector<char>> l; //왼쪽
vector<vector<char>> r; //오른쪽
vector<vector<pair<char, char>>> command;

int T, N, counter = 0;

void paint();
void init();
void print();
void erase();
void action(int);
void rotate(char, char);
void rotateClock(vector<vector<char>>&);
void rotateUnClock(vector<vector<char>>&);

int main(int argc, const char * argv[]) {
    cin>>T;
    init();
    while(counter != T){
        paint();
        action(counter);
        print();
        //erase();
        counter++;
    }
    
    return 0;
}

void rotateClock(vector<vector<char>>& v){
    char c1 = v[0][0];
    char c2 = v[1][0];
    
    v[0][0] = v[2][0];
    v[1][0] = v[2][1];
    v[2][0] = v[2][2];
    v[2][1] = v[1][2];
    v[2][2] = v[0][2];
    v[1][2] = v[0][1];
    v[0][2] = c1; //v[0][0]
    v[0][1] = c2; //v[1][0]
}

void rotateUnClock(vector<vector<char>>& v){
    char c1 = v[0][0];
    char c2 = v[0][1];
    
    v[0][0] = v[0][2];
    v[0][1] = v[1][2];
    v[0][2] = v[2][2];
    v[1][2] = v[2][1];
    v[2][2] = v[2][0];
    v[2][1] = v[1][0];
    v[2][0] = c1; //v[0][0]
    v[1][0] = c2; //v[0][1]
}


void rotate(char side, char dir){
    char t1, t2, t3;
    if(side == 'U'){
        t1 = l[0][0];
        t2 = l[0][1];
        t3 = l[0][2];
        if(dir == '+'){ //check
            l[0][0] = f[0][0];
            l[0][1] = f[0][1];
            l[0][2] = f[0][2];
            
            f[0][0] = r[0][0];
            f[0][1] = r[0][1];
            f[0][2] = r[0][2];
            
            r[0][0] = b[0][0];
            r[0][1] = b[0][1];
            r[0][2] = b[0][2];
            
            b[0][0] = t1;
            b[0][1] = t2;
            b[0][2] = t3;
            rotateClock(u);
        }else{ //check
            l[0][0] = b[0][0];
            l[0][1] = b[0][1];
            l[0][2] = b[0][2];
            
            b[0][0] = r[0][0];
            b[0][1] = r[0][1];
            b[0][2] = r[0][2];
            
            r[0][0] = f[0][0];
            r[0][1] = f[0][1];
            r[0][2] = f[0][2];
            
            f[0][0] = t1;
            f[0][1] = t2;
            f[0][2] = t3;
            rotateUnClock(u);
        }
    } else if(side == 'D'){
        t1 = l[2][0];
        t2 = l[2][1];
        t3 = l[2][2];
        if(dir == '+'){ //check
            l[2][0] = b[2][0];
            l[2][1] = b[2][1];
            l[2][2] = b[2][2];
            
            b[2][0] = r[2][0];
            b[2][1] = r[2][1];
            b[2][2] = r[2][2];
            
            r[2][0] = f[2][0];
            r[2][1] = f[2][1];
            r[2][2] = f[2][2];
            
            f[2][0] = t1;
            f[2][1] = t2;
            f[2][2] = t3;
            rotateUnClock(d); //d는 꺼꾸로 생각했어서 반대로
        }else{ //check
            l[2][0] = f[2][0];
            l[2][1] = f[2][1];
            l[2][2] = f[2][2];
            
            f[2][0] = r[2][0];
            f[2][1] = r[2][1];
            f[2][2] = r[2][2];
            
            r[2][0] = b[2][0];
            r[2][1] = b[2][1];
            r[2][2] = b[2][2];
            
            b[2][0] = t1;
            b[2][1] = t2;
            b[2][2] = t3;
            
            rotateClock(d); //d는 꺼꾸로 생각했어서 반대로
        }
    } else if(side == 'F'){
        t1 = l[0][2];
        t2 = l[1][2];
        t3 = l[2][2];
        if(dir == '+'){// check
            l[0][2] = d[2][0];
            l[1][2] = d[2][1];
            l[2][2] = d[2][2];
            
            d[2][0] = r[2][0];
            d[2][1] = r[1][0];
            d[2][2] = r[0][0];
            
            r[2][0] = u[2][2];
            r[1][0] = u[2][1];
            r[0][0] = u[2][0];
            
            u[2][2] = t1;
            u[2][1] = t2;
            u[2][0] = t3;
            
            rotateClock(f);
        }else{ //check
            l[0][2] = u[2][2];
            l[1][2] = u[2][1];
            l[2][2] = u[2][0];
            
            u[2][2] = r[2][0];
            u[2][1] = r[1][0];
            u[2][0] = r[0][0];

            r[2][0] = d[2][0];
            r[1][0] = d[2][1];
            r[0][0] = d[2][2];

            d[2][0] = t1;
            d[2][1] = t2;
            d[2][2] = t3;

            
            rotateUnClock(f);
        }
    } else if(side == 'B'){
        t1 = l[0][0];
        t2 = l[1][0];
        t3 = l[2][0];
        if(dir == '+'){
            l[0][0] = u[0][2];
            l[1][0] = u[0][1];
            l[2][0] = u[0][0];
            
            u[0][2] = r[2][2];
            u[0][1] = r[1][2];
            u[0][0] = r[0][2];
            
            r[2][2] = d[0][0];
            r[1][2] = d[0][1];
            r[0][2] = d[0][2];
            
            d[0][0] = t1; //00
            d[0][1] = t2; //10
            d[0][2] = t3; //20
            rotateClock(b);
        }else{
            l[0][0] = d[0][0];
            l[1][0] = d[0][1];
            l[2][0] = d[0][2];
            
            d[0][0] = r[2][2];
            d[0][1] = r[1][2];
            d[0][2] = r[0][2];
            
            r[2][2] = u[0][2];
            r[1][2] = u[0][1];
            r[0][2] = u[0][0];
            
            u[0][2] = t1;
            u[0][1] = t2;
            u[0][0] = t3;
            
            rotateUnClock(b);
        }
    } else if(side == 'L'){
        t1 = u[0][0];
        t2 = u[1][0];
        t3 = u[2][0];
        if(dir == '+'){
            u[0][0] = b[2][2];
            u[1][0] = b[1][2];
            u[2][0] = b[0][2];
            
            b[2][2] = d[2][0];
            b[1][2] = d[1][0];
            b[0][2] = d[0][0];
            
            d[2][0] = f[0][0];
            d[1][0] = f[1][0];
            d[0][0] = f[2][0];
            
            f[0][0] = t1;
            f[1][0] = t2;
            f[2][0] = t3;
            rotateClock(l);
        }else{
            u[0][0] = f[0][0];
            u[1][0] = f[1][0];
            u[2][0] = f[2][0];
            
            f[0][0] = d[2][0];
            f[1][0] = d[1][0];
            f[2][0] = d[0][0];
            
            d[2][0] = b[2][2];
            d[1][0] = b[1][2];
            d[0][0] = b[0][2];
            
            b[2][2] = t1;
            b[1][2] = t2;
            b[0][2] = t3;
            rotateUnClock(l);
        }
    } else if(side == 'R'){
        t1 = u[0][2];
        t2 = u[1][2];
        t3 = u[2][2];
        if(dir == '+'){
            u[0][2] = f[0][2];
            u[1][2] = f[1][2];
            u[2][2] = f[2][2];
            
            f[0][2] = d[2][2];
            f[1][2] = d[1][2];
            f[2][2] = d[0][2];
            
            d[2][2] = b[2][0];
            d[1][2] = b[1][0];
            d[0][2] = b[0][0];
            
            b[2][0] = t1; //22
            b[1][0] = t2; //12
            b[0][0] = t3; //00
            rotateClock(r);
        }else{
            u[0][2] = b[2][0];
            u[1][2] = b[1][0];
            u[2][2] = b[0][0];
            
            b[0][0] = d[0][2];
            b[1][0] = d[1][2];
            b[2][0] = d[2][2];
            
            d[0][2] = f[2][2];
            d[1][2] = f[1][2];
            d[2][2] = f[0][2];
            
            f[2][2] = t3; //22
            f[1][2] = t2; //12
            f[0][2] = t1; //02
            rotateUnClock(r);
        }
    }
}

void action(int counter){
    for(int i = 0 ; i < command[counter].size() ; i++){
        char side, dir;
        side = command[counter][i].first;
        dir = command[counter][i].second;
        rotate(side, dir);
    }
}

void print(){
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cout<<u[i][j];
        }cout<<endl;
    }
}
//
//void erase(){
//    command.clear();
//}

void paint(){
    u.assign(3, vector<char>(3,'w'));
    d.assign(3, vector<char>(3,'y'));
    f.assign(3, vector<char>(3,'r'));
    b.assign(3, vector<char>(3,'o'));
    l.assign(3, vector<char>(3,'g'));
    r.assign(3, vector<char>(3,'b'));
}

void init(){
    int count = T;
    while(count != 0){
        int num = 0;
        cin>>num;
        vector<pair<char, char>> tmp;
        for(int i = 0 ; i < num ; i++){
            char side, dir;
            cin>>side>>dir;
            tmp.push_back(make_pair(side, dir));
        }
        command.push_back(tmp);
        count--;
    }
    
}
