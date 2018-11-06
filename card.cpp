//
// Created by Zanel on 11/1/2018.
//

#include "card.h"
Card::Card(){ // default, ace of spades
    mySuit = spades;
    myRank = 1;
}

Card::Card(int rank, Suit s){
    mySuit = s;
    myRank = rank;
}

string Card::toString() const{ // return string version e.g. Ac 4h Js
    string s = suitString(mySuit);
    string r = rankString(myRank);

    return r+s;

}

bool Card::sameSuitAs(const Card& c) const { // true if suit same as c
    if(c.mySuit == mySuit)
        return true;
    return false;

}

int  Card::getRank() const{   // return rank, 1..13
    return myRank;
}

string Card::suitString(Suit s)  const{
    string suit;
    switch (s){
        case spades:
            suit = "s";
            break;
        case hearts:
            suit = "h";
            break;
        case diamonds:
            suit = 'd';
            break;
        case clubs:
            suit = 'c';
            break;
    }
    return suit;

}  // return "s", "h",...

string Card::rankString(int r)  const{
    string rank;
    switch(r){
        case 1:
            rank = "A";
            break;
        case 2:
            rank = "2";
            break;
        case 3:
            rank = "3";
            break;
        case 4:
            rank = "4";
            break;
        case 5:
            rank = "5";
            break;
        case 6:
            rank = "6";
            break;
        case 7:
            rank = "7";
            break;
        case 8:
            rank = "8";
            break;
        case 9:
            rank = "9";
            break;
        case 10:
            rank = "10";
            break;
        case 11:
            rank = "J";
            break;
        case 12:
            rank = "Q";
            break;
        case 13:
            rank = "K";
            break;
    }
    return rank;

}  // return "A", "2", ..."Q"


bool Card::operator == (const Card& rhs) const{
    if((mySuit == rhs.mySuit) && (myRank == rhs.myRank))
        return true;
    return false;

}
bool Card::operator != (const Card& rhs) const{
    if((mySuit == rhs.mySuit) && (myRank == rhs.myRank))
        return false;
    return true;

}