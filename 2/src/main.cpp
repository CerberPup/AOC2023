#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int powerGame(string& game)
{
    int minr = 0;
    int ming = 0;
    int minb = 0;
    auto semicolon = find(game.begin(),game.end(),':');
    auto digit = find_if(semicolon,game.end(), [](const char& c){return isdigit(c);});
    while (digit != game.end()) {
        string number = {*digit};
        while (isdigit(*(digit +1))) {
            number.push_back(*++digit);
        }
        digit+=2;
        int num = stoi(number);
        if (*(digit) == 'r') {
            minr = minr > num?minr:num;
        }
        if (*(digit) == 'g') {
            ming = ming > num?ming:num;
        }
        if (*(digit) == 'b') {
            minb = minb > num?minb:num;
        }

        digit = find_if(digit,game.end(), [](const char& c){return isdigit(c);});

    }
    return minr*ming*minb;
}

bool isGameValid(string& game)
{
    auto semicolon = find(game.begin(),game.end(),':');
    auto digit = find_if(semicolon,game.end(), [](const char& c){return isdigit(c);});
    while (digit != game.end()) {
        string number = {*digit};
        while (isdigit(*(digit +1))) {
            number.push_back(*++digit);
        }
        digit+=2;
        int max = 12;
        if (*(digit) == 'g') {
            max = 13;
        }
        if (*(digit) == 'b') {
            max = 14;
        }
        if (stoi(number) > max) {
            return false;
        }

        digit = find_if(digit,game.end(), [](const char& c){return isdigit(c);});

    }
    return true;
}

void work(vector<string>& data){
    int sum = 0;
    for (int i = 0; i<data.size(); i++) {
        // if(isGameValid(data[i])){
        //     sum+=i+1;
        // }
        sum+=powerGame(data[i]);
    }
    cout<<sum<<endl;
}

int main (int argc, char *argv[]) {
    vector<string> InputData;
    auto file = fstream("data.txt");
    std::string line;
    while (std::getline(file, line))
    {
        InputData.push_back(line);
    }
    
    work(InputData);

    return 0;
}
