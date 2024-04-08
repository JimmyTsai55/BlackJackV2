//
//  Deck.cpp
//  BlackJackV2
//
//  Created by 杰珉 蔡 on 2024/4/2.
//

#include "Deck.hpp"
#include <iostream>
using namespace std;
using namespace deckn;
namespace deckn {
Deck::Deck() {
    deck = {};
    deckremain = 0;
    drawcardnum = 0;
}

Deck::~Deck() {
    
}
//    製作牌庫 一共a副牌 13*4*a
void Deck::initializeDeck(int a) {
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 1; k < 14; ++k) {
                deck.push_back(k);
            }
        }
    }
}
//     用四捨五入取總牌庫裡面剩下幾副牌
void Deck::deckRemaining() {
    setdeckremain((float)round(deck.size() / 52.0 * 10) / 10);
}
////    分牌進去想要的牌庫 並從總牌庫裡面刪除
int Deck::drawCard() {
    int num = 0;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, (int)deck.size()-1);
    int index = dis(gen);
    //    decknumber.push_back((aa.getdeck())[index]);
    //    aab.countRunningCount(aa.getdeck()[index]);
    num = deck[index];
    swap(deck[index], deck[deck.size()-1]);
    deck.pop_back();
    return num;
}
//
void Deck::showDeck(const vector<int>& deck) const {
    for (int num : deck) {
        cout << num << " ";
    }
    cout << endl;
}
void Deck::showMyDeck() const {
    showDeck(deck);
}

}
