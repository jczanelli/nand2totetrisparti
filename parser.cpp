#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

vector<string> parser(){

    //Variables
    ifstream file;
    string line;
    vector<string> contents;
    string tempString;

    //Open file
    //file.open("C:/Users/Juliano/Downloads/Coursera/Nand2Tetris Part I/Week 6/Project 06/add/Add.asm");
    //file.open("C:/Users/Juliano/Downloads/Coursera/Nand2Tetris Part I/Week 6/Project 06/max/Max.asm");
    file.open("C:/Users/Juliano/Downloads/Coursera/Nand2Tetris Part I/Week 6/Project 06/max/MaxL.asm");
    //file.open("C:/Users/Juliano/Downloads/Coursera/Nand2Tetris Part I/Week 6/Project 06/pong/Pong.asm");
    //file.open("C:/Users/Juliano/Downloads/Coursera/Nand2Tetris Part I/Week 6/Project 06/rect/Rect.asm");

    //Checks if file exists and remove lines which begin with /, * (comments) and blank lines
    if(file.is_open()){
            while(getline(file,line)){
                    if((line[0] != '/')&&(line[0] != '*')&&(line != "")){
                        contents.push_back(line);
                    }
            }

    }
    else cout << "Could not find file in specified location.";


    //Change comments in the same line as code to blank spaces which are removed in next step
    for(int i = 0; i < contents.size();i++){
        tempString = contents[i];
        for(int j = 0; j < tempString.size();j++){
            if((tempString[j] == '/') || (tempString[j] == '*')){
                    for(int k = j; k < tempString.size();k++){
                        tempString[k] = ' ';
                    }
            }
        }
        contents[i] = tempString;
    }

    //Remove blank spaces
    for(int i =0; i < contents.size();i++){
            contents[i].erase(remove_if(contents[i].begin(), contents[i].end(), ::isspace), contents[i].end());
    }

    //Close file
    file.close();
    return contents;
}

