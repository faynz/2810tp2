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
		cout << "word[index] =  " << index << endl;
		cout << "Letter to be inserted: " << word[index] << endl;

		// (Has to be reset each time )
		bool found = false;

		// #1: Compare node and string's letter
		//cout << "nodes size = " << nodes.size() << endl;

		for(unsigned int i=0; i < nodes.size(); i++){
			if (word[index] == nodes[i]->letter){
				whichchild = i;
				found = true;
			}
		}

		// Test
		cout << "found = " << found << endl;
		cout << endl;

		// #2: State existed or not?
		if(found == false) {

			// Create new node
			shared_ptr<state_t> ptr (new state_t());
			ptr->letter = word[index];

			// Mark last node as EndOfWord and set nTerminals
			if((word.length()-1) == index){
				ptr->isEndOfWord = true;
				ptr->nTerminals = 1; // Hasn't been found yet so needs to be set (can't do ++nTerminals)
			}else{
				ptr->isEndOfWord = false; // PROBLEM HERE FIX
				ptr->nTerminals = 0;
			}

			// Test
			cout << "Entered false" << endl;
			cout << endl;

			// Test: print node info
			cout << "Letter: " << ptr->letter << endl;
			cout << "isEndOfWord: " << ptr->isEndOfWord << endl;
			cout << "nTerminals: " << ptr->nTerminals << endl;
			cout << endl;

			// Add node to children
			nodes.push_back(ptr);


			/// continu insertion
			++index;
			insert(word, index, nodes[nodes.size()-1]->children);

		}

		if(found == true){

			// Mark last node as EndOfWord
			if((word.length()-1) == index){
				nodes[whichchild]->isEndOfWord = true;
				++nodes[whichchild]->nTerminals;
			}
			
			// Test
			cout << "Entered true" << endl;
			cout << endl;

			// Test: print node info
			cout << "Letter: " << nodes[whichchild]->letter << endl;
			cout << "isEndOfWord: " << nodes[whichchild]->isEndOfWord << endl;
			cout << "nTerminals: " << nodes[whichchild]->nTerminals << endl;
			cout << endl;

			// continu insertion
			++index;
			insert(word, index, nodes[whichchild]->children);
		}
	}
}


// Will return true for a shorter word (need to put terminal states in insert and validate)
bool Trie::search(string& word, vector<shared_ptr<state_t>>& nodes_vector){

	for(int i = 0; i < word.length(); i++){

		// Test
		cout << "i = " << i << endl;
		// Reset found
		bool found = false;

		for(unsigned int j = 0; j < nodes_vector.size(); j++){

			// Test comparison ?
			cout << "Vector letter : " << nodes_vector[j]->letter << endl;
			cout << "String letter : " << word[i] << endl;

			if(nodes_vector[j]->letter == word[i]){

				// Test
				cout << "Letter " << word[i] << " was found, continuing search" << endl;

				// continu search
				found = true;
				nodes_vector = nodes_vector[j]->children;
				break;
			}

		}

		// If found is still false after looping through all nodes, return false;
		if(found == false){

			cout << "Returning false" << endl; // Test
			return false;
		}

	}

	cout << "Returning true" << endl; // Test

	return true;
}


//

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
