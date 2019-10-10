//cards.h
//Authors: Romtin Toranji
//All class declarations go here
//Constructor:
//	Card():
//		Postcondition: makes a card with NULL next;
//	Card(char suit, char rank)
//		Postcondition: makes a card with suit and rank
//	Player():
//		Default constructor
//	Player(string names):
//		Postcondition: gives a player with its name set
//Destructor:
//	~Player()
//		Postcondition: deletes all the nodes in the linked list
//	~Card()
//		Postcondition: deletes a card node
//Accessor:
//	predecessor:
//		Postcondition: given a node it gives the predecessor card
//	successor:
//		Postcondition: given a node it gives the successor card
//	getSuit
//		Postcondition:returns suit
//	getRank
//		Postcondition: returns rank
//	string getName() const;
//		Postcondition: return name
//	Player::Card* getRoot() const;
//		Postcondition: returns root
//	void printInOrder() const;
//		Postcondition: prints out cards of a bst in order
//Modification:
//	void add(Player::Card& c);
//		Postcondition:adds card to bst
//	bool match(Player::Card& c);
//		Postcondition: matches card in linked list and deletes it
//	void deleteCard(Player::Card& c);
//		Postcondition: deletes card in bst
//Operators
//	friend ostream& operator <<(ostream &os, const Player::Card& c);
//		Postcondition:outputs members of bst given player
//friend bool operator ==(const Player::Card& c1, const Player::Card& c2);
//		Postcondition: checks if two cards are equal
#ifndef CARDS_H
#define CARDS_H
using namespace std;
#include <string>
#include <iostream>

class Player{
	public:
	class Card{
		friend class Player;
		public:
			//constructor
			Card();
			Card(char suit, char rank);
			//destructor
			~Card();
			//Accessor Functions
			char getSuit() const;
			char getRank() const;
			
			int getValue() const;
			//Mutator Functions
			Card* left;
			Card* right;
			Card* parent;
		private:
			char suit;
			char rank;
			int value;
	};
	//constructor
	Player();
	Player(string names);
	//destructor
	~Player();
	//Modificaiton Member functions
	void add(Player::Card& c);
	bool match(Player::Card& c);
	void deleteCard(Player::Card& c);
	void deleteCard2(Player::Card& c);
	void deleteCard3(Player::Card& c);
	void deleteCardHelper(Player::Card& c, int n);
	void deleteCard4(Player::Card& c);
	void add2(Player::Card& c);
	//accessor functions
	string getName() const;
	Player::Card* getRoot() const;
	void printInOrder(Card& z) const;
	void printBSTHelper(Player::Card* z) const;
	void printPreOrder(Card& z) const;
	void printBSTHelper2(Player::Card* z) const;
	Player::Card* predecessor(Player::Card& c) const;
	Player::Card* successor(Player::Card& c) const;
	Player::Card* getMinimum() const;
	Player::Card* getMaximum() const;
	friend ostream& operator <<(ostream &os, const Player::Card& c);
	friend bool operator ==(const Player::Card& c1, const Player::Card& c2);
	
	private:
		string name;
		Card* root;
		Card* root2;
};
		
ostream& operator <<(ostream &os, const Player::Card& p);
bool operator ==(const Player::Card& c1, const Player::Card& c2);
#endif
