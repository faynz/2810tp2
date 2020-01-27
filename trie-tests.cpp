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
	string word = "word", wala = "wala";

	trie.insert(word);
	//trie.print(trie.start);

	cout << "Size of vector start after insertion of first word: " << trie.start.size() << endl;
	trie.insert(wala);


	// cout << trie;

        return 0;
}
