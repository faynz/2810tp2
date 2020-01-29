#include "trie.h"

Trie::Trie(){

	for(unsigned int i = 0; i < start.size(); i++)
		start[i] = nullptr;
}


void Trie::insert(string& word){
	insert(word, 0, start);
}

// insert will take in the child's vector (children)
void Trie::insert(string& word, int index, vector<shared_ptr<state_t>>& nodes){

	// Indicates which child we are passing when insert is called
	int whichchild;

	// Condition check (keep inserting or not)
	if (index < word.length()){

		// Print tests
		cout << "Inserting word : " << word << endl;
		cout << "word[index] =  " << index << endl;
		cout << "Letter to be insert: " << word[index] << endl;

		// (Has to be reset each time )
		bool found = false;

		// #1: Compare node and string's letter
		cout << "nodes size = " << nodes.size() << endl;

		for(unsigned int i=0; i < nodes.size(); i++){
			if (word[index] == nodes[i]->letter){
				whichchild = i;
				cout << "In for loop, letter matched at index  = " << whichchild << " (Whichchild)" << endl;
				found = true;
			}
		}

		// #2: State existed or not?

		cout << "found = " << found << endl;

		if(found == false) {

			// Create new node
			shared_ptr<state_t> ptr (new state_t());
			ptr->letter = word[index];
			ptr->nTerminals = 0;
			ptr->isEndOfWord = false;

			nodes.push_back(ptr);

			// Test
			// cout << "Entered false" << endl;
			// cout << endl;

			/// continu insertion
			++index;
			insert(word, index, nodes[nodes.size()-1]->children);

		}

		if(found == true){

			// Test
			// cout << "Entered true" << endl;
			// cout << endl;

			// continu insertion
			++index;
			insert(word, index, nodes[whichchild]->children);
		}
	}
}


/*
 * ostream& operator<<(ostream& os, const Trie& trie){
 *
 * 	state_t* current = trie.start;
 *
 *
 *
 * 	return ;
 *
 * }
 */


/*
 * void Trie::print(shared_ptr<state_t> node){
 *
 * 	if(node != nullptr){
 * 		cout << node->letter << endl;
 * 		if(node->children.size() != 0){
 * 			print(node->children[0]);
 * 		}
 * 	} else {
 * 		cout << "End of word" << endl;
 * 	}
 *
 * }
 */
