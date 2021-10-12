#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

void second_pass(vector<string>& parsed_file, vector<string>& symbol_table){

    //Variables
    string temp;
    string instr;
    int n = 16;
    bool is_on_table;
    int pos;
    int dec;
    vector<string> bin_number;
    int remainder;
    string converted_number;
    string jump;
    string jump_code;
    string dest;
    string dest_code;
    bool is_eq;
    bool is_semicolon;
    int pos_eq;
    int pos_semicolon;
    string comp;
    string comp_code;
    /*vector<string> jump_vec;
    vector<string> dest_vec;
    vector<string> comp_vec;*/

    //Inserting variables in symbol  table
    for(int i = 0; i < parsed_file.size();i++){
        temp = parsed_file[i];
        instr = "";
        if(temp[0] == '@'){
            for(int j = 1; j < temp.size();j++){
                instr = instr+temp[j];
            }

            //Detect if variable is already on table
            for (int k = 0; k < symbol_table.size(); k++){
                if(instr == symbol_table[k]){
                    is_on_table = true;
                    pos = k;
                    break;
                }
                else is_on_table = false;
            }

            //If variable is on table: write on file @position_on_symbol_table
            //If variable is not on table: write on file @n, write variable in symbol_table[n]
            if(is_on_table == true){
                parsed_file[i] = '@'+to_string(pos);
            }

            else if(is_on_table == false && symbol_table[pos] != "" && instr[0] != '0' && instr[0] != '1' && instr[0] != '2' && instr[0] != '3' && instr[0] != '4' && instr[0] != '5' && instr[0] != '6' && instr[0] != '7' && instr[0] != '8' && instr[0] != '9' && instr != "SCREEN" && instr != "KBD"){
                parsed_file[i] = '@'+to_string(n);
                symbol_table[n] = instr;
                n++;
            }
        }
    }

    //Converting A instructions to binary
    for(int i = 0; i < parsed_file.size();i++){
        temp = parsed_file[i];
        instr = "";
        converted_number = "";
        if(temp[0] == '@'){
            for(int j = 1; j < temp.size();j++){
                instr = instr+temp[j];
            }

            //Converting address to binary
            dec = stoi(instr);
            if (dec == 0){                                          //If the number is 0, convert 0 to string and stores on list
                converted_number = (to_string(dec));
            }
            else{
                while(dec != 0){                                     //Else, convert the number from decimal to binary
                  remainder = dec%2;
                  converted_number = converted_number+to_string(remainder);
                  dec = dec/2;
                }
            }

            //Checking if binary have 16 bits
            while(converted_number.size() < 16){
                converted_number = converted_number+'0';
            }

            //Inverting binary number to correct form
            for (int j = 0; j < 16 / 2; j++){                                           //Reverse string starting in
                swap(converted_number[j], converted_number[16 - j - 1]);                //two corners
            }
            parsed_file[i] = converted_number;
        }
    }

    //Converting C instructions to binary; dest=comp;jump
    //Jump
    for(int i = 0; i < parsed_file.size();i++){
        temp = parsed_file[i];
        if(temp.size() < 16){
            jump = "";
            for(int j = 0; j < temp.size();j++){
                if(temp[j] == ';'){
                    for(int k = j+1; k < temp.size();k++){
                        jump = jump+temp[k];
                    }
                }
            }

            if(jump == "JGT"){
                jump_code = "001";
            }
            else if(jump == "JEQ"){
                jump_code = "010";
            }
            else if(jump == "JGE"){
                jump_code = "011";
            }
            else if(jump == "JLT"){
                jump_code = "100";
            }
            else if(jump == "JNE"){
                jump_code = "101";
            }
            else if(jump == "JLE"){
                jump_code = "110";
            }
            else if(jump == "JMP"){
                jump_code = "111";
            }
            else jump_code = "000";

        }


    //Dest

        temp = parsed_file[i];
        if(temp.size() < 16){
            dest = "";
            for(int j = 0; j < temp.size();j++){
                if(temp[j] == '='){
                    for(int k = 0; k < j; k++){
                        dest = dest+temp[k];
                    }
                }
            }

            if(dest == "M"){
                dest_code = "001";
            }
            else if(dest == "D"){
                dest_code = "010";
            }
            else if(dest == "MD"){
                dest_code = "011";
            }
            else if(dest == "A"){
                dest_code = "100";
            }
            else if(dest == "AM"){
                dest_code = "101";
            }
            else if(dest == "AD"){
                dest_code = "110";
            }
            else if(dest == "AMD"){
                dest_code = "111";
            }
            else dest_code = "000";

        }


    //Comp

        temp = parsed_file[i];
        if(temp.size() < 16){
            comp = "";
            is_eq = false;
            is_semicolon = false;
            for(int j = 0; j < temp.size();j++){
                if(temp[j] == '='){
                    is_eq = true;
                    pos_eq = j;
                }
                else if(temp[j] == ';'){
                    is_semicolon = true;
                    pos_semicolon = j;
                }
            }
            if(is_eq == true && is_semicolon == false){
                for(int k = pos_eq+1; k < temp.size();k++){
                    comp = comp+temp[k];
                }
            }
            else if(is_eq == false && is_semicolon == true){
                for(int k = 0; k < pos_semicolon;k++){
                    comp = comp+temp[k];
                }
            }
            else if(is_eq == true && is_semicolon == true){
                for(int k = pos_eq+1; k < pos_semicolon;k++){
                    comp = comp+temp[k];
                }
            }

            if(comp == "0"){
                comp_code = "0101010";
            }
            else if(comp == "1"){
                comp_code = "0111111";
            }
            else if(comp == "-1"){
                comp_code = "0111010";
            }
            else if(comp == "D"){
                comp_code = "0001100";
            }
            else if(comp == "A"){
                comp_code = "0110000";
            }
            else if(comp == "!D"){
                comp_code = "0001101";
            }
            else if(comp == "!A"){
                comp_code = "0110001";
            }
            else if(comp == "-D"){
                comp_code = "0001111";
            }
            else if(comp == "-A"){
                comp_code = "0110011";
            }
            else if(comp == "D+1"){
                comp_code = "0011111";
            }
            else if(comp == "A+1"){
                comp_code = "0110111";
            }
            else if(comp == "D-1"){
                comp_code = "0001110";
            }
            else if(comp == "A-1"){
                comp_code = "0110010";
            }
            else if(comp == "D+A"){
                comp_code = "0000010";
            }
            else if(comp == "D-A"){
                comp_code = "0010011";
            }
            else if(comp == "A-D"){
                comp_code = "0000111";
            }
            else if(comp == "D&A"){
                comp_code = "0000000";
            }
            else if(comp == "D|A"){
                comp_code = "0010101";
            }
            else if(comp == "M"){
                comp_code = "1110000";
            }
            else if(comp == "!M"){
                comp_code = "1110001";
            }
            else if(comp == "-M"){
                comp_code = "1110011";
            }
            else if(comp == "M+1"){
                comp_code = "1110111";
            }
            else if(comp == "M-1"){
                comp_code = "1110010";
            }
            else if(comp == "D+M"){
                comp_code = "1000010";
            }
            else if(comp == "D-M"){
                comp_code = "1010011";
            }
            else if(comp == "M-D"){
                comp_code = "1000111";
            }
            else if(comp == "D&M"){
                comp_code = "1000000";
            }
            else if(comp == "D|M"){
                comp_code = "1010101";
            }
            parsed_file[i] = "111"+comp_code+dest_code+jump_code;
        }
    }
}
