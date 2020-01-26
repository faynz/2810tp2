#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
// #include <cstdlib> ???

using namespace std;

/*
 * object_t - Definition of an object
 * @type - type of the object
 * @code - unique string that identifies an object
 * @name - name of the object

 */

typedef struct{
	string type;
	string code;
	string name;
} object_t;


// using smart pointers ?
// Defining inventory
typedef vector<shared_ptr<object_t>> inventory_t;

// Verifies if specific inventory contains certain object using the object's code
bool inventory_contains(inventory_t, string search_code);

// Add an object to an inventory
void inventory_add_object(inventory_t, object_t);

#endif
