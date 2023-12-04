#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string,char>c2n =
{
    {"one",'1'},
    {"two",'2'},
    {"three",'3'},
    {"four",'4'},
    {"five",'5'},
    {"six",'6'},
    {"seven",'7'},
    {"eight",'8'},
    {"nine",'9'},
    {"1",'1'},
    {"2",'2'},
    {"3",'3'},
    {"4",'4'},
    {"5",'5'},
    {"6",'6'},
    {"7",'7'},
    {"8",'8'},
    {"9",'9'}
};
unordered_map<string,char>c2nr =
{
    {"eno",'1'},
    {"owt",'2'},
    {"eerht",'3'},
    {"ruof",'4'},
    {"evif",'5'},
    {"xis",'6'},
    {"neves",'7'},
    {"thgie",'8'},
    {"enin",'9'},
    {"1",'1'},
    {"2",'2'},
    {"3",'3'},
    {"4",'4'},
    {"5",'5'},
    {"6",'6'},
    {"7",'7'},
    {"8",'8'},
    {"9",'9'}
};

template<class T>
char find_digit_in_container(T it1,T it2, unordered_map<string,char>& string2number)
{
    for (;it1!=it2; it1++) {
        auto it2 = it1;
        string match = "";
        for (int i = 0; i<5;i++) {
            match.push_back(*it2++);
            auto res = string2number.find(match);
            if(res != string2number.end())
            {
                return res->second;
            }
        }
    }
    return '!';
}

void work(vector<string>& data)
{

    char* buf= new char[3]; 
    buf[3]='\0';
    int num = 0;
    for (auto& d : data) {
        buf[0] = find_digit_in_container(d.begin(), d.end(), c2n);
        buf[1] = find_digit_in_container(d.rbegin(), d.rend(), c2nr);
        // buf[0] = *std::find_if(d.begin(), d.end(), [](char& c){return isdigit(c);});
        // buf[1] = *std::find_if(d.rbegin(), d.rend(), [](char& c){return isdigit(c);});
        // cout<< d <<endl;
        num+= atoi(buf);
    }
    cout<< num <<endl;
    delete [] buf;
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
