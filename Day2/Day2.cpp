#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void parseAndCheckInput(string path){
    string line;
    ifstream data(path);
    int solution = 0;
    
	if(data.is_open())
    {
        while(getline(data,line))
        {
            int lowerBound = 0;
            int upperBound = 0;
            string temp = line.substr(0, line.find("-"));
            line.erase(0, temp.length()+1);
            stringstream convert1(temp);
            convert1 >> lowerBound;

            temp = line.substr(0, line.find(" "));
            line.erase(0, temp.length()+1);
            stringstream convert2(temp);
            convert2 >> upperBound;
            char letter = line[0];
            string password = line.substr(3, line.length());

            int count = 0;
            for (int i = 0; i < password.length(); i++)
            {
                if (password[i] == letter)
                {
                    count += 1;
                }
            }
            if (count >= lowerBound && count <= upperBound)
            {
                solution += 1;
            }
            
            
        }
        data.close();
    }
    else cout << "Unable to open file\n";
    cout << solution << "\n";
    return;
}

int main(int argc, char* argv[]){

    if (argc != 2)
	{
		cout << "Please provide an argument!\n";
		return 1;
	}

    parseAndCheckInput(argv[1]);

    return 0;
}