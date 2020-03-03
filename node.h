#include <string>
using namespace std;

class node{
    public:
        // node();
        node(int toNum,string toSuit);
        node(node * toAdd);
        ~node();

        void display(node * cur);                  // Displays only last hand's card info
        //void remove();
        //void dealer();                             // Randomly generates the dealers hand and compares to player
        //void draw();                               // Retrieves first 2 cards for hand
        //void hit(node * head);                     // Retrieves the next card
        node *& getNext();
        void setNext(node * value);
        int getNum();
        string getSuit();

    private:
        node * next;
        int num;
        string suit;
        
};