#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
using namespace std;

typedef pair<int, int> point;

int parseNumber(const vector<string>& data, point& xy_)
{
    int x = xy_.first;
    while (isnumber(data[xy_.second][x]) ) {
        x--;
    }
    string snumber;
    int length = data[0].size()-1;
    for (x=max(x+1, 0); x <= length && isnumber(data[xy_.second][x]); x++) {
        snumber.push_back(data[xy_.second][x]);
    }
    xy_.first = min(x,length);
    return stoi(snumber);
}

int calcRatio(const vector<string>& data, const point& xy)
{
    int ratio = 0;
    int length = data[0].size()-1;
    int right = min(length,xy.first+1);
    int top = min(xy.second +1, length);
    for (int y = max(xy.second -1, 0); y <= top; y++) {
        for (int x =max(xy.first -1, 0); x <= right; x++) {
            const char& c = data[y][x];
            if (isnumber(c)) {
                point p = {x,y};
                auto n = parseNumber(data, p);
                if(ratio == 0){
                    ratio = n;
                    x=p.first;
                }
                else {
                    return ratio * n;
                }
            }
        }
    }
    return 0;
}

bool isSymbolAround(const vector<string>& data,const point& xy1,const point& xy2)
{
    int length = data[0].size()-1;
    int right = min(length,xy2.first+1);
    int bottom = min(xy2.second +1, length);
    for (int y = max(xy1.second -1, 0); y <= bottom; y++) {
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
    int ratio = 0;
    int length = data[0].size();
    string snumber = "";
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
            if (data[y][x] == '*') {
                ratio+=calcRatio(data,{x,y});
            }
        }
    }
    cout<<"Sum: "<<sum<<endl;
    cout<<"Ratio: "<<ratio<<endl;
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
