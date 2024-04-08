//
//  Player.cpp
//  BlackJackV2
//
//  Created by 杰珉 蔡 on 2024/4/2.
//

#include "Player.hpp"
using namespace std;
Player::Player() {
    hand = {};
}

Player::~Player() {
    
}
//  計算點數
int Player::countpoint() const {
    int allpoints = 0;
    for(int point : hand) {
        if(point >= 2 && point <= 9) {
            allpoints += point;
        } else if(point >= 10) {
            allpoints += 10;
        }
    }
//  如果總數不超過21點則將Ａ認為11點，其餘都將Ａ認為 1 點
    for (int point : hand) {
        if (point == 1) {
            allpoints += (allpoints + 11 <= 21) ? 11 : 1;
        }
    }
    return allpoints;
}

//要牌
void Player::addCard(int card) {
    hand.push_back(card);
}
// 清理牌庫
void Player::cleardeck() {
    hand.clear();
}
bool Player::decideHit() const {
    return getScore() < 17;
}
