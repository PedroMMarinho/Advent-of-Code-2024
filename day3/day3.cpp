#include <iostream>
#include <regex>
#include <fstream>

using namespace std;

int main(){
    ifstream f("input.txt");

    regex b ("mul\\((\\d{1,3}),(\\d{1,3})\\)");
    int mulSum {0};
    string s;

    smatch match;
    
    while (getline(f, s)){
        
        auto search_start = s.cbegin();

        while(regex_search(search_start,s.cend(),match,b) ){
            search_start = match[0].second;
            mulSum +=  stoi((match[1].str())) *  stoi((match[2].str()));
        }
    }

    cout << mulSum << endl;
    return 0;
}
