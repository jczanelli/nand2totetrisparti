#include <string>
#include <vector>

#include <iostream>

using namespace std;

void first_pass(vector<string> &parsed_file){

    //Variables
    string temp;
    string label;
    vector<string> labellist;
    int line_number = 0;
    vector<string> label_pos;

    //Find all (LABELS) and store them inside list
    for(int i = 0; i < parsed_file.size();i++){
        temp = parsed_file[i];
        label = "";
        if(temp[0] == '('){
            for(int j = 0; j < temp.size();j++){
                if(temp[j] == ')'){
                    for(int k = 1; k < j;k++){
                        label = label+temp[k];
                    }
                    labellist.push_back(label);
                    label_pos.push_back(to_string(line_number));
                }
            }
        }
        else line_number++;     //Increment only if line is not (LABEL)
    }

    //Find @LABEL on parsed_file vector and change them for line number reference
    line_number = 0;
    for(int i = 0; i < parsed_file.size();i++){
        for(int j = 0; j < labellist.size();j++){
            if(parsed_file[i] == ('@'+labellist[j])){
                parsed_file[line_number] = '@'+label_pos[j];
            }
        }
        line_number++;
    }

    //Deleting (LABELS)
    for(int i = 0; i < parsed_file.size();i++){
        temp = parsed_file[i];
        if(temp[0] == '('){
            parsed_file.erase(parsed_file.begin()+i);
        }
    }
}
