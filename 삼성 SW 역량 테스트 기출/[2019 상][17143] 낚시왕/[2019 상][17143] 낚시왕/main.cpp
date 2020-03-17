//
//  main.cpp
//  [2019 상][17143] 낚시왕
//
//  Created by YOO TAEWOOK on 2020/03/07.
//  Copyright © 2020 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Shark{
    int r,c; //상어의 위치
    int s; //속력
    int d; //이동방향
    int z; //크기
    int no; //상어번호
};

vector<vector<Shark> > map, initMap; //로직에 쓸 맵과 초기화 할 맵
vector<pair<int, int> > dir; //1 위 2 아래 3 오른쪽 4 왼쪽
queue<Shark> q; //상어가 들어가는 큐
vector<bool> erase; //상어에 번호를 남겨서 죽었는지 살았는지 체크

int fisherMan = 0; //낚시꾼의 초기 위치
int ans = 0; //상어 사이즈의 합
int R, C, M;

void init();
void solve();
void print();
int changeDir(int);

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}

int changeDir(int dir){
    if(dir == 1)
        return 2;
    if(dir == 2)
        return 1;
    if(dir == 3)
        return 4;
    if(dir == 4)
        return 3;
    return 0;
}

void solve(){
    if(M == 0){ //초기에 상어가 한 마리도 없으면
        cout<<0<<endl; //0을 출력
        return;
    }
    //print();
    while(++fisherMan <= C){
        //cout<<fisherMan<<"초"<<endl;
        
        //낚시 시작 (방향은 2 아래)
        pair<int, int> fishing = make_pair(1, fisherMan);
        while(map[fishing.first][fishing.second].z == 0){ // 상어 번호(no>0)을 발견하면 멈춤
            fishing = make_pair(fishing.first + dir.at(2).first, fishing.second + dir.at(2).second);
            if(fishing.first > R || fishing.first < 1 || fishing.second > C || fishing.second < 1){ //해당 열에 상어 없음
                fishing = make_pair(fishing.first - dir.at(2).first, fishing.second - dir.at(2).second);
                break;
            }
        }
        int target = map[fishing.first][fishing.second].no;
        if(target != 0){ //상어를 발견
            ans += map[fishing.first][fishing.second].z; //상어 잡고(사이즈 더하기)
            erase.at(map[fishing.first][fishing.second].no) = true; //생존벡터의 죽은 상어의 인덱스를 true로 업데이트
            //cout<<target<<" 상어는 잡혀갔다"<<endl;
        }
        
        map = initMap; //아무것도 없는 새로운 맵으로 초기화
        //상어 이동
        int qSize = (int)q.size();
        for(int i = 0 ; i < qSize ; i++){
       
            Shark now = q.front();
            q.pop();
            if(erase.at(now.no)){ //만약에 죽은 상어라면 pop만하고 다시 처음으로 돌아간다
                //cout<<now.no<<" 상어는 죽었다"<<endl;
                continue;
            }
            
            int r = now.r;
            int c = now.c;
            int d = now.d;
            int cnt = now.s;
            if(d == 1 || d == 2){ // 다시 제자리에 돌아오는데 (R-1)*2 혹은 (C-1)*2 만큼 이동하므로 속도를 이로 나누어 나머지를 속도로 갱신
                cnt = cnt % ((R-1)*2);
            }else{
                cnt = cnt % ((C-1)*2);
            }
            while(cnt-- > 0){ //그 후 맵의 끝에 가면 방향을 바꿔 움직여줌
                r += dir.at(d).first;
                c += dir.at(d).second;
                if(r < 1 || c < 1 || r > R || c > C){ //벽에 닿았으면 방향을 바꾼다.
                    r -= dir.at(d).first;
                    c -= dir.at(d).second;
                    d = changeDir(d);
                    cnt++;
                }
            }
            //상어 정보 업데이트 (이동이 끝난 상어)
            now.r = r;
            now.c = c;
            now.d = d;
            
            if(map[r][c].no != 0){ //방문 된 위치로 이동했을 경우
                Shark origin = map[r][c];
                if(origin.z < now.z){//현재 상어가 더 크면
                    erase.at(origin.no) = true; //기존 상어 삭제
                    map[r][c] = now; //현재 상어가 자리 차지
                    q.push(now); //상어 큐에 삽입
                }else{
                    erase.at(now.no) = true; //현재 상어 삭제
                }
            }else{ //방문 된 위치가 아닐 경우
                map[r][c] = now;
                q.push(now);
            }
        }
        //print();
    }
    cout<<ans<<endl;
}

void print(){
    for(int i = 1 ; i < R ; i++){
        for(int j = 1 ; j <C ; j++){
            cout<<"("<<map[i][j].no<<",";
            int dir = map[i][j].d;
            if(dir == 1){
                cout<<"위)";
            }else if(dir == 2){
                cout<<"아래)";
            }else if(dir == 3){
                cout<<"오)";
            }else if(dir == 4){
                cout<<"왼)";
            }else if(dir == 0){
                cout<<"0)";
            }
            cout<<"\t";
        }cout<<endl;
    }cout<<endl;
}

void init(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin>>R>>C>>M;
    initMap.assign(R+1, vector<Shark>(C+1, {0,0,0,0,0}));
    map = initMap;
    //initVisit.assign(R, vector<bool>(C, false));
    
    
    for(int i = 1 ; i <= M ; i++){ //상어 마릿수만큼
        int r,c,s,d,z;
        cin>>r>>c>>s>>d>>z;
        map[r][c] = {r,c,s,d,z,i}; //맵에 업데이트
        q.push({r,c,s,d,z,i}); //상어 큐에 넣고
    }
    
    erase.assign(M + 1, false); //초기 상어들은 살아있음
    dir.push_back(make_pair(0, 0));
    dir.push_back(make_pair(-1, 0)); //위 1
    dir.push_back(make_pair(1, 0)); //아래 2
    dir.push_back(make_pair(0, 1)); //오른쪽 3
    dir.push_back(make_pair(0, -1)); //왼쪽 4
}
