#include "linkedList.h"
#include <iostream>
#include "string.h"

#include <ctime>

using namespace std;

linkedList::linkedList():head(NULL)//,tail(NULL)
{}

linkedList::~linkedList(){
   /*
    if(head){
        removeAll(head); // Recursive delete
        head = NULL;
    }
    */
}

// Creates the initial deck of cards all in order
void linkedList::create(){
    // Add Spades to deck
    node * temp;

    for(int i = 1; i < 14; i++){
        temp = new node(i,"Spades");
        insert(temp, head);
    }
/*
    // Add Diamonds to deck
    for(int i = 1; i < 14; i++){
        temp = new node(i,"Diamonds");
        insert(temp, head);
    }

    // Add Clubs to deck
    for(int i = 1; i < 14; i++){
        temp = new node(i,"Clubs");
        insert(temp, head);
    }

    // Add Hearts to deck
    for(int i = 1; i < 14; i++){
        temp = new node(i,"Hearts");
        insert(temp, head);
    }*/

    // Finish Circular Linked List
    //cout << "Linking tail to head..." << endl;
    //setTail(head);
}

/*void linkedList::setTail(node * cur){
    if(!cur)
        return;

    else if(cur->getNext() == NULL){
        tail = cur;
        tail->setNext(head);
    }
    else 
        setTail(cur->getNext());
}
*/

void linkedList::removeCard(node *& toDel, node *& cur){
    // No list
    if(!cur)
        return;
    // First item is the delete item and only item in list
    if(cur == toDel && cur->getNext() == NULL){
        cout << "DELETING " << cur->getNum() << " of " << cur->getSuit() << endl << endl;
        delete cur;
        cur = NULL;
        return;
    }

    if(cur == toDel){
        //tail->setNext(cur->getNext());
        cout << "DELETING " << cur->getNum() << " of " << cur->getSuit() << endl << endl;

        delete cur;
        //cur = tail->getNext();
    }

    while(cur->getNext() != NULL && cur->getNext() != toDel){
        cur = cur->getNext();
    }

    if(cur->getNext() == toDel){
        node * temp = cur->getNext();
        cur->setNext(temp->getNext());

        cout << "DELETING " << temp->getNum() << " of " << temp->getSuit() << endl;

        delete temp;
        temp = NULL;
    }
    else{
        cout << "--- Could not find "<< toDel->getNum() << " of " << toDel->getSuit() << " in removeCard()." << endl;
    }
    /*
    // First item is the deletion item but not only item in list
    else if(cur == toDel && cur->getNext() != cur){
        if(cur->getNext()->getNext() == cur){
            tail = cur->getNext();
            delete cur;
            cur = tail;
        }
        else{
            node * temp = cur->getNext();
            delete cur;
            cur = temp;
            tail->setNext(cur);
        }
    }
    // Next item is the delete item
    else if(cur->getNext() == toDel){
        if(cur->getNext()->getNext() == cur){
            tail = cur;
            delete cur->getNext();
            cur->setNext(cur);
        }
        else{
            node *temp = cur->getNext()->getNext();
            delete cur->getNext();
            cur->setNext(temp);
        }
    }
    // Traverse
    else
        removeCard(toDel,cur->getNext());
    */
}

void linkedList::shuffle(){
        node * shuffledDeck; // not using yet
        shuffle(head, shuffledDeck);
}

void linkedList::shuffle(node *& head, node *& shuffledDeck){
    node * find;
    srand((unsigned int) time (NULL)); //activates the generator
    node * copyHead = head;
    head = NULL;
    //tail->setNext(copyHead);

    int counter = 1;

    // Go through each card in old deck, and randomly add it to end of new deck
    for(int i = 0; i < 12; i++){
        
        int randomNum = rand() % (12);            // Generate random number between 0-52
        cout << randomNum << endl;
        find = traverse(randomNum,copyHead);//->getNext(); // Get that random card
        //cout << "CARD FOUND" << endl;
        find->display(find);

        //cout << "COPYING NODE" << endl;
        copy(find,head);
        //cout << "NODE COPIED" << endl;
        cout << endl;

        cout << "REMOVING NODE" << endl;
        removeCard(find,copyHead);
        cout << "CARD NUMBER " << counter << " REMOVED" << endl << endl;
        displayRemaining(copyHead);
        counter++;
    }
    cout << "\nCards copied: " << counter << endl;

    //head = shuffledDeck;
}

node * linkedList::traverse(int num, node * cur){
    if(num == 0 || cur == NULL)
        return cur;

    while(num != 0){
        cur = cur->getNext();
        num--;
    }
    return cur;
} 

// Recursive insert function
void linkedList::insert(node *& toAdd, node *& cur){
    // No List
    if(!cur) 
        cur = toAdd;  // Set initial head of list
    
    // Found end of list
    else if(cur->getNext() == NULL)
        cur->setNext(toAdd);
    // Keep Traversing to find end of list
    else
        insert(toAdd,cur->getNext());
    
}

// Copies a node and adds it to a new list
void linkedList::copy(node *& toAdd, node *& cur){
    // Create list if no list
    if(!cur){
        node * temp = new node(toAdd);
        cur = temp;
    }
    // Found end of list
    else if(cur->getNext() == NULL){
        node * temp = new node(toAdd);
        cur->setNext(temp);
    }
    // Keep Traversing to find end of list
    else{
        copy(toAdd,cur->getNext());
    }
}

// Displays all cards in the deck
void linkedList::displayAll(){
    //int counter = 0;

    // List is Empty
    if(!head)
        cout << "Empty List!" << endl;
    
    // Display First item
    //node * temp = head;
    //temp->display(temp);
    //counter++;

    //cout << counter << endl << endl;

    // Increment and display until at start
    do{
        head->display(head);
        head = head->getNext();

        //counter++;
        //cout << counter << endl << endl;
    }while(head != NULL);
    //cout << "\nCards Displayed: " << counter << endl;
}

// Displays all cards in the deck
void linkedList::displayRemaining(node * remainingDeck){
    //int counter = 0;

    // List is Empty
    if(!remainingDeck)
        cout << "Empty List!" << endl;
    
    // Display First item
    //node * temp = remainingDeck;
    //temp->display(temp);
    //counter++;

    //cout << counter << endl << endl;

    // Increment and display until at start
    do{
        remainingDeck->display(remainingDeck);
        remainingDeck = remainingDeck->getNext();
        //counter++;
        //cout << counter << endl << endl;
    }while(remainingDeck->getNext() != NULL);
    //cout << "\nCards Displayed: " << counter << endl;
}