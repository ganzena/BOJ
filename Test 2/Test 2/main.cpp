//
//  main.cpp
//  Test 2
//
//  Created by YOO TAEWOOK on 2018. 3. 30..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <algorithm>
#include <limits.h>

using namespace std;
typedef pair<int, int> pii;

vector<pii> dir = {pii(-1, 0), pii(0, -1), pii(1, 0), pii(0, 1)};

int userX, userY, shopNum;
int shopX, shopY, couponNum;
string shopName;

class ShopInfo{

public:
    int shopX, shopY, couponNum;
    string shopName;
    ShopInfo(int shopX, int shopY, string shopName, int couponNum){
        this->shopX = shopX;
        this->shopY = shopY;
        this->shopName = shopName;
        this->couponNum = couponNum;
    }

};

struct COMPARE{
    bool operator()(pair<ShopInfo, ShopInfo> shop1, pair<ShopInfo, ShopInfo> shop2){
        if(shop1.second.shopX + shop1.second.shopY < shop2.second.shopX + shop2.second.shopY)
                return shop1.second.shopX + shop1.second.shopY < shop2.second.shopX + shop2.second.shopY;
        
        
    
    }
};

vector<pair<ShopInfo, ShopInfo>> shopVector;
vector<pair<ShopInfo, ShopInfo>>::iterator iter;

int main(int argc, const char * argv[]) {
    cin>>userX>>userY>>shopNum;
    int length = shopNum;
    while(shopNum--){
        cin>>shopX>>shopY>>shopName>>couponNum;
        ShopInfo shopFirst(shopX, shopY, shopName, couponNum);
        int X = shopX - userX;
        int Y = shopY - userY;
        if(X < 0)
            X *= -1;
        X /= 100;
        X *= 100;
        if(Y < 0)
            Y *= -1;
        Y /= 100;
        Y *= 100;
        ShopInfo shopSecond(X, Y, shopName, couponNum);
        shopVector.push_back(pair<ShopInfo, ShopInfo>(shopFirst, shopSecond));
    }
    
    sort(shopVector.begin(), shopVector.end(), COMPARE());
    
    for(iter = shopVector.begin() ; iter != shopVector.end() ; iter++){
        cout<<iter->first.shopX<<" "<<iter->first.shopY<<" "<<iter->first.shopName<<" "<<iter->first.couponNum<<endl;
    }
    
    
    return 0;
}

