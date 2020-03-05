/*
Written by Joshua Lee
*/

#include <iostream>
#include <string>
#include "linkedList.h"


using namespace std;

int main(){
    // Variables
    int choice = 0;

    // Initialize blackjack game objects
    linkedList deck;
    //linkedList hand;
    //linkedList dealer;
        
    cout << "Initial Starting Deck" << endl ;
    deck.create();

    // Menu
    do{
        cout << "1) Display Deck" << endl;
        cout << "2) Shuffle Deck" << endl;
        cout << "5) Quit" << endl;
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1: 
                cout << "Displaying the Deck" << endl ;
                deck.displayAll();
                break;
            case 2: 
                cout << "Shuffling the Deck" << endl ;
                deck.shuffle();
                break;
            case 5:
                break;
            default:
                cout << "\nInvalid Option!" << endl;
                break;
        }
    }while(choice != 5);
}