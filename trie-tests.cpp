#include "parser.h"
#include "trie.h"
#include "inventory.h"

// Define functions

/**
 * @initialise(): Init the three Trie trees with the content from the file
 */


// Chercher un objet


int main(){

	// INSERT TESTING ----------------------------------------------------------
	Trie trie;
	string word1 = "boko", word2 = "baka", word3 = "bok", word4 = "boko";


	cout << "Inserting word: " << word1 << endl;
	cout << endl;
	trie.insert(word1);
	cout << "========================================================" << endl;
	cout << "Inserting word: " << word2 << endl;
	cout << endl;
	trie.insert(word2);
	cout << "========================================================" << endl;
	cout << "Inserting word: " << word3 << endl;
	trie.insert(word3);
	cout << "========================================================" << endl;
	cout << "Inserting word: " << word4 << endl;
	trie.insert(word4);

	// SEARCH TESTING ----------------------------------------------------------

	//cout << "Searching for word: " << word3 << endl;
	//trie.search(word3, trie.start);


        return 0;
}
