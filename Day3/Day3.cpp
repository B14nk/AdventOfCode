#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void parseInput(vector<string> &input, string path){
    string line;
    ifstream data(path);
    int solution_1 = 0;
    int solution_2 = 0;
    
	if(data.is_open())
    {
        while(getline(data,line))
        {
            input.emplace_back(line);
        }
        data.close();
    }
    else cout << "Unable to open file\n";
    return;
}

long compute(vector<string> &input, int right, int down){
    int count = 0;
    int i = 0;
    int it = 0;
    
    while(i < input.size()-1)
    {
        it = (it + right) % input[1].length();
        i += down;
        if (input[i][it] == '#')
        {
            count += 1;
        }
    }
    return count;
}




int main(int argc, char* argv[]){

    if (argc != 2)
	{
		cout << "Please provide an argument!\n";
		return 1;
	}

    vector<string> input;

    parseInput(input, argv[1]);
    cout << compute(input, 1, 1) * compute(input, 3, 1) * compute(input, 5, 1) * compute(input, 7, 1) * compute(input, 1, 2)<< "\n";
    return 0;
}