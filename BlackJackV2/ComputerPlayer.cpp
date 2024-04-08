//
//  ComputerPlayer.cpp
//  BlackJackV2
//
//  Created by 杰珉 蔡 on 2024/4/2.
//

#include "ComputerPlayer.hpp"
ComputerPlayer::ComputerPlayer() {
    
}
ComputerPlayer::~ComputerPlayer() {
    
}
bool ComputerPlayer::decideHit() const {
    // Simple example logic: hit if under 16
    return getScore() < 16;
}

ComputerPlayer::ComputerPlayer(const string& name) : Player(name) {
}
