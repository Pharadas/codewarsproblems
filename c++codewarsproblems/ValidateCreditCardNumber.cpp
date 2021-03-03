#include<string>
#include<iostream>

using namespace std;

bool validate(long long int n) {
    string numString = to_string(n);
    int totalSum = 0;

    for (int i = 0; i < (int) numString.size(); i++) {((int) numString.size() % 2 == 0 && i % 2 == 0) || ((int) numString.size() % 2 != 0 && i % 2 != 0) ? ((int) numString[i] - 48) * 2 >= 10 ? totalSum += (((int) numString[i] - 48) * 2) - 9 : totalSum += ((int) numString[i] - 48) * 2 : totalSum += (int) numString[i] - 48;}

    if (totalSum % 10 == 0) {return true;} else {return false;}
}

// test
int main() {
    cout << validate(8675309) << endl;
    return 0;
}