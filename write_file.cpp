#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void write_file(vector<string> &parsed_file){

    //Variables

    ofstream myfile ("MaxL.hack");
      if (myfile.is_open())
      {
        for(int i = 0; i < parsed_file.size();i++){
            myfile << parsed_file[i] << "\n";
        }
        myfile.close();
      }
      else cout << "Unable to open file";
}
