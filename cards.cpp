//cards.cpp
//Authors: Romtin Toranji 3/1/2019
//Implementation of the classes defined in cards.h

using namespace std;
#include <string>
#include "cards.h"

#include <cstdlib>

Player::Card::Card() {
	suit = ' ';
	rank = ' ';
	left = NULL;
	right = NULL;
	parent = NULL;
	value = 0;
}

Player::Card::Card(char suits, char ranks) {
	suit = suits;
	rank = ranks;
	left = NULL;
	right = NULL;
	parent = NULL;
	int x = 0,y(0);
	if(suit == 'c'){
		x = 0;
	}else if(suit == 'd'){
		x = 100;
	}else if(suit == 's'){
		x = 200;
	}else if(suit == 'h'){
		x=300;
	}
	if(rank == '1'){
		y = 10;
	}else if(rank == 'a'){
		y = 1;
	}else if(rank =='j'){
		y = 11;
	}else if(rank =='q'){
		y = 12;
	}else if(rank =='k'){
		y = 13;
	}else{
		y = rank - 48;
	}
	value = x + y;
}

Player::Card::~Card(){
	//delete left;
	//delete right;
}

char Player::Card::getSuit() const{
	return suit;
}
char Player::Card::getRank() const{
	return rank;
}
int Player::Card::getValue() const{
	return value;
}

bool operator ==(const Player::Card& c1, const Player::Card& c2) {
	if(c1.getRank()==c2.getRank() && c1.getSuit()==c2.getSuit()){
		return true;
	}
	return false;
}

Player::Player() {
	root = NULL;
}

Player::Card* Player::successor(Player::Card& c) const{
	Player::Card* n = &c;
	if(n==NULL){
		return NULL;
	}
	if(n->right){
		n = n->right;
		while(n->left){
			n = n->left;
		}
		return n;
	}
	Player::Card* p = n->parent;
	while(p!=NULL && n == p->right){
		n=p;
		p=p->parent;
	}
	return p;

	/*if(root == NULL)
		return NULL; 
	Player::Card* n = root;
	while(n){
		if(n->value == c.value){
			break;
		}
		if(n->value < c.value){
			n=n->right;
		}if(n->value > c.value){
			n=n->left;
		}
	}
	Player::Card* z = root;
	while(z->right){
		z=z->right;
	}
	if(z->value == n->value){
		return NULL;
	}
	if(n->value == c.value){
		if(n->right){
			n=n->right;
			while(n->left){
				n = n->left;
			}
			return n;
		}
		Player::Card* tmp = n->parent;
		while(tmp->parent != NULL && n == tmp->right){
			n = tmp;
			tmp = tmp->parent;
		}
		return tmp;
	}
	return NULL;*/
}
Player::Card* Player::predecessor(Player::Card& c) const{
	Player::Card* n = &c;
	if(n == NULL){
		return NULL;
	}
	if(n->left){
		n = n->left;
		while(n->right){
			n = n->right;
		}
		return n;
	}
	if(n->parent){
		Player::Card* p = n->parent;
		while(p!=NULL && n == p->left){
			n=p;
			p=p->parent;
		}
		return p;
	}
	return NULL;

	/*if(root == NULL)
	return NULL; 
	Player::Card* n = root;
	while(n){
		if(n->value == c.value){
			break;
		}
		if(n->value < c.value){
			n=n->right;
		}if(n->value > c.value){
			n=n->left;
		}
	}
		Player::Card* z = root;
	while(z->right){
		z=z->right;
	}
	if(z->value == n->value){
		return NULL;
	}
	if(n->value == c.value){
		if(n->left){
			n=n->left;
			while(n->right){
				n = n->right;
			}
			return n;
		}
		Player::Card* tmp = n->parent;
		while(tmp->parent != NULL && n == tmp->right){
			n = tmp;
			tmp = tmp->parent;
		}
		return tmp;
	}
	return NULL;*/
}

Player::Player(string names) {
	name = names;
	root = NULL;
}

Player::~Player() {
	//delete root;
}

bool Player::match(Player::Card& c) {
	Player::Card* n = getRoot();
	if(root == NULL){
		return 0;
	}
	while(n){ 
		if(n->getValue() == c.getValue()){
			if(c.rank == '1'){
				cout<< name <<" picked matching card "<<c.suit<<" 10"<<endl;
			}else{
				cout<< name <<" picked matching card "<<c.suit<<" "<<c.rank<<endl;
			}
			deleteCard(*n);
			return true;
		}if(n->getValue() < c.getValue()){
			n = n->right;
		}else{
			n = n->left;
		}
	}
	//cout<<"No matching card"<<endl;
	return false;
}

