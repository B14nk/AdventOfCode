#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>

using namespace std;

void readFileToArray(vector <int> &input, unordered_set <int> &input_set, string path){
    string line;
    ifstream data(path);
    
	if (data.is_open())
    {
        while ( getline(data,line) )
        {
            stringstream convert(line);

            int temp = 0;
            convert >> temp;
            input.emplace_back(temp);
            //input_set.emplace(temp);
            input_set.insert(temp);
            
            
        }
        data.close();
    }

    else cout << "Unable to open file\n";

	return;
}

int computeSolution1(vector <int> &input, unordered_set <int> &input_set){

    for (int i = 0; i < input.size(); i++)
    {
        if(input_set.count(2020-input[i]) == 1){
            return input[i] * (2020-input[i]);
        }
        
    }
    
    return 1;
}

int computeSolution2(vector <int> &input, unordered_set <int> &input_set){

    for (int i = 0; i < input.size(); i++)
    {
        for (int j = i+1; j < input.size(); j++)
        {
            if(input_set.count(2020-input[i]-input[j]) == 1){
            return input[i] * input[j] * (2020-input[i]-input[j]);
        }
            
        }
        
    }
    
    return 1;
}


int main(int argc, char* argv[]){

    if (argc != 2)
	{
		cout << "Please provide an argument!\n";
		return 1;
	}

    vector <int> input;
    unordered_set <int> input_set;

    readFileToArray(input, input_set, argv[1]);
    cout << computeSolution1(input, input_set) << "\n";
    cout << computeSolution2(input, input_set) << "\n";
    return 0;


}