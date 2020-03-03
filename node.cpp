#include "linkedList.h"
#include <iostream>
#include <string>

node::node(int toNum,string toSuit){

        num = toNum;
        suit = toSuit;
        next = NULL;
}

node::node(node * toAdd){

        num = toAdd->num;
        suit = toAdd->suit;
        next = NULL;
}

node::~node(){
    next = NULL;
}

void node::setNext(node * value){
    next = value;
}

node *& node::getNext(){
    return next;
}

int node::getNum(){
    return num;
}
        
string node::getSuit(){
    return suit;
}

void node::display(node * cur)
{
	//Nothing here
	if(!cur)
		return;

    if(cur->num > 1 && cur->num < 11){
        cout << "The card is " << num << " of " << suit << endl;
    }
    else if(cur->num == 1){
        cout << "The card is Ace of " << suit << endl;
    }
    else if(cur->num == 11){
        cout << "The card is Jack of " << suit << endl;
    }
    else if(cur->num == 12){
        cout << "The card is Queen of " << suit << endl;
    }
    else if(cur->num == 13){
        cout << "The card is King of " << suit << endl;
    }
}

