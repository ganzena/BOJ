//
//  main.cpp
//  간단한거할때
//
//  Created by YOO TAEWOOK on 2020/09/26.
//

#include <iostream>
using namespace std;


int a = 300,b = 60,c = 10;
int arr[3];

int main(int argc, const char * argv[]) {
    int time;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>time;
    
        if(time >= a){
            arr[0] = time / a;
            time = time % a;
        }
        if(time >= b){
            arr[1] = time / b;
            time = time % b;
        }
        if(time >= c){
            arr[2] = time/c;
            time = time%c;
        }
        if(time != 0){
            cout<<-1<<"\n";
            return 0;
        }
    
    cout<<arr[0]<<' '<<arr[1]<<' '<<arr[2]<<"\n";
    
    return 0;
}
