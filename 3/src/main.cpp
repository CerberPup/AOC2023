#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
using namespace std;

typedef pair<int, int> point;

bool isSymbolAround(const vector<string>& data,const point& xy1,const point& xy2)
{
    int length = data[0].size()-1;
    int right = min(length,xy2.first+1);
    int top = min(xy2.second +1, length);
    for (int y = max(xy1.second -1, 0); y <= top; y++) {
        for (int x =max(xy1.first -1, 0); x <= right; x++) {
            const char& c = data[y][x];
            if (c!='.' && !isnumber(c)) {
                return true;
            }
        }
    }
    return false;
}

void work(vector<string>& data){
    int sum = 0;
    int length = data[0].size();
    string snumber = "";
    isSymbolAround(data, {49,139}, {51,139});
    for (int y = 0; y<data.size(); y++) {
        for (int x = 0; x < length; x++) {
            if (isdigit(data[y][x])) {
                point left = {x,y};
                snumber.push_back(data[y][x]);
                while(isdigit(data[y][++x]) && x < length){
                    snumber.push_back(data[y][x]);
                }
                if(isSymbolAround(data, left, {x-1,y})){
                    sum+=stoi(snumber);
                }
                snumber.clear();
            }
        }
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
