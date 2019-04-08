#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int T;
    string N;
    cin >> T;

    for (size_t i = 0; i < T; ++i) {
        cin >> N;
        string A, B;

        for (const auto& c : N) {
            if (c == '4') {
                A += '3';
                B += '1';
            } else {
                A += c;
                B += '0';
            }
        }

        cout << "Case #" << i + 1 << ": " << stoi(A) << ' ' << stoi(B) << endl;
    }

    return 0;
}
