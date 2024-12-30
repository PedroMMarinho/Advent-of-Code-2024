# include <iostream>
# include <fstream>
# include <vector>
#include <numeric>
using namespace std;

void readFile(string filename, vector<vector<char>> &data){
    ifstream file(filename);
    string line;
    while(getline(file, line)){
        vector<char> row;
        
        for(int i = 0; i < line.size(); i++){
            row.push_back(line[i]);
        }
        data.push_back(row);
    }
    file.close();
}

int check_surrounding_word(pair<int,int> coordinates,vector<vector<char>>& data){ 
    vector<int> vec(8,1); 
    string target = "MAS";
    int x = coordinates.first, y = coordinates.second;
    int index = 0;
    // checkLeft
    for (int i = 0; i < 3; i++){
        y--;
        if (y < 0 || target[i] != data[x][y]){
            vec[index] = 0;
            break;
        }
    }
    x = coordinates.first, y = coordinates.second;
    index++;
    // checkRight
    for (int i = 0; i < 3; i++){
        y++;
        if (y >= data[0].size() || target[i] != data[x][y]){
            vec[index] = 0;
            break;
        }
    }
    x = coordinates.first, y = coordinates.second;
    index++;

    // checkUp
    for (int i = 0; i < 3; i++){
        x--;
        if (x < 0 || target[i] != data[x][y]){
            vec[index] = 0;
            break;
        }
    }
    x = coordinates.first, y = coordinates.second;
    index++;

    // checkDown
    for (int i = 0; i < 3; i++){
        x++;
        if (x >= data.size() || target[i] != data[x][y]){
            vec[index] = 0;
            break;
        }
    }
    x = coordinates.first, y = coordinates.second;
    index++;
    // checkDiagonal right
    for (int i = 0; i < 3; i++){
        x--;
        y++;
        if (x < 0 || y >= data[0].size()  || target[i] != data[x][y]){
            vec[index] = 0;
            break;
        }
    }
    x = coordinates.first, y = coordinates.second;
    index++;
    // checkDiagonal left
    for (int i = 0; i < 3; i++){
        x--;
        y--;
        if (x < 0 || y < 0  || target[i] != data[x][y]){
            vec[index] = 0;
            break;
        }
    }
    x = coordinates.first, y = coordinates.second;
    index++;
    // checkDiagonal right down
    for (int i = 0; i < 3; i++){
        x++;
        y++;
        if (x >= data.size() || y >= data[0].size()  || target[i] != data[x][y]){
            vec[index] = 0;
            break;
        }
    }
    x = coordinates.first, y = coordinates.second;
    index++;
    // checkDiagonal left down
    for (int i = 0; i < 3; i++){
        x++;
        y--;
        if (x >= data.size() || y < 0  || target[i] != data[x][y]){
            vec[index] = 0;
            break;
        }
    }
    return accumulate(vec.begin(), vec.end(), 0);;
}

int main(){
    vector<vector<char>> data;
    readFile("input.txt", data); 
    int res = 0;
    for(auto i = 0; i < data.size(); i++){
        for (auto j = 0; j < data[0].size() ;j++){
            if (data[i][j] == 'X'){
                res += check_surrounding_word({i,j}, data);
            }
        }
    }
    cout << res << endl;
    return 0;
}