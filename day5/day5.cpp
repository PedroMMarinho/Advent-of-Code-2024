#include <bits/stdc++.h>

using namespace std;

void readFile(string filename, map<int,vector<int>> &data, vector<vector<int>> &rows){
    ifstream file(filename);
    string line;

    while(getline(file, line)){

        if (line.empty()){
            break;
        }

        string key, value;
        bool fstNum = true;
        for (int i = 0; i < line.size(); i++){
            if(line[i] == '|'){
                fstNum = false;
                continue;
            }
            if(fstNum){
                key += line[i];
            }
            else {
                value +=line[i];
            }
        }
        int iValue = stoi(value), iKey = stoi(key);

        if (data.find(iKey) == data.end()){
            vector<int> vec;
            vec.push_back(iValue);
            data[iKey] = vec;
        }else{
            data[iKey].push_back(iValue);
        }

    }

    while (getline(file, line))
    {
        std::vector<int> result;
        std::stringstream ss(line);
        std::string token;

        while (std::getline(ss, token, ',')) {
            result.push_back(std::stoi(token)); // Convert to integer and store
        }
       rows.push_back(result);
    }
    
    file.close();
}

int main(){
    map<int,vector<int>> mapa;
    vector<vector<int>> vec;
    readFile("input.txt",mapa, vec);
    vector<int> indexes;
    int w = -1;
    int res = 0;
    
    /*
    for (vector<int> row : vec){
        for (int i = 0; i < row.size(); i++){
            cout << row[i] << " ";
        }
        cout << endl;
    }

    for (auto it = mapa.begin(); it != mapa.end(); ++it){
        cout << it->first << " => ";
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2){
            cout << *it2 << " ";
        }
        cout << endl;
    }

    */
    

    for (const auto &row : vec){
        w++;
        bool isCorrectlyOrdenated = true;
        for (auto i = 0; i < row.size() ; i++){
            vector<int> numbers = mapa[row[i]];

            for( int j = i + 1; j < row.size(); j++){
                
                if(find(numbers.begin(), numbers.end(),row[j]) == numbers.end()){
                    
                    isCorrectlyOrdenated = false;
                    break;
                }
            }
            if(!isCorrectlyOrdenated) break;
        }
        if(isCorrectlyOrdenated){
            indexes.push_back(w);
        }
    }
    for (int j = 0; j < indexes.size(); j++){
        res += vec[indexes[j]][vec[indexes[j]].size() / 2];
    }
    cout << res << endl;
    return 0;
}