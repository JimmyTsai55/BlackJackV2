//
//  ComputerPlayer.hpp
//  BlackJackV2
//
//  Created by 杰珉 蔡 on 2024/4/2.
//

#ifndef ComputerPlayer_hpp
#define ComputerPlayer_hpp

#include <stdio.h>
#include "Player.hpp"

class ComputerPlayer : public Player {
public:
    ComputerPlayer();
    virtual ~ComputerPlayer();
    bool decideHit() const override;
    // 實現特定於電腦玩家的決策邏輯
    // 其他電腦玩家特有的方法
    explicit ComputerPlayer(const string& name);

//    virtual void addCard(int card) override;
};
#endif /* ComputerPlayer_hpp */
