#include "parser.h"

void parse_file(string& inventory_file){

        // ifstream in(inventory_file); // expression in brackets must be in("string") and not in(string)
        
        ifstream in;
        in.open(inventory_file);

        if(in.fail()){
                cerr << "Error" << endl;
                // return false;
                // exit(1);
        }
        
        // return false;
        
        while(!in.eof())
        {
                string line, nom, code, type;
                stringstream ss;
                
                getline(in, line);        
                ss << line;
                
                ss >> nom  >> code >> type;
                cout << "Nom: " << nom 
                     << " Code: " << code
                     << " Type: " << type 
                     << endl;                
        }

        in.close();
        
        // return true;

}

void read_word(string& inventory_file ){

        
                
}


void read_character(){


}
