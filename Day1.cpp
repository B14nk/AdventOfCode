#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector <int> readFileToArray(vector <int> &input, string path){
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
            
            
        }
        data.close();
    }

    else cout << "Unable to open file\n";

	return input;
}

int computeSolution1(vector <int> &input){

    for (int i = 0; i < input.size(); i++)
    {
        for (int j = i+1; j < input.size(); j++)
        {
            if(input[i] + input[j] == 2020){
                return input[i]*input[j];
            }
        }
        
    }
    
    return 1;
}

int computeSolution2(vector <int> &input){

    for (int i = 0; i < input.size(); i++)
    {
        for (int j = i+1; j < input.size(); j++)
        {
            for (int k = j+1; k < input.size(); k++)
            {
                if(input[i] + input[j] + input[k] == 2020){
                    return input[i]*input[j]*input[k];
                }
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

    readFileToArray(input, argv[1]);

    cout << computeSolution1(input) << "\n";
    cout << computeSolution2(input) << "\n";
    return 0;


}