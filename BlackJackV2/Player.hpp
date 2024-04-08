//
//  Player.hpp
//  BlackJackV2
//
//  Created by 杰珉 蔡 on 2024/4/2.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Player {
private:
    vector<int> hand;
protected:
    string name;
public:
    Player();
    virtual ~Player();
    Player(const string& name) : name(name) {}
    string getName() const {
        return name;
    }
    vector<int> getHand() const {
        return hand;
    }  // 獲取手牌

    void cleardeck();
    int countpoint() const;
    int getScore() const {
        return countpoint();
        }
    virtual void addCard(int card);
    virtual bool decideHit() const;
};
#endif /* Player_hpp */
