#include "parser.h"
#include "trie.h"
#include "inventory.h"

// Define functions

/**
 * @initialise(): Init the three Trie trees with the content from the file
 */


// Chercher un objet


int main(){

	inventory_t item1;

	Trie trie;
	string word1 = "word", word2 = "wora", word3 = "wora";

	trie.insert(word1);
	cout << "========================================================" << endl;
	trie.insert(word2);
	cout << "========================================================" << endl;
	trie.insert(word3);


	// cout << trie;

        return 0;
}
