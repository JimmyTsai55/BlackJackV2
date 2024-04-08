//
//  BlackJack.hpp
//  BlackJackV2
//
//  Created by 杰珉 蔡 on 2024/4/2.
//

#ifndef BlackJack_hpp
#define BlackJack_hpp

#include <stdio.h>
#include <vector>
#include <memory>
#include <iostream>
#include "Deck.hpp"
#include "Player.hpp"
#include "ComputerPlayer.hpp"
#include "BankerPlayer.hpp"
using namespace std;
using namespace deckn;

class BlackJack {
private:
    Deck deck;
    vector<unique_ptr<ComputerPlayer>> ComputerPlayers;
    unique_ptr<BankerPlayer> banker;
    unique_ptr<Player> player;
    int betmoney;
    int poolmoney;
public:
    BlackJack();
    virtual ~BlackJack();
    void minusmoney(int&);
    void plusmoney(int&);
    void showall();
    void dealInitialCards();
    void showAllHands() const;
    void clearall();
    void autoadd();
    void Bankerautoadd();
    void playerhit();
    void bankerhit();

    void setPoolmoney(int poolmoney) {
        this->poolmoney = poolmoney;
    }
    void setBetmoney(int betmoney) {
        this->betmoney = betmoney;
    }
    int getPoolmoney() const {
        return poolmoney;
    }
    int getBetmoney() const {
        return betmoney;
    }
    int getplayerpoint() const {
        return player->countpoint();
    }
    int getbankerpoint() const {
        return banker->countpoint();
    }
};

#endif /* BlackJack_hpp */