void Player::add(Player::Card& c) {
	Card* n = root;
	Card* y = NULL;
	while(n){
		y = n;
		if(n->value > c.value){
			n = n->left;
		}else{
			n = n->right;
		}
	}
	if (!root) {
		root = &c;
		return;
    }
	
	else if( c.value < y->value){
		y->left = &c;
		c.parent = y;
		return;
	}else{
		y->right = &c;
		c.parent = y;
		return;
	}

			
			
	return;
}
void Player::add2(Player::Card& c) {
	Card* n = root2;
	Card* y = NULL;
	while(n){
		y = n;
		if(n->value > c.value){
			n = n->left;
		}else{
			n = n->right;
		}
	}
	if (!root2) {
		root2 = &c;
		return;
    }
	
	else if( c.value < y->value){
		y->left = &c;
		c.parent = y;
		return;
	}else{
		y->right = &c;
		c.parent = y;
		return;
	}

			
			
	return;
}
Player::Card* Player::getMinimum() const{
	Player::Card* mini = root;
	while(mini->left){
		mini=mini->left;
	}
	return mini;
}
Player::Card* Player::getMaximum() const{
	Player::Card* maxi = root;
	while(maxi->right){
		maxi = maxi->right;
	}
	return maxi;
}
void Player::deleteCard4(Player::Card& c){
	int n = c.value;
	/*if(n != root->value){
		add2(*getRoot());
	}*/
	add2(*root);
	deleteCardHelper(*root, n);
	root = root2;
	root2 = NULL;
}
void Player::deleteCardHelper(Player::Card& c, int n){
	/*if(c.left->value == n){
		deleteCardHelper(*c.left, n);
		add2(*c.right);
		deleteCardHelper(*c.right, n);
	}else if(c.right->value == n){
		add2(*c.left);
		deleteCardHelper(*c.left, n);
		deleteCardHelper(*c.right, n);
	}else{
		add2(*c.right);
		deleteCardHelper(*c.right, n);
		add2(*c.left);
		deleteCardHelper(*c.left, n);
	}*/
		add2(*c.right);
		deleteCardHelper(*c.right, n);
		add2(*c.left);
		deleteCardHelper(*c.left, n);
}
	
void Player::deleteCard3(Player::Card& c){
	/*if(getRoot() == NULL)
		cout<<"1"<<endl;
		return;
	Player::Card* n = getRoot();
	if(n->right == NULL && n->left == NULL){
		root = NULL;
	}
	while(n){
		if(n->value == c.getValue()){
			break;
		}
		if(n->value < c.getValue()){
			n=n->right;
		}if(n->value > c.getValue()){
			n = n->left;
		}
	}
	if(n->value != c.getValue()){
		cout<<"2"<<endl;
		return;
	}
	if(n->left == NULL && n->right == NULL){
		if(n->parent){
			if(n->parent->left == n){
				cout<<"1"<<endl;
				n->parent->left = NULL;
			}else{
				cout<<"1"<<endl;
				n->parent->right = NULL;
			}
		}
		delete n;
		return;
	}
	else if((n->left && !n->right) || (n->right && !n->left)) {
		if(n->left){
			if(!n->parent){
				n->left->parent = NULL;
				root = n->left;
			}
			else if(n->parent->left == n){
				n->parent->left = n->left;
				n->left->parent = n->parent;
			}else{
				n->parent->right = n->left;
				n->left->parent = n->parent;
			}
		}
		else {
			if(!n->parent){
				n->right->parent = NULL;
				root = n->right;
			}
			else if(n->parent->left == n){
				n->parent->left = n->right;
				n->right->parent = n->parent;
			}
			else {
				n->parent->right = n->right;
				n->right->parent = n->parent;
			}
		}
		delete n;
		return;
	}
	else{
		Player::Card* tmp = successor(*n);
		n->value = tmp->value;
		n->rank = tmp->rank;
		n->suit = tmp->suit;
		deleteCard3(*tmp);
	}
	return;*/
}
void Player::deleteCard2(Player::Card& c){
	if(getRoot() == NULL)
		return;
	Player::Card* n = getRoot();
	if(n->right == NULL && n->left == NULL){
		root = NULL;
	}
	while(n){
		if(n->value == c.getValue()){
			break;
		}
		if(n->value < c.getValue()){
			n=n->right;
		}if(n->value > c.getValue()){
			n = n->left;
		}
	}
	if(n->value != c.getValue()){
		return;
	}
	if(n->left == NULL && n->right == NULL){
		if(n->parent){
			if(n->parent->left == n){
				n->parent->left = NULL;
			}else{
				n->parent->right = NULL;
			}
		}
		delete n;
		return;
	}
	else if((n->left && !n->right) || (n->right && !n->left)){
		if(n->left){
			if(!n->parent){
				n->left->parent = NULL;
				root = n->left;
				n->left = NULL;
			}
			else if(n->parent->left == n){
				n->parent->left = n->left;
				n->left->parent = n->parent;
				n->left = NULL;
			}else{
				n->parent->right = n->left;
				n->left->parent = n->parent;
				n->right = NULL;
			}
		}
		else {
			if(!n->parent){
				n->right->parent = NULL;
				root = n->right;
				n->right = NULL;
			}
			else if(n->parent->left == n){
				n->parent->left = n->right;
				n->right->parent = n->parent;
			}
			else {
				n->parent->right = n->right;
				n->right->parent = n->parent;
			}
		}
		delete n;
		return;
	}
	else{
		Player::Card targetCard;
		targetCard.value = n->value;
		targetCard.rank = n->rank;
		targetCard.suit = n->suit;
		Player::Card* predNode = predecessor(*n);
		n->value = predNode->value;
		n->rank = predNode->rank;
		n->suit = predNode->suit;
		deleteCard2(*predNode);
	}
	return;
}
		
