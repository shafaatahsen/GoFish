// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    int numCards = 13;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    cout << "size is= " << d.size() << endl;

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    cout << "size is= " << d.size() << endl;

    Card book1, book2;  //these are the cards that I used to play the game

    while (p1.checkHandForPair(book1, book2)){      //this books any pairs that p1 has after being dealt cards
        p1.bookCards(book1,book2);
        p1.removeCardFromHand(book1);
        p1.removeCardFromHand(book2);
    }
    cout << p1.getName() << "'s book is:" << p1.showBooks() << endl;
    cout << p1.getName() << "'s hand is:" << p1.showHand()<< endl;

    while (p2.checkHandForPair(book1, book2)){      //this books any pairs that p2 has after being dealt cards
        p2.bookCards(book1,book2);
        p2.removeCardFromHand(book1);
        p2.removeCardFromHand(book2);
    }

    cout << p2.getName() << "'s book is:" << p2.showBooks() << endl;
    cout << p2.getName() << "'s hand is:" << p2.showHand() << endl;

    book1 = p1.chooseCardFromHand();    //checks if chooseCardFromHand func. works

    cout << book1 << endl;  //check if card gotten is in the hand (sanity check)

    while (p2.cardInHand(book1)){  //if they have cards that match they give up the card and the other player books pair
        book2 = p2.removeCardFromHand(book1);   //you should copy paste this code whenever either player is asking for
        p1.addCard(book2);                      //cards from other player because they keep going until they say no
        p1.bookCards(book1,book2);
        p1.removeCardFromHand(book1);
        p1.removeCardFromHand(book2);

        book1 = p1.chooseCardFromHand();    //gets a new card to ask for
    }

    cout << p1.getName() << "'s book is:" << p1.showBooks() << endl;
    cout << p1.getName() << "'s hand is:" << p1.showHand()<< endl;

    cout << p2.getName() << "'s book is:" << p2.showBooks() << endl;
    cout << p2.getName() << "'s hand is:" << p2.showHand()<< endl;

    if (p1.getBookSize() > p2.getBookSize()){       //if p1 has a bigger book then they win
        cout << p1.getName() << " wins!" << endl;
        cout << p2.getName() << " loses! HAHAHA" << endl;
    }
    else {      //if p2 has a bigger book then they win
        cout << p2.getName() << " wins!" << endl;
        cout << p1.getName() << " loses!" << endl;
    }



    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

