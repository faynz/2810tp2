#include "trie.h"

#ifndef TRIE_H
#define TRIE_H


Trie::Trie(){
        start->children = nullptr;
        start->isEndOfWord = false;
        start->nTerminals = 0;

}

void Trie::insert(string& word){
        insert(word, 0, start);
}


void Trie::insert(string& word, int index, shared_ptr<state_t> node){

        // i is used to iterate through children
        int i = 0;
        shared_ptr<state_t> current = node;
        bool found = false;

        // If the vector contains a pointer.
        if(current->children.size() != 0){
                // While the pointer isnt null, check if it's character is equal to the selected character of the string
                while(current->children[i] != nullptr){

                        if(current->children[i]->letter == string[index]){
                                found == true;
                                break;
                        } else {

				++i;
                        }
                }

		if(found == true){
                        ++index;
                        current = current->children[i]; // What happens if I assign a new pointer to the shared ptr **** Something might not work here
                        insert(word, index, current);
                } else {

                        // Missing the creation and push back of a new node
                        shared_ptr<state_t> ptr = new state_t;

                        // Assign
                        ptr->letter = string[index];
                        ptr->nTerminals = 0;
                        ptr->isEndOfWord = false;

                        current->children.push_back(ptr);

                }
        }
}
// The length of the string hasnt been considered yet



ostream& operator<<(ostream& os, const Trie& trie){

	state_t* current = trie.start;



	return ;

}

#endif
