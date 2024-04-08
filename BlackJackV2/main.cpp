//
//  main.cpp
//  BlackJackV2
//
//  Created by 杰珉 蔡 on 2024/4/2.
//

#include <iostream>
#include "BlackJack.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "BankerPlayer.hpp"
#include "ComputerPlayer.hpp"
#include <sqlite3.h>

using namespace std;
enum Command {
    ADD,
    NEXT,
    QUIT,
    GO,
    UNKNOWN // 不正確任何已知命令的情况
};
Command getCommand(const string& input) {
    if (input == "add") return ADD;
    if (input == "next") return NEXT;
    if (input == "quit") return QUIT;
    if (input == "go") return GO;
    return UNKNOWN; // 输入不正確的任何已知命令
}
int main(int argc, const char* argv[]) {
    BlackJack game;
    Deck deck;
    game.setBetmoney(25);
    game.setPoolmoney(1000);
    string inputcommand;
    bool addstop = true;
    bool newgame = true;
    int betmultiple = 0;
    while (newgame) {
        cout << "How many bet: ";
        cin >> betmultiple;
        game.dealInitialCards();
        //幫其他玩家自動補牌
        game.autoadd();
        game.showall();
        addstop = true;
        while (addstop) {
            game.showAllHands();
            cout << "Enter your command(add, next, quit, go): ";
            cin >> inputcommand;
            Command cmd = getCommand(inputcommand);
            switch (cmd) {
                case ADD:
                    game.playerhit();
                    if (game.getplayerpoint() > 21) {
                        cout << "!!!!!!!LOSE!!!!!!" << endl;
                    }
                    break;
                case NEXT:
                    game.Bankerautoadd();
                    game.showAllHands();
                    if (game.getplayerpoint() > 21) {
                        game.minusmoney(betmultiple);
                        cout << "!!!!!!!LOSE!!!!!!" << endl;
                    } else if (game.getbankerpoint() > 21 ||
                               game.getplayerpoint() > game.getbankerpoint()) {
                        game.plusmoney(betmultiple);
                        cout << "!!!Winner Winner Chicken Dinner!!!" << endl;
                    } else if (game.getbankerpoint() == game.getplayerpoint()) {
                        cout << "!!!equal!!!" << endl;
                    } else {
                        game.minusmoney(betmultiple);
                        cout << "!!!!!!!LOSE!!!!!!" << endl;
                    }
                    cout << "====NEW_GAME====" << endl;
                    game.clearall();
                    addstop = false;
                    break;
                    
                case QUIT:
                    cout << "=========quit==========" << endl;
                    newgame = false;
                    addstop = false;
                    break;
                    
                default:
                    cout << "Invalid command" << endl;
                    break;
            }
        }
    }
    game.showall();
    return 0;
}
