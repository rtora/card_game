//Romtin Toranji
using namespace std;
#include <string>
#include "cards.h"
#include <cstdlib>
  void testCardgetSuit();
  void testCardgetRank();
  void testdeleteCard();
  void testmatch();
  void testgetName();
  void testsuccessor();
  void testoperatorequals();
  bool double_equals(double x, double y);
  void startTestGroup(string groupName);
  void assertEquals(double expected, double actual, string testDescription);
  void assertEqualsS(string expected, string actual, string testDescription);
  bool string_equals(string x, string y);
  void assertEqualsC(char expected, char actual, string testDescription);
  bool char_equals(char x, char y);
  void assertEqualsB(bool expected, bool actual, string testDescription);
  void printBST();
  void printBSTHelper(Player::Card* z);
  
  
int main(){
  testCardgetSuit();
  testCardgetRank();
  testgetName();
  testdeleteCard();
  testmatch();
  testoperatorequals();
  printBST();
  testsuccessor();

  //call other test functions here
  return 0;
}

bool double_equals(double x, double y){
    return abs(x-y) < 0.001;
}

void startTestGroup(string groupName){
  cout << "-------- " << groupName << "---------" << endl;
}

// You may need to define other assertEquals functions for other types (this one is for double)
void assertEquals(double expected, double actual, string testDescription){
  if (double_equals(expected, actual)) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEqualsS(string expected, string actual, string testDescription){
  if (string_equals(expected, actual)) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}



bool string_equals(string x, string y){
    return x == y;
}

void assertEqualsC(char expected, char actual, string testDescription){
  if (char_equals(expected, actual)) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

bool char_equals(char x, char y){
    return x == y;
}

void assertEqualsB(bool expected, bool actual, string testDescription){
	  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}
	

void testCardgetSuit(){
  startTestGroup("getSuit");		    
  
  //SET UP STATISTICIANS NEEDED FOR TESTS
  Player::Card c1('h', '2'), c2('d','a'),c3;

  //RUN TESTS BY CALLING ASSERT EQUALS
  assertEqualsC('h', c1.getSuit(), "normal case");
  assertEqualsC('d', c2.getSuit(), "normal case");
  assertEqualsC(' ', c3.getSuit(), "empty Card");
}
void testgetName(){
  startTestGroup("get name");		    
  
  //SET UP STATISTICIANS NEEDED FOR TESTS
  Player p1("swag"),p2("swaggy");

  //RUN TESTS BY CALLING ASSERT EQUALS
  assertEqualsS("swag", p1.getName(), "normal case");
  assertEqualsS("swaggy", p2.getName(), "normal case");
}
void testCardgetRank(){
  startTestGroup("getRank");		    
  
  //SET UP STATISTICIANS NEEDED FOR TESTS
  Player::Card c1('h', '2'), c2('d','a'),c3;
  //RUN TESTS BY CALLING ASSERT EQUALS
  assertEqualsC('2', c1.getRank(), "normal case");
  assertEqualsC('a', c2.getRank(), "normal case");
  assertEqualsC(' ' , c3.getRank(), "empty Card");
}

void testdeleteCard(){
	startTestGroup("deleteCard");
	Player alice;
	Player bob;
	Player obama;
	Player master;
	Player::Card c1('h', '2'), c2('d','a'),c3('s','6'), c4('h','7'),c5('c','6'),
	c6('c','k'),c7('d','j'); //cdsh
	Player::Card ca1('c','2'),ca2('d','a'),ca3('h','1'),ca4('c','3'),ca5('d','j'),ca6('s','1'),ca7('h','a');
	Player::Card cb1('h','3'), cb2('s','1'), cb3('c','a'),cb4('c','3'),cb5('s','5'),cb6('h','1'),cb7('d','a'),cb8('h','j'),cb9('h','q');
	Player::Card cm1('c','2'), cm2('d','a'), cm3('h','1'),cm4('c','3'),cm5('d','j'),cm6('s','1'),cm7('h','a'),cm8('h','j'),cm9('h','k'),cm10('h','k');
	alice.add(c1);
	alice.add(c2);
	alice.add(c3);
	alice.add(c4);
	alice.add(c5);
	alice.add(c6);
	bob.add(ca1);
	bob.add(ca2);
	bob.add(ca3);
	bob.add(ca4);
	bob.add(ca5);
	bob.add(ca6);
	bob.add(ca7);
	obama.add(cb1);
	obama.add(cb2);
	obama.add(cb3);
	obama.add(cb4);
	obama.add(cb5);
	obama.add(cb6);
	obama.add(cb7);
	obama.add(cb8);
	obama.add(cb9);
	master.add(cm1);
	master.add(cm2);
	master.add(cm3);
	master.add(cm4);
	master.add(cm5);
	master.add(cm6);
	master.add(cm7);
	master.add(cm8);
	master.add(cm9);
	cout<<"master pre-order"<<endl;
	master.printPreOrder(*master.getRoot());
	cout<<"Master match"<<endl;
	master.deleteCard(cm4);
	cout<<"master pre-order qwerty"<<endl;
	master.printPreOrder(*master.getRoot());
	cout<<"master pre-order"<<endl;
	master.printBSTHelper(master.getRoot());
	master.deleteCard(cm2);
	cout<<"master pre-order qwerty"<<endl;
	master.printPreOrder(*master.getRoot());
	cout<<"master pre-order"<<endl;
	master.printBSTHelper(master.getRoot());
	master.deleteCard(cm6);
	cout<<"master pre-order qwerty"<<endl;
	master.printPreOrder(*master.getRoot());
	cout<<"master pre-order"<<endl;
	master.printBSTHelper(master.getRoot());
	master.deleteCard(cm3);
	cout<<"master pre-order after"<<endl;
	master.printPreOrder(*master.getRoot());
	cout<<"master in order"<<endl;
	master.printBSTHelper(master.getRoot());
	/*cout<<cm1.right->right->parent->parent->parent->getValue()<<endl;
	cout<<cm1.right->right->parent->parent->getValue()<<endl;
	cout<<cm1.right->left->parent->parent->getValue()<<endl;*/
	master.deleteCard(cm8);
	cout<<"master pre-order qwerty"<<endl;
	master.printPreOrder(*master.getRoot());
	cout<<"master pre-order"<<endl;
	master.printBSTHelper(master.getRoot());
	master.deleteCard(cm9);
	cout<<"master pre-order qwerty"<<endl;
	master.printPreOrder(*master.getRoot());
	cout<<"master pre-order"<<endl;
	master.printBSTHelper(master.getRoot());
	/*printBSTHelper(alice.getRoot());
	cout<<endl;
	alice.deleteCard(c2);//101
	alice.deleteCard(c5);
	printBSTHelper(alice.getRoot());
	cout<<endl;
	printBSTHelper(bob.getRoot());
	cout<<endl;
	bob.deleteCard(ca4);
	bob.deleteCard(ca2);
	bob.deleteCard(ca6);
	bob.deleteCard(ca3);
	printBSTHelper(bob.getRoot());
	cout<<endl;
	printBSTHelper(obama.getRoot());
	cout<<endl<<"obama"<<endl;
	//obama.deleteCard4(cb4);
	obama.deleteCard(cb4);
	obama.deleteCard(cb7);
	obama.deleteCard(cb2);
	obama.deleteCard(cb6);
	obama.deleteCard(cb8);
	obama.deleteCard(cb9);
	printBSTHelper(obama.getRoot());
	cout<<endl;*/
}
void printBST() {
	Player alice, bob;
	startTestGroup("printBST in-order");
	Player::Card c1('h', '2'), c2('d','a'),c3('s','6'), c4('h','7'),c5;
	Player::Card cp1('d', '2'), cp2('d','a'),cp3('s','6'), cp4('h','7'),cp5;
	alice.add(c1);
	alice.add(c2);
	alice.add(c3);
	alice.add(c4);
	bob.add(cp1);
	bob.add(cp2);
	bob.add(cp3);
	bob.add(cp4);
	cout<<"Alice"<<endl;
	printBSTHelper(alice.getRoot());
	cout<<"BOB"<<endl;
	printBSTHelper(bob.getRoot());
	return;
}
void printBSTHelper(Player::Card* z){
	if(z){
		printBSTHelper(z->left);
		cout<<z->getSuit()<<" "<<z->getRank()<<endl;
		printBSTHelper(z->right);
	}
}
	
void testmatch(){
	startTestGroup("test match");
	Player alice;
	Player obama;
	Player master;
	Player::Card c1('h', '2'), c2('d','a'),c3('s','6'), c4('h','7'),c5;
	Player::Card cp1('d', '2'), cp2('d','a'),cp3('s','6'), cp4('h','7'),cp5('h','9');
	Player::Card cb1('h','3'), cb2('s','1'), cb3('c','a'),cb4('c','3'),cb5('s','5'),cb6('h','1'),cb7('d','a'),cb8('h','j'),cb9('h','q');
	Player::Card cm1('c','2'), cm2('d','a'), cm3('h','1'),cm4('c','3'),cm5('d','j'),cm6('s','1'),cm7('h','a'),cm8('h','j'),cm9('h','q'),cm10('h','k');
	//Player::Card c99('c','4');
	/*alice.add(c1);
	alice.add(c2);
	alice.add(c3);
	alice.add(c4);
	alice.add(c5);
	obama.add(cb1);
	obama.add(cb2);
	obama.add(cb3);
	obama.add(cb4);
	obama.add(cb5);
	obama.add(cb6);
	obama.add(cb7);
	obama.add(cb8);
	obama.add(cb9);*/
	master.add(cm1);
	master.add(cm2);
	master.add(cm3);
	master.add(cm4);
	master.add(cm5);
	master.add(cm6);
	master.add(cm7);
	//master.add(c99);
	master.add(cm8);
	master.add(cm9);
	master.add(cm10);
	bool a,b,c,d,e,f,g,h;
	/*Player::Card* qr = alice.getRoot();
	Player::Card* q = &cp4;
	a = alice.match(cp1);
	b = alice.match(cp2);
	c = alice.match(*q);
	d = alice.match(cp4);
	e = alice.match(*q);
	f = alice.match(*qr);
	g = alice.match(*qr);
	h = alice.match(cp5);*/
	bool a1,b1,cc1,d1,e1,f1,g1;
	a1 = obama.match(cb4);
	b1 = obama.match(cb7);
	d1 = obama.match(cb2);
	e1 = obama.match(cb6);
	f1 = obama.match(cb8);
	bool a2,b2,cc2,d2,e2,f2,g2;
	cout<<"master pre-order"<<endl;
	master.printPreOrder(*master.getRoot());
	cout<<"Master match"<<endl;
	a2 = master.match(cm4);
	cout<<"master pre-order qwerty"<<endl;
	master.printPreOrder(*master.getRoot());
	cout<<"master pre-order"<<endl;
	master.printBSTHelper(master.getRoot());
	b2 = master.match(cm2);
	cout<<"master pre-order qwerty"<<endl;
	master.printPreOrder(*master.getRoot());
	cout<<"master pre-order"<<endl;
	master.printBSTHelper(master.getRoot());
	d2 = master.match(cm6);
	cout<<"master pre-order qwerty"<<endl;
	master.printPreOrder(*master.getRoot());
	cout<<"master pre-order"<<endl;
	master.printBSTHelper(master.getRoot());
	e2 = master.match(cm3);
	cout<<"master pre-order after"<<endl;
	master.printPreOrder(*master.getRoot());
	cout<<"master in order"<<endl;
	master.printBSTHelper(master.getRoot());
	f2 = master.match(cm8);
	cout<<"master pre-order qwerty"<<endl;
	master.printPreOrder(*master.getRoot());
	cout<<"master pre-order"<<endl;
	master.printBSTHelper(master.getRoot());
	master.match(cm9);
	cout<<"master pre-order qwerty"<<endl;
	master.printPreOrder(*master.getRoot());
	cout<<"master pre-order"<<endl;
	master.printBSTHelper(master.getRoot());
	master.match(cm10);
	cout<<"master pre-order qwerty"<<endl;
	master.printPreOrder(*master.getRoot());
	cout<<"master pre-order"<<endl;
	master.printBSTHelper(master.getRoot());
	/*
	assertEqualsB(false, a, "normal case");
	assertEqualsB(true, b, "normal case");
	assertEqualsB(true, c, "normal case");
	assertEqualsB(false, d, "normal case");
	assertEqualsB(false, e, "normal case");
	assertEqualsB(true, f, "normal case");
	assertEqualsB(false, g, "normal case");
	assertEqualsB(false, h, "normal case");
	assertEqualsB(true, a1, "normal case");
	assertEqualsB(true, b1, "normal case");
	assertEqualsB(true, d1, "normal case");
	assertEqualsB(true, e1, "normal case");
	assertEqualsB(true, f1, "normal case");
	printBSTHelper(obama.getRoot());
	cout<<endl;
	assertEqualsB(true, a2, "normal case");
	assertEqualsB(true, b2, "normal case");
	assertEqualsB(true, d2, "normal case");
	assertEqualsB(true, e2, "normal case");
	assertEqualsB(true, f2, "normal case");
	Player::Card* bb = master.getRoot();
	while(bb->right){
		cout<<bb->getValue()<<endl;
		bb = bb->right;
	}
	printBSTHelper(master.getRoot());
	cout<<endl;
	*/
}
void testsuccessor(){
	startTestGroup("test successor");
	Player alice;
	Player bob;
	Player::Card c1('h', '2'), c2('d','a'),c3('s','6'), c4('h','7'),c5('c',9);
	Player::Card cp1('h','3'), cp2('s','1'), cp3('c','a'), cp4('c','3'), cp5('s','5'), cp6('h','1'), cp7('d','a');
	alice.add(c1);
	alice.add(c2);
	alice.add(c3);
	alice.add(c4);
	alice.add(c5);
	bob.add(cp1);
	bob.add(cp2);
	bob.add(cp3);
	bob.add(cp4);
	bob.add(cp5);
	bob.add(cp6);
	bob.add(cp7);
	int a,b,c,d,e,f;
	a= (alice.successor(c1))->getValue();
	b = (alice.successor(c2))->getValue();
	c = (alice.successor(c3))->getValue();
	e = (alice.successor(c5))->getValue();
	f = (bob.successor(cp1))->getValue();
	assertEquals(307, a, "normal case");
	assertEquals(206, b, "normal case");
	assertEquals(302, c, "normal case");
	assertEquals(101, e, "normal case");
	assertEquals(310, f, "normal case");
}
void testoperatorequals() {
	startTestGroup("test equals");
	Player::Card c1('h', '2'), c2('d','a'),c3('s','6'), c4('h','7'),c5;
	Player::Card cp1('d', '2'), cp2('d','a'),cp3('s','6'), cp4('h','7'),cp5;
	bool a,b,c,d,e;
	a = (c1 == cp1);
	b = (c2 == cp2);
	c = (c3 == cp3);
	d = (c4 == cp4);
	e = (c5 == cp5);
	assertEqualsB(a, false, "normal case");
	assertEqualsB(b, true, "normal case");
	assertEqualsB(c, true, "normal case");
	assertEqualsB(d, true, "normal case");
	assertEqualsB(e, true, "normal case");
}
	
/*void testStatisticianSum() {
  startTestGroup("SUM");
  statistician s5, s6;
  s5.next(8.1);
  s5.next(2.4);
  s5.next(3.2);
  s5.next(5.2);
  s5.next(1.3);
  s5.next(1.6);
  s5.next(-10.2);

  assertEquals(11.6, s5.sum(), "normal case");
  assertEquals(0, s6.sum(), "empty statistician");
}*/