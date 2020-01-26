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

// insert will take in the child's vector (children)
void Trie::insert(string& word, int index, vector<shared_ptr<state_t>> nodes){


	// Gotta loop till I find the first nullptr and make it equal to whichchild!!!!**********
	// Must be done everytime, if found its equal to i, if not found its equal to position of first null ptr in the vector(nodes.size() after I already pushed back)
	int whichchild;

	// Condition check (keep inserting or not)
	while (index < word.length()){


		// Print tests
		cout << "Index: " << index << endl;
		cout << "Letter: " << word[index] << endl;

		// (Has to be reset each time )
		bool found = false;


		// #1: Compare node and string's letter
		cout << "nodes size = " << nodes.size() << endl;
		for(unsigned int i=0; i < nodes.size(); i++){
			if (word[index] == nodes[i]->letter){
				int whichchild = i; // Indicates which child we are passing when insert is called
				cout << "whichchild after being found = " << whichchild << endl;
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
			cout << "Letter of new node: " << nodes[index]->letter << endl;

			/// continu insertion
			++index;
			// insert(word, index, nodes[nodes.size()]->children);

		}

		if(found == true){

			// continu insertion
			++index;
			// insert(word, index, nodes[whichchild]->children);
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
