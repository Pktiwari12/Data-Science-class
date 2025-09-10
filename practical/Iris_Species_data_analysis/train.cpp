#include<iostream>
#include "../algorithm/single_neuran.h"
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

int main(){
    ifstream file("../Iris_species_kaggle/Iris_normalized_freature_with_dummy_var.csv");
    if(!file.is_open()){
        cout << "Error occurs during opening the file" << endl;
        return -1;
    }
    string line;
    vector<vector<float>> data;
    stringstream ss;
    bool header = false;
    while(getline(file,line)){
        if(header == false){
            header = true;
            continue;
        }
        ss << line;
        vector<float>row;
        string buffer;
        while(getline(ss, buffer, ',' )){
            // cout << buffer << "\t" ;
            row.push_back(stof(buffer));

        }
        data.push_back(row);
        // cout << endl;
        // clear sting stream
        ss.clear();
    }
    file.close();
    // for(int i = 0 ; i < data.size() ; i++){
    //     for(int j = 0 ; j < data[i].size() ; j++){
    //         cout << data[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    // cout << data.size() << endl << data[99].size() ;
    

    // call single neuron
    single_neuran_step_fxn(1,3,3,3,1,data);
}