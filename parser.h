#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "inventory.h"
#include "trie.h"

using namespace std;

/**
 * parse_file() - function that parses a file
 * @inventory_file: name of the file we want to open
 * @name: Trie that defines the name of the object
 * @code: Trie that defines the unique code of the object
 * @type: Trie that defines the type of the object 
 */ 
void parse_file(string& inventory_file);

/**
 * read_word() - function that allows us to read the file word by word

 */
void read_word();

/**
 * read_character() - function that allows us to read the file word by word

 */

void read_character();


#endif
