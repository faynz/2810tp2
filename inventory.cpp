#include "inventory.h"

bool inventory_contains(inventory_t& inventory, string search_code){
	for(int i = 0; i < inventory.size(); i++){
		if(inventory[i]->code == search_code){
			return true;
		}
	}

	return false;
}

void inventory_add_object(inventory_t inventory, object_t object){

// #1 method
// Will initialise a pointer to an object by default
	inventory.push_back(make_shared<object_t>());

	inventory[inventory.size() - 1]->type = object.type;
	inventory[inventory.size() - 1]->code = object.code;
	inventory[inventory.size() - 1]->name = object.name;

// #2 method
/*
 * shared_ptr<object_t> ptr = make_shared<object_t>();
 *
 * ptr->type = object.type;
 * ptr->code = object.code;
 * ptr->name = object.name;
 *
 * inventory.push_back(ptr);
 */


}
