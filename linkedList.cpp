#include "linkedList.h"
#include <iostream>
#include "string.h"

#include <ctime>

using namespace std;

linkedList::linkedList():head(NULL),tail(NULL)
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
    for(int i = 1; i < 14; i++){
       node * temp = new node(i,"Spades");
       insert(temp, head);
    }


    // Add Diamonds to deck
    for(int i = 0; i < 14; i++){
       node * temp = new node(i,"Diamonds");
       insert(temp, head);
    }

    // Add Clubs to deck
    for(int i = 0; i < 14; i++){
       node * temp = new node(i,"Clubs");
       insert(temp, head);
    }

    // Add Hearts to deck
    for(int i = 0; i < 14; i++){
       node * temp = new node(i,"Hearts");
       insert(temp, head);
    }

    //setTail(head);
    //tail->setNext(head);
}

/*void linkedList::setTail(node * head){
    if(!head)
        return;

    else if(head->getNext == NULL)
        tail = head;
    
    else 
        setTail(head->getNext());
}*/

void linkedList::removeNode(node *& toDel, node *& cur){
    // No list
    if(!cur)
        return;
    if(cur == toDel){
        cur = toDel->getNext();
        delete toDel;
    }
    else if(cur->getNext() == toDel){
        cur->setNext(toDel->getNext());
        delete toDel;
    }
    else
        removeNode(toDel,cur->getNext());
    
}

void linkedList::shuffle(){
        
        
        node * shuffledDeck;
        shuffle(head, shuffledDeck);

        //copy(temp,head);                  // Add random card to new deck
        //node * copy = new node(temp);
        //if(!head){
        //    head = copy;
        //}
        //    head->setNext(copy);

        //removeNode(temp,head);                          // Remove random card from old deck
}

void linkedList::shuffle(node *& head, node *& shuffledDeck){
    node * find;
    srand((unsigned int) time (NULL)); //activates the generator

    // Go through each card in old deck, and randomly add it to end of new deck
    for(int i = 0; i < 52; i++){
        node * copyHead = head;
        int randomNum = rand() % (53-i);            // Generate random number between 0-52
        cout << randomNum << endl;
        find = traverse(randomNum,copyHead);//->getNext(); // Get that random card
        cout << "CARD FOUND" << endl;
        find->display(find);

        cout << "COPYING NODE" << endl;
        copy(find,shuffledDeck);
        cout << "NODE COPIED" << endl;
    }
    head = shuffledDeck;
}

node * linkedList::traverse(int num, node * cur){
    if(num == 0 || cur->getNext() == NULL)
        return cur;

    for(int i = 0; i < num; i++){
        cur = cur->getNext();
    }
    return cur;
} 

// Recursive insert function
void linkedList::insert(node *& toAdd, node *& cur){
    // No List
    if(!cur){
        // Set initial head of list
        cur = toAdd;
        //cur->setNext(NULL);
    }
    // Found end of list
    else if(cur->getNext() == NULL){
        cur->setNext(toAdd);
        //toAdd->setNext(NULL);
    }
    // Keep Traversing to find end of list
    else{
        insert(toAdd,cur->getNext());
    }
}

void linkedList::copy(node *& toAdd, node *& cur){
    if(!cur){
        node * temp = new node(toAdd);
        cur = temp;
    }
    // Found end of list
    else if(cur->getNext() == NULL){
        node * temp = new node(toAdd);
        cur->setNext(temp);
        //toAdd->setNext(NULL);
    }
    // Keep Traversing to find end of list
    else{
        insert(toAdd,cur->getNext());
    }
}

// Displays all cards in the deck
void linkedList::displayAll(){
    if(!head)
        cout << "Empty List!" << endl;
    
    node * temp = head;
    while(temp){
        temp->display(temp);
        temp = temp->getNext();
    }
}