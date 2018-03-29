//
//  main.cpp
//  [14889] 스타트와 링크
//
//  Created by YOO TAEWOOK on 2018. 3. 15..
//  Copyright © 2018년 Yoo TaeWook. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int lineNum;
int minimum = 10000000;
int teamNum;

vector< vector<int> > startLink;
vector<int> startTeam;

void makeTeam(int, int);
vector<int> teamVector;
int main(int argc, const char * argv[]) {
    cin>>lineNum;
    teamNum = lineNum / 2; // 각 팀의 인원은 총 인원 / 2
    startLink.assign(lineNum, vector<int>(lineNum));
    startTeam.assign(teamNum, 0);
    
    for(int i = 0 ; i < lineNum ; i++){ //팀원 받기
        for(int j = 0 ; j < lineNum ; j++){
            cin>>startLink[i][j];
        }
    }
    
    for(int i = 0 ; i < lineNum ; i++){ // 팀 대기열
        teamVector.push_back(i);
    }
    
    makeTeam(0, 0);
    
    cout<<minimum<<endl;
    
    return 0;
}
void makeTeam(int start, int depth){
    if(depth == teamNum){ //depth가 팀 인원일때
        vector<int> linkTeam;
        int startPower = 0; //start팀 전투력
        int linkPower = 0; //link팀 전투력
        int result; //start팀 전투력 - link팀 전투력
        for(int i = 0 ; i < teamVector.size() ; i++){
            bool contain = false;
            for(int j = 0 ; j < startTeam.size() ; j++){
                if(startTeam.at(j) == teamVector.at(i))
                    contain = true;
            }
            if(!contain){
                linkTeam.push_back(teamVector.at(i)); // start팀에 없는 번호를 link팀에 할당
            }
        }
        // 팀 별 전투력 계산
        for(int i = 0 ; i < teamNum ; i++){
            for(int j = 0 ; j < teamNum ; j++){
                startPower += startLink[startTeam[i]][startTeam[j]];
                linkPower += startLink[linkTeam[i]][linkTeam[j]];
            }
        }
        result = startPower - linkPower;
        if(result < 0)
            result *= -1;
        minimum = min(minimum, result);
        return;
    }
    
    for(int i = start ; i < lineNum ; i++){
        startTeam[depth] = teamVector[i]; //start팀 선별
        makeTeam(i + 1, depth + 1);
    }
}
