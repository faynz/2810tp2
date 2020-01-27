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
	string word1 = "word", word2 = "bala";

	trie.insert(word1);
	//trie.print(trie.start);

	cout << "Size of vector start after insertion of first word: " << trie.start.size() << endl;
	trie.insert(word2);


	// cout << trie;

        return 0;
}
