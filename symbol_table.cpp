#include <vector>
#include <string>

using namespace std;

vector<string> symbol_table(vector<string> parsed_file){

    //Variables
    vector<string> var_table(32767);
    vector<string> spc_table(5);

    //Initialize symbol table with pre-defined values
    var_table[0] = "R0";
    var_table[1] = "R1";
    var_table[2] = "R2";
    var_table[3] = "R3";
    var_table[4] = "R4";
    var_table[5] = "R5";
    var_table[6] = "R6";
    var_table[7] = "R7";
    var_table[8] = "R8";
    var_table[9] = "R9";
    var_table[10] = "R10";
    var_table[11] = "R11";
    var_table[12] = "R12";
    var_table[13] = "R13";
    var_table[14] = "R14";
    var_table[15] = "R15";
    var_table[16384] = "SCREEN";
    var_table[24576] = "KBD";
    for(int i = 16; i < var_table.size();i++){      //Initialize rest of positions of symbol table
        if((i != 16384) && (i != 24576)){
            var_table[i] = "";
        }
    }

    //Pre-defined values for special table
    spc_table[0] = "SP";
    spc_table[1] = "LCL";
    spc_table[2] = "ARG";
    spc_table[3] = "THIS";
    spc_table[4] = "THAT";

    return var_table;
}
