//Romtin Toranji
#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }
  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files
  Player alice("Alice");
  Player bob("Bob");
  
  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
	  Player::Card *z = NULL;
	  
	  char suits = line[0];
	  char ranks = line[2];
	  z = new Player::Card(suits,ranks);
	  alice.add(*z);
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
	  Player::Card *z = NULL;
	  
	  char suits = line[0];
	  char ranks = line[2];
	  z = new Player::Card(suits,ranks);
	  bob.add(*z);
  }
  cardFile2.close();
  bool turn = true;
  bool matchi = true;
  Player::Card* bb = bob.getMinimum();
  Player::Card* aa = alice.getMaximum();  
  while(matchi){
	  if(turn == true && bob.successor(*bb)){
		  Player::Card* tmp = bob.successor(*bb);
		  if(alice.match(*bb) == true){
			  bob.deleteCard(*bb);
			  turn = false;
		  }
		  bb = tmp;
		  
	  }
	  if(bb->getValue()>aa->getValue()){
		  break;
	  }
	  if(bob.successor(*bb) == NULL){
		  break;
	  }
	  if(turn == false && alice.predecessor(*aa)){
		  Player::Card* tmp2 = alice.predecessor(*aa);			  
		  if(bob.match(*aa) == true){
			  alice.deleteCard(*aa);
			  turn = true;
		  }
		  aa = tmp2;
	  }
	  if(bb->getValue()>aa->getValue()){
		  break;
	  }
	  if(alice.predecessor(*aa) == NULL){
		  break;
	  }
  }
  cout<<endl<<"Alice's cards:"<<endl;
  alice.printInOrder(*alice.getRoot());
  cout<<endl;
  cout<<"Bob's cards:"<<endl;
  bob.printInOrder(*bob.getRoot());

  return 0;
}
