#include<vector>
#include<iostream>

using namespace std;

vector<int> snail(const vector<std::vector<int>> &snail_map) {
    const int vectorSize = (int) snail_map[0].size();
    vector<int> result;

    for (int setter = 0; setter < vectorSize; setter++) {
        // top left->right
        for (int i = setter; i < vectorSize - setter; i++) {
            result.push_back(snail_map[setter][i]);
        }
        // left top->down
        for (int i = setter + 1; i < vectorSize - setter; i++) {
            result.push_back(snail_map[i][vectorSize - setter - 1]);
        }
        // bottom right->left
        for (int i = vectorSize - setter - 2; i > setter - 1; i--) {
            result.push_back(snail_map[vectorSize - setter - 1][i]);
        }
        // left bottom->top
        for (int i = vectorSize - setter - 2; i > setter; i--) {
            result.push_back(snail_map[i][setter]);
        }
    }

    return result;
}

// test
int main() {
    vector<vector<int>> snail_map[[]] = {{89,  307, 263, 192, 708, 93, 848,  936, 37,  165},
                                         {832, 974, 115, 21, 751, 813, 113,  870, 477, 904},
                                         {806, 156, 475, 181, 26, 54,  792,  427, 61,  950},
                                         {905, 686, 526, 752, 572, 525, 599, 949, 459, 164},
                                         {405, 173, 767, 963, 249, 313, 685, 851, 464, 747},
                                         {909, 86, 152,  405, 435, 726, 995, 428, 180, 78},
                                         {889, 84, 956,  234, 931, 98,  375, 832, 255, 365},
                                         {849, 236, 961, 877, 139, 664, 49,  958, 964, 744},
                                         {62,  146, 794, 759, 502, 365, 410, 417, 410, 75},
                                         {125, 252, 232, 663, 227, 753, 693, 455, 706, 698}};

    vector<int> result = snail(snail_map);

    for (auto i : result) {
        cout << i << endl;
    }

    return 0;
}