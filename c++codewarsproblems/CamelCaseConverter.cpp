#include<string>
#include<iostream>

using namespace std;

string to_camel_case(string text) {
    string result;
    pair<int,int> indexPair;
    char c;
    indexPair.first = 0;

    for (int i = 0; i < (int) text.size(); i++) {
        if (i == 0 && isupper(text[0])) {text[0] = char(toupper(text[0]));}
        if (text[i] == '-' || text[i] == '_') {
            indexPair.second = i;
            c = text[indexPair.first];
            if (indexPair.first != 0) {text[indexPair.first] = char(toupper(c));};
            result += string(text.substr(indexPair.first, indexPair.second - indexPair.first));
            indexPair.first = i + 1;
        }
        else if (i + 1 == (int) text.size()) {
            c = text[indexPair.first];
            text[indexPair.first] = char(toupper(c));
            result += string(text.substr(indexPair.first, (int) text.size() - indexPair.first));
        }
    }
    cout << result << endl;
    return result;
}

// test
int main() {
    to_camel_case("the-stealth-warrior");
    return 0;
}