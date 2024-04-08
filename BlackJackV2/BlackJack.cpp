//
//  BlackJack.cpp
//  BlackJackV2
//
//  Created by 杰珉 蔡 on 2024/4/2.
//

#include "BlackJack.hpp"
using namespace std;
BlackJack::BlackJack() {
    deck.initializeDeck(5);
    ComputerPlayers.push_back(make_unique<ComputerPlayer>
                              ("ComputerPlayerA"));
    ComputerPlayers.push_back(make_unique<ComputerPlayer>
                              ("ComputerPlayerB"));
    ComputerPlayers.push_back(make_unique<ComputerPlayer>
                              ("ComputerPlayerC"));
    ComputerPlayers.push_back(make_unique<ComputerPlayer>
                              ("ComputerPlayerD"));
    banker = make_unique<BankerPlayer>("Banker");
    player = make_unique<Player>("Human");
    betmoney = 0;
    poolmoney = 0;
}

BlackJack::~BlackJack() {
    
}
void BlackJack::minusmoney(int &a) {
    this->poolmoney -= a*betmoney;
}
void BlackJack::plusmoney(int &a) {
    this->poolmoney -= a*betmoney;
}
void BlackJack::showall() {
    deck.deckRemaining();
    //    cout << "RunningCount : " << c21p.countRunningCount() << endl;
    cout << "Deck Remaining: " << deck.getdeck().size() <<
    ", " << deck.getdeckremain() <<
    ", Used : " << 260 - deck.getdeck().size() << endl;
    //    cout << "TrueCount: " << c21p.trueCount() << endl;
    //    cout << "Bet* : " << c21p.bet() << endl;
    cout << "MoneyPool: " << getPoolmoney() << endl;
}
void BlackJack::dealInitialCards() {
    //  幫玩家以及電腦玩家發兩張牌
    for (auto& cps : ComputerPlayers) {
        cps->addCard(deck.drawCard());
        cps->addCard(deck.drawCard());
    }
    banker->addCard(deck.drawCard());
    banker->addCard(deck.drawCard());
    player->addCard(deck.drawCard());
    player->addCard(deck.drawCard());
}

void BlackJack::showAllHands() const {
    //     電腦玩家展示手牌
    for (const auto& cps : ComputerPlayers) {
        vector<int> hand = cps->getHand();
        cout << cps->getName() << "'s hand: ";
        for (int card : hand) {
            cout << card << " ";
        }
        cout << ", " << cps->countpoint();
        cout << endl;
    }
    //    莊家展示手牌
    cout << banker->getName() << "'s hand: ";
    vector<int> bankerHand = banker->getHand();
    for (int card : bankerHand) {
        cout << card << " ";
    }
    cout << ", " << banker->countpoint();
    cout << endl;
//       玩家展示手牌
    cout << player->getName() << "'s hand: ";
    vector<int> playerhand = player->getHand();
    for (int card : playerhand) {
        cout << card << " ";
    }
    cout << ", " << player->countpoint();
    cout << endl;
}
void BlackJack::clearall() {
    for (const auto& cps : ComputerPlayers) {
        cps->cleardeck();
    }
    player->cleardeck();
    banker->cleardeck();
}
void BlackJack::autoadd() {
    for(const auto& cps : ComputerPlayers) {
        if(cps->decideHit()) {
            cps->addCard(deck.drawCard());
        }
    }
}
void BlackJack::Bankerautoadd() {
    if(banker->decideHit()) {
        banker->addCard(deck.drawCard());
    }
}
void BlackJack::playerhit() {
    player->addCard(deck.drawCard());
}

void BlackJack::bankerhit() {
    banker->addCard(deck.drawCard());
}


