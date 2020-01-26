#include "trie.h"

Trie::Trie(){

	for(unsigned int i = 0; i < start.size(); i++)
		start[i] = nullptr;
}

/*
 * void Trie::insert(string& word){
 *         insert(word, 0, start);
 * }
 */


// Gotta start checking if we have reached the end of the word ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ THIS IS THE CONDITION THAT DEFINES WETHER WE KEEP CALLING INSERT OR NOT
// insert will take in the child's vector (children)
void Trie::insert(string& word, int index, vector<shared_ptr<state_t>> nodes){


        // i is used to iterate through children
	bool found = false;
	// If whichchild is equal to -1, we are not calling insert (double check)
	// Gotta loop till I find the first nullptr and make it equal to whichchild!!!!**********
	// Must be done everytime, if found its equal to i, if not found its equal to position of first null ptr in the vector
	int whichchild = -1;

	// Print tests
	cout << "Index: " << index << endl;
	cout << "Letter: " << word[index] << endl;
	cout << "(1) whichchild: " << whichchild << endl;



	// Condition check (keep inserting or not)
	while (index < word.length()){

		// This should include Case 1 (Vector is empty)
		// #1: Compare node and string's letter
		for(unsigned int i=0; i < nodes.size(); i++){

			if (word[index] == nodes[i]->letter){
				int whichchild = i; // Indicates which child we are passing when insert is called
				found = true;
			}
		}


		// #2: Node isn't found, created and push_back a new node
		if(found == false) {

			shared_ptr<state_t> ptr (new state_t());
			ptr->letter = word[index];
			ptr->nTerminals = 0;
			ptr->isEndOfWord = false;

			nodes.push_back(ptr);

		} else { // Node is found
			++index;
			cout << "(2) whichchild: " << whichchild << endl;
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
