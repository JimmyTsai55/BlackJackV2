//
//  BankerPlayer.cpp
//  BlackJackV2
//
//  Created by 杰珉 蔡 on 2024/4/2.
//

#include "BankerPlayer.hpp"
BankerPlayer::BankerPlayer() {
    
}
BankerPlayer::~BankerPlayer() {
    
}
bool BankerPlayer::decideHit() const {
    // Dealer logic: hit if under 17
    return getScore() < 17;
}
BankerPlayer::BankerPlayer(const string& name) : Player(name) {
}