void Player::deleteCard(Player::Card& c) {
	if(getRoot() == NULL){
		return;
	}
	Player::Card* n = getRoot();
	if(n->right == NULL && n->left == NULL){
		root = NULL;
	}
	while(n){
		if(n->value == c.getValue()){
			break;
		}
		if(n->value < c.getValue()){
			n=n->right;
		}if(n->value > c.getValue()){
			n = n->left;
		}
	}
	if(n->value != c.getValue()){
		return;
	}
	if(n->right == NULL && n->left == NULL){
		if(n->parent){
			if(n->parent->left == n){
				n->parent->left = NULL;
				//n->parent = NULL;
				delete n;
				return;
			}else{
				n->parent->right = NULL;
				//n->parent = NULL;
				delete n;
				return;
			}
		}
		root = NULL;
		return;
	}
	if(n->right == NULL || n->left == NULL){
		if(n->parent == NULL) {
			if(n->right){
				root = n->right;
				n->right->parent = NULL;
				//n->right = NULL;
				delete n;
				return;
			}else{
				root = n->left;
				n->left->parent = NULL;
				//n->left = NULL;
				delete n;
				return;
			}
		}else if(n->right){
			if(n->parent->right == n){
				n->parent->right = n->right;
				n->right->parent = n->parent;
				delete n;
				return;
			}if(n->parent->left == n){
				n->parent->left = n->right;
				n->right->parent = n->parent;
				//n->parent = NULL;
				//n->right = NULL;
				delete n;
				return;
			}
		}else if(n->left){
			if(n->parent->left == n){
				n->parent->left = n->left;
				n->left->parent = n->parent;
				//n->parent = NULL;
				//n->left = NULL;
				delete n;
				return;
			}if(n->parent->right == n){
				n->parent->right = n->left;
				n->left->parent = n->parent;
				delete n;
				return;
			}
		}
	}
	if(n->right != NULL && n->left != NULL){
		Player::Card* mini = n;
		mini = mini->right;
		while(mini->left){
			mini = mini->left;
		}
		n->value = mini->value;
		n->rank = mini->rank;
		n->suit = mini->suit;
		if(mini->parent->left == mini && mini->right == NULL){	
			mini->parent->left = NULL;
			delete mini;
			return;
		}else if(mini->parent->right == mini && mini->right == NULL){
			mini->parent->right = NULL;
			delete mini;
			return;
		}
		else if(mini->right){
			if(mini->parent->right == mini){
				mini->parent->right = mini->right;
				mini->right->parent = mini->parent;
				delete mini;
				return;
			}
			if(mini->parent->left == mini){
				mini->parent->left = mini->right;
				mini->right->parent = mini->parent;
				delete mini;
				return;
			}
		}
		//deleteCard(*mini);
		
	}
	return;
}

string Player::getName() const{
	return name;
}

Player::Card* Player::getRoot() const{
	return root;
}

void Player::printInOrder(Card& z) const{
	Card* n = &z;
	printBSTHelper(n);
}
void Player::printPreOrder(Card& z) const{
	Card* n = &z;
	printBSTHelper2(n);
}
void Player::printBSTHelper(Player::Card* z) const{
	if(z){
		printBSTHelper(z->left);
		if(z->getRank() == '1'){
			cout<<z->getSuit()<<" 10"<<endl;
		}else{
		cout<<z->getSuit()<<" "<<z->getRank()<<endl;
		}
		printBSTHelper(z->right);
	}
}
void Player::printBSTHelper2(Player::Card* z) const{
	if(z){
		cout<<z->getSuit()<<" "<<z->getRank()<<" "<<endl;
		printBSTHelper2(z->left);
		printBSTHelper2(z->right);
	}
}
ostream& operator <<(ostream &os, Player::Card& z){
	Player::Card* n = &z;
	if(n){
		if(n->left){
			cout << n->left;
		}
		cout<<n->getRank()<<" "<<n->getSuit()<<endl;
		if(n->right){
			cout<< n->right;
		}
	}
	return os;
}

