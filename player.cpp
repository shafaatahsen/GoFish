//
// Created by Zanel on 11/1/2018.
//

#include "player.h"


void Player::addCard(Card c){ //adds a card to the hand
    myHand.push_back(c);

}
void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
}



bool Player::checkHandForBook(Card &c1, Card &c2){
    return (c1 == c2);
}


bool Player::rankInHand(Card c) const{
   int r = c.getRank();
   for(int i = 0; i < myHand.size(); i++){
        if (myHand[i].getRank() == c.getRank()){
            return true;
        }
   }
   return false;
}


Card Player::chooseCardFromHand() const{
    return myHand[0];
}


bool Player::cardInHand(Card c) const{
    for(int i = 0; i < myHand.size(); i++){
        if (myHand[i] == c){
            return true;
        }
    }
    return false;
}



Card Player::removeCardFromHand(Card c){
    Card temp;
    vector<Card>::iterator it;
    for(it = myHand.begin(); it != myHand.end(); it++) {
        if (c == *it) {
            temp = *it;
            myHand.erase(it);
            return temp;
        }
    }
}

string Player::showHand() const{
    for(int i = 0; i < myHand.size(); i++){
        cout << myHand[i]<< " ";
    }
    cout << endl;
}
string Player::showBooks() const{
    for(int i = 0; i < myBook.size(); i++){
        cout << myBook[i]<< " ";
    }
    cout << endl;
}

int Player::getHandSize() const{
    return myHand.size();
}
int Player::getBookSize() const{
    return myBook.size();
}



bool Player::checkHandForPair(Card &c1, Card &c2){
    Card temp;
    vector<Card>::iterator it,iter;
    for(it = myHand.begin(); it != myHand.end(); it++) {
        for(iter = it +1;iter != myHand.end(); iter++ )
        if (iter->getRank() == it->getRank()) {
            c1 = *iter;
            c2 = *it;
            return true;
        }
    }
    return false;
}


bool Player::sameRankInHand(Card c) const{
    vector<Card>::const_iterator iter;
    for(iter = myHand.begin(); iter != myHand.end(); iter++){
        if(c.getRank() == iter->getRank())
            return true;
    }
    return false;
}