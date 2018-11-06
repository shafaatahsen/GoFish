//
// Created by Zanel on 11/1/2018.
//

#include "player.h"

Player::Player();



void Player::addCard(Card c){ //adds a card to the hand
    myHand.push_back(c);

}
void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
}



bool Player::checkHandForBook(Card &c1, Card &c2);


bool Player::rankInHand(Card c) const{
   int r = c.getRank();
   vector<Card>::iterator iter;
   for(iter = myHand.begin(); iter != myHand.end(); iter++){

   }
}


Card Player::chooseCardFromHand() const;


bool Player::cardInHand(Card c) const;


Card Player::removeCardFromHand(Card c);

string Player::showHand() const;
string Player::showBooks() const;

int Player::getHandSize() const;
int Player::getBookSize() const;



bool Player::checkHandForPair(Card &c1, Card &c2);


bool Player::sameRankInHand(Card c) const;