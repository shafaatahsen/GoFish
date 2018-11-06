//
// Created by Zanel on 11/1/2018.
//

#include "deck.h"
#include "card.h"

Deck::Deck(){ // pristine, sorted deck
    myIndex = 0;
    for(int i = Card::spades; i<=Card::clubs; i++){
        for(int j = 0; j<14; j++){
            myCards[myIndex] = Card(j,static_cast<Card::Suit>(i));
            myIndex++;
        }
    }

    myIndex = 0;

}

void Deck::shuffle(){  // shuffle the deck, all 52 cards present


    random_shuffle(&myCards[0],&myCards[51]);


}
Card Deck::dealCard(){ // get a card, after 52 are dealt, fail
    int i = myIndex;
    myIndex++;
    if(myIndex>52)
        return NULL;
    else
        return myCards[i];


}

int  Deck::size() const{ // # cards left in the deck
    return SIZE - myIndex;

}
