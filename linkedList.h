//#include "blackjack.h"
#include "node.h"

class linkedList{
    public:
        // Constructor and Deconstructor
        linkedList();
        ~linkedList();

        void insert(node *& toAdd, node *& head);   // Inserts the hand to list
        void copy(node *& toAdd, node *& head);     // Inserts the hand to list

        void displayAll();                             // Display Cards
        void displayRemaining(node * remainingDeck);                             // Display Cards
        void removeCard(node *& toDel, node *& head);
        //void setTail(node * head);
        //void removeAll(node * head);

        node * traverse(int num, node * cur);      // Recursive traverse function
        //void draw();                               // Call draw function?
        //void drawNew();                            // Only called when the player makes a new hand
        //void hit();                                // When the player draws a singular card
        //void stand();                              // Calls dealer to start their turn

        void create();                             // Creates the deck of cards
        void shuffle();                            // Calls shuffle function
        void shuffle(node *& head, node *& shuffledDeck);                // Shuffles the deck of cards
    private:
        node * head;
       //node * tail;
};