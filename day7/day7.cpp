#include <bits/stdc++.h>

using namespace std;
long long int readFile(string filename){
    ifstream file(filename);
    string line;

    long long int finalRes = 0;
    while(getline(file,line)){

        istringstream stream(line);
        bool firstElem = true;
        vector<long long int> vec;   
        long long int value;
        while(stream){
            string num;
            stream >> num;
            if (num == "") break;
            if(firstElem) value = stoll(num.substr(0,num.size() - 1));

            if(!firstElem){
                vec.push_back(stoi(num));
            }

            firstElem = false;
        }
        
        int totalCombinations = 1 << (vec.size() - 1);
        //cout << "For value " << value << endl;
        for (int mask = 0; mask < totalCombinations; mask++){
            long long int res = 0;
            bool firstIter = true;
            for (int i = 0; i < vec.size() - 1; i++){
                if (mask & (1 << i)){
                    if(firstIter) res+= vec[i] + vec[i+1]; 
                    else res+= vec[i+1];                  
                }else{
                    if(firstIter) res+= vec[i] * vec[i+1]; 
                    else res*=vec[i+1];
                }
                firstIter = false;
            }
            //cout << res << endl;
            if(res == value){
                finalRes+= value;
                break;
            }
        }
    }
    return finalRes;
}


int main(){
    cout << readFile("input.txt") << endl;
    return 0;
}