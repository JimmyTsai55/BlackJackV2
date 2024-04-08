//
//  Deck.hpp
//  BlackJackV2
//
//  Created by 杰珉 蔡 on 2024/4/2.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include <vector>
#include <random>
#include <cmath>
#include <regex>
#include <algorithm>
using namespace std;
namespace deckn {
class Deck {
private:
    vector<int> deck;
    float deckremain;
    int drawcardnum;
protected:
public:
    Deck();
    virtual ~Deck();
    void initializeDeck(int);
    int drawCard();
    void deckRemaining();
    //    void clearDecks();
    void showDeck(const vector<int>&) const;
    void showMyDeck() const;
    
    const vector<int> &getdeck() const {
        return deck;
    }
    vector<int> &getdeck() {
        return deck;
    }
    int &getdrawcardnum() {
        return drawcardnum;
    }
    const float &getdeckremain() const {
        return deckremain;
    }
    void setdeck(vector<int> deck) {
        this->deck = deck;
    }
    void setdeckremain(float deckremain) {
        this->deckremain = deckremain;
    }
    void setdrawcardnum(int drawcardnum) {
        this->drawcardnum = drawcardnum;
    }
};
}
#endif /* Deck_hpp */
