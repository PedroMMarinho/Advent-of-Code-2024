
#include <bits/stdc++.h>

using namespace std;

void readFile(string filename, vector<vector<int>> &data, pair<int,int> &startingPoint){
    ifstream file(filename);
    string line;
    int i = 0;
    while (getline(file,line))
    {

        vector<int> row;
        int j = 0;
        for (char elem : line){
            if (elem == '.'){
                row.push_back(0); // not visited
            }
            if (elem == '#'){
                row.push_back(2); // obstacle
            }
            if (elem == '^'){
                row.push_back(1);
                startingPoint = {i,j};
            } 
            j++;
        }
        data.push_back(row);
        i++;
    }
    
}

int main(){

    vector<vector<int>> lab;
    pair<int,int> startingPoint;
    readFile("input.txt",lab,startingPoint);
    int direction = 0; // 0 is up, 1 is right, 2 is down , 3 is left
   
    int res = 1;
    while (true){
        pair<int,int> oldStartingPoint = startingPoint; 
        
        if (direction == 0){
            startingPoint.first--;
        }
        if (direction == 1){
            startingPoint.second++;
        }
        if(direction == 2){
            startingPoint.first++;
        }
        if(direction == 3) startingPoint.second--;

        bool outOfBounds = startingPoint.first < 0 || startingPoint.first >= lab.size() || startingPoint.second < 0 || startingPoint.second >= lab[0].size();

        if (outOfBounds) break;

        int typeOfParcel = lab[startingPoint.first][startingPoint.second];

        if( typeOfParcel == 2){
            direction = (direction + 1) % 4;
            startingPoint = oldStartingPoint;
        }

        if(typeOfParcel == 0){
            res++;
            lab[startingPoint.first][startingPoint.second] = 1;
        }
    }
    cout << res << endl;

    return 0;
}