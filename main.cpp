#include <iostream>
#include <string>
#include <vector>
#include "header.hpp"

using namespace std;

int main()
{
    //Variables
    vector<string> p_file;
    vector<string> s_table;

    p_file = parser();

    vector<string>& parsed_file = p_file;
    /*
    cout << "Parsed file:" << "\n";
    for(int i = 0; i <parsed_file.size(); i++){
        cout << "Linha " << i << ": " << parsed_file[i] << "\n";
    }
    */

    s_table = symbol_table(parsed_file);

    vector<string>& sym_table = s_table;
    /*
    for(int i = 0; i < sym_table.size(); i++){
        if(sym_table[i] != ""){
            cout << sym_table[i] << "\n";
        }
    }
    */

    first_pass(parsed_file);
    /*
    cout << "First pass:" << "\n";
    for(int i = 0; i <parsed_file.size(); i++){
        cout << "Linha " << i << ": " << parsed_file[i] << "\n";
    }*/


    second_pass(parsed_file,sym_table);

    cout << "Second Pass:" << "\n";
    for(int i = 0; i <parsed_file.size(); i++){
        cout << "Linha " << i << ": " << parsed_file[i] << "\n";
    }
/*
    cout << "Symbol  table:" << "\n";
    for(int i = 0; i < sym_table.size(); i++){
        if(sym_table[i] != ""){
            cout << "Linha " << i << ": " << sym_table[i] << "\n";
        }
    }*/

    write_file(parsed_file);
    return 0;
}
