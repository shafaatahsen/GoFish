//
// Created by Zanel on 11/1/2018.
//

#include "deck.h"
#include "card.h"
#include <assert.h>

Deck::Deck(){ // pristine, sorted deck
    myIndex = 0;
    for(int i = Card::spades; i<=Card::clubs; i++){
        for(int j = 1; j<14; j++){
            myCards[myIndex] = Card(j,static_cast<Card::Suit>(i));
            myIndex++;
        }
    }

    myIndex = 0;

}

void Deck::shuffle(){  // shuffle the deck, all 52 cards present
    unsigned int currentTime = (unsigned)time(NULL);

    srand(currentTime); //seed the random number generator



    for(int i = 0; i<52;i++){
//cout<<rand()<<endl; test if numbers are different each time
        int randIndex = rand()%52;
        Card temp = myCards[randIndex];
        myCards[randIndex] = myCards[i];
        myCards[i] = temp;
    }


}
Card Deck::dealCard(){ // get a card, after 52 are dealt, fail
    int i = myIndex;
    myIndex++;
    assert(myIndex < 53);
    return myCards[i];


}

int  Deck::size() const{ // # cards left in the deck
    return SIZE - myIndex;

}
