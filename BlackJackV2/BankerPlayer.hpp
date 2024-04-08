//
//  BankerPlayer.hpp
//  BlackJackV2
//
//  Created by 杰珉 蔡 on 2024/4/2.
//

#ifndef BankerPlayer_hpp
#define BankerPlayer_hpp

#include <stdio.h>
#include "Player.hpp"

class BankerPlayer : public Player {
public:
    BankerPlayer();
    virtual ~BankerPlayer();
    bool decideHit() const override;
    explicit BankerPlayer(const string& name);

    // 實現特定於莊家的決策邏輯
    // 莊家可能還有其他特有的方法和屬性
//    virtual void addCard(int card) override;
};
#endif /* BankerPlayer_hpp */
