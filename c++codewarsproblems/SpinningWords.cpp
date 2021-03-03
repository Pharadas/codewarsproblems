#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
    
string spinningWords(const string &str) {
    string result;
    pair<int,int> indexPair;
    string holder;
    indexPair.first = 0;

    for (int i = 0; i < (int) str.size(); i++) {
        if (str[i] == ' ') {
            indexPair.second = i;
            holder = string(str.substr(indexPair.first, indexPair.second - indexPair.first));
            if ((int) holder.size() >= 5) {reverse(holder.begin(), holder.end());}
            result += holder + ' ';
            indexPair.first = i + 1;
        }
        else if (i + 1 == (int) str.size()) {
            holder = string(str.substr(indexPair.first, (int) str.size() - indexPair.first));
            if ((int) holder.size() >= 5) {reverse(holder.begin(), holder.end());}
            result += holder;
        }
    }
    return result;
}

// test
int main() {
    string result = spinningWords("Pizza is the best vegetable");
    cout << result << endl;
    return 0;
}