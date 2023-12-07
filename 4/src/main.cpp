#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
#include <list>

using namespace std;

int game2copies(string& game)
{

    unordered_set<int> winningNumbers;
    int ret = 0;
    std::stringstream ss(game);
    string data;
    ss >> data >> data;
    bool winning = true;
    while (ss>> data) {
        if (winning){
            if (data == "|"){
                winning = false;
                continue;
            }
            winningNumbers.emplace(stoi(data));
        }else{
            const bool found = winningNumbers.find(stoi(data))!= winningNumbers.end();
            if (found) {
                ret+=1;
            }
        }
    }
    return ret;
}

int game2points(string& game)
{
    unordered_set<int> winningNumbers;
    int ret = 0;
    std::stringstream ss(game);
    string data;
    ss >> data >> data;
    bool winning = true;
    while (ss>> data) {
        if (winning){
            if (data == "|"){
                winning = false;
                continue;
            }
            winningNumbers.emplace(stoi(data));
        }else{
            const bool found = winningNumbers.find(stoi(data))!= winningNumbers.end();
            if (found) {
                if(ret == 0){
                    ret = 1;
                }else {
                    ret*=2;
                }
            }
        }
    }
    return ret;
}

void work(vector<string>& data){
    int sum = 0;
    int cards = 0;
    list<int> clones;
    for (int i = 0; i<data.size(); i++) {
        sum += game2points(data[i]);
        int number = 1;
        if (clones.empty() == false)
        {
            number = clones.front();
            clones.pop_front();
        }
        int toclone = game2copies(data[i]);
        auto it = clones.begin();
        for (int j = 0; j < toclone; j++) {
            if (it != clones.end()) {
                *it+=number;
                it++;
            }else {
                clones.push_back(number+1);
                it = clones.end();
            }
        }
        cards+=number;
    }
    cout<<"Sum: "<<sum<<endl;
    cout<<"Cards: "<<cards<<endl;
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
