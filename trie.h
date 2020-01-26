#ifndef TRIE_H
#define TRIE_H

// #include <cstdlib>
#include "inventory.h"
#include <string>
#include <memory>
#include <vector>
using namespace std;

/**
   Structure:
   ---------------
   @state_t: structure representing a node of the trie tree

   @child:
   @letter: represents the character that is held by the current state
   @isEndOfWord: indicates if state is recognised by automaton
   @nTerminals: indicates number of words recognised by the current state (duplicate words ..)
   @inventory: Indicates all the objects that are held up to this state. The further we progress
   into the tree and pass terminal states, the more the inventory grows


*/

struct state_t {

        vector<shared_ptr<state_t>> children;
        char letter;
        bool isEndOfWord;
        unsigned int nTerminals;
        inventory_t inventory;
};


/**

   @start: root of the whole trie

*/

class Trie {
public:
        Trie();
	void insert(string& word);
        void insert(string& word, int index, shared_ptr<state_t> node);
        void search(string);

	friend ostream& operator<<(ostream& os, const Trie& trie);

        // attributes
        shared_ptr<state_t> start;

};


// Shared pointers
/*
  C    There is CAR and CARS, multiple pointers on letters C, A and R
  |
  A
  |
  R
  |
  S




*/

/* General Idea


   current is a TrieNode.

   while(string.length)
   {
   if(current.doesNotExist){
   createNewTrieNode
   }

   current.next();

   }

   current.isEndOfWord = true;

*/

#endif
