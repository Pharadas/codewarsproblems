#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

string weightforweight(string GI) {
    string result;
    int thisSum;
    vector<pair<int, string>> trueWeight;
    pair<int,int> indexPair;

    indexPair.first = 0;
    for (int i = 0; i < (int) GI.size(); i++) {
        thisSum = 0;
        if (GI[i] == ' ') {
            indexPair.second = i;
            for (char x : string(GI.substr(indexPair.first, indexPair.second - indexPair.first))) {thisSum += (int) x - 48;}
            trueWeight.push_back(pair<int, string> (thisSum, string(GI.substr(indexPair.first, indexPair.second - indexPair.first))));
            indexPair.first = i + 1;
        }
        else if (i + 1 == (int) GI.size()) {
            for (char x : string(GI.substr(indexPair.first, (int) GI.size() - indexPair.first))) {thisSum += (int) x - 48;}
            trueWeight.push_back(pair<int, string> (thisSum, string(GI.substr(indexPair.first, indexPair.second - indexPair.first))));
        }
    }
    sort(trueWeight.begin(), trueWeight.end());
    for (int i = 0; i < (int) trueWeight.size(); i++) {
        i != (int) trueWeight.size() - 1 ? result += trueWeight[i].second + ' ' : result += trueWeight[i].second;
    }
    cout << result << endl;
    return result;
}

// test
int main() {
    cout << weightforweight("56 65 74 100 99 68 86 180 90") << endl;
    return 0;
}