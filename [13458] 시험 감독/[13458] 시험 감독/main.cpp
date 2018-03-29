//
//  main.cpp
//  [13458] 시험 감독
//
//  Created by YOO TAEWOOK on 2018. 3. 20..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> classVector;

int main(int argc, const char * argv[]) {
    int classNum, master, assistant;
    long long int requiredNum = 0;
    cin>>classNum;
    
    while(classNum--){
        int studentNum;
        cin>>studentNum;
        classVector.push_back(studentNum);
    }
    
    cin>>master>>assistant;
    
    for(int i = 0 ; i < classVector.size() ; i++){
        int temp = classVector[i];
        temp -= master;
        requiredNum++;
        if(temp > 0){
            requiredNum += temp / assistant;
            if(temp % assistant != 0)
                requiredNum++;
        }
    }
    
    printf("%lld\n", requiredNum);
    
    return 0;
}
